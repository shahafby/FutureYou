#include <string>
#include "FutureYou/gameMannager/square.h"
#include "FutureYou/gameMannager/record.h"
#include "FutureYou/gameMannager/player.h"

class AlumniRecords
{
    public:
    Question questions[3];
    string name;

    AlumniRecords(string alumniName, Question questionsForAlumni[]){
      name = alumniName;
     questions = questionsForAlumni;
     }
    }
};

class Question
{
  public:
    Record questionReocrd;
    Record correctQuestionRecord;
    Record wrongQuestionRecord;
    boolean asked;
    String alumni;
    int correctQuestionAnswerNumber;

    Question(String newAlumni, Record newQuestion, Record newCorrectAnswer, newWrongAnswer, boolean newAsked,int newCorrectQuestionAnswerNumber)
    {
        questionReocrd = newQuestion;
        correctQuestionRecord = newCorrectQuestion;
        wrongQuestionRecord = newWrongQuestion;
        asked = false;
        alumni = newAlumni;
        correctQuestionAnswerNumber = newCorrectQuestionAnswerNumber;
    }
};

