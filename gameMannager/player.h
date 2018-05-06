#include "alumniRecord.h"
#include "square.h"

class Square
{
  public:
    //1 = player1 ; 2 = player 2
    int playerID;
    Square currentSquare;
    Square capturedSquared[];

    Square(Square initSquare, int ID)
    {
        playerID = ID;
        currentSquare = initSquare;
        capturedSquared = new Square[10];
    }
};
