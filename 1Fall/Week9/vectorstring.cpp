#include <iostream>
#include <vector>

using namespace std;

void addVector(vector<string>& list) {
    
    string addin;
    int i = 1;
    
    cout << "Enter words" << endl;
    
    while (cin >> addin) {
        
        if(addin == "quit")
            return;
            
        list.resize(i);
        list.at(i - 1) = addin;
        i++;
        
    }

}

int main() {
    
    vector<string> list;
    int i = 0;
    
    addVector(list);
    
    cout << "The vector you put in has: ";
    
    for ( i = 0; i < list.size(); ++i) {
        
        cout << list.at(i) << " ";
    }
    
    cout << endl;
    
    return 0;
}