//
//  main.cpp
//  Ultra-QuickSort
//
//  Created by Francisco on 8/13/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 10810

#include <iostream>
#include <stdio.h>
#include <vector>

#define size            500002
#define maximoentero    1000000000

using namespace std;

long numeros[size];
long numswaps;
long izquierda[size];
long derecha[size];


void merge(long ini, long med, long fin){
    
    long i;
    long j;
    
    //Guardo valores en la izquierda
    long ind1;
    for(i = ini, ind1 = 1; i <= med; i++){
        //izquierda[ind1++] = numeros[i]; //Primero graba el valor en ind1, y luego aumenta ind1
        izquierda[ind1] = numeros[i];
        ind1++;
    }
    izquierda[ind1] = maximoentero;
    
    //Guardo valores en la derecha
    long ind2;
    for(j = med + 1, ind2 = 1; j <= fin; j++){
        derecha[ind2] = numeros[j];
        ind2++;
    }
    derecha[ind2] = maximoentero;
    
    i = 1;
    j = 1;
    long k;
    
    for(k = ini; k <= fin; k++){
        if(izquierda[i] > derecha[j]){
            numswaps += ind1 - i;
            numeros[k] = derecha[j];
            j++;
        }
        else{
            numeros[k] = izquierda[i];
            i++;
        }
    }
}

void mergesort(long inicio, long fin){
    
    if(inicio < fin){
        
        long medio;
        medio = (inicio + fin) / 2;
        
        mergesort(inicio,medio);
        mergesort(medio + 1, fin);
        
        merge(inicio,medio,fin);
        
    }
    
}

int main()
{
    
    long cant;
    
    while(true){
        
        scanf("%ld",&cant);
        if(cant == 0) break;
    
        for(long i = 1; i <= cant; i++){

            scanf("%ld",&numeros[i]);
            
            //cout << numeros[i] << " ";
        }
        //cout << endl;
        
        numswaps = 0;
        
        mergesort(1,cant);
        
        //cout << "# Swaps: " << numswaps << endl;
        
        //for(int i = 1; i <= cant; i++){
        //    cout << numeros[i] << " ";
        //}
        //cout << endl;
        
        printf("%ld\n",numswaps);
    }

    return 0;
}

