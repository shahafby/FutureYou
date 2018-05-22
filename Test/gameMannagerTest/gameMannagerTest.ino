#include <string.h>
#include "objects.h"

#define STATE_START 10
#define STATE_LOCATION 20
#define STATE_QUESTION 30

#define NUM_SQUARES 26


Player player1;

Square allSquares[2];
Alumni alumni[1];
Question kerenQuestions[3];

/*
int[] buttonPins = {1,2,3};
int[] buttonStates = {0,0,0};
*/

int state = STATE_START;

void setup()
{
    Serial.begin(9600);
    initGame();
}



void loop()
{
    switch (state){
    case STATE_START:       
        state = handleStateStart();
        break;
    case STATE_LOCATION:
        state = handleStateLocation();
        break;
    case STATE_QUESTION:
        state = handleStateQuestion();
        break;
    }
   
}

int handleStateStart(){
    
    return STATE_LOCATION;
}

int handleStateLocation(){

    return STATE_QUESTION;
}

int handleStateQuestion(){

    return STATE_QUESTION;

}

void initAllSquares(){
  allSquares[0] = new Square(alumni[0], 0);
  allSquares[1] = new Square(alumni[0], 1);
}

void initAlumni(){
  alumni[0] = new Alumni('keren',kerenQuestions);
}

void initGame(){
    initAlumni();
    initAllSquares();
    
    player1 = new Player(1,allSquares[0]);
  
    state = STATE_START;
  
}





void initAlumniQuestions(){
    //TODO insert all the correct answers
  for (int i = 0; i < 1; i ++){
    kerenQuestions[i] =  New Question('keren', New Record(1,4*i + 1), New Record(1,4*i + 2), New Record(1,4*i + 3), New Record(1,4*i + 4));
  }
}
