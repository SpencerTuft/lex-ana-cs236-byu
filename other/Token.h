//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_TOKEN_H
#define LEX_ANA_CS236_BYU_TOKEN_H

#include <string>

using namespace std;

class Token {
 private:
  int line; // the token starting line number
  string type; // the token type
  string value ; // the value of the token
 public:
  Token(int l, string &t, string &v): line(l), type(t), value(v) {};

  string toString() {
    return "(" + type + "," + value + "," + to_string(line) + ")";
  }
};

#endif //LEX_ANA_CS236_BYU_TOKEN_H
