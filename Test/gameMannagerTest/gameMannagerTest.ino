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
    initGame();
    delay(100);  
    serialmp3_init();
    delay(100);  
    serialmp3_set_vol(22);
    delay(100);
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

void initAlumniQuestions(){
  for(int i=0; i < 3; i++){
    Record kerenRecs[4];
    kerenRecs[0].init(1,  i * 4 + 1);
    kerenRecs[1].init(1,  i * 4 + 2);
    kerenRecs[2].init(1,  i * 4 + 3);
    kerenRecs[3].init(1,  i * 4 + 4);
    
    Record danielRecs[4];
    danielRecs[0].init(2,  i * 4 + 1);
    danielRecs[1].init(2,  i * 4 + 2);
    danielRecs[2].init(2,  i * 4 + 3);
    danielRecs[3].init(2,  i * 4 + 4); 

    Record uriRecs[4];
    uriRecs[0].init(3,  i * 4 + 1);
    uriRecs[1].init(3,  i * 4 + 2);
    uriRecs[2].init(3,  i * 4 + 3);
    uriRecs[3].init(3,  i * 4 + 4);
    
    Record yahavRecs[4];
    yahavRecs[0].init(4,  i * 4 + 1);
    yahavRecs[1].init(4,  i * 4 + 2);
    yahavRecs[2].init(4,  i * 4 + 3);
    yahavRecs[3].init(4,  i * 4 + 4);    

    Record roniRecs[4];
    roniRecs[0].init(5,  i * 4 + 1);
    roniRecs[1].init(5,  i * 4 + 2);
    roniRecs[2].init(5,  i * 4 + 3);
    roniRecs[3].init(5,  i * 4 + 4);
    
    Record asafRecs[4];
    asafRecs[0].init(6,  i * 4 + 1);
    asafRecs[1].init(6,  i * 4 + 2);
    asafRecs[2].init(6,  i * 4 + 3);
    asafRecs[3].init(6,  i * 4 + 4);

    Record idcRecs[4];
    idcRecs[0].init(7,  i * 4 + 1);
    idcRecs[1].init(7,  i * 4 + 2);
    idcRecs[2].init(7,  i * 4 + 3);
    idcRecs[3].init(7,  i * 4 + 4);


    
    kerenQuestions[i].init("keren", kerenRecs[0], kerenRecs[1], kerenRecs[2], kerenRecs[3]);
    danielQuestions[i].init("daniel", danielRecs[0], danielRecs[1], danielRecs[2], danielRecs[3]);
    uriQuestions[i].init("uri", uriRecs[0], uriRecs[1], uriRecs[2], uriRecs[3]);
    yahavQuestions[i].init("yahav", yahavRecs[0], yahavRecs[1], yahavRecs[2], yahavRecs[3]);
    roniQuestions[i].init("roni", roniRecs[0], roniRecs[1], roniRecs[2], roniRecs[3]);
    asafQuestions[i].init("asaf", asafRecs[0], asafRecs[1], asafRecs[2], asafRecs[3]);
    idcQuestions[i].init("idc", idcRecs[0], idcRecs[1], idcRecs[2], idcRecs[3]);
  }
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
    player2.init(2,allSquares[0]);

    currentPlayer = player1;
    
    Square currentSquare = allSquares[0];
    state = STATE_START;
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
//    return STATE_LOCATION;
}




//Record* initRecords(Record records[4], int folder, int firstFile){
//  for(int i=0; i < 3; i++){
//    records[i].init(folder,firstFile + i);   
//  }
//  return records;
//}


//void initTempRecords(int alumniFolder, int alumniFile){}



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
    while(serialmp3_checkStatus() != 30) {
      //Serial.print(" getIsPlaying() : ");
      //Serial.println(getIsPlaying());
    }
    delay(2);
    Serial.print("optionsRecord folder : ");
    Serial.print(currentQuestion.optionsRecord.folder);
    Serial.print(" file : ");
    Serial.println(currentQuestion.optionsRecord.file);
    serialmp3_play(currentQuestion.optionsRecord.folder,currentQuestion.optionsRecord.file);
    delay(50);

    //currentQuestion.playQuestion();
    //currentQuestion.asked = true;
    return STATE_INPUT;
}











