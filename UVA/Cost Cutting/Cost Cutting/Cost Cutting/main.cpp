//
//  main.cpp
//  Cost Cutting
//
//  Created by Francisco on 7/21/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 11727

#include <stdio.h>
#include <iostream>
using namespace std;



void mi_respuesta(void){
    
    int N;
    
    scanf("%d",&N);
    
    for (int i = 1; i <= N; i++){
        int num1;
        int num2;
        int num3;
        
        scanf("%d %d %d", &num1, &num2, &num3);
        
        if(num1 < num2){
            if (num2 < num3){
                printf("Case %d: %d\n",i,num2);
            }
            else{
                if(num3 < num1){
                    printf("Case %d: %d\n",i,num1);
                }
                else{
                    printf("Case %d: %d\n",i,num3);
                }
            }
        }
        else{
            if (num1 < num3){
                printf("Case %d: %d\n",i,num1);
            }
            else{
                if(num2 < num3){
                    printf("Case %d: %d\n",i,num3);
                }
                else{
                    printf("Case %d: %d\n",i,num2);
                }
            }
        }
    }
    
}

int main()
{
    
    mi_respuesta();
    
    return 0;
}

