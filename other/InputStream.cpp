//
// Created by Spencer Tuft on 9/17/18.
//

#include "InputStream.h"
InputStream::InputStream(string &fileName) {
  ifstream ifs(fileName);
  if (ifs.is_open()) {
    while (!ifs.eof()) {
      char c;
      ifs.get(c);
      str.push_back(c);
    }

    ifs.close();
    str.push_back(-1);
  } else {
    cout << "File not found" << endl;
  }
}
char InputStream::currentChar() {
  return str[charLoc];
}
void InputStream::forward() {
  int next = charLoc++;
  if (str[next] == '\n') currentLineNum++;
}
int InputStream::currentLine() {
  return currentLineNum;
}
string InputStream::toString() {
  return str;
}
