#pragma once
#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>

class Candidate
{
private: 
	std::string candidate; //nombre del candidato
	int votes; //votos del candidato

public: 
	//constructor y destructor
	Candidate();
	~Candidate();

	//constructor para inicializar el nombre y votos
	Candidate(std::string pCandidate, int pVotes); 
	void setName(std::string pCandidate); //establece el nombre del candidato
	void setVotes(int pVotes); //establece el numero de votos
	std::string getName(); //obtiene el nombre
	int getVotes(); //obtiene el voto 
};

#endif // !CANDIDATE_H



