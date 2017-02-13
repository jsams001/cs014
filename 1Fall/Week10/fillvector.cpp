#include <iostream>
#include <vector>

using namespace std;

void fill_vector (vector<int> & v, int adj){
    
    for (int i = 0; i < v.size(); ++i) {
        
        v.at(i) = adj;
    }
}

int main() {
    
    vector<int> v(5);
    vector<int> v2(5);
    
    for (int i = 0; i < v.size(); ++i){
        
        cout << v.at(i) << " ";
    }
    
    
    int adj = 0;
    
    cin >> adj;
    
    fill_vector(v, adj);
    
    for (int i = 0; i < v.size(); ++i){
        cout << v.at(i) << " ";
    }
    
    cout << endl;
    return 0;
}