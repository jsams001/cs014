#include <iostream>
#include <cstdlib>
using namespace std;

double percentHeads (double tosses) {
    
    srand(4444);
    
    int toss = 0;
    int heads = 0;
    int i = 0;
    for (i = 0; i < tosses; ++i) {
        toss = rand() % 2;
        if (toss == 0)
            heads++;
    }
    
    return (static_cast<double>(heads) / tosses) * 100.0;
}

int main() {
    double tosses = 0;
    double percentage = 0;
    
    cout << "Enter the number of times you want to toss the coin: ";
    cin >> tosses;
    cout << endl;

    percentage = percentHeads(tosses);
    
    cout << "Heads came up " << percentage << "% of the time." << endl;
    
    return 0;
}