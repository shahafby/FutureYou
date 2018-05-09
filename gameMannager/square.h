#include "FutureYou/gameMannager/question.h"
#include "FutureYou/gameMannager/record.h"
#include "FutureYou/gameMannager/player.h"
#include <string>

class Square
{
    public:
    int pinID;
    bool taken;
    string owendBy;
    Question[] questions;

    Square(Question[] questionsForSquares, int pin){
      taken = false;
      questions = questionsForSquares;
      pinID = pin;
    }
};
