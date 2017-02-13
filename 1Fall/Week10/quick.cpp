#include <iostream>
#include <vector>
using namespace std;

void printFirstname (const vector<string> list){
   
    for (int i = 0; i < list.size(); ++i){
        for(int j = 0; j < list.at(i).find(" "); ++j) {
            cout << list.at(i);
        }
        cout << endl;
    }    
    
    return;
}


int main () {
    vector<string> list;

    list.at(0) = "jon snow";
    list.at(1) = "ed lee";
    list.at(2) = "tim at";

    int print = list.at(1).size();
    
    cout << print << endl;
    return 0;
    
}