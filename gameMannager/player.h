#include "alumniRecord.h"
#include "square.h"

class Player
{
  public:
    int playerID;
    Square currentSquare;
    Square capturedSquared[];

    Player(Square initSquare, int ID)
    {
        playerID = ID;
        currentSquare = initSquare;
        capturedSquared = new Square[10];
    }
};
