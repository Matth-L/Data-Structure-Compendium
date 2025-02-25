#include "Machine.h"
#include <random>
#include <iostream>

Machine::Machine()
{
    basicTime = 1;
    timeToCreate = 1;
}

Machine::Machine(int t)
{
    basicTime = t;
    timeToCreate = t;
}

bool Machine::CreatePiece()
{
    return timeToCreate == 0;
}

void Machine::Update()
{
    if (timeToCreate > 0)
    {
        timeToCreate -= 1;
    }
    else
    {
        timeToCreate = basicTime;

        std::random_device device;
        std::mt19937 rng(device());

        // random entre 1 et 4
        std::uniform_int_distribution<> break_dist(1, 4);
        int breakdown = break_dist(rng);
        
        if (breakdown)
        {
            // random entre 10 et 20 demi minutes
            std::uniform_int_distribution<> reparation_dist(10, 20);
            int reparationTime = reparation_dist(rng);

            timeToCreate += reparationTime;
        }
    }
}