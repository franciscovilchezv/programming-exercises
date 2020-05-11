//
//  main.cpp
//  ID Codes
//
//  Created by Francisco on 7/31/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 146

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string line;
    
    while (getline(cin,line)){
        if(line == "#") break;
        
        if (next_permutation(line.begin(), line.end())){
            cout << line << "\n";
        }
        else{
            cout << "No Successor\n";
        }
    }
    
    return 0;
}

