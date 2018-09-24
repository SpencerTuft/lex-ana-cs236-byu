//
// Created by Spencer Tuft on 9/18/18.
//

#ifndef LEX_ANA_CS236_BYU_DATALOG_H
#define LEX_ANA_CS236_BYU_DATALOG_H

#include <iostream>
#include <string>
#include "Token.h"
#include "InputStream.h"
#include <regex>

bool fstart(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  char currentChar = inputStream->currentChar();

  // Check for whitespace
  if (isspace(currentChar)) {
    inputStream->forward();

    // Check for colon
  } else if (currentChar == ':') {
    currentState = "COLON";

    // Check for letter
  } else if (std::regex_match(std::string(1, currentChar), std::regex("^[a-zA-Z]$"))) {
    currentState = "IDENTIFIER";

    // Check for period
  } else if (currentChar == '.') {
    currentState = "PERIOD";

    // Check for comma
  } else if (currentChar == ',') {
    currentState = "COMMA";

    // Check for string
  } else if (currentChar == '\'') {
    currentState = "STRING";

    // Check for end of file
  } else if (currentChar == -1) {
    currentState = "EOF";

    // Check for incompleteness
  } else {
    std::cout << "ERROR: Unrecognized symbol [" << currentChar << "]" << std::endl;
    inputStream->forward();
  }
  return false;
}

bool fcolon(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  if (inputStream->nextChar() == '-') {
    currentToken->set("COLON_DASH", ":-");
    inputStream->forward(2);
  } else {
    currentToken->set("COLON", ":");
    inputStream->forward();
  }
  return true;
}

bool fperiod(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  currentToken->set("PERIOD", ".");
  inputStream->forward();
  return true;
}

bool fcomma(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  currentToken->set("COMMA", ",");
  inputStream->forward();
  return true;
}

bool fstring(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  // Current token is a quote
  char quote = '\'';
  currentToken->addValue(inputStream->currentChar());
  inputStream->forward();

  while(true) {
    if (inputStream->currentChar() == quote && inputStream->nextChar() == quote) {
      currentToken->addValue(quote);
      inputStream->forward(2);
    } else if (inputStream->currentChar() == quote){
      currentToken->addValue(inputStream->currentChar());
      inputStream->forward();
      break;
    } else {
      currentToken->addValue(inputStream->currentChar());
      inputStream->forward();
    }
  }

  currentToken->setType("STRING");
  return true;
}

bool fidentifier(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  // Set identifier state
  currentToken->setType("ID");

  // Current and all following characters that are letters or numbers
  do {
    currentToken->addValue(inputStream->currentChar());
    inputStream->forward();
  } while(std::regex_match(std::string(1, inputStream->currentChar()), std::regex("^[a-zA-Z0-9]$")));

  // Check if identifier is a special identifier
  std::string value = currentToken->getValue();
  if (value == "Schemes") {
    currentToken->setType("SCHEMES");
  } else if (value == "Facts") {
    currentToken->setType("FACTS");
  } else if (value == "Rules") {
    currentToken->setType("RULES");
  } else if (value == "Queries") {
    currentToken->setType("QUERIES");
  }
  return true;
}
#endif //LEX_ANA_CS236_BYU_DATALOG_H
