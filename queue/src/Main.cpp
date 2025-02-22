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



    while (fileFinal.taille() < 100)
    {
        // Etape 3 : Mise à jour des machines
        MT.update();
        MJ.update();
        MA.update();
        MP.update();

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
        if (MP.createPiece() && !fileTete.estVide() && !fileJupe.estVide() && !fileAxe.estVide())
        {
            try
            {
                filePiston.enfiler(Piece(fileTete.defiler(), fileJupe.defiler(), fileAxe.defiler()));
            }
            catch (std::invalid_argument e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        // Etape 5 : Assemblage des pièces
        if (!filePiston.estVide())
        {
            fileFinal.enfiler(filePiston.defiler());
        }

        halfMinutes++;
    }

    float minutes = (float)halfMinutes / 2;
    bool isHalf = (minutes - (int)minutes) == 0.5f;
    
    std::cout << "Temps total : " << halfMinutes / 120 << "h " << (int)minutes%60 << "min " << ( (isHalf) ? 30 : 0 ) << "sec" << std::endl;
    std::cout << "Soit : " << minutes << " minutes." << std::endl;
    

    return 0;
}