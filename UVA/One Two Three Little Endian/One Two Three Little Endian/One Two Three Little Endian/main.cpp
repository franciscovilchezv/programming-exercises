//
//  main.cpp
//  One Two Three Little Endian
//
//  Created by Francisco on 7/30/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 594

#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{

    int num;
    
    while(scanf("%d",&num) != EOF){
        
        bool negativo = (num < 0);
        
        stringstream aux;
        string numero;
        
        aux << hex << num;
        
        numero = aux.str();
        
        string::size_type longitud = numero.size();
        
        stringstream num_hexa;
        while(longitud < 8){
            if( negativo)
                num_hexa << "f";
            else
                num_hexa << "0";
            
            longitud++;
        }
        num_hexa << aux.str();
        
        //Invertir el num_hexa (leer como little endian
        
        numero = num_hexa.str();
        
        stringstream nn;
        
        for(int i = longitud - 2 + 1; i >= 0; i -= 2){
            nn << numero[i-1] << numero[i];
        }
        
        //cout << num_hexa.str() << " " << longitud << "\n";
        
        stringstream num_invertido;
        num_invertido << hex << nn.str();
        
        unsigned int numero_convertido;
        num_invertido >> numero_convertido;

        printf("%d converts to %d\n",num, numero_convertido);
        
        //cout << num_invertido.str() << " " << longitud << "\n";
        
        
        
        
    }
    
    
    
    return 0;
}

