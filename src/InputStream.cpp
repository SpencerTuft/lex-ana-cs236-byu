//
// Created by Spencer Tuft on 9/17/18.
//

#include "InputStream.h"
InputStream::InputStream(std::string &fileName) {
  std::ifstream ifs(fileName);
  if (ifs.is_open()) {
    while (!ifs.eof()) {
      char c;
      ifs.get(c);
      str.push_back(c);
    }

    ifs.close();
    str.push_back(-1);
  } else {
    std::cout << "File not found" << std::endl;
  }
}
char InputStream::currentChar() const {
  return str[charLoc];
}
char InputStream::nextChar() const {
  return str[charLoc+1];
}
void InputStream::forward() {
  charLoc++;
  if (str[charLoc] == '\n') {
    currentLineNum++;
  }
}
void InputStream::forward(int num) {
  for (int i = 0; i < num; i ++) {
    forward();
  }
}
int InputStream::currentLine() const {
  return currentLineNum;
}
std::string InputStream::toString() const {
  return str;
}
