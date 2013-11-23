//
//  MyClass.cpp
//  Sample
//
//  Created by Ravi Desai on 11/23/13.
//  Copyright (c) 2013 Ravi Desai. All rights reserved.
//

#include "MyClass.h"
#include <iostream>
using namespace std;

MyClass::MyClass() {
    x = 10;
}

void MyClass::print() {
    cout << x << endl;
}