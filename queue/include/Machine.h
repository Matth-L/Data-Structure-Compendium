#ifndef MACHINE_H
#define MACHINE_H

/**
 * @class Machine
 * @brief Représente une machine qui créer des pièces à intervalle régulier.
 */
class Machine
{
private:
    int timeToCreate = 0; /**< Temps requis pour créer une pièce. */
    int basicTime; /**< Temps normal pour créer un pièce. */

public:
    Machine();

    /**
     * @brief Constructeur paramètré pour la machine.
     * 
     * @param t Le temps normal pour créer une pièce.
     */
    Machine(int t);

    /**
     * @brief Actualise l'état de la machine.
     */
    void Update();

    /**
     * @brief Vérifie si la machine peut créer une pièce.
     * 
     * @return true si la machine peut créer une pièce, false sinon.
     */
    bool CreatePiece();
};

#endif