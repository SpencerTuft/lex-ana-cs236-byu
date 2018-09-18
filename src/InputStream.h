//
// Created by Spencer Tuft on 9/17/18.
//

#ifndef LEX_ANA_CS236_BYU_INPUTSTREAM_H
#define LEX_ANA_CS236_BYU_INPUTSTREAM_H

#include <fstream>
#include <string>

using namespace std;

class InputStream {
 private:
  string str;
  int currentLineNum = 1;
  int charLoc;
 public:
  InputStream(string& fileName) {
    ifstream ifs(fileName);

    while (!ifs.eof()) {
      char c;
      ifs.get(c);
      str.push_back(c);
    }

    ifs.close();
  }
  char currentChar();
  void forward();
  void back();
  int getLineNumber();
};

#endif //LEX_ANA_CS236_BYU_INPUTSTREAM_H
