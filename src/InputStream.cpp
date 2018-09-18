//
// Created by Spencer Tuft on 9/17/18.
//

#include "InputStream.h"
char InputStream::currentChar() {
  return str[charLoc];
}
void InputStream::forward() {
  int next = charLoc++;
  if (str[next] == '\n') currentLineNum++;
}
void InputStream::back() {
  int prev = charLoc--;
  if (str[prev] == '\n') currentLineNum--;
}
int InputStream::getLineNumber() {
  return currentLineNum;
}
