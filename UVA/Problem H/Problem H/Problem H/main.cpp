//
//  main.cpp
//  Relational Operator - Problem H
//
//  Created by Francisco on 7/21/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 11172

#include <stdio.h>
#include <iostream>
using namespace std;



void mi_respuesta(void){

    int N;
    
    scanf("%d",&N);
    
    while(N--){
        int num1;
        int num2;
        
        scanf("%d %d",&num1,&num2);
        
        if(num1 < num2){
            printf("%c\n",'<');
        }
        else if(num1 > num2){
            printf("%c\n",'>');
        }
        else{
            printf("%c\n",'=');
        }
 
        
    }
    
    
}

int main()
{

    mi_respuesta();
    
    return 0;
}

