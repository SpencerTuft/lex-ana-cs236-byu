//
// Created by Spencer Tuft on 9/18/18.
//

#ifndef LEX_ANA_CS236_BYU_DATALOG_H
#define LEX_ANA_CS236_BYU_DATALOG_H

#include <iostream>
#include <string>
#include "Token.h"
#include "InputStream.h"

bool pwhitespace(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  inputStream.forward(); // Skip whitespace
  currentToken.setLine(inputStream.getLineNumber()); // Retrieve the current token line number
  currentState = "START";
  return false;
}

bool pcolon(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  if (inputStream.peek() == '-') {
    currentToken.set("COLON_DASH", ":-");
    inputStream.forward(2);
  } else {
    currentToken.set("COLON", ":");
    inputStream.forward();
  }
  currentState = "START";
  return true;
}

bool pperiod(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.set("PERIOD", ".");
  inputStream.forward();
  currentState = "START";
  return true;
}

bool pcomma(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.set("COMMA", ",");
  inputStream.forward();
  currentState = "START";
  return true;
}

bool pqmark(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.set("Q_MARK", "?");
  inputStream.forward();
  currentState = "START";
  return true;
}

bool pmultiply(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.set("MULTIPLY", "*");
  inputStream.forward();
  currentState = "START";
  return true;
}

bool padd(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.set("ADD", "+");
  inputStream.forward();
  currentState = "START";
  return true;
}

bool pstring(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  char quote = '\'';

  // Current token is a quote
  currentToken.setType("STRING");
  currentToken.addValue(inputStream.get());
  inputStream.forward();

  while (inputStream.get() != quote) {
    if (inputStream.get() == -1) {
      currentToken.setType("UNDEFINED");
      return true;
    }
    currentToken.addValue(inputStream.get());
    inputStream.forward();
  }

  currentToken.addValue(inputStream.get());
  inputStream.forward();
  currentState = "POSSIBLE_STRING_END";
  return false;
}

bool ppstring(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  char quote = '\'';
  if (inputStream.get() == quote) { // Found an apostrophe
    currentState = "STRING"; // Back to the string state
    return false; // Continue without creating string token
  } else { // Found string end
    currentState = "START"; // Will return to starting state
    return true; // new string token will be created
  }
}

bool pidentifier(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  // Set identifier state
  currentToken.setType("ID");

  // Current and all following characters that are letters or numbers
  do {
    currentToken.addValue(inputStream.get());
    inputStream.forward();
  } while (isalnum(inputStream.get()));

  // Check if identifier is a special identifier
  std::string value = currentToken.getValue();
  if (value == "Schemes") {
    currentToken.setType("SCHEMES");
  } else if (value == "Facts") {
    currentToken.setType("FACTS");
  } else if (value == "Rules") {
    currentToken.setType("RULES");
  } else if (value == "Queries") {
    currentToken.setType("QUERIES");
  }

  currentState = "START";
  return true;
}

bool pcomment(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  char bar = '|';
  char hash = '#';
  std::string barhash = "|#";
  char newline = '\n';
  char end = -1;

  // Beginning of comment ritual
  currentToken.addValue(hash);
  inputStream.forward();

  if (inputStream.get() != bar) { // Is single-line comment
    while (inputStream.get() != newline && inputStream.get() != end) { // Check for end of line or file
      currentToken.addValue(inputStream.get());
      inputStream.forward();
    }
  } else { // Is multi-line comment
    currentToken.addValue(bar); // Add bar symbol to value
    inputStream.forward();

    while (!(inputStream.get() == bar && inputStream.peek() == hash)) {
      // Check for end of file
      if (inputStream.get() == end) {
        currentToken.setType("UNDEFINED");
        return true;
      }
      // Add any other symbols to token value
      currentToken.addValue(inputStream.get());
      inputStream.forward();
    }

    // End of multi-line comment ritual
    currentToken.addValue(barhash);
    inputStream.forward(2);
  }
  currentToken.setType("COMMENT");

  currentState = "START";
  return true;
}

bool pparen(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  char cc = inputStream.get();
  if (cc == '(') {
    currentToken.set("LEFT_PAREN", cc);
  } else {
    currentToken.set("RIGHT_PAREN", cc);
  }
  inputStream.forward();

  currentState = "START";
  return true;
}

bool pund(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.set("UNDEFINED", inputStream.get());
  inputStream.forward();

  currentState = "START";
  return true;
}

#endif //LEX_ANA_CS236_BYU_DATALOG_H
