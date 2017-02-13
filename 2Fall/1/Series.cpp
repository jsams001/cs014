#include "Series.h"

Series::Series() : k(0), biggest_known(0){}

void Series::set_k(int input) {
    
    k = input;
    return;
}

void Series::set_weights(double mainweights[]) {
    
    for(int i = 0; i < k; ++i) {
        weights[i] = mainweights[i];
    }
    return;
}
        
void Series::set_initial(double maininitial[]) {
    
    for(int i = 0; i < k; ++i) {
        current[i] = maininitial[i];
    }
    return;
}

void Series::set_val(int n) {
    
    double answer = 0.0;
    double GenArray[n + 1];
    
    if(n <= biggest_known)
        return;
        
    for(int i = 0; i < k; ++i) {
        GenArray[i] = current[i] * weights[i];
    }
        
    for(int i = k; i < n; ++i) {
            GenArray[i] = 0;
        for(int j = 0; j < k; ++j) {
            GenArray[i] += GenArray[i - j - 1] * weights[k - j];
        }
    }
    
    for(int i = n - k; i < n; ++i) {
        answer += GenArray[i];
        cout << GenArray[i] << " ";
    }
    
    return;
}