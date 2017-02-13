#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector<double>& vctrList)
{
    double userDouble = 0.0;
    int i = 1;

    cout << "Enter numbers to populate the vector ";
    cout << "(enter any other character to end user input): "; 

    while (cin >> userDouble) {
        
        vctrList.resize(i);
        vctrList.at(i - 1) = userDouble;
        i++;
    }
    cout << endl;

    return;
}

double meanVector(const vector <double> &v) {

    unsigned int i = 0;
    double sum = 0;
    unsigned int size = v.size();
    
    for (i = 0; i < size; ++i) {
        
        sum = sum + v.at(i);
    }
    
    return sum / v.size();
}

double varianceVector(double vectorAvg, const vector <double> &v) {
    
    vector<double> newV;
    unsigned int i = 0;
    newV.resize(v.size());
    double sum = 0;
    unsigned int size = v.size();
    
    for(i = 0; i < size; ++i) {
        
        newV.at(i) = v.at(i) - vectorAvg;
        newV.at(i) = pow(newV.at(i), 2);
        sum = sum + newV.at(i);
    }
    
    return sum / v.size();
}

double standardDeviationForVariance(double vectorVariance) {

    return sqrt(vectorVariance);
}

int main() {
    vector<double> vctrList;
    double avg = 0.0;
    double var = 0.0;
    double stdDev = 0.0;
    unsigned int i = 0;

    fillVector(vctrList);

    cout << "You entered: ";
    for (i = 0; i < vctrList.size(); ++i) {
        
        cout << vctrList.at(i) << " ";
    }
    cout << endl;
    
    avg = meanVector(vctrList);
    
    var = varianceVector(avg, vctrList);
    
    stdDev = standardDeviationForVariance(var);
    
    cout << "The mean is: " << avg << endl;
    cout << "The variance is: " << var << endl;
    cout << "The standard deviation is: " << stdDev << endl;
    
    return 0;
}