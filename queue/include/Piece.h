#ifndef PIECE_H
#define PIECE_H

enum PieceType {
    TETE,
    JUPE,
    AXE,
    PISTON
}; 

class Piece
{

private:
    PieceType type;

public:
    Piece();
    Piece(PieceType t);
    Piece(Piece p1, Piece p2, Piece p3);
    
    // getters
    PieceType getType() const;
};


#endif