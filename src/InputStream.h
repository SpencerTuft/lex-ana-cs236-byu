//
// Created by Spencer Tuft on 9/17/18.
//

#ifndef LEX_ANA_CS236_BYU_INPUTSTREAM_H
#define LEX_ANA_CS236_BYU_INPUTSTREAM_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class InputStream {
 private:
  string str = "";
  int currentLineNum = 1;
  int charLoc = 0;
 public:
  InputStream() = default;
  ~InputStream() = default;
  explicit InputStream(string& fileName);
  char currentChar();
  void forward();
  int currentLine();
  string toString();
};

#endif //LEX_ANA_CS236_BYU_INPUTSTREAM_H
