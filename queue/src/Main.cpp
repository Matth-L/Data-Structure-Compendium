#include "File.h"
#include "Piece.h"
#include "Machine.h"
#include <iostream>

int main() {

    // Etape 1 : Création des files d'attente pour chaque pièce
    File<Piece> fileTete;
    File<Piece> fileJupe;
    File<Piece> fileAxe;
    File<Piece> filePiston;
    File<Piece> fileFinal;

    Piece pa();

    // Etape 2 : Création des machines
    Machine MT(4);
    Machine MJ(6);
    Machine MA(5);
    Machine MP(2);

    int halfMinutes = 0;

    bool canCreatePiston = false;



    while (fileFinal.taille() < 100)
    {
        // Etape 3 : Mise à jour des machines
        MT.update();
        MJ.update();
        MA.update();

        // Etape 4 : Création des pièces
        if (MT.createPiece())
        {
            fileTete.enfiler(Piece(TETE));
        }
        if (MJ.createPiece())
        {
            fileJupe.enfiler(Piece(JUPE));
        }
        if (MA.createPiece())
        {
            fileAxe.enfiler(Piece(AXE));
        }
        if (!fileTete.estVide() && !fileJupe.estVide() && !fileAxe.estVide())
        {
            filePiston.enfiler(Piece(fileTete.defiler(), fileJupe.defiler(), fileAxe.defiler()));
        }

        if (!filePiston.estVide())
        {
            MP.update();
        }
        
        // Etape 5 : Assemblage des pièces
        if (!filePiston.estVide() && MP.createPiece())
        {
            fileFinal.enfiler(filePiston.defiler());
        }

        halfMinutes++;
    }

    // Calcul du temps total
    float minutes = (float)halfMinutes / 2;
    bool isHalf = (minutes - (int)minutes) == 0.5f;
    
    // Affichage du temps total
    std::cout << "Temps total : " << halfMinutes / 120 << "h " << (int)minutes%60 << "min " << ( (isHalf) ? 30 : 0 ) << "sec" << std::endl;
    std::cout << "Soit : " << minutes << " minutes." << std::endl;
    

    return 0;
}