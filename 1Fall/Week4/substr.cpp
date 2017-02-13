#include <iostream>
#include <string>
using namespace std;

int main () {
    
    //cout << endl;
    
    string sentence;
    cout << "Enter a sentence:\n";
    getline(cin, sentence);
    
    int posSpace = sentence.find(' ');
    string word1 = sentence.substr(0, posSpace);
    cout << word1 << endl;
    
    int posSpace2 = sentence.find(' ', posSpace+1);
    string word2 = sentence.substr(posSpace+1, posSpace2 - posSpace - 1);
    cout << word2 << endl;
    
    return 0;
    
}