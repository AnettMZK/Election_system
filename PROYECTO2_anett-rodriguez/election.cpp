#include "election.h"

Election::Election() {

}

Election::~Election() {

}

void Election::indicateNames(){
    this->candidate[0].setName("Hermione Granger");
    this->candidate[1].setName("Draco Malfoy");
    this->candidate[2].setName("Harry Potter");
    this->candidate[3].setName("Cedric Diggory");
    this->candidate[4].setName("Tom Riddle");
    this->candidate[5].setName("Ron Weasley");
    this->candidate[6].setName("Cho Chang");
    this->candidate[7].setName("Neville Lomgbotton");
}

void Election::toString() {
    //Definir color 
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << std::left << std::setw(20) << "Candidato" << std::right << std::setw(13) << "Votos" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        std::cout << i + 1 << ". " << std::left << std::setw(20) << this->candidate[i].getName() << std::right << std::setw(10) << this->candidate[i].getVotes() << std::endl;
    } std::cout << std::endl;

}

void Election::indicateVotes() {
    int population = 1000000; 
    int number; 

  // Inicializar el generador de números aleatorios con una semilla basada en el tiempo actual
    std::mt19937 rng(std::time(nullptr));

    // Definir la distribución para los números aleatorios (0 a population)
    std::uniform_int_distribution<int> dist(0, population);

    number = dist(rng);
    this->candidate[0].setVotes(number);

    for (int i = 1; i < MAX_CANDIDATES; i++) {
        population -= this->candidate[i - 1].getVotes();
        std::uniform_int_distribution<int> new_dist(0, population);
        number = new_dist(rng);
        this->candidate[i].setVotes(number);
    }
}

float Election::totalVotes() {
    float totalVotes = 0;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        totalVotes += this->candidate[i].getVotes();
    }
    return totalVotes;
}

void Election::topRated() {
    int major = 0;
    int pos = 0;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (this->candidate[i].getVotes() > major) {
            major = this->candidate[i].getVotes();
            pos = i;
        }
    }
    
    std::cout << "CANDIDATO MAS VOTADO: " << this->candidate[pos].getName() << " con " << major << " votos" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}


void Election::showByVotesPercentage() {
    float finalVotes = totalVotes();
    std::cout << "TOTAL DE VOTOS: " << finalVotes << std::endl;
    

    float threshold = 30.0;
    bool found = false;

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\n---------------------------------------------------------" << std::endl;
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n       CANDIDATOS QUE SUPERARON EL 30%      \n" << std::endl;

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        float percentage = (candidate[i].getVotes() * 100) / finalVotes;
        if (percentage > threshold) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << char(254) << " " << this->candidate[i].getName() << " con " << percentage << "% votos" << std::endl;
            found = true;
        }
    }

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n       CANDIDATOS QUE NO SUPERARON EL 30%       \n" << std::endl;

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        float percentage = (candidate[i].getVotes() * 100) / finalVotes;
        if (percentage <= threshold) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << char(254) << " " << this->candidate[i].getName() << " con " << percentage << "% votos" << std::endl;
        }
    }
    if (!found) {
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "\n[Ningun candidato supero el 30% de los votos]" << std::endl;
    }
}

bool Election::isWinnerDefined() {
    float finalVotes = totalVotes();
    float threshold = 40.0;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        float percentage = (candidate[i].getVotes() * 100) / finalVotes;
        if (percentage > threshold) {
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            std::cout << "\n      AL MENOS UN CANDIDATO SUPERO EL 40%      \n";

            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << "\n--------------------------------------------------" << std::endl;
            std::cout << "El candidadato ganador es: " << this->candidate[i].getName() << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
            return true;
        }
    } return false;
}

void Election::showElectionResult(Election& election, Election& electionTwo) {
    int firstWinner = -1, secondWinner = -1;

    if (!isWinnerDefined()) {
        for (int i = -1; i < MAX_CANDIDATES; i++) {
            if (firstWinner == -1 || candidate[i].getVotes() > candidate[firstWinner].getVotes()) {
                secondWinner = firstWinner; 
                firstWinner = i; 
            }
            else if (secondWinner == -1 || candidate[i].getVotes() > candidate[secondWinner].getVotes()) {
                secondWinner = i; 
            }
        }

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "\n      NINGUN CANDIDADO OBTUVO EL 40% DE LOS VOTOS      \n";
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cout << "\nEl segundo proceso electoral sera entre: \n"; 
        std::cout << "1. " << this->candidate[firstWinner].getName() << std::endl;
        std::cout << "2. " << this->candidate[secondWinner].getName() << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        secondElection(electionTwo);
        showComparation(election, electionTwo); 

    }

}

void Election::secondElection(Election& electionTwo) {

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n      SEGUNDA RONDA ELECTORAL AVELORIA 2024      \n" << std::endl;

    electionTwo.indicateNames();
    electionTwo.indicateVotes();

    electionTwo.toString();

    electionTwo.topRated();
    electionTwo.isWinnerDefined();

    electionTwo.getAbstentionismPercentage();
}

void Election::getAbstentionismPercentage() {
    int population = 1000000;
    totalVotes();

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\nTOTAL DE ABSTENCION: " << population - totalVotes() << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "TOTAL DE POBLACION: " << population << std::endl;
    std::cout << "-----------------------" << std::endl;
}


void Election::showComparation(Election& election, Election& electionTwo) {
    float votes1 = election.totalVotes(); 
    float votes2 = electionTwo.totalVotes(); 


    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n    COMPARACION DE LA PRIMERA Y SEGUNDA ELECCION 2024      \n" << std::endl;

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << std::left << std::setw(20) << "Candidato" << std::right << std::setw(20) << "Votos Eleccion 1" << std::setw(30) << "Votos Eleccion 2" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        std::cout << std::left << std::setw(20) << election.candidate[i].getName() << std::right << std::setw(17) << election.candidate[i].getVotes() << std::setw(27) << electionTwo.candidate[i].getVotes() << std::endl;
    } 
    std::cout << std::endl;

}



//RETO OPCIONAL, GRAFICA

void Election::printGraphic() {
    float finalVotes = totalVotes();
    const int scale = 100; 
    int population = 1000000;
    float newAbstentionism = population - totalVotes(); 

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "      GRAFICO DE VOTOS     \n";

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    //Linea para todos los votos de los candidatos 
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        std::string newName = this->candidate[i].getName();
       float newVotes = this->candidate[i].getVotes(); 
       float candidatesPercentage = (newVotes * 100) / finalVotes;
       int CandidatesVotesBar = (candidatesPercentage * scale / 100.0);

       if (candidatesPercentage > 0 && CandidatesVotesBar == 0) {
           CandidatesVotesBar = 1; 
       }

        std::cout << std::left << std::setw(20) << newName << " | "; 
        for (int j = 0; j < CandidatesVotesBar; j++) {
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            std::cout << char(219);
        }
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cout << " " << std::fixed << std::setprecision(1) << candidatesPercentage << "%" << std::endl;
    }

    //linea para la cantidad de abstencionismo
    float abstentionismPercentage = (newAbstentionism * 100) / population;
    int abstentionismBar = abstentionismPercentage * scale / 100; 

    if (abstentionismPercentage > 0 && abstentionismBar == 0) {
        abstentionismBar = 1;
    }
    std::cout << std::left << std::setw(20) << "Abstencion" << " | "; 
    for (int j = 0; j < abstentionismBar; j++) {
        setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << char(219);
    }
    std::cout << " " << std::fixed << std::setprecision(1) << abstentionismPercentage << "%" << std::endl;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}