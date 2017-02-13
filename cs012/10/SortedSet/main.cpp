#include "SortedSet.h"

int main() {
    
    // SortedSet list1;
    // //cout << "List1: Add a 10 " << endl;
    // list1.add(90);
    // //list1.display();
    // //cout << "List1: Add a 20 " << endl;
    // list1.add(10);
    // //list1.display();
    // //cout << "List1: Add a 90 " << endl;
    // list1.add(20);
    // //list1.display();
    // //ADD SEEMS TO WORK
    
    // SortedSet list2;
    // //cout << "List2: Add a 20 " << endl;
    // list2.add(20);
    // //list2.display();
    // //cout << "List2: Add a 40 " << endl;
    // list2.add(40);
    // //list2.display();
    // //cout << "List2: Add a 10" << endl;
    // list2.add(10);
    // //list2.display();
    // //cout << "List2: Try and add another 10" << endl;
    // //list2.display();
    // //ADD SEEMS TO WORK
    
    // //cout << "Union (|) test" << endl;
    // //SortedSet list3;
    // //list3 = list1 | list2;
    // //cout << "List3: Expect 10 20 40 90" << endl;
    // //list3.display();
    // //UNION SEEMS TO WORK - NOW IT WORKS
    
    // cout << "List1 display " << endl;
    // list1.display();
    // cout << "List2 display " << endl;
    // list2.display();
    
    // cout << "Intersection (&) test " << endl;
    // SortedSet list4;
    // list4 = list1 & list2;
    // cout << "List4: Expect 10 20 " << endl;
    // list4.display();
    // //NOT DONE; FIX THIS LATER
    
    SortedSet list1;
    SortedSet list2;
    
    // list1.add(10);
    // list1.add(30);
    // list1.add(40);
    // list1.add(50);
    // list1.add(90);
    
    // list2.add(10);
    // list2.add(30);
    // list2.add(50);
    // list2.add(60);
    // list2.add(70);
    
    // cout << "List1: ";
    // list1.display(); 
    // cout << "List2: ";
    // list2.display();
    
    // SortedSet list3;
    
    // list3 = list1 & list2;
    // // cout << endl << "Expect: 10 30 50 " << endl << "List3: ";
    // list3.display();
    //INTERSECTION NOW WORKS
    
    SortedSet list4;
    
    list4.add(10);
    list4.add(50);
    //cout << endl << "Expect: 10 50 " << endl << "List4: ";
    list4.display();
    
    SortedSet list5;
    list4 &= list5;
    list4.display();
    
    return 0;
}