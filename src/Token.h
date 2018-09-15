//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_TOKEN_H
#define LEX_ANA_CS236_BYU_TOKEN_H

#include <string>
using namespace std;

class Token {
 private:
  int character; // the starting character number
  int line; // the token starting line number
  string type; // the token type
  string value; // the value of the token
 public:
  Token(const int c, const int l, const string &t, const string &v) {
    character = c;
    line = l;
    type = t;
    value = v;
  };
  ~Token() = default;

  int getCharacter() {
    return character;
  };
  int getLine() {
    return line;
  };
  string getValue() {
    return type;
  };
  string getType() {
    return value;
  };
};

#endif //LEX_ANA_CS236_BYU_TOKEN_H
