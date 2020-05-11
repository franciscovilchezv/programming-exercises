//
//  main.cpp
//  Event Planning
//
//  Created by Francisco on 7/22/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 11559

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void mi_respuesta(void){
    
    int participantes;
    int presupuesto;
    int num_hoteles;
    int num_semanas;
    
    while(scanf("%d %d %d %d",&participantes,&presupuesto,&num_hoteles,&num_semanas) != EOF){
        
        int costo_minimo = 2147483647;
        
        for(int i = 0; i < num_hoteles; i++){
            
            int precio;
            
            scanf("%d",&precio);
            
            for(int j = 0; j < num_semanas; j++){
                int camas_disponibles;
                scanf("%d",&camas_disponibles);
                
                if(camas_disponibles >= participantes){
                    int costo = participantes * precio;
                    
                    if((costo < costo_minimo) && (costo < presupuesto)){
                        costo_minimo = costo;
                    }
                }
            }
            
        }
        
        if( costo_minimo == 2147483647){
            printf("%s\n","stay home");
        }
        else{
            printf("%d\n",costo_minimo);
        }
        
    }
    
}

int main()
{
    
    mi_respuesta();
    
    return 0;
}

