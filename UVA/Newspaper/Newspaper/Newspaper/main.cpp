//
//  main.cpp
//  Newspaper
//
//  Created by Francisco on 7/31/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 11340

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    int cantidad_articulos;
    
    scanf("%d",&cantidad_articulos);
    
    while (cantidad_articulos--) {

        string buff;
        int lineas_valores_letras;
        
        scanf("%d",&lineas_valores_letras);
        
        map <char,double> ganancias;
        
        while(lineas_valores_letras--){
            
            getline(cin,buff);            //Me como el salto de linea
            
            char letra;
            double precio_letra; //en centimos
            
            scanf("%c",&letra);
            scanf("%lf",&precio_letra);

            precio_letra /= 100;
            ganancias[letra] = precio_letra;
            
            //printf("Registrado: %c %lf\n",letra,precio_letra);
        }
        
        int lineas_articulo;
        scanf("%d",&lineas_articulo);
        
        getline(cin,buff); //Me como el salto de linea
        
        double pago = 0.0;
        
        while(lineas_articulo--){
            
            string linea;
            
            getline(cin,linea);
            
            stringstream ss(linea);
            
            char c;
            
            while(ss >> c){
                pago += ganancias[c];
                //printf("Caracter: %c -> %.2lf\n",c,pago);
            }
            
        }
        
        printf("%.2lf$\n",pago);
        
    }
    
    return 0;
}

