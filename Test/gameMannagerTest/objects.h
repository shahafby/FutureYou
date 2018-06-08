
class Record
{
  public:
    int file;
    int folder;
    int recLength;
    Record(){}
    
    Record(int newFolder , int newFile, int newRecLength)
    {
        file = newFile;
        folder = newFolder;
        recLength = newRecLength;
    }

    init(int newFolder , int newFile, int newRecLength)
    {
        file = newFile;
        folder = newFolder;
        recLength = newRecLength;
    }
    /*playRecord(){
      Serial.println("enter play record");
      serialmp3_play(Record::folder,Record::file);
    }*/
};


class Question
{
  public:
    Record questionRecord;
    Record optionsRecord;
    Record correctQuestionRecord;
    Record wrongQuestionRecord;
    boolean asked;
     // 0 = wasn't answered ; 1 = player 1 ; 2 = player 2
    int answeredBy;
    String alumni;
    int correctAnswerNumber;

    Question(){}
    Question(String newAlumni, Record newQuestion, Record newOptionsRecord, Record newCorrectQuestion, Record newWrongQuestion, int newCorrectAnswerNumber)
    {
        alumni = newAlumni;
        questionRecord = newQuestion;
        optionsRecord = newOptionsRecord;
        correctQuestionRecord = newCorrectQuestion;
        wrongQuestionRecord = newWrongQuestion;
        correctAnswerNumber = newCorrectAnswerNumber;
        asked = false;
    }

    init(String newAlumni, Record newQuestion, Record newOptionsRecord, Record newCorrectQuestion, Record newWrongQuestion, int newCorrectAnswerNumber)
    {
        alumni = newAlumni;
        questionRecord = newQuestion;
        optionsRecord = newOptionsRecord;
        correctQuestionRecord = newCorrectQuestion;
        wrongQuestionRecord = newWrongQuestion;
        correctAnswerNumber = newCorrectAnswerNumber;
        asked = false;
    }
};

class Alumni
{
    public:
    Question questions[3];
    String name;
    Alumni(){}

    Alumni(String alumniName, Question questionsForAlumni[]){
      name = alumniName;
      questions[0] = questionsForAlumni[0];
      questions[1] = questionsForAlumni[1];
      questions[2] = questionsForAlumni[2];
    }

    init(String alumniName, Question questionsForAlumni[]){
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

    init(Alumni newAlumni, int pin){
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

    init(int newID, Square newCurrentSquare)
    {
        playerID = newID;
        currentSquare = newCurrentSquare;
        numberOfCapturedSquared = 0;
    }
};







