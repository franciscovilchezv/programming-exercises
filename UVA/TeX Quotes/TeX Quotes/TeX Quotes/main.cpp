//
//  main.cpp
//  TeX Quotes
//
//  Created by Francisco on 7/25/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 272

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[])
{
    char c;
    bool inicio = true;
    
    while(scanf("%c",&c) != EOF){
        
        if (c == '"'){
            if (inicio){
                printf("%s","``");
                inicio = false;
            }
            else{
                printf("%s","''");
                inicio = true;
            }
            
        }
        else{
            printf("%c",c);
        }
        
    }

    return 0;
}

