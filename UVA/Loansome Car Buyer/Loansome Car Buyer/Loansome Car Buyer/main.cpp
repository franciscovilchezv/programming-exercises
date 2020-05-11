//
//  main.cpp
//  Loansome Car Buyer
//
//  Created by Francisco on 7/21/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 10114

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


void mi_respuesta(void){
    
    int meses;
    double deposito;
    double precio_del_carro;
    int cant_lineas;
    
    while(scanf("%d %lf %lf %d",&meses,&deposito,&precio_del_carro,&cant_lineas)){
        
        if(meses < 0) break;
        
        double prestamo_restante = precio_del_carro;
        double valor_del_carro = precio_del_carro + deposito;
        
        double pago_mensual = precio_del_carro / meses;
        
  //      printf("%lf %lf\n",valor_del_carro,prestamo_restante);
        
        //Lecturas que no se debieron realizar guardan aca los valores leidos
        int mes_arrastrado = -1;
        double depreciacion_arrastrada = 0;
        
        int mes_ant = 0;
        double depreciacion_ant = 0;
        
        int i = 0;
        int m = 0;
        
        int mes = 0;
        double depreciacion = 0;
        
        int terminar = 0;
        
        while ( true ){
            
            //Inicio lectura de datos
            if((mes_arrastrado == -1) && (m < cant_lineas)){
            
                string decimal_string;
                string devaluar_string;

                cin >> mes;
                cin >> decimal_string;
            
                devaluar_string = "0" + decimal_string;
                char temp[255];
                strcpy(temp, devaluar_string.c_str());
                depreciacion = atof(temp);
                
                m++;
            }
            else{
                if(i == mes_arrastrado){
                    mes = mes_arrastrado;
                    depreciacion = depreciacion_arrastrada;
                    mes_arrastrado = -1;
                    depreciacion_arrastrada = 0;
                }
                else{
                    
                }
            }
            //Fin lectura de datos
            
            //Variables finales
            //mes: Mes de la depreciacion
            //depreciacion: Depreciacion del mes
            
            double cant_depreciar;
            
            
            if(i == mes){
                cant_depreciar = valor_del_carro * depreciacion;
                
            }
            else{
                
                if(mes_arrastrado == -1){
                    mes_arrastrado = mes;
                    depreciacion_arrastrada = depreciacion;
                }
                
                mes = mes_ant + 1;
                depreciacion = depreciacion_ant;
                
                cant_depreciar = valor_del_carro * depreciacion;
                
            }
            
            mes_ant = mes;
            depreciacion_ant = depreciacion;
            
            
            valor_del_carro = valor_del_carro - cant_depreciar;
            
            if(mes != 0){
                prestamo_restante = prestamo_restante - pago_mensual;
            }
            
            //cout << mes << " " << depreciacion << "\n";
//            printf("%lf %lf\n",valor_del_carro,prestamo_restante);
            

            if((prestamo_restante < valor_del_carro) && (terminar == 0)){
                if(mes == 1){
                    printf("%d month\n",mes);
                }
                else{
                    printf("%d months\n",mes);
                }
                terminar = 1;
                if(i >= cant_lineas){
                    break;
                }
            }
            else if(i >= cant_lineas){
                if(terminar == 1){
                    break;
                }
                /*else{
                    mes_arrastrado = mes + 1;
                    depreciacion_arrastrada = depreciacion;
            
                    printf("Lineas %d %d\n",i,cant_lineas);
                }*/
            }
            
            
            i++;
            
        }
        
    }
    
    
}

int main()
{
    
    mi_respuesta();
    
    return 0;
}
