//
//  main.cpp
//  Major Scales
//
//  Created by Francisco on 7/25/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 10528

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>


using namespace std;

int N_tonalidades = 12;
int cant_notas_escala = 7;

bool pertenece(int lista[], int num){
    
    for(int i = 0; i < cant_notas_escala; i++){
        if(lista[i] == num) return true;
    }
    
    return false;
}

int main(int argc, const char * argv[])
{

    
    map<string,int> numeros_notas;
    numeros_notas["C"] = 1;
    numeros_notas["C#"] = 2;
    numeros_notas["D"] = 3;
    numeros_notas["D#"] = 4;
    numeros_notas["E"] = 5;
    numeros_notas["F"] = 6;
    numeros_notas["F#"] = 7;
    numeros_notas["G"] = 8;
    numeros_notas["G#"] = 9;
    numeros_notas["A"] = 10;
    numeros_notas["A#"] = 11;
    numeros_notas["B"] = 12;
    
    string posibles_tonalidades[13];
    posibles_tonalidades[1] = "C";
    posibles_tonalidades[2] = "C#";
    posibles_tonalidades[3] = "D";
    posibles_tonalidades[4] = "D#";
    posibles_tonalidades[5] = "E";
    posibles_tonalidades[6] = "F";
    posibles_tonalidades[7] = "F#";
    posibles_tonalidades[8] = "G";
    posibles_tonalidades[9] = "G#";
    posibles_tonalidades[10] = "A";
    posibles_tonalidades[11] = "A#";
    posibles_tonalidades[12] = "B";

    int escala_mayor[7] = {0,2,4,5,7,9,11};
    
    string s;
    
    while (getline(cin,s)){
        
        if (s == "END") break;
                
        stringstream ss(s);
        char nota_leida[3];
        
        vector<string> notas;
        
        while(ss >> nota_leida){
            // Recorro nota por nota de la linea
            
            notas.push_back(nota_leida);
        }
        
        bool inicio = true;
        
        for(int i = 1; i <= N_tonalidades; i++){
            
            int root = i;
            
            bool tonalidad_valida = true;
            
            for(vector<string>::iterator it = notas.begin(); it != notas.end(); it++){
                int valor_nota_actual = numeros_notas[*it];
                
                if (valor_nota_actual < root) valor_nota_actual += 12;
                    
                if(pertenece(escala_mayor,valor_nota_actual-root)){
                    continue;
                }
                else{
                    tonalidad_valida = false;
                    break;
                }
                
            }
            
            if(tonalidad_valida){
                
                if(inicio){
                    cout << posibles_tonalidades[root];
                    inicio = false;
                }
                else{

                    cout << " " << posibles_tonalidades[root];
                }
                
            }
            
        }
            
        
        
        cout << "\n";
    }
    
    return 0;
}

    
