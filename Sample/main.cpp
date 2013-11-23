//
//  main.cpp
//  Sample
//
//  Created by Ravi Desai on 11/23/13.
//  Copyright (c) 2013 Ravi Desai. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "MyClass.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    MyClass mc;
    cout << "Hello, World! ";
    mc.print();

    string msg;
    cin >> msg;
    
    cout << "from stdin: " << msg << endl;
    
    return 0;
}

