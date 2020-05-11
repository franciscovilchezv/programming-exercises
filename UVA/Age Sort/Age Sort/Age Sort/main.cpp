//
//  main.cpp
//  Age Sort
//
//  Created by Francisco on 8/23/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    
    while(true){
 
        int cant;
        
        scanf("%d",&cant);
        
        if(cant == 0) break;

        vector<int> numeros;
        
        int max = 0;
        int min = 2147483647;
        
        for(int i = 0; i < cant; i++){
            int temp;
            scanf("%d",&temp);
            numeros.push_back(temp);
            
            if (numeros[i] < min){
                min = numeros[i];
            }
            else if(numeros[i] > max){
                max = numeros[i];
            }
    
            //cout << numeros[i] << " ";
        }
        
        //cout << endl;
        
        //cout << min << endl;
        //cout << max << endl;
        //cout << endl;
        
        int cantidades[max - min + 1];
        
        for(int i = 0; i < (max - min + 1); i++){
            cantidades[i] = 0;
        }
        
        for(int i = 0; i < cant; i++){
            cantidades[numeros[i] - min] = cantidades[numeros[i] - min] + 1;
        }
        
        
        int z = 0;
        for (int i = min; i <= max;i++){
            while(cantidades[i - min] > 0){
                numeros[z] = i;
                z++;
                cantidades[i-min] = cantidades[i-min] - 1;
            }
        }
        
        for(int i = 0; i < cant; i++){
            if (i != cant - 1){
                printf("%d ",numeros[i]);
            }
            else{
                printf("%d\n",numeros[i]);
            }
        }
        
        /*
        for(int i = 0; i < cant_distintos; i++){
            cout << i << ") " << cantidades[i] << endl;
        }
        cout << endl;
        */
    }
    
    return 0;
}

