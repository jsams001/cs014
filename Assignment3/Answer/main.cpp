#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Fraction.h"

using namespace std;

void process_file(string, string);
string replaceExtension(string, string);
template<typename T>
ostream& operator<<(ostream&, const vector<T>&);
template<typename T>
void square_sort(vector<T> &);
template<typename T>
void partition(const vector<T>&, vector<int>&);
template<typename T>
void sort_blocks(vector<T>&, const vector<int>&);
template<typename T, typename T_iterator>
void reverse_insertion_sort(T_iterator, T_iterator);
template<typename T, typename T_iterator>
void insertRight(T_iterator, T_iterator);
template<typename T>
void cubic_sort(vector<T>&);
template<typename T>
void updateTarget(vector<T> &, vector<vector<int> > &, vector<int> &,int, int);
template<typename T>
void partition(const vector<T>&, vector<vector<int> >&, vector<int>&);
template<typename T>
void sort_blocks(vector<T>&, const vector<vector<int> > &);
int block_end(const vector<int>&, int, int);
int block_end(const vector<vector<int> >&, int, int, int);

int main(int argc, char** argv){
    string filename = "";
    string outputFilename = "";
    if(argc != 2){
        filename = "";
        cout<<"Enter test cases in the following format:"<<endl<<
        "For each test case, the first row contains a single character, "<<
        "where â€œiâ€ indicates that the next row contains a sequence of integers "<<
        "each separated by a single white space, and â€œfâ€ indicates that the next "<<
        "row contains a sequence of fractions, where pairs of integers represent "<<
        "the numerator and denominator of each fractional value, and all integers "<<
        "are once again separated by a single space."<<endl<<
        "Press ctrl+D (Linux)/ ctrl+Z (Windows) at the end."<<endl;
    }
    else{
        filename = argv[1];
        outputFilename = replaceExtension(filename,".out");
        
    }
    
    process_file(filename,outputFilename);
    return 0;
}

//-----------------------------------------------------------------------------
void process_file(string filename, string outputFilename){
    istream *in;
    ostream *out;
    ostringstream oss;
    
    oss<<"=============Output============="<<endl;
    
    if(filename == ""){
        in = &cin; // Read data from standard input(cin)
        out = &cout; // Write result to standard output (cout)
    }
    else{
        ifstream* inFS = new ifstream (filename.c_str());
        ofstream* outFS = new ofstream(outputFilename.c_str());
        
        if(!inFS->is_open()){
            cout<<"Error opening "<<filename<<endl;
            return;
        }
        if(!outFS->is_open()){
            cout<<"Error opening "<<outputFilename<<endl;
            return;
        }
        in = inFS;
        out = outFS;
    }
    
    string line = "";
    while(getline(*in,line)){
        if(line == "i"){//read integers
            oss<<line<<endl;//write to output string stream
            
            vector<int> v1,v2;
            int num;
            
            getline(*in,line);
            istringstream iss(line);
            
            while(iss>>num){
                v1.push_back(num);
            }
            
            v2 = v1;
            square_sort(v1);
            cubic_sort(v2);
            
            oss<<"Square Sort: "<<v1<<endl; //write sorted vector using overloaded operator<<
            oss<<"Cubic Sort:  "<<v2<<endl; //write sorted vector using overloaded operator<<
        }
        else if(line == "f"){//read fractions
            oss<<line<<endl;//write to output string stream
            
            vector<Fraction> v1,v2;
            int numerator,denominator;
            
            getline(*in,line);
            istringstream iss(line);
            
            while(iss>>numerator>>denominator){
                v1.push_back(Fraction(numerator,denominator));
            }
            
            v2 = v1;
            square_sort(v1);
            cubic_sort(v2);
            
            oss<<"Square Sort: "<<v1<<endl; //write sorted vector to output using overloaded operator<<
            oss<<"Cubic Sort:  "<<v2<<endl; //write sorted vector to output using overloaded operator<<
        }
        else{
            cout<<"Error in file."<<endl;
            return;
        }
    }
    *out<<oss.str(); //write the entire result to output
    out->flush();
    if(filename!=""){
        ((ofstream *)out)->close(); //close ofstream
    }
}

//-----------------------------------------------------------------------------
string replaceExtension(string str, string ext){
    string newStr = str;
    int idx = str.rfind('.', str.length());
    if (idx>0) {
      newStr.replace(idx, ext.length(), "");
    }
    newStr += ext;
    return newStr;
}

//-----------------------------------------------------------------------------
//Overloads operator << so it works for vectors and
//you can cout a vector e.g. cout<<v;
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& rhs){
    if(rhs.empty())
        return out;
        
    out<<rhs.at(0);
    for(int i = 1; i < rhs.size(); ++i)
        out<<", "<<rhs.at(i);
    return out;
}

//-----------------------------------------------------------------------------
template<typename T>
void square_sort(vector<T> &v){
    if(v.empty())
        return;
        
    vector<int> left;

    partition(v,left);
    sort_blocks(v,left);
    
    int curBlock = 0;
    int targetBlock = 0;
    for(int p = 0; p < v.size(); ++p){
        int smallest_pos = left.at(curBlock);
        for(int i = curBlock; i < left.size(); ++i ){
            int index = left.at(i);
            if(v.at(index) < v.at(smallest_pos)){
                smallest_pos = index;
                targetBlock = i;
            }
        } 
        
        if( p != smallest_pos){
            swap(v.at(p),v.at(smallest_pos));
        
            int blockStart = left.at(targetBlock);
            int blockEnd = block_end(left,targetBlock,v.size());//(targetBlock == left.size() - 1 ? v.size(): left.at(targetBlock+1)) - 1;
            
            typename vector<T>::iterator blockStartIter = v.begin();
            advance(blockStartIter, blockStart);
            typename vector<T>::iterator blockEndIter = v.begin();
            advance(blockEndIter, blockEnd);
            insertRight<T>(blockStartIter,blockEndIter);
        }
        
        left.at(curBlock)++; //shrink active block
        if(curBlock + 1 < left.size() && left.at(curBlock) == left.at(curBlock + 1))
        {
            //Block is absorbed completely.
            curBlock++;
        }
    }
}

//-----------------------------------------------------------------------------
template<typename T>
void partition(const vector<T>& v, vector<int>&left){
    int n = v.size();    
    int b = sqrt(n);
    int s = n/b;
    
    int r = n % s; //r is the number of blocks of size s+1
    
    //set block boundaries
    for(int i = 0; i < b; ++i){
        if(i == 0)
            left.push_back(0);
        else if( i <= r)
            left.push_back(left.at(i-1) + s + 1); //block of size s+1
        else
            left.push_back(left.at(i-1) + s); //block of size s
    }
}

//-----------------------------------------------------------------------------
template<typename T>
void sort_blocks(vector<T>& v, const vector<int>& left){
    int b = left.size(); // b is number of blocks
    for(int i = 0; i < b; ++i){
        int blockStart = left.at(i);
        int blockEnd = block_end(left,i,v.size());//(i < b-1? left.at(i+1):v.size()) - 1;
        
        typename vector<T>::iterator blockStartIter = v.begin();
        advance(blockStartIter, blockStart);
        typename vector<T>::iterator blockEndIter = v.begin();
        advance(blockEndIter, blockEnd);
        
        reverse_insertion_sort<T>(blockStartIter, blockEndIter);
    }
}

//-----------------------------------------------------------------------------
template<typename T, typename T_iterator>
void reverse_insertion_sort(T_iterator start, T_iterator end){
    //cout<<"rev last"<<*last<<" "<<*start<<endl;
    for(T_iterator it = end ; it != start; --it){
        insertRight<T>(it,end);
    }
    insertRight<T>(start,end);
}

//-----------------------------------------------------------------------------
template<typename T, typename T_iterator>
void insertRight(T_iterator p, T_iterator l){
    T temp = *p;
    T_iterator j = p;
    ++j;
    ++l;
    while(j != l && *j < temp){
        *p = *j;
        ++p;
        ++j;
    }
    *p = temp;
}

//-----------------------------------------------------------------------------
template<typename T>
void cubic_sort(vector<T> &v){
    if(v.empty())
        return;
    vector<vector< int> > left;
    vector<int> activeBlock;
    
    partition(v,left,activeBlock);
    sort_blocks(v,left);
    
    int curSuperBlock = 0;
    int targetSuperBlock = 0;
    
    for(int p = 0; p < v.size(); ++p){
        //Call updateTarget to have smallest element of the superblock
        //is located at the first element of the superblock
        for(int i = curSuperBlock; i < left.size(); ++i){
            int s = left.at(i).at(activeBlock.at(i));
            updateTarget(v,left,activeBlock,i,s);
        }
        
        //find smallest element
        int smallest_pos = p;
        for(int i = curSuperBlock; i < left.size(); ++i){
            int index = left.at(i).at(activeBlock.at(i));
            if(v.at(index) < v.at(p)){
                smallest_pos = index;
                targetSuperBlock = i;
            }
        }
        
        //swap donor with target
        if(p != smallest_pos){
            swap(v.at(p), v.at(smallest_pos));
            
            int blockStart = left.at(targetSuperBlock).at(activeBlock.at(targetSuperBlock));
            int blockEnd = block_end(left,targetSuperBlock,activeBlock.at(targetSuperBlock),v.size());//(activeBlock.at(targetSuperBlock) < left.at(targetSuperBlock).size() - 1 ? left.at(targetSuperBlock).at(activeBlock.at(targetSuperBlock)+1) :
                       //(targetSuperBlock < left.size() - 1 ? left.at(targetSuperBlock + 1).at(0) : v.size())) - 1;
            
            typename vector<T>::iterator blockStartIter = v.begin();
            advance(blockStartIter, blockStart);
            typename vector<T>::iterator blockEndIter = v.begin();
            advance(blockEndIter, blockEnd);
            
            insertRight<T>(blockStartIter,blockEndIter);
        }
        
        //shrink active block and active superblock
        int curBlock = activeBlock.at(curSuperBlock);
        left.at(curSuperBlock).at(curBlock)++; //shrink active block
        
        if(curBlock + 1 < left.at(curSuperBlock).size() && left.at(curSuperBlock).at(curBlock) == left.at(curSuperBlock).at(curBlock + 1))
        {
            //Block is absorbed completely.
            activeBlock.at(curSuperBlock)++;
        }
        
        if(curSuperBlock + 1 < left.size() && left.at(curSuperBlock).back() == left.at(curSuperBlock + 1).at(0))
        {
            //superBlock is absorbed completely.
            curSuperBlock++;
        }
    }
}

//-----------------------------------------------------------------------------
template<typename T>
void partition(const vector<T>& v, vector<vector<int> >& left, vector<int>& activeBlock){
    int n = v.size();  
    int sb = cbrt(n); //number of super blocks
    int sn = n/sb; //number of elements in super block
    int r = n%sn; //r shows the number of superblocks of size sn+1

    //set left of superblocks
    for(int i = 0; i < sb; ++i){
        vector<int> innerBlockLeft;
        if(i == 0){
            innerBlockLeft.push_back(0);
            left.push_back(innerBlockLeft);
        }
        else if( i <= r){
            innerBlockLeft.push_back(left.at(i-1).at(0) + sn + 1 ); //super block of size sn+1
            left.push_back(innerBlockLeft);
        }else{
            innerBlockLeft.push_back(left.at(i-1).at(0) + sn); //super block of size sn
            left.push_back(innerBlockLeft);
        }
        activeBlock.push_back(0);
    }

    //set left of inner blocks for each superblock 
    for(int i = 0; i < sb; ++i){
        int b = sqrt(sn); //number of inner blocks
        int s = sn/b;
        int rm = sn%s; //rm shows the number of blocks of size s+1
        for(int j = 1; j < b; ++j){
            if(j <= rm){
                int l = left.at(i).at(j-1) + s + 1;
                left.at(i).push_back(l);
            }else{
                int l = left.at(i).at(j-1) + s;
                left.at(i).push_back(l);
            }
        }
    }
}

//-----------------------------------------------------------------------------
template<typename T>
void sort_blocks(vector<T>& v, const vector<vector<int> > &left){
    int sb = left.size(); // sb is the number of superblocks
    //int blockStart, blockEnd;
    for(int i = 0; i < sb; ++i){
        int b = left.at(i).size(); // b is the number of inner blocks for superblock i
        for(int j = 0; j < b; ++j){
            int blockStart = left.at(i).at(j);
            int blockEnd = block_end(left, i, j, v.size());
            
            typename vector<T>::iterator blockStartIter = v.begin();
            advance(blockStartIter, blockStart);
            typename vector<T>::iterator blockEndIter = v.begin();
            advance(blockEndIter, blockEnd);
            
            reverse_insertion_sort<T>(blockStartIter, blockEndIter);
        }
    }
}

//-----------------------------------------------------------------------------
template<typename T>
void updateTarget(vector<T> &v, vector<vector<int> > &left, vector<int> &activeBlock,int superBlock, int p){
    int curBlock = activeBlock.at(superBlock);
    int targetBlock = 0;
    int smallest_pos = left.at(superBlock).at(curBlock);
        for(int i = curBlock; i < left.at(superBlock).size(); ++i ){
            int index = left.at(superBlock).at(i);
            if(v.at(index) < v.at(smallest_pos)){
                smallest_pos = index;
                targetBlock = i;
            }
        }

    if( p != smallest_pos){
        swap(v.at(p),v.at(smallest_pos));
        
        int blockStart = left.at(superBlock).at(targetBlock);
        int blockEnd = block_end(left,superBlock,targetBlock,v.size()); //(targetBlock < left.at(superBlock).size() - 1 ? left.at(superBlock).at(targetBlock+1) :
                       //(superBlock < left.size() - 1 ? left.at(superBlock + 1).at(0) : v.size())) - 1;
        
        typename vector<T>::iterator blockStartIter = v.begin();
        advance(blockStartIter, blockStart);
        typename vector<T>::iterator blockEndIter = v.begin();
        advance(blockEndIter, blockEnd);
        
        insertRight<T>(blockStartIter,blockEndIter);
    }
}

//-----------------------------------------------------------------------------
//returns end of block (square sort version)
int block_end(const vector<int> &left, int blockNo, int vectorSize){
    if(blockNo >= left.size()){//invalid blockNo
        return vectorSize;
    }
    if(blockNo < left.size() - 1){
        return left.at(blockNo + 1) - 1;
    }
    else{//last block
        return vectorSize - 1;
    }
}

//-----------------------------------------------------------------------------
//returns end of block (cubic sort version)
int block_end(const vector<vector<int> >& left, int superBlockNo, int blockNo, int vectorSize){
    if(superBlockNo >= left.size())//invalid blockNo
            return vectorSize;
    if(blockNo < left.at(superBlockNo).size() - 1){//block is not the last block of the superblock
        return left.at(superBlockNo).at(blockNo + 1) - 1;
    }
    else if(superBlockNo < left.size() - 1){
        return left.at(superBlockNo + 1).at(0) - 1;
    }
    else{//last block of last superblock
        return vectorSize - 1;
    }
}