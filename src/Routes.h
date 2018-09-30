//
// Created by Spencer Tuft on 9/28/18.
//

#ifndef LEX_ANA_CS236_BYU_ROUTES_H
#define LEX_ANA_CS236_BYU_ROUTES_H

#include <cctype>

bool rwhitespace(char currentChar) {
  return isspace(currentChar) != 0;
}

bool rcolon(char currentChar) {
  return currentChar == ':';
}

bool ridentifier(char currentChar) {
  return isalpha(currentChar) != 0;
}

bool rperiod(char currentChar) {
  return currentChar == '.';
}

bool rcomma(char currentChar) {
  return currentChar == ',';
}

bool rqmark(char currentChar) {
  return currentChar == '?';
}

bool rmultiply(char currentChar) {
  return currentChar == '*';
}

bool radd(char currentChar) {
  return currentChar == '+';
}

bool rstring(char currentChar) {
  return currentChar == '\'';
}

bool rcomment(char currentChar) {
  return currentChar == '#';
}

bool rparen(char currentChar) {
  return currentChar == '(' || currentChar == ')';
}

#endif //LEX_ANA_CS236_BYU_ROUTES_H
