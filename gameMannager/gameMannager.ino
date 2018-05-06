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
AlumniRecords alumni[];
Questions kerenQuestions[];
Questions ranQuestions[];
Questions yahavQuestions[];
Questions DanielQuestions[];
Questions asafQuestions[];
Questions oriQuestions[];

//Array of all magnetic sensors in the board
int magneticSensors;

//Thresholds for the magnetic sensor in order to detect players
player1Threshold;
player2Threshold;

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
    return STATE_LOCATION;
}

//switches all the current player data
Player switchPlayer(Player p){
    return (p == player2 ? player1 : player2);
}

int handleStateLocation(){
    while(currentPlayer.currentSquare != (currentSquare = getPlayerSqaure(currentPlayer)){
        delay(10);
    }
    return STATE_QUESTION;
}

//reutrn the player currentSqaure
Square getPlayerSqaure(Player p){
    int sensorValue;
    for( int i = 0; i < magneticSensors.size() ; i++){
        sensorValue = analogRead(magneticSensors[i]);
        if(p.playerID == 1 && sensorValue > player1Threshold) return sensorToSquare(sensorValue);
        if(p.playerID == 2 && sensorValue < player2Threshold) return sensorToSquare(sensorValue);
    }
}

//return the sqaure the this sensor value is on
Square sensorToSquare(int sensorValue){
    //TO:DO
return new Square();

}

AlumniRecords[] initAlumniRecords(){
  alumniQuestions();
  alumni[0] = New AlumniRecords('keren',kerenQuestions);
  alumni[1] = New AlumniRecords('ran',ranQuestions);
  alumni[2] = New AlumniRecords('yahav',yahavQuestions);
  alumni[3] = New AlumniRecords('daniel',danielQuestions);
  alumni[4] = New AlumniRecords('asaf',asafQuestions);
  alumni[5] = New AlumniRecords('ori',oriQuestions);
}

Square[] initAllSquares(){
  Square squares = {
    New Square()
  
  }
}

void init alumniQuestions(){
  for (int i = 0; i < 9; i ++){
    kerenQuestions[i / 3] =  New Question('keren', New Record(1,i + 1), New Record(1,i + 1), New Record(1,i + 1)),
  }
  for (int i = 0; i < 9; i ++){
    ranQuestions[i / 3] =  New Question('ran', New Record(1,i + 1), New Record(1,i + 1), New Record(1,i + 1)),
  }
  for (int i = 0; i < 9; i ++){
    yahavQuestions[i / 3] =  New Question('yahav', New Record(1,i + 1), New Record(1,i + 1), New Record(1,i + 1)),
  }
  for (int i = 0; i < 9; i ++){
    danielQuestions[i / 3] =  New Question('daniel', New Record(1,i + 1), New Record(1,i + 1), New Record(1,i + 1)),
  }
  for (int i = 0; i < 9; i ++){
    asafQuestions[i / 3] =  New Question('asaf', New Record(1,i + 1), New Record(1,i + 1), New Record(1,i + 1)),
  }
  for (int i = 0; i < 9; i ++){
    oriQuestions[i / 3] =  New Question('ori', New Record(1,i + 1), New Record(1,i + 1), New Record(1,i + 1)),
  }
}

