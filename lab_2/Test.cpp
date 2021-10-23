//#include "lab2.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <cassert>
#include "lab2.h"
//#include "Tests.h"
using namespace std;




int main(){
//    testall();
    cout << "Queue" << endl;
    Queue<int, LinkedList<int>> Test;
    Test.push(1);
    Test.push(2);
    Test.push(3);
    Test.push(4);
    Test.setIndex(0,5);
    cout << Test.pop() << endl;
    cout << Test.pop() << endl;
    cout << Test.pop() << endl;
    cout << Test.pop() << endl;
    Stack<int, LinkedList<int>> Test2;
    cout << "Stack" << endl;
    Test2.push(1);
    Test2.push(2);
    Test2.push(3);
    Test2.push(4);
    Test2.setIndex(0,5);
    cout << Test2.pop() << endl;
    cout << Test2.pop() << endl;
    cout << Test2.pop() << endl;
    cout << Test2.pop() << endl;
//    DynamicArray<int> A;
//    A.append(1);
//    A.append(2);
//    A.append(3);
//    DynamicArray<DynamicArray<int>> Test;
//    Test.appendClass(A);
//    cout<< Test.getFirst().getFirst() <<endl;
//
//    mainMenu();

}

