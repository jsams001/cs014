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

string maxVector(const vector<string>& list) {
    
    int max = 0;
    
    for(int i = 0; i < list.size(); ++i) {
        
        if(list.at(i).size() > list.at(max).size())
            max = i;
    }
    return list.at(max);
}

int main() {
    
    vector<string> list;
    int i = 0;
    string max;
    
    addVector(list);
    
    cout << "The vector you put in has: ";
    
    for ( i = 0; i < list.size(); ++i) {
        
        cout << list.at(i) << " ";
    }
    
    cout << endl;
    
    max = maxVector(list);
    
    cout << "Largest word in vector is " << max << endl;
    
    return 0;
}