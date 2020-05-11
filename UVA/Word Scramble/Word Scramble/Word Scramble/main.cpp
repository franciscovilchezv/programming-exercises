//
//  main.cpp
//  Word Scramble
//
//  Created by Francisco on 7/25/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 483

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{

    string s;
    
    while (getline(cin, s)){
        stringstream ss(s);
        
        string temp;
        bool imprimir_linea = false;
        
        while (ss >> temp){
            
            if(imprimir_linea){
                cout << " ";
            }
            else{
                imprimir_linea = true;
            }
            
            reverse(temp.begin(),temp.end());
            cout << temp;
        }
        
        cout << "\n";
    }
    
    
    
    return 0;
}

