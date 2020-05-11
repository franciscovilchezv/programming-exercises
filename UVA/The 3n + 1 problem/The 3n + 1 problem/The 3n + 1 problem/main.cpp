//
//  main.cpp
//  The 3n + 1 problem
//
//  Created by Francisco on 7/24/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 100


#include <stdio.h>
#include <iostream>
using namespace std;



void mi_respuesta(void){
  
    int i,j;
    while (scanf("%d %d",&i,&j) != EOF){
        
        int cycle_length_max = 0;
        int temp_i = i;
        int temp_j = j;
        
        if(i > j){
            swap(i,j);
        }
        
        while(i <= j){
            
            int n = i;
            
            //Algoritmo
            int cycle_length = 1;
            
            while(n != 1) {
                
                if(n % 2 == 1){
                    n = 3 * n + 1;
                    n /= 2;
                    cycle_length += 2;
                }
                else{
                    n /= 2;
                    cycle_length++;
                }
                
            
            }
            
            if(cycle_length > cycle_length_max){
                cycle_length_max = cycle_length;
                
            }
            
            i++;
            
        }
        
        printf("%d %d %d\n",temp_i,temp_j,cycle_length_max);
        
    }
    
}

int main()
{
    
    mi_respuesta();
    
    return 0;
}


