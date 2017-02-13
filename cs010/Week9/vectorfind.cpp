#include <iostream>
#include <vector>

using namespace std;

int findVector(const vector<string>& list, string find) {

    int i = 0;
    
    for (i = 0; i < list.size(); ++i) {
        
        if (find == list.at(i))
            return i;
    }
    
    return -1;
}


int main() {
    
    vector<string> list(6);
    int location = 0;
    string finding;
    
    list.at(0) = "1";
    list.at(1) = "1";
    list.at(2) = "1";
    list.at(3) = "1";
    list.at(4) = "5";
    list.at(5) = "6";
    
    cout << "Enter a word in the sentence: ";
    cin >> finding;
    
    location = findVector(list, finding);
    
    cout << "The location of the vector is at " << location << endl;
    
    return 0;
}