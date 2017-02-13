#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "Series.h"

    //0 + 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21 + 34 + 55
    //0   1   2   3   4   5   6   7    8    9    10

int totalAdds = 0;
int totalCalls = 1;
int totalMoves = 0;

//START OF PART 2
double FibLoop(int n) {
    
    int FibArr[n];
    FibArr[0] = 0;
    if(n == 0)
        return FibArr[0];
        
    FibArr[1] = 1;
    if(n == 1)
        return FibArr[1];
    
    int first = 0;
    int second = 1;
    
    for(int i = 2; i < n + 1; ++i) {
        FibArr[i] = first + second;
        first = second;
        second = FibArr[i];
        ++totalAdds;
    }
    
    return FibArr[n];
    
}

double FibRec(int n) {
    
    if(n == 0)
        return 0;
    else if(n == 1) 
        return 1;
    else {
        totalCalls += 2;
        totalAdds++;
        return FibRec(n - 2) + FibRec(n - 1);
    }
}

//START OF PART 4
void FibRec2(int n, double &oneBack, double &twoBack) {
    
    totalCalls++;
    
    double temp = 0;
    
    if(n == 1) {
        twoBack = 0;
        oneBack = 1;
        return;
    }

    FibRec2(n - 1, oneBack, twoBack);
    temp = oneBack;
    oneBack += twoBack;
    twoBack = temp;
    totalAdds++;
    totalMoves++;
    return;
}

double FibRecNew(int n) {
    
    double oneBack = 0;
    double twoBack = 0;
    
    if(n == 0)
        return 0;
    else if(n == 1) 
        return 1;
    else {
        FibRec2(n, oneBack, twoBack);
        return oneBack;
    }
}

//START OF PART 5
double GenLoop(int n, int k, double initial[], double weight[]) {
    
    double answer = 0.0;
    double GenArray[n + 1];
    
    if(n < k)
        return initial[n];
        
    for(int i = 0; i < k; ++i) {
        GenArray[i] = initial[i];
    }
        
    for(int i = k; i <= n; ++i) {
            GenArray[i] = 0;
        for(int j = 0; j < k; ++j) {
            GenArray[i] += GenArray[i - j - 1] * weight[k - j];
        }
    }
    
    for(int i = n - k; i < n; ++i) {
        answer += GenArray[i];
    }
    
    totalAdds = k;    
    return answer;
    
}

void GenRec2(int n, int k, double initial[], double weight[], double back[]) {
    
    double sum = 0.0;
    int mod = 0;
    
    totalCalls++;
    
    if(n == k)
        return;
    else {
        
        GenRec2(n - 1, k, initial, weight, back);
        
        for(int i = 0; i < k; ++i) {
            sum += back[k] * weight[k];
        }

        totalMoves++;
        
        back[mod % k] = sum;
        ++mod;
        return;
    }
}

double GenRec(int n, int k, double initial[], double weight[]) {
     
    if(n < k)
        return initial[n];
        
    double back[k];
    double answer = 0.0;
    
    for(int i = 0; i < k; ++i) {
        back[i] = initial[i];
    }
    
    GenRec2(n, k, initial, weight, back);
    
    for(int i = 0; i < k; ++i) {
        answer += back[i] * weight[i];
    }
    
    return answer;
    
}

int main() {
    
    int input1 = 0;
    ofstream file1;
    ofstream file2;
    ofstream file3;
    ofstream file4;
    ofstream file5;
    
    cout << "Start of test 1: Enter a Fibonacci number: ";
    cin >> input1;
    cout << endl;
    
    file1.open("test1.csv");
    if(!file1.is_open()) {
        cout << "Error: Could not open file. " << endl;
        return 1;
    }
    
    for(int i = 0; i <= input1; ++i) {
            totalAdds = 0;
            totalCalls = 1;
            totalMoves = 0;
            FibLoop(i);
            file1 << i << ", " << totalAdds << ", " << totalCalls;
            totalAdds = 0;
            totalCalls = 1;
            totalMoves = 0;
            FibRec(i);
            file1 << ", " << totalAdds << ", " << totalCalls << endl;
    }
    
    file1.close();
    
    file2.open("test2.csv");
    if(!file2.is_open()) {
        cout << "Error: Could not open file. " << endl;
        return 1;
    }
    
    for(int i = 0; i <= input1; ++i) {
            totalAdds = 0;
            totalCalls = 1;
            totalMoves = 0;
            FibLoop(i);
            file2 << i << ", " << totalAdds << ", " << totalCalls << ", " << totalMoves;
            totalAdds = 0;
            totalCalls = 1;
            totalMoves = 0;
            FibRecNew(i);
            file2 << ", " << totalAdds << ", " << totalCalls << ", " << totalMoves << endl;
    }
    
    file2.close();
    
    int input3 = 0;
    int kvalue = 0;
    double wvalue = 0.0;
    int check = 0;
    int check2 = 0;
    
    cout << "Start of test 3: Enter your F(n) value: ";
    cin >> input3;
    cout << "Enter your k value (how many terms you're adding): ";
    cin >> kvalue;
    
    double initial[kvalue];
    double weight[kvalue];
    
    cout << "Do you want to name the initial values? Press 1 for yes: ";
    cin >> check;
    if(check == 1) {
        int j = 1;
        for(int i = 0; i < kvalue; ++i) {
            cout << "Enter " << j << ": ";
            ++j;
            cin >> initial[i];
        }
    }
    else {
        for(int i = 0; i < kvalue; ++i) {
            initial[i] = FibLoop(i);
        }
    }
    
    cout << "Do you want different weights? Press 2 for yes: ";
    cin >> check2;
    if(check2 == 2) {
        int j = 1;
        for(int i = 0; i < kvalue; ++i) {
            cout << "Enter " << j << ": ";
            ++j;
            cin >> weight[i];
        }
    }
    else {
        cout << "Enter your weight value: ";
        cin >> wvalue;
        for(int i = 0; i < kvalue; ++i) {
            weight[i] = wvalue;
        }
    }
    
    file3.open("test3.csv");
    if(!file3.is_open()) {
        cout << "Error: Could not open file. " << endl;
        return 1;
    }
    
    for(int i = 0; i <= input3; ++i) {
            totalAdds = 0;
            totalCalls = 1;
            totalMoves = 0;
            GenLoop(input3, kvalue, initial, weight);
            file3 << i << ", " << totalAdds << ", " << totalCalls << ", " << totalMoves;
            totalAdds = 0;
            totalCalls = 1;
            totalMoves = 0;
            GenRec(input3, kvalue, initial, weight);
            file3 << ", " << totalAdds << ", " << totalCalls << ", " << totalMoves << endl;
    }
    
    file3.close();
    
    file4.open("test4.csv");
    if(!file4.is_open()) {
        cout << "Error: Could not open file. " << endl;
        return 1;
    }
    
    if(check2 == 2) {
        file4 << "k value is " << kvalue << ", " << "our initial values are: ";
            for(int j = 0; j < kvalue; ++j) {
                file4 << initial[j] << " "; 
            }
            file4 << endl;
        for(int i = 0; i <= input3; ++i) {
            file4 << GenLoop(i, kvalue, initial, weight) << " ";
        }
    }
    
    file4.close();
    
    /*ORIGINAL PROGRAM WHEN TESTING VALUES IN CONSOLE
    cout << "The fibonacci value when calling FibLoop for " << input << " is " << FibLoop(input) << "." << endl;
    cout << "FibLoop totalAdds: " << totalAdds << endl;
    cout << "FibLoop totalCalls: " << totalCalls << endl << endl;
    
    file << input << ", " << totalAdds << ", " << totalCalls;
    
    totalAdds = 0;
    totalCalls = 1;
    totalMoves = 0;
    
    cout << "The fibonacci value when calling FibRec for " << input << " is " << FibRec(input) << "." << endl;
    cout << "FibRec totalAdds: " << totalAdds << endl;
    cout << "FibRec totalCalls: " << totalCalls << endl;
    
    file << ", " << totalAdds << ", " << totalCalls << endl;
    */
    
    return 0;
}
