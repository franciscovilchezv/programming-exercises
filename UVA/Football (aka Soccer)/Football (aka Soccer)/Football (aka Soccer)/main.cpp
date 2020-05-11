//  C++11
//  main.cpp
//  Football (aka Soccer)
//
//  Created by Francisco on 8/3/14.
//  Copyright (c) 2014 Apple. All rights reserved.
//  UVA: 10194

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

//Compile with C++11

struct Equipo{
    string name;
    int points;
    int wins;
    int ties;
    int loses;
    int goal_difference;
    int goals_scored;
    int goals_against;
    int games_played ; //(less is better)
    //orden alfabetico
};

void imprimir_equipo_formato(Equipo team, int pos){
    cout << pos << ") ";
    cout << team.name << " " << team.points << "p, ";
    cout << team.games_played << "g";
    printf(" (%d-%d-%d), %dgd (%d-%d)",team.wins,team.ties,team.loses,team.goal_difference,team.goals_scored,team.goals_against);
    cout << "\n";
    
}

void imprimir_equipo(Equipo team){
    cout << "* Equipo: " << team.name << "\n";
    cout << "Points: " << team.points << "\n";
    cout << "Games Played: " << team.games_played << "\n";
    cout << "Wins: " << team.wins << "\n";
    cout << "Ties: " << team.ties << "\n";
    cout << "Loses: " << team.loses << "\n";
    cout << "Goal Difference: " << team.goal_difference << "\n";
    cout << "Goals Scored: " << team.goals_scored << "\n";
    cout << "Goals Against: " << team.goals_against << "\n";
    cout << "\n";
}

bool compareRecords(const Equipo &a,const Equipo &b){
    
    if(a.points > b.points) return true;
    if(a.points < b.points) return false;
    
    if(a.wins > b.wins) return true;
    if(a.wins < b.wins) return false;
    
    if(a.goal_difference > b.goal_difference) return true;
    if(a.goal_difference < b.goal_difference) return false;
    
    if(a.goals_scored > b.goals_scored) return true;
    if(a.goals_scored < b.goals_scored) return false;
    
    if(a.games_played < b.games_played) return true;
    if(a.games_played > b.games_played) return false;
    
    if(strcasecmp(a.name.c_str(),b.name.c_str()) < 0) return true;
    
    return false;
}

int main()
{
    
    string buff;
    int num_torneos;
    
    scanf("%d",&num_torneos);
    getline(cin,buff);
    
    while(num_torneos--){
        
        string nombre_torneo;
        //Equipos participantes
        vector <Equipo> equipos;
        
        getline(cin, nombre_torneo);
        
        int num_equipos;
        
        scanf("%d",&num_equipos);
        getline(cin,buff);
        
        //Auxiliar para saber las posiciones de los equipos en el vector
        int n_aux = 0;
        map <string,int> equiposxnum;
        
        while(num_equipos--){
            Equipo temp;
            
            getline(cin,temp.name);
            temp.points = 0;
            temp.wins = 0;
            temp.ties = 0;
            temp.loses = 0;
            temp.goal_difference = 0;
            temp.goals_scored = 0;
            temp.goals_against = 0;
            temp.games_played = 0;
            
            equipos.push_back(temp);
            equiposxnum[temp.name] = n_aux;
            
            n_aux++;
        }
        
        int num_partidos;
        
        scanf("%d",&num_partidos);
        getline(cin,buff);
        
        while(num_partidos--){
            string linea;
            
            //*** Variables que se utilizan
            
            string local;
            string visita;
            int goles_local;
            int goles_visita;
            
            //*** Fin variables que se utilizan
            
            getline(cin,linea);
            
            //Datos del equipo local
            
            // - Nombre local
            size_t pos1 = linea.find("#");
            local = linea.substr(0,pos1);
            
            linea = linea.substr(pos1 + 1,linea.size() - pos1 - 1);
            
            // - Goles local
            pos1 = linea.find("@");
            goles_local = atoi(linea.substr(0,pos1).c_str());
            
            linea = linea.substr(pos1 + 1,linea.size() - pos1 - 1);
            
            //Datos del equipo visitante
            
            // - Goles visita
            pos1 = linea.find("#");
            goles_visita = atoi(linea.substr(0,pos1).c_str());
            
            linea = linea.substr(pos1 + 1,linea.size() - pos1 - 1);
            
            // - Nombre visita
            visita = linea.substr(0,linea.size());
            
            
            // ** Asingnacion de puntajes a los equipos
            
            //Win: 3
            //Tie: 1
            //Loss: 0
            
            //Gano el local
            if(goles_local > goles_visita){

                //Local
                equipos[equiposxnum[local]].points += 3;
                equipos[equiposxnum[local]].wins += 1;
                equipos[equiposxnum[local]].goal_difference += (goles_local - goles_visita);
                equipos[equiposxnum[local]].goals_scored += goles_local;
                equipos[equiposxnum[local]].goals_against += goles_visita;
                equipos[equiposxnum[local]].games_played += 1;
                
                //Visita
                equipos[equiposxnum[visita]].loses += 1;
                equipos[equiposxnum[visita]].goal_difference -= (goles_local - goles_visita);
                equipos[equiposxnum[visita]].goals_scored += goles_visita;
                equipos[equiposxnum[visita]].goals_against += goles_local;
                equipos[equiposxnum[visita]].games_played += 1;
            }
            //Empate
            else if(goles_local == goles_visita){
                
                //Local
                equipos[equiposxnum[local]].points += 1;
                equipos[equiposxnum[local]].ties += 1;
                equipos[equiposxnum[local]].goals_scored += goles_local;
                equipos[equiposxnum[local]].goals_against += goles_visita;
                equipos[equiposxnum[local]].games_played += 1;
                
                //Visita
                equipos[equiposxnum[visita]].points += 1;
                equipos[equiposxnum[visita]].ties += 1;
                equipos[equiposxnum[visita]].goals_scored += goles_visita;
                equipos[equiposxnum[visita]].goals_against += goles_local;
                equipos[equiposxnum[visita]].games_played += 1;
                
            }
            //Gano la visita
            else if(goles_local < goles_visita){
                
                //Local
                equipos[equiposxnum[local]].loses += 1;
                equipos[equiposxnum[local]].goal_difference -= (goles_visita - goles_local);
                equipos[equiposxnum[local]].goals_scored += goles_local;
                equipos[equiposxnum[local]].goals_against += goles_visita;
                equipos[equiposxnum[local]].games_played += 1;
                
                //Visita
                equipos[equiposxnum[visita]].points += 3;
                equipos[equiposxnum[visita]].wins += 1;
                equipos[equiposxnum[visita]].goal_difference += (goles_visita - goles_local);
                equipos[equiposxnum[visita]].goals_scored += goles_visita;
                equipos[equiposxnum[visita]].goals_against += goles_local;
                equipos[equiposxnum[visita]].games_played += 1;
                
            }

        }
        
        sort(equipos.begin(),equipos.end(),&compareRecords);
        
        cout << nombre_torneo << "\n";
        
        for(int i = 0; i < equipos.size(); i++){
            imprimir_equipo_formato(equipos[i], i + 1);
        }
        
        if(num_torneos > 0) cout << "\n";
        
    }
    
    
    return 0;
}



