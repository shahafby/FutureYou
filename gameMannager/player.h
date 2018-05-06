#include "alumniRecord.h"
#include "square.h"

class Square
{
  public:
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
