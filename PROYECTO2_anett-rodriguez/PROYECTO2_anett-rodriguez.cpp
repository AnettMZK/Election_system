#include <iostream>
#include "candidate.h"
#include "election.h"
#include <windows.h>

void clearScreen() {
    system("cls"); 
}

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    Election ELECCION_PROCESO1_2024; // Crear un objeto Election
    Election ELECCION_PROCESO2_2024;

    ELECCION_PROCESO1_2024.indicateNames(); // Llamar a la función para imprimir los candidatos
    ELECCION_PROCESO1_2024.indicateVotes();

    int option = 0; 
    do {
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "\n   MENU DEL SISTEMA DE VOTACIONES DE AVELORIA 2024   \n" << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cout << " [1] Mostrar resultados.    \n"; 
        std::cout << " [2] Mostrar grafico.       \n";
        std::cout << " [3] salir.                 \n";
        std::cout << "\n--------------------------------------------------\n"; 
        std::cin >> option; 

        clearScreen(); 

        switch (option) {
        case 1: 
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            std::cout << "   SISTEMA DE VOTACIONES DE AVELORIA 2024   \n" << std::endl;

            ELECCION_PROCESO1_2024.toString(); // Imprime los objetos
            ELECCION_PROCESO1_2024.topRated();
            ELECCION_PROCESO1_2024.getAbstentionismPercentage();
            ELECCION_PROCESO1_2024.showByVotesPercentage();
            ELECCION_PROCESO1_2024.showElectionResult(ELECCION_PROCESO1_2024,ELECCION_PROCESO2_2024);

            break; 
        case 2: 
            ELECCION_PROCESO1_2024.printGraphic();

            break; 

        case 3:
            std::cout << "SALIENDO.......";

        defautl: 
            std::cout << "ERROR!!!!!";
        }
    } while (option != 3); 
    return 0;
}


