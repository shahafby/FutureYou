#include <string.h>
#include "objects.h"
#include "serial_mp3.h"

#define STATE_START 10
#define STATE_LOCATION 20
#define STATE_QUESTION 30
#define STATE_INPUT 40
// no need ! #define STATE_WRONG 50
#define STATE_CORRECT 60
#define STATE_CHECKWIN 70
#define STATE_ENDGAME 80
#define STATE_NEWGAME 90

#define NUM_SQUARES 26

Player currentPlayer;
Square currentSquare;
Question currentQuestion;
Player player1;
Player player2;

Square allSquares[2];
Alumni alumni[1];
Question kerenQuestions[3];
Record tempRecords[4];

/*
int[] buttonPins = {1,2,3};
int[] buttonStates = {0,0,0};
*/

//Thresholds for the magnetic sensor in order to detect players
int player1Threshold = 600;
int player2Threshold = 300;

int state = STATE_START;

void setup()
{
    Serial.begin(9600);
    delay(100);  
    serialmp3_init();
    delay(100);  
    serialmp3_set_vol(22);
    delay(100);
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

//switches all the current player data
Player switchPlayer(Player p){
    return (p.playerID == player2.playerID)? player1 : player2;
}

int handleStateStart(){
    currentPlayer = switchPlayer(currentPlayer);
    return STATE_LOCATION;
}

//reutrn the player currentSqaure
Square getPlayerSqaure(Player p){
    int sensorValue;
    for( int i = 0; i < sizeof(allSquares) ; i++){
        sensorValue = analogRead(allSquares[i].pinID);
        if(p.playerID == 1 && sensorValue > player1Threshold){
          return allSquares[i];
        }
        if(p.playerID == 2 && sensorValue < player2Threshold){
          return allSquares[i];
        }
    }
}

int handleStateLocation(){
    while(currentPlayer.currentSquare.pinID == getPlayerSqaure(currentPlayer).pinID){
        delay(10);
    }
    currentPlayer.currentSquare = getPlayerSqaure(currentPlayer);
    return STATE_QUESTION;
}

void getCurrentQuestion(){
    for(int i=0;i<3;i++){
      //NEED TO THINK HOW TO INITZAILZE
        currentQuestion = currentPlayer.currentSquare.alumni.questions[i];
        //stop at the first unasked question
        if(!currentQuestion.asked) return ;
    }
    //indactor that there is no more questions to ask
    currentQuestion.anwerdBy = -1;
}

int handleStateQuestion(){
    getCurrentQuestion();
    //if there is no more questions
    if(cuurentQuestion.anwerdBy == -1) return STATE_CHECKWIN;

    serialmp3_play(currentQuestion.questionRecord.folder,currentQuestion.questionRecord.file);
    cuurentQuestion.asked = true;
    return STATE_INPUT;
}

void initAllSquares(){
  allSquares[0].init(alumni[0], 0);
  allSquares[1].init(alumni[0], 1);
}

void initAlumni(){
  alumni[0].init("keren",kerenQuestions);
}

void initGame(){
    initAlumni();
    initAllSquares();
    
    player1.init(1,allSquares[0]);
    player2.init(2,allSquares[0]);

    currentPlayer = player1;
    Square currentSquare = allSquares[0];
    state = STATE_START;
}


void initTempRecords(int alumniFolder, int alumniFile){}


void initAlumniQuestions(){
    //TODO insert all the correct answers
  for (int i = 0; i < 1; i ++){
    tempRecords[0].init(1,4*i);
    tempRecords[1].init(1,4*i + 1);    
    tempRecords[2].init(1,4*i + 2);
    tempRecords[3].init(1,4*i + 3);   
    kerenQuestions[i].init("keren", tempRecords[0], tempRecords[1], tempRecords[2], tempRecords[3]);
  }
}
