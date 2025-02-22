#ifndef MACHINE_H
#define MACHINE_H

class Machine
{
private:
    int timeToCreate = 0;
    int basicTime;

public:
    Machine();
    Machine(int t);

    void update();
    bool createPiece();
};

#endif