//
//  main.cpp
//  Division of Nlogonia
//
//  Created by Francisco on 7/21/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 11498

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

string calcular_cuadrante(int divx, int divy, int coordx, int coordy){

    if( (divx == coordx) || (divy == coordy) ){
        return "divisa";
    }
    else{
        
        if(coordx < divx){
            
            if(coordy < divy){
                return "SO";
            }
            else{
                return "NO";
            }
            
        }
        else{
            
            if(coordy < divy){
                return "SE";
            }
            else{
                return "NE";
            }
            
        }
        
    }
    return "";
}

void mi_respuesta(void){
    
    int N;
    
    while(scanf("%d",&N)){
        
        if (N == 0) break;
        
        int divx;
        int divy;
        
        scanf("%d %d", &divx, &divy);
        
        while(N--){
            int coordx;
            int coordy;
            
            scanf("%d %d",&coordx,&coordy);
            
            string rpta = calcular_cuadrante(divx, divy, coordx, coordy);
            
            cout << rpta << "\n";
            
        }
        
        
    }
    

    
}

int main()
{
    
    mi_respuesta();
    
    return 0;
}

