//
// Created by Spencer Tuft on 9/13/18.
//

#include <vector>
#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "State.h"
#include "Token.h"

Lexer::Lexer(std::string &fileName, std::vector<State> states) : inputStream(fileName), tcurrent() {
  std::string value;

  // Loop through the characters one by one till the end of the file
  while(inputStream.currentChar() != -1) {
    // Find the current state definition
    bool stateFound = false;
    for (auto &state : states) {
      if (currentState == state.getId()) {
        stateFound = true;
        state.process(&inputStream, &tcurrent, currentState);
        if (currentState == "START") {
          tokens.push_back(tcurrent);
          tcurrent = Token(inputStream.currentLine());
        }
      }
    }

    // Check against non-implemented states
    if (stateFound) {
      std::cout << "Found state for " << currentState << " in your grammar" << std::endl;
    } else {
      std::cout << "Missing state for " << currentState << " in your grammar" << std::endl;
    }

    // Increment to the next character in the stream
    inputStream.forward();
  }

  std::cout << std::endl << "Done." << std::endl;
}

std::string Lexer::toString() {
  std::stringstream ss;
  int listLength = static_cast<int>(tokens.size());

  for (int i = 0; i < listLength; i++) {
    ss << tokens[i].toString();
    if (i != listLength - 1) {
      ss << std::endl;
    }
  }

  return ss.str();
}
