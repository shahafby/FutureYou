#include "FutureYou/gameMannager/question.h"
#include "FutureYou/gameMannager/square.h"
#include "FutureYou/gameMannager/record.h"

class Player
{
  public:
    //1 = player1 ; 2 = player 2
    int playerID;
    Square currentSquare;
    int numberOfCapturedSquared;

    Player(Square initSquare, int ID)
    {
        playerID = ID;
        currentSquare = initSquare;
        capturedSquared = 0;
    }
};
