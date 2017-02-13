#include <list>
#include <sstream>
#include <fstream>

#include "TableItem.h"

int main(int argc, char* argv[]) {

    list<TableItem> TableList;
    
    string uInput;
    string fInput;
    
    string newWord;
    char check;
    
    ifstream opening;
    ofstream outfile;
    
    int inc = 1;

    //IF NO OPTIONAL FILENAME IS PRESENT, THE STANDARD INPUT WILL RUN
    if(argc == 1) {
        
        //Reads from keyboard/standard input
        cout << "Enter a sentence: " << endl;
        getline(cin, uInput);
        istringstream inSS(uInput);
        
        //Starts reading from standard input; places each unique word into the list
        while(inSS.get(check)) {
            
            if(isalpha(check)) { //Ensures that only letters are put into the word. 
                newWord += check;
            }
            
            else if(!newWord.empty()) { //Once you hit the first instance of a non-letter, start putting the word in
                
                newWord.at(0) = tolower(newWord.at(0)); 
                
                TableItem newItem;
                newItem.setWord(newWord);
                newItem.newPos(inc);
                
                //If the list is empty or the word coming in comes after the last word in the list as of now
                //(such as newWord = zebra and the last word in the list is xylophone), just push it to the last value
                if(TableList.empty() || newWord > TableList.back().word()) {
                    TableList.push_back(newItem);
                }
                else {
                    for(std::list<TableItem>::iterator i = TableList.begin(); i != TableList.end(); ++i) {
                        if(newWord == i->word()) { //If a duplicate word is found, simply update the vector for that word
                            i->newPos(inc);
                            break;
                        }
                        else if(newWord < i->word()) { //Going through the list
                            TableList.insert(i, newItem);
                            break;
                        }
                    }
                }
            ++inc;
            newWord.clear();
            }
        }
        
        cout << endl;
        //After TableList is complete, we write the results to the console
        for(std::list<TableItem>::iterator i = TableList.begin(); i != TableList.end(); ++i) {
            cout << i-> word() << " ";
            for(int j = 0; j < i->posSize() - 1; j++) {
                cout << i->atPos(j) << ", ";
            }
            cout << i->atPos(i->posSize() - 1) << endl;
        }
        
        //Frequency part: Put the two most frequent words after you output the list
        
        list<TableItem>::iterator most = TableList.begin();
        list<TableItem>::iterator next = TableList.begin();
        vector<string> freq;
        for(std::list<TableItem>::iterator i = TableList.begin(); i != TableList.end(); ++i) {
            if(most->posSize() < i->posSize() && freq.empty()) {
                next = most;
                most = i;
            }
        }
        cout << "This single most-frequent word appears " << most->posSize() << " times: " << most->word() << endl;
        cout << "These second most-frequent word(s) appears " << next->posSize() << " times: " << next->word() << endl;
    }
    
    //FILENAME PRESENT, RUNNING FROM FILE ARGUMENT GIVEN
    else {
        fInput = argv[1];
        opening.open(fInput.c_str());
        
        if(!opening.is_open()) {
            cout << "Error: Could not open file. " << endl;
            return 1;
        }
        
        //Read from second argument
        while(opening.get(check)) {
            
            if(isalpha(check)) {
                newWord += check;
            }
            //Same logic as above
            else if(!newWord.empty()){
                
                newWord.at(0) = tolower(newWord.at(0));
                
                TableItem newItem;
                newItem.setWord(newWord);
                newItem.newPos(inc);
                
                if(TableList.empty() || newWord > TableList.back().word()) {
                    TableList.push_back(newItem);
                }
                else {
                    for(std::list<TableItem>::iterator i = TableList.begin(); i != TableList.end(); ++i) {
                        if(newWord == i->word()) {
                            i->newPos(inc);
                            break;
                        }
                        else if(newWord < i->word()) {
                            TableList.insert(i, newItem);
                            break;
                        }
                    }
                }
            ++inc;
            newWord.clear();
            }
        }
        opening.close();
        
        //Read the results of TableList into table_(second argument)
        fInput = "table_" + fInput;
        outfile.open(fInput.c_str());
            
        if(!outfile.is_open()) {
            cout << "Error: Could not open file" << endl;
            return 1;
        }
    
        for(std::list<TableItem>::iterator i = TableList.begin(); i != TableList.end(); ++i) {
                outfile << i-> word() << " ";
                for(int j = 0; j < i->posSize() - 1; j++) {
                    outfile << i->atPos(j) << ", ";
                }
                outfile << i->atPos(i->posSize() -1) << endl;
            }
            
        list<TableItem>::iterator most = TableList.begin();
        list<TableItem>::iterator next = TableList.begin();
        for(std::list<TableItem>::iterator i = TableList.begin(); i != TableList.end(); ++i) {
            if(most->posSize() < i->posSize()) {
                next = most;
                most = i;
            }
        }
        outfile << "This single most-frequent word appears " << most->posSize() << " times: " << most->word() << endl;
        outfile << "These second most-frequent word(s) appear " << next->posSize() << " times: " << next->word() << endl;
            
        outfile.close();
    }
        
    return 0;
}
