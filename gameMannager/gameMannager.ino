#include "FutureYou/gameMannager/question.h"
#include "FutureYou/gameMannager/square.h"
#include "FutureYou/gameMannager/record.h"
#include "FutureYou/gameMannager/player.h"


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
Question cuurentQuestion;

AlumniRecords alumni[];

Questions kerenQuestions[];
Questions ranQuestions[];
Questions yahavQuestions[];
Questions DanielQuestions[];
Questions asafQuestions[];
Questions oriQuestions[];

int[] buttonPins = {1,2,3};
int[] buttonStates = {0,0,0};

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
    switch (state){
    case STATE_START:       
        state = new StartState().start();
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
    alumni = initAlumniRecords();

    state = handleStateStart();

    //TODO : initializing the buttons pins as input (pinMode(buttonPin1, INPUT);)
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
    while(currentPlayer.currentSquare == (currentSquare = getPlayerSqaure(currentPlayer)){
        delay(10);
    }
    return STATE_QUESTION;
}

//reutrn the player currentSqaure
Square getPlayerSqaure(Player p){
    int sensorValue;
    for( int i = 0; i < allSquares.size() ; i++){
        sensorValue = analogRead(allSquares[i].pinID)
        if(p.playerID == 1 && sensorValue > player1Threshold) return allSquares[i];
        if(p.playerID == 2 && sensorValue < player2Threshold) return allSquares[i];
    }
}

int handleStateQuestion(){
    cuurentQuestion = getCurrentQuestion();
    //if there is no more questions
    if(!cuurentQuestion) return STATE_CHECKWIN;

    serialmp3_play(cuurentQuestion.questionRecord.folder,cuurentQuestion.questionRecord.file);
    return STATE_INPUT;

}

Question getCurrentQuestion(){
    for(int i=0;i<3;i++){
        if(!currentSqaure.questions[i].taken) return currentSqaure.questions[i];
    }
    return null;
}

int handleStateInput(){
    boolean correctAnswer = true;
    int answerNumber = checkResponse;
    
    while(!answerNumber) answerNumber = checkResponse;

    if(answerNumber == curren)
}

int checkResponse()
{
    if(buttonStates[0]==HIGH) return 0;
    if(buttonStates[1]==HIGH) return 1;
    if(buttonStates[2]==HIGH) return 2;
    
    return null;
}





AlumniRecords[] initAlumniRecords(){
  AlumniRecords arr[];
  alumniQuestions();
  arr[0] = New AlumniRecords('keren',kerenQuestions);
  arr[1] = New AlumniRecords('ran',ranQuestions);
  arr[2] = New AlumniRecords('yahav',yahavQuestions);
  arr[3] = New AlumniRecords('daniel',danielQuestions);
  arr[4] = New AlumniRecords('asaf',asafQuestions);
  arr[5] = New AlumniRecords('ori',oriQuestions);

  return arr;
}

Square[] initAllSquares(){
  //TODO
  }
}

void init alumniQuestions(){
  for (int i = 0; i < 3; i ++){
    kerenQuestions[i] =  New Question('keren', New Record(1,3*i + 1), New Record(1,3*i + 2), New Record(1,3*i + 3)),
    ranQuestions[i] =  New Question('ran', New Record(2,3*i + 1), New Record(2,3*i + 2), New Record(2,3*i + 3)),
    yahavQuestions[i] =  New Question('yahav', , New Record(3,3*i + 1), New Record(3,3*i + 2), New Record(3,3*i + 3)),
    danielQuestions[i] =  New Question('daniel', , New Record(4,3*i + 1), New Record(4,3*i + 2), New Record(4,3*i + 3)),
    asafQuestions[i] =  New Question('asaf', , New Record(5,3*i + 1), New Record(5,3*i + 2), New Record(5,3*i + 3)),
    oriQuestions[i] =  New Question('ori', , New Record(6,3*i + 1), New Record(6,3*i + 2), New Record(6,3*i + 3)),
  }
}

