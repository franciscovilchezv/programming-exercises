//
//  main.cpp
//  Horror Dash
//
//  Created by Francisco on 7/24/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 11799

#include <stdio.h>
#include <iostream>
using namespace std;


void mi_respuesta(void){
    
    int T;
    
    scanf("%d",&T);
    
    for(int i = 1; i <= T; i++){
        int N;
        
        scanf("%d",&N);
        
        int max = 0;
        while(N--){
            int num;
            scanf("%d",&num);
            
            if( num > max) max = num;
                
        }
        
        printf("Case %d: %d\n",i,max);
        
    }
    
}

int main()
{
    
    mi_respuesta();
    
    return 0;
}

