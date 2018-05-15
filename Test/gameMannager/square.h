#include "FutureYou/gameMannager/question.h"
#include "FutureYou/gameMannager/record.h"
#include "FutureYou/gameMannager/player.h"
#include <string>

class Square
{
    public:
    int pinID;
    // 0 = not taken ; 1 = player 1 ; 2 = player 2
    int taken;
    string owendBy;
    Question[] questions;

    Square(Question[] questionsForSquares, int pin){
      taken = 0;
      questions = questionsForSquares;
      pinID = pin;
    }
};
