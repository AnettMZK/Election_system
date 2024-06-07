#include "candidate.h"

Candidate::Candidate() {
	votes = 0; 
}
Candidate::~Candidate() {

}

Candidate::Candidate(std::string pCandidate, int pVotes) {
	candidate = pCandidate;
	votes = pVotes;
}

//sets
void Candidate::setName(std::string pCandidate) {
	candidate = pCandidate;
}

void Candidate::setVotes(int pVotes) {
	votes = pVotes; 
}

//gets

std::string Candidate::getName() {
	return candidate; 
}

int Candidate::getVotes() {
	return votes;
}

