#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

#include "Deck.h"

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &out, const vector<Card> &rhs);

/* ***********
   One created function; calculates probability using the Monte Carlo
   method.
   ***********
*/
double monteCarlo(int ncards, int ndeals);

int main() {
   
   srand(2222);
   
   string input;
   string outfile;
   ofstream newfile;
   int ncards = 0;
   int ndeals = 0;
   int pairs = 0;
   Deck hand;
   
   vector<Card> theHand;
   
   cout << "Do you want to output all hands to a file?(Yes/No) " << endl;
   cin >> input;
   if(input == "Yes") {
      
      cout << "Enter name of output file: " << endl;
      cin >> outfile;
   
      newfile.open(outfile.c_str());
      if (!newfile.is_open()) {
         cout << "Could not open file " << outfile << endl;
         return 1;
      }
      
   }
   
   cout << "Enter number of cards per hand: " << endl;
   cin >> ncards;
   
   cout << "Enter number of deals (simulations): " << endl;
   cin >> ndeals;
   
   for(int i = 0; i < ndeals; ++i) {
      hand.shuffleDeck();
      theHand.clear();
      for(int j = 0; j < ncards; ++j)
         theHand.push_back(hand.dealCard());
      
      if(hasPair(theHand)) {
         ++pairs;
         newfile << "Found Pair!! ";
      }
      else
         newfile << "             ";
         
      if (input == "Yes") 
         newfile << theHand << endl;
   }
   
   cout << "Chances of receiving a pair in a hand of " << ncards << " cards is: " << monteCarlo(pairs, ndeals) << "%" << endl;
   
   newfile.close();
   
   return 0;
}

bool hasPair(const vector<Card> &theHand) {
   
   int chance = 0;
   
   for(unsigned int i = 0; i < theHand.size(); ++i) {
      
      chance = theHand.at(i).getRank();
      for(unsigned int j = i + 1; j < theHand.size(); ++j)
         if(chance == theHand.at(j).getRank())
            return true;
   }
   
   return false;
}

ostream & operator<<(ostream &out, const vector<Card> &theHand) {
   
   for(unsigned int i = 0; i + 1 < theHand.size(); ++i)
      out << theHand.at(i) << ", ";
   
   out << theHand.at(theHand.size() - 1);
   
   return out;
}

double monteCarlo(int pairs, int ndeals) {
   
   return 100.0 * (static_cast<double>(pairs) / ndeals);
}