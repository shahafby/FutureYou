#include "alumniRecord.h"
#include "square.h"
#include "player.h"

#define STATE_START 10
#define STATE_LOCATION 20
#define STATE_QUESTION 30
#define STATE_INPUT 40
#define STATE_WRONG 50
#define STATE_CORRECT 60
#define STATE_CHECKWIN 70

#define NUM_SQUARES 26

Player player1;
Player player2;
Square allSquares[];
Player currentPlayer;
Square currentSquare;
AlumniRecords alumniRec[];


void setup()
{
    Serial.begin(9600);
    initGame();
}
void loop()
{
    switch (state)
    {
    case STATE_START:
        state = handleStateStart();
        break;
    case STATE_LOCATION:
        state = handleStateLocation();
        break;
    case STATE_QUESTION:
        state = handleStateQuestion();
        break;
    case STATE_INPUT:
        state = handleStateInput();
        break;
    case STATE_WRONG:
        state = handleStateWrong();
        break;
    case STATE_CORRECT:
        state = handleStateCorrect();
        break;
    case STATE_CHECKWIN:
        state = handleStateCheckhWin();
        break;
    }
}

void initGame(){
    player1 = new Player();
    player2 = new Player();
    allSquares = initAllSquares();
    

}
int handleStateStart(){
    currentPlayer = switchPlayer(currentPlayer);
    
}

//switches all the current player data
Player switchPlayer(Player p){

}

Square[] initAllSquares(){
  Square squares[NUM_SQUARES] 
  for(int i = 0; i < NUM_SQUARES; i++){
    squares[i] = new Square(,) // todo.....
  }
}

AlumniRecords[] initAlumniRecords(){
  AlumniRecords alumniRec[6] = 
  {
    New  
    }
  
}


