#include <sstream>
#include <fstream>

#include "UBTree.h"
#include "AVLTree.h"
#include "HyperTree.h"

int main(int argc, char* argv[]) {
    
    ifstream infile;
    string readfile;
    
    double input;
    UBTree<double> ub;
    AVLTree<double> avl;
    HyperTree<double> hyp;
    

    //IF NO OPTIONAL FILENAME IS PRESENT, THE STANDARD INPUT WILL RUN
    if(argc != 2) {
        
        cout << "No filename present. Exiting. " << endl;
        return 0;
        
    }
    
    //FILENAME PRESENT, RUNNING FROM FILE ARGUMENT GIVEN
    else {
        
        readfile = argv[1];
        infile.open(readfile.c_str());
        
        if(!infile.is_open()) {
            cout << "Error: Could not open file. " << endl;
            return 1;
        }
        
        int idx = readfile.rfind('.', readfile.length());
        if (idx > 0)
          readfile.replace(idx, 4, ".out");
          
        outfile.open(readfile.c_str());
        if(!outfile.is_open()) {
            cout << "Error: Could not open file" << endl;
            return 1;
        }
        
        string line;
        int testcase = 1;
        
        while(!infile.eof()) {
            getline(infile, line);
            istringstream line2(line);
            while(line2 >> input) {
                ub.insert(input);
                avl.insert(input);
            }
            outfile << "TEST CASE: " << testcase << endl;
            ub.prettyPrint();
            outfile << endl;
            avl.prettyPrint();
            outfile << endl;
            
            ub.makeEmpty();
            avl.makeEmpty();
            ++testcase;
        }
        infile.close();
        outfile.close();
        
    }
    
    return 0;
}