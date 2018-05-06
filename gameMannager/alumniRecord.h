#include <string>

class AlumniRecords
{
    public:
    Question questions[4];
    string name;
};

class Question
{
  public:
    Record question;
    Record correctQuestion;
    Record wrongQuestion;
    boolean asked;
    String alumni;

    Question( String newAlumni, Record newQuestion, Record newCorrectQuestion, newWrongQuestion, boolean newAsked)
    {
        question = newQuestion;
        correctQuestion = newCorrectQuestion;
        wrongQuestion = newWrongQuestion;
        asked = false;
        alumni = newAlumni;
    }
};

class Record
{
  public:
    int file;
    int folder;

    Record(int newFolder, int newFile)
    {
        file = newFile;
        folder = newFolder;
    }
};
