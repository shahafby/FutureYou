#include <string>
#include "FutureYou/gameMannager/question.h"
#include "FutureYou/gameMannager/square.h"
#include "FutureYou/gameMannager/player.h"

class AlumniRecords
{
    public:
    Question[3] questions;
    string name;

    AlumniRecords(string alumniName, Question[3] alumniquestion){
      name = alumniName;
      questions = alumniquestion;
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
