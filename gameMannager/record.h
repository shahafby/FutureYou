#include <string>
#include "FutureYou/gameMannager/question.h"
#include "FutureYou/gameMannager/square.h"
#include "FutureYou/gameMannager/player.h"

class AlumniRecords
{
    public:
    Question questions[3];
    string name;

    AlumniRecords(string alumniName, Question question){
      name = alumniName;
      questions[i] = new Question (name,
     }
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
