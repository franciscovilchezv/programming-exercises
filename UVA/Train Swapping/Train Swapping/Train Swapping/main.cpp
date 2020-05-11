//
//  main.cpp
//  Train Swapping
//
//  Created by Francisco on 8/4/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 299

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{

    int N;
    
    scanf("%d",&N);
    
    while(N--){
        int L;
        
        scanf("%d",&L);
        
        vector <int> carriages;
        
        while(L--){
            
            int aux;
            scanf("%d",&aux);
            
            carriages.push_back(aux);
            
        }
        
        int num_swaps = 0;
        
        for(int i = 0; i < carriages.size(); i++){
            
            for(int j = i + 1; j < carriages.size(); j++){
                if(carriages[j] < carriages[i]){
                    int temp = carriages[i];
                    carriages[i] = carriages[j];
                    carriages[j] = temp;
                    num_swaps++;
                }
            }
            
        }
        
        printf("Optimal train swapping takes %d swaps.\n",num_swaps);
        
    }
    
    return 0;
}

