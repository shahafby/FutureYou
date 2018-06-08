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

Square allSquares[30];
Alumni alumni[7];

Record tempRecords[4];

Question kerenQuestions[3];
Question danielQuestions[3];
Question uriQuestions[3];
Question yahavQuestions[3];
Question roniQuestions[3];
Question asafQuestions[3];
Question idcQuestions[3];

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;


//Thresholds for the magnetic sensor in order to detect players
int player1Threshold = 600;
int player2Threshold = 300;

int state = STATE_START;




void initAlumniQuestions(){
  Record kerenRecs[12];
  kerenRecs[0].init(1,1,23);kerenRecs[1].init(1,2,10);kerenRecs[2].init(1,3,13);kerenRecs[3].init(1,4,16);
  kerenRecs[4].init(1,5,15);kerenRecs[5].init(1,6,16);kerenRecs[6].init(1,7,14);kerenRecs[7].init(1,8,13);
  kerenRecs[8].init(1,9,15);kerenRecs[9].init(1,10,23);kerenRecs[10].init(1,11,13);kerenRecs[11].init(1,12,13);
  kerenQuestions[0].init("keren", kerenRecs[0], kerenRecs[1], kerenRecs[2], kerenRecs[3],3);
  kerenQuestions[1].init("keren", kerenRecs[4], kerenRecs[5], kerenRecs[6], kerenRecs[7],1);
  kerenQuestions[2].init("keren", kerenRecs[8], kerenRecs[9], kerenRecs[10], kerenRecs[11],1);

    
  Record danielRecs[12];
  danielRecs[0].init(2,1,16.5);danielRecs[1].init(2,2,13);danielRecs[2].init(2,3,10);danielRecs[3].init(2,4,10);
  danielRecs[4].init(2,5,15);danielRecs[5].init(2,6,13);danielRecs[6].init(2,7,14);danielRecs[7].init(2,8,15);
  danielRecs[8].init(2,9,17);danielRecs[9].init(2,10,16);danielRecs[10].init(2,11,25);danielRecs[11].init(2,12,15);
  danielQuestions[0].init("daniel", danielRecs[0], danielRecs[1], danielRecs[2], danielRecs[3],2);
  danielQuestions[1].init("daniel", danielRecs[4], danielRecs[5], danielRecs[6], danielRecs[7],1);
  danielQuestions[2].init("daniel", danielRecs[8], danielRecs[9], danielRecs[10], danielRecs[11],3); 

  Record uriRecs[12];
  uriRecs[0].init(3,1,16);uriRecs[1].init(3,2,11);uriRecs[2].init(3,3,16);uriRecs[3].init(3,4,16);
  uriRecs[4].init(3,5,11);uriRecs[5].init(3,6,13);uriRecs[6].init(3,7,20);uriRecs[7].init(3,8,19);
  uriRecs[8].init(3,9,22);uriRecs[9].init(3,10,17);uriRecs[10].init(3,11,18);uriRecs[11].init(3,12,25);
  uriQuestions[0].init("uri", uriRecs[0], uriRecs[1], uriRecs[2], uriRecs[3],3);
  uriQuestions[1].init("uri", uriRecs[4], uriRecs[5], uriRecs[6], uriRecs[7],3);
  uriQuestions[2].init("uri", uriRecs[8], uriRecs[9], uriRecs[10], uriRecs[11],3); 
    
  Record yahavRecs[12];
  yahavRecs[0].init(4,1,28);yahavRecs[1].init(4,2,9);yahavRecs[2].init(4,3,9);yahavRecs[3].init(4,4,10);
  yahavRecs[4].init(4,5,31);yahavRecs[5].init(4,6,18);yahavRecs[6].init(4,7,18);yahavRecs[7].init(4,8,18);
  yahavRecs[8].init(4,9,31);yahavRecs[9].init(4,10,14);yahavRecs[10].init(4,11,26);yahavRecs[11].init(4,12,27);
  yahavQuestions[0].init("yahav", yahavRecs[0], yahavRecs[1], yahavRecs[2], yahavRecs[3],2);
  yahavQuestions[1].init("yahav", yahavRecs[4], yahavRecs[5], yahavRecs[6], yahavRecs[7],1);
  yahavQuestions[2].init("yahav", yahavRecs[8], yahavRecs[9], yahavRecs[10], yahavRecs[11],1);  

  Record roniRecs[12];
  roniRecs[0].init(5,1,11);roniRecs[1].init(5,2,13);roniRecs[2].init(5,3,10);roniRecs[3].init(5,4,11);
  roniRecs[4].init(5,5,13);roniRecs[5].init(5,6,18);roniRecs[6].init(5,7,11);roniRecs[7].init(5,8,10);
  roniRecs[8].init(5,9,7);roniRecs[9].init(5,10,21);roniRecs[10].init(5,11,22);roniRecs[11].init(5,12,22);
  roniQuestions[0].init("roni", roniRecs[0], roniRecs[1], roniRecs[2], roniRecs[3],3);
  roniQuestions[1].init("roni", roniRecs[4], roniRecs[5], roniRecs[6], roniRecs[7],3);
  roniQuestions[2].init("roni", roniRecs[8], roniRecs[9], roniRecs[10], roniRecs[11],3); 
    
  Record asafRecs[12];
  asafRecs[0].init(6,1,14);asafRecs[1].init(6,2,16);asafRecs[2].init(6,3,16);asafRecs[3].init(6,4,16);
  asafRecs[4].init(6,5,16);asafRecs[5].init(6,6,18);asafRecs[6].init(6,7,20);asafRecs[7].init(6,8,22);
  asafRecs[8].init(6,9,16);asafRecs[9].init(6,10,16);asafRecs[10].init(6,11,18);asafRecs[11].init(6,12,20);
  asafQuestions[0].init("asaf", asafRecs[0], asafRecs[1], asafRecs[2], asafRecs[3],1);
  asafQuestions[1].init("asaf", asafRecs[4], asafRecs[5], asafRecs[6], asafRecs[7],1);
  asafQuestions[2].init("asaf", asafRecs[8], asafRecs[9], asafRecs[10], asafRecs[11],3); 
    
    
  Record idcRecs[12];
  idcRecs[0].init(7,1,14);idcRecs[1].init(7,2,16);idcRecs[2].init(7,3,16);idcRecs[3].init(7,4,16);
  idcRecs[4].init(7,5,16);idcRecs[5].init(7,6,18);idcRecs[6].init(7,7,20);idcRecs[7].init(7,8,22);
  idcRecs[8].init(7,9,16);idcRecs[9].init(7,10,16);idcRecs[10].init(7,11,18);idcRecs[11].init(7,12,20);
  idcQuestions[0].init("idc", idcRecs[0], idcRecs[1], idcRecs[2], idcRecs[3],3);
  idcQuestions[1].init("idc", idcRecs[4], idcRecs[5], idcRecs[6], idcRecs[7],2);
  idcQuestions[2].init("idc", idcRecs[8], idcRecs[9], idcRecs[10], idcRecs[11],1); 
}

void initAlumni(){
  alumni[0].init("keren",kerenQuestions);
  alumni[1].init("daniel",danielQuestions);
  alumni[2].init("uri",uriQuestions);
  alumni[3].init("yahav",yahavQuestions);
  alumni[4].init("roni",roniQuestions);
  alumni[5].init("asaf",asafQuestions);
  alumni[6].init("idc",idcQuestions);
  
}

void initAllSquares(){
  allSquares[0].init(alumni[0], 0);
  allSquares[1].init(alumni[1], 1);
/*  allSquares[2].init(alumni[1], 2);
  allSquares[3].init(alumni[2], 3);
  allSquares[4].init(alumni[6], 4);
  allSquares[5].init(alumni[3], 5);
  allSquares[6].init(alumni[6], 6);
  allSquares[7].init(alumni[1], 7);
  allSquares[8].init(alumni[0], 8);
  allSquares[9].init(alumni[6], 9);
  allSquares[10].init(alumni[4], 10);
  allSquares[11].init(alumni[5], 11);
  allSquares[12].init(alumni[6], 12);
  // prison
//    allSquares[13].init(alumni[2], 13);
  allSquares[14].init(alumni[3], 14);
  allSquares[15].init(alumni[6], 15);
  allSquares[16].init(alumni[4], 16);
  allSquares[17].init(alumni[1], 17);
  allSquares[18].init(alumni[5], 18);
  allSquares[19].init(alumni[2], 19);
  allSquares[20].init(alumni[6], 20);
  allSquares[21].init(alumni[4], 21);
  allSquares[22].init(alumni[3], 22);
  allSquares[23].init(alumni[0], 23);
  allSquares[24].init(alumni[5], 24);
  allSquares[25].init(alumni[2], 25);
  allSquares[26].init(alumni[6], 26);
  */  
}

void initGame(){
    initAlumniQuestions();
    initAlumni();
    initAllSquares();
    
    player1.init(1,allSquares[0]);
    //player2.init(2,allSquares[0]);

    currentPlayer = player1;
    
    Square currentSquare = allSquares[0];
    state = STATE_START;
}

//switches all the current player data
Player switchPlayer(Player p){
    return (p.playerID == player2.playerID)? player1 : player2;
}

int handleStateStart(){
    //currentPlayer = switchPlayer(currentPlayer);
    return STATE_LOCATION;
}

//reutrn the player currentSqaure
Square getPlayerSqaure(Player p){
    int sensorValue;
    for( int i = 0; i < 2 ; i++){
        sensorValue = analogRead(allSquares[i].pinID);
        if(p.playerID == 1 && sensorValue > player1Threshold) return allSquares[i];
        if(p.playerID == 2 && sensorValue < player2Threshold) return allSquares[i];
    }
    return currentPlayer.currentSquare;
}

int handleStateLocation(){
    Serial.print("current square ");
    Serial.println(currentPlayer.currentSquare.pinID);
    Square newSquare = getPlayerSqaure(currentPlayer);
    while(currentPlayer.currentSquare.pinID == newSquare.pinID){
        newSquare = getPlayerSqaure(currentPlayer);
        delay(10);
    }
    currentPlayer.currentSquare.init(newSquare.alumni,newSquare.pinID);
    Serial.print("current square ");
    Serial.println(currentPlayer.currentSquare.pinID);
    currentSquare = currentPlayer.currentSquare;
    return STATE_QUESTION;
}





void setCurrentQuestion(){
    Alumni currentAlumni = currentSquare.alumni;
    for(int i = 0;i < 3; i++){
      currentQuestion = currentAlumni.questions[i];
      if(!currentQuestion.asked){
        Serial.println("found question");
        return;
      }
    }
}

int handleStateQuestion(){
    Serial.println("handleStateQuestion");
    
    setCurrentQuestion();
    Serial.print("questionRecord folder : ");
    Serial.print(currentQuestion.questionRecord.folder);
    Serial.print(" file : ");
    Serial.println(currentQuestion.questionRecord.file);
    serialmp3_play(currentQuestion.questionRecord.folder,currentQuestion.questionRecord.file);
    delay(currentQuestion.questionRecord.recLength * 1000);
    Serial.print("optionsRecord folder : ");
    Serial.print(currentQuestion.optionsRecord.folder);
    Serial.print(" file : ");
    Serial.println(currentQuestion.optionsRecord.file);
    serialmp3_play(currentQuestion.optionsRecord.folder,currentQuestion.optionsRecord.file);
    delay(currentQuestion.optionsRecord.recLength * 1000);
    
    currentQuestion.asked = true;
    return STATE_INPUT;
}

int handleStateInput(){
    Serial.println("handleStateInput");
    int answerNumber = checkResponse();
    
    while(!answerNumber) answerNumber = checkResponse();
    Serial.print("Answer number : ");
    Serial.println(answerNumber);
     
    if(answerNumber == currentQuestion.correctAnswerNumber){
        Serial.println("True");
        serialmp3_play(currentQuestion.correctQuestionRecord.folder,currentQuestion.correctQuestionRecord.file);
        delay(currentQuestion.correctQuestionRecord.recLength * 1000);
        return STATE_CORRECT;
    }
    else{
        Serial.println("False");
        serialmp3_play(currentQuestion.wrongQuestionRecord.folder,currentQuestion.wrongQuestionRecord.file);
        delay(currentQuestion.wrongQuestionRecord.recLength * 1000);
        return STATE_START;
    }
}

int checkResponse()
{
    if(digitalRead(buttonPin1)==HIGH) return 1;
    if(digitalRead(buttonPin2)==HIGH) return 2;
    if(digitalRead(buttonPin3)==HIGH) return 3;
    
    return 0;
}

int handleStateCorrect(){
    Serial.println("handleStateCorrect");
    currentPlayer.currentSquare.taken = currentPlayer.playerID;
    currentPlayer.numberOfCapturedSquared++;
    return STATE_CHECKWIN;
}

int handleStateCheckhWin() {
    Serial.println("handleStateCheckhWin");
    if(currentPlayer.numberOfCapturedSquared >= 3) return STATE_ENDGAME;
    
    return STATE_START;
}

int handleStateEndGame() {
    Serial.println("handleStateEndGame");
    
    return -1;
}

void setup()
{
    Serial.begin(9600);
    initGame();
    delay(100);  
    serialmp3_init();
    delay(100);  
    serialmp3_set_vol(22);
    delay(100);
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);
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
    case STATE_INPUT:
        state = handleStateInput();
        break;
    case STATE_CORRECT:
        state = handleStateCorrect();
        break;
    case STATE_CHECKWIN:
        state = handleStateCheckhWin();
        break;
    case STATE_ENDGAME:
        state = handleStateEndGame();
        break;
    }
}







