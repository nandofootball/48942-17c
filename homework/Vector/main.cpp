/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 19, 2015, 3:30 PM
 */

#include <cstdlib>
#include <iostream>
#include "Simplevector.h"
using namespace std;

int main(int argc, char** argv) {
    SimpleVector<int> vec(5);
//    cout << vec[0] << endl;;
    for(int i=0;i<5;i++){
        vec.push(i);
    }
//    vec.push(4);
//    vec.push(5);
//    vec.pull();
//    vec.push(10);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}

