#pragma once
#ifndef ELECTION_H
#define ELECTION_H

#include "candidate.h"
#include <iostream>
#include <random> //Para los numeros aleatorios
#include <iomanip> //Para ordenar las filas y columnas
#include <windows.h> //Para los colores

//Cantidad de candidatos que pueden participar en las elecciones
const int MAX_CANDIDATES = 8;

class Election
{
private:
	Candidate candidate[MAX_CANDIDATES]; // almacena los candidatos

	//Usar color en textos 
	void setConsoleColor(WORD color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}

public:
	//constructor y destructor 
	Election(); 
	~Election();

	void indicateNames(); //nombres de los candidatos
	void toString(); //imprime los candidatos y sus votos
	void indicateVotes(); //asigna los votos a cada candidato
	float totalVotes(); //calcula la cantidad de votos 
	void topRated(); //encuentra al candidato mas votado
	void showByVotesPercentage(); //calcula el 30% de los votos emitidos
	bool isWinnerDefined(); //encuentra al ganador usando el 40%
	void showElectionResult(Election& election, Election& electionTwo); //si ningun candidato tiene el 40% busca a los mas votados y realiza una segunda eleccion
	void secondElection(Election& electionTwo);
	void getAbstentionismPercentage(); //nivel de abstencion
	void showComparation(Election& election, Election& electionTwo);  //compara la primera y segunda elccion

	//Reto opcional; 
	void printGraphic(); //imprime el grafico 
};
#endif

