#include <string>

//class AlumniRecords
//{
//    public:
//    Question questions[3];
//    string name;
//
//    AlumniRecords(string alumniName, Question question){
//      name = alumniName;
//      questions[i] = new Question (name,
//     }
//    }
//};

class Question
{
  public:
    Record question;
    Record correctQuestion;
    Record wrongQuestion;
    boolean asked;
    String alumni;

    Question(String newAlumni, Record newQuestion, Record newCorrectAnswer, newWrongAnswer, boolean newAsked)
    {
        question = newQuestion;
        correctQuestion = newCorrectQuestion;
        wrongQuestion = newWrongQuestion;
        asked = false;
        alumni = newAlumni;
    }
};

