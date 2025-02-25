#include "Piece.h"
#include <stdexcept>

Piece::Piece() : type(TETE) {}

Piece::Piece(PieceType t)
{
    type = t;
}

Piece::Piece(Piece p1, Piece p2, Piece p3)
{
    if ( (p1.getType() != p2.getType()) && 
         ( p1.getType()!= p3.getType()) && 
         (p2.getType() != p3.getType()) )
    {
        type = PISTON;
    }
    else
    {
        throw std::invalid_argument("Tout les type de piece doivent être differents.");
    }
}

PieceType Piece::getType() const
{
    return type;
}

