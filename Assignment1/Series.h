#ifndef SERIES_H
#define SERIES_H

#include <iostream>
using namespace std;

class Series {
    private: 
        int k;
        double weights[];
        double current[1000];
        int biggest_known;
    public:
        Series();
        void set_k(int input);
        void set_weights(double mainweights[]);
        void set_initial(double maininitial[]);
        void set_val(int n);
};

#endif