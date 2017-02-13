#include <iostream>
#include <vector>

using namespace std;

void populateVector(vector<int>& newV, string line){
    
    int i = 1;
    
    for(i = 1; i < line.size(); ++i){
        
        newV.resize(i);
        newV.at(i - 1) = line.size(i - 1);
    }
    
    return;
    
}

int countLetters(const vector<int>& newV, string find) {
    
    int i = 0;
    int j = 0;
    
    for (i = 0; i < newV.size(); ++i) {
        for (current = 'a'; current <= 'z'; ++current){
            
            if(newV.at(i) == current)
                alphabet.at(i)++;
        }
    }
}


int main() {
    vector<int> alphabet(26);
    vector<int> newV;
    string line;
    char current = 'a';
    int i = 0;
    
    cout << "Enter a line of text: ";
    getline(cin, line);
    
    populateVector(newV, line);
    countLetters(alphabet, line);
    
    for (current = 'a'; i <= 'z'; ++current) {
        
        cout << current << ": "
        
        for (i = 0; i < newV.size(); ++i){
            
            cout << newVsize.at(i) << endl;
        }
    }
    
    return 0;
}