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
        MT.Update();
        MJ.Update();
        MA.Update();

        // Etape 4 : Création des pièces
        if (MT.CreatePiece())
        {
            fileTete.enfiler(Piece(TETE));
        }
        if (MJ.CreatePiece())
        {
            fileJupe.enfiler(Piece(JUPE));
        }
        if (MA.CreatePiece())
        {
            fileAxe.enfiler(Piece(AXE));
        }
        if (!fileTete.estVide() && !fileJupe.estVide() && !fileAxe.estVide())
        {
            filePiston.enfiler(Piece(fileTete.defiler(),
                                     fileJupe.defiler(), 
                                     fileAxe.defiler()));
        }

        // Etape 4.1 : Mise à jour de la machine MP sous condition 
        // de piston à créer
        if (!filePiston.estVide())
        {
            MP.Update();
        }
        
        // Etape 5 : Assemblage des pièces
        if (!filePiston.estVide() && MP.CreatePiece())
        {
            fileFinal.enfiler(filePiston.defiler());
        }

        // Incrémentation du temps
        halfMinutes++;
    }

    // Calcul du temps total
    float minutes = (float)halfMinutes / 2;
    bool isHalf = (minutes - (int)minutes) == 0.5f;
    
    // Affichage du temps total
    std::cout << "Temps total : " << halfMinutes / 120 << "h " << 
    (int)minutes%60 << "min " << ( (isHalf) ? 30 : 0 ) << "sec" << std::endl;
    std::cout << "Soit : " << minutes << " minutes." << std::endl;
    

    return 0;
}