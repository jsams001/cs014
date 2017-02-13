#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    
    srand(time(0));
    
    int i = 0;
    int j = 0;
    int count = 0;
    
    while (i <= 1000){
        
        j = rand() % ((8 - 5) + 1) + 5;
        i += j;
        cout << i << endl;
        ++count;
    }
    
    cout << "It took " << count << " rolls to get to 1000." << endl;
    
    return 0;
}

/* TEACHER'S METHOD 

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    
    srand(time(0));
    
    //continue generating a pseudorandom int between 5 and 8
    //count how many rolls it takes to reach a score >= 1000.
    int score = 0;
    int rolls = 0;
    
   do {
        score += rand() % 4 + 5;
        ++rolls;
        cout << score << endl;
    }  while (i <= 1000);
    cout << rolls << endl;

    return 0;
}
