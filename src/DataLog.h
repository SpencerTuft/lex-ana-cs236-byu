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

void fstart(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  char currentChar = inputStream->currentChar();

  // Check for colon
  if (currentChar == ':') {
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

    // Check for incompleteness
  } else {
    std::cout << "ERROR: Unrecognized symbol [" << currentChar << "]" << std::endl;
  }
}

void fcolon(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  if (inputStream->nextChar() != '-') {
    currentToken->setValue(":-");
    currentToken->setType("COLON_DASH");
    currentState = "START";
    inputStream->forward(2);
  } else {
    currentToken->setType("COLON");
    currentToken->setValue(':');
    currentState = "START";
    inputStream->forward();
  }
}

void fperiod(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  currentToken->setValue('.');
  currentToken->setType("PERIOD");
  currentState = "START";
  inputStream->forward();
}

void fcomma(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  currentToken->setValue(',');
  currentToken->setType("COMMA");
  currentState = "START";
  inputStream->forward();
}

void fstring(InputStream* inputStream, Token* currentToken, std::string &currentState) {
  // Current token is a quote
  currentToken->addValue(inputStream->currentChar());
  inputStream->forward();

  while(inputStream->currentChar() != '\'') {

  }

  currentToken->setType("STRING");
  currentState = "START";
}

void fidentifier(InputStream* inputStream, Token* currentToken, std::string &currentState) {
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

  // Return to start state and advance inputStream
  currentState = "START";
}

#endif //LEX_ANA_CS236_BYU_DATALOG_H
