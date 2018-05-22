
class Record
{
  public:
    int file;
    int folder;
    Record()
    {
        file = 0;
        folder = 0;
    }
    
    Record(int newFolder , int newFile  )
    {
        file = newFile;
        folder = newFolder;
    }
};


class Question
{
  public:
    Record questionReocrd;
    Record optionsRecord;
    Record correctQuestionRecord;
    Record wrongQuestionRecord;
    boolean asked;
     // 0 = wasn't answered ; 1 = player 1 ; 2 = player 2
    int anwerdBy;
    String alumni;

    Question(){}
    Question(String newAlumni, Record newQuestion, Record newOptionsRecord, Record newCorrectQuestion, Record newWrongQuestion)
    {
        alumni = newAlumni;
        questionReocrd = newQuestion;
        optionsRecord = newOptionsRecord;
        correctQuestionRecord = newCorrectQuestion;
        wrongQuestionRecord = newWrongQuestion;
        asked = false;
    }
};

class Alumni
{
    public:
    Question questions[3];
    String name;
    Alumni();

    Alumni(String alumniName, Question questionsForAlumni[]){
      name = alumniName;
      questions[0] = questionsForAlumni[0];
      questions[1] = questionsForAlumni[1];
      questions[2] = questionsForAlumni[2];
    }
};

class Square
{
    public:
    int pinID;
    // 0 = not taken ; 1 = player 1 ; 2 = player 2
    int taken;
    Alumni alumni;
    Square(){}
    Square(Alumni newAlumni, int pin){
      taken = 0;
      alumni = newAlumni;
      pinID = pin;
    }
};

class Player
{
  public:
    //1 = player1 ; 2 = player 2
    int playerID;
    Square currentSquare;
    int numberOfCapturedSquared;
    Player(){}
    Player(int newID, Square newCurrentSquare)
    {
        playerID = newID;
        currentSquare = newCurrentSquare;
        numberOfCapturedSquared = 0;
    }
};







