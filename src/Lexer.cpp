#include <utility>

//
// Created by Spencer Tuft on 9/13/18.
//

#include <vector>
#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "State.h"
#include "Token.h"

bool pstart(InputStream &inputStream, Token &currentToken, std::string &currentState) {
  currentToken.setLine(inputStream.getLineNumber()); // Set line at beginning of every new token
  return false;
}

std::string route(InputStream inputStream, States states, std::string &currentState) {
  for (auto &state : states) {
    bool routeFound = state.second.runRoute(inputStream.get());
    if (routeFound) {
      return state.first;
    }
  }
  return "UNDEFINED";
}

Lexer::Lexer(std::string &fileName, std::vector<State> inputStates) {
  // Initialize input stream
  inputStream = InputStream(fileName);

  // Initialize states map
  states.emplace("START", State("START", nullptr, pstart));
  for (auto &state : inputStates) {
    states.emplace(state.getId(), state);
  }
}

void Lexer::analyze() {
  // Check input stream load orl korrect
  if (!inputStream.isReady()) {
    std::cout << "No input stream loaded" << std::endl;
    return;
  }

  // Process one character at a time till the end of file
  while (inputStream.get() != -1) {

    // State Router/Switch
    if (currentState == "START") {
      currentState = route(inputStream, states, currentState);
    }

    // Run process of current state
    bool storeToken = states
        .at(currentState)
        .runProcess(inputStream, currentToken, currentState);

    // Save token and reset
    if (storeToken) {
      tokens.push_back(currentToken); // Store token in the tokens list
      currentToken = Token(inputStream.getLineNumber()); // Reset the current token
    }
  }

  // End of file ritual
  currentToken.set("EOF", "", inputStream.getLineNumber());
  tokens.push_back(currentToken);
}

std::string Lexer::toString() {
  if (inputStream.isReady()) {
    std::stringstream ss;
    int listLength = static_cast<int>(tokens.size());

    for (int i = 0; i < listLength; i++) {
      ss << tokens[i].toString();
      ss << std::endl;
    }

    ss << "Total Tokens = " << tokens.size() << std::endl;

    return ss.str();
  } else {
    return "";
  }
}
