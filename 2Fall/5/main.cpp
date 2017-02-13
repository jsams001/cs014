#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h> 

using namespace std;

int main() {
    struct room {
    
        vector<string> longStory;
        string shortStory = "";
        vector<int> next;
        int previous;
    };
    
    struct edge {
    
        int start; 
        int end;
        double W;
    };
    
    vector<room> V; // Two vectors that must be declared in the program
    vector<edge> E;
    ifstream infile; //File to read in the text.txt file
    string input; //String value to be read from the text.txt
    int sec = 1; //Indicates which section of the text.txt file you are currently at
    
    int comp; //Comparison int to make sure the 1, 2, matches with the vertex S1
    int prev; //Takes the previous int and ensures that 2, isn't put into 1, and so on S1 
    vector<string> temp; //After temp is filled, you assign this to longStory S1
    
    char junk; //Stupid char I'm using to get rid of comma between starting and ending room S3
    int num2 = 0; //Number that will read into the ending position of edge S3
    int max = 0; //Maximum value in the row; this value will be put into the edge as W. S3
    
    infile.open("text.txt");
    
    if(!infile.is_open()) {
        cout << "Error opening " << endl;
        return 1;
    }
    
    while(!infile.eof()) {
        getline(infile, input);
        istringstream read(input);
        read >> comp;
        
        if(sec == 1) {
            room putin;
            if(input == "-1,END") {
                sec++;
                prev = 1;
            }
            else if(input == "1") {}
            else {
                if(prev == comp) { //EX: Current line is 1, previous line was 1,
                    prev = comp;
                    input = input.substr(input.find(",") + 1);
                    temp.push_back(input);
                }
                else { //EX: Current line is 2, but previous line was 1,
                    prev = comp;
                    putin.longStory = temp;
                    temp.clear();
                    V.push_back(putin);
                    input = input.substr(input.find(",") + 1);
                    temp.push_back(input);
                }
            }
        }
        
        else if(sec == 2) {
            if(input == "-1") {
                sec++;
            }
            else if(input == "2")
                comp = 1;
            else {
                input = input.substr(input.find(",") + 1);
                V.at(comp).shortStory = input;
            }
                
        }
        
        else if(sec == 3) {
            if(input == "-1" || input == "3") {}
            else {
                edge putin2;
                read >> junk;
                read >> num2;
                if(num2 == 303) {
                    if(comp == 117) {
                        putin2.start = comp;
                        putin2.end = 122;
                        putin2.W = 100;
                    }
                    else if(comp == 122) {
                        putin2.start = comp;
                        putin2.end = 122;
                        putin2.W = 100;
                    }
                }
                else if(num2 >= 300) {
                    continue;
                }
                else {
                    putin2.start = comp;
                    putin2.end = num2;
                    read >> junk;
                    read >> num2;
                    max = num2;
                    while(read >> num2) {
                        read >> junk;
                        read >> num2;
                        if(num2 > max)
                            max = num2;
                    }
                    putin2.W = max;
                    // V.at(putin.start).next.push_back(putin)
                    E.push_back(putin2);
                }
            }
        }
    }
    infile.close();
    
    // for(unsigned int i = 0; i < E.size() - 1; ++i) {
    
    //     V.at(E.at(i).start).next.push_back(E.at(i).W);
    // }
    
    /*  Our ifstream file is closed, signifying that we have two vectors full of rooms and edges. 
        Each individual room has multiple elements of a longStory description, along with one shortStory description
        if applicable.
        Edges are done as well. 
        Now we start asking for user input
        ***Work on room ints next and previous***
    */
    
    int uinput;
    string usercheck;
    int i = 1;
    vector<int> vertex;
    
    cout << "Enter three vertex numbers, between 1 and the maximum: " << endl;
    
    while(i < 4) {
        cout << "Enter vertex number " << i << ": " << endl;
        cin >> uinput;
        
        if(uinput >=1 && uinput <= 140) {
            for(int j = 0; j < V.at(uinput).longStory.size(); ++j) {
                cout << V.at(uinput).longStory.at(j) << endl;
            }
            cout << endl << "Are you happy with this input? Type Y if so, anything else for no: " << endl;
            cin >> usercheck;
            if(usercheck == "Y" || usercheck == "y") {
                ++i;
                vertex.push_back(uinput);
            }
            else
                continue;
        }
        else {
            cout << "Please enter a valid vertex next time. " << endl; 
            break;
        }
    }
    
    cout << "Your vertexes are " << vertex.at(0) << ", " << vertex.at(1) << ", and " << vertex.at(2) << endl;
    
    
    
    // for(int i = 1; i < V.size(); ++i) {
    //     for(int j = 0; j < V.at(i).next.size(); ++j) {
    //         cout << V.at(i).next.at(j) << endl;
    //     }
    // }
    
    // for(unsigned int i = 0; i < E.size(); ++i) {
    //     cout << "START: " << E.at(i).start << " END: " << E.at(i).end << " WEIGHT: " << E.at(i).W << endl;
    // }
    
    // cout << E.size() << endl;
    
    return 0;
}