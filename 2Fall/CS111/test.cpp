#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    
    ifstream infile;
    double value;
    double d = 7;
    double p = 95;
    double answer = 0;
    double convert = 89;
    vector<double> v;
    
    infile.open("file");
    
    if(!infile.is_open()) {
        cout << "Error opening " << endl;
        return 1;
    }
   
    while(infile >> value) {
        v.push_back(value);
    }
    v.push_back(9);
   
    for(unsigned int i = 0; i < v.size() - 1; ++i) {
        answer = fmod((pow(v.at(i), d)), p);
        
        if(answer == 2)
            cout << " ";
        if(answer == 3)
            cout << ",";
        if(answer == 4)
            cout << ".";
        if(answer >= 8)
            cout << static_cast<char>(answer + convert);
    }
    cout << endl;
        
    return 0;
}