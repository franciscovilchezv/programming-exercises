//
//  main.cpp
//  DNA Sorting
//
//  Created by Francisco on 8/5/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 612

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

struct Chains{
    string cad;
    int measure;
};

bool compareRecords(const Chains &a,const Chains &b){
    
    if(a.measure < b.measure) return true;
    
    return false;
}



int main()
{
    
    string buff;
    
    int N;
    
    scanf("%d",&N);
    
    while (N--){
        
        int cant_digitos;
        int cant_lineas;
        
        scanf("%d %d",&cant_digitos,&cant_lineas);
        getline(cin,buff);
        
        vector<Chains> cadenas;
        
        while(cant_lineas--){

            Chains temp;

            getline(cin,temp.cad);
            temp.measure = 0;
            
            //cout << temp.cad.size() << " -> " << temp.cad[0] << " -> ";
            
            for(int i = 0; i < temp.cad.size(); i++){
                for(int j = i+1; j < temp.cad.size(); j++){
                    
                    if(temp.cad[i] > temp.cad[j]){
                        temp.measure++;
                    }
                    
                }
            }
            
            cadenas.push_back(temp);
            
            //cout << temp.cad << " -> " << temp.measure << "\n";
        }
        
        stable_sort(cadenas.begin(), cadenas.end(), &compareRecords);
        
        for(int i = 0; i < cadenas.size(); i++){

            Chains temp = cadenas[i];
            //cout << temp.cad.size() << " -> " << temp.cad[0] << " -> ";
            //cout << temp.cad << " -> " << temp.measure << "\n";
            cout << temp.cad << "\n";
        }
        
        if (N > 0) cout << "\n";
    }

    return 0;
}

