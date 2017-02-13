#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
   
using namespace std;

int readData(string filename, vector<double>& angle, vector<double>& lift) {
   
   ifstream opening;
   double value;
   double value2;
   
   opening.open(filename.c_str());
   if(!opening.is_open()) {
      
      cout << "Error opening " << filename << endl;
      exit(EXIT_FAILURE);
   }
   
   while(opening >> value) {
        angle.push_back(value);
        
        opening >> value2;
        lift.push_back(value2);
         
    }
   
   opening.close();
   
   return 0;
}

bool isOrdered(const vector<double>& angle) {
   
   if(!angle.empty()) {
      for(unsigned int i = 0; i + 1 < angle.size(); ++i) {
      
         if(angle.at(i) > angle.at(i + 1))
         
            return false;
      }
   }
   
   return true;
}

void reorder(vector<double>& angle, vector<double>& lift) {
   
   double temp = 0;
   
   for(unsigned int i = 0; i + 1 < angle.size(); ++i) {
      for(unsigned int j = ; j + 1 < angle.size(); ++j) {
         if(angle.at(j) > angle.at(j + 1)) {
         
            temp = angle.at(j);
            angle.at(j) = angle.at(j + 1);
            angle.at(j + 1) = temp;
         
            temp = lift.at(j);
            lift.at(j) = lift.at(j + 1);
            lift.at(j + 1) = temp;
         }
      }
   }
   
   return;
}

double interpolation(double input, const vector<double>& angle, const vector<double>& lift) {
   
   for(unsigned int i = 0; i < angle.size(); ++i) {
      
      if(angle.at(i) == input)
         return lift.at(i);   
}
   
   for(unsigned int i = 0; i < angle.size(); ++i) {
      
      if(input > angle.at(i)) {
         return lift.at(i) + (input - angle.at(i))/(angle.at(i + 1) - angle.at(i)) * (lift.at(i + 1) - lift.at(i));
      }
   }
   
   return 0;
}

int main() {
   
   string filename;
   double input;
   double coe = 0;
   bool check = true;
   vector<double> angle;
   vector<double> lift;
   
   cout << "Enter name of input data file:" << endl << endl;
   cin >> filename;
   
   readData(filename, angle, lift);
   
   if(angle.empty()) {
      while(angle.empty() || (angle.size() != lift.size())) {
         cout << "Please enter another file " << endl;
         cin >> filename;
         readData(filename, angle, lift);
      }
   }
   
   while(!(isOrdered(angle))) {
      reorder(angle, lift);
   }
   
   while(check) {
      
      cout << "Flight path angle? (Press 99 to exit) " << endl;
      cin >> input;
      
      if (input == 99) 
         check = false;
      else if (input < angle.at(0) || input > angle.back()) {
         cout << "Please enter a value in range." << endl;
      }
      else {
         coe = interpolation(input, angle, lift);
         cout << "Coefficient of lift for " << input << " is: " << coe << endl;
      }
      
   }
      
   return 0;
   
}