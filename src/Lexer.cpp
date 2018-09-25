//
// Created by Spencer Tuft on 9/13/18.
//

#include <vector>
#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "State.h"
#include "Token.h"

Lexer::Lexer(std::string &fileName, std::vector<State> states)
    : inputStream(fileName), tcurrent(inputStream.currentLine()) {
  // Loop through the characters one by one till the end of the file character
  while (inputStream.currentChar() != -1) {

    for (auto &state : states) { // Search for the current state definition
      if (currentState == state.getId()) { // If state definition found
        // Run the function associated with this state
        bool createToken = state.process(inputStream, tcurrent, currentState);
        if (createToken) {
          currentState = "START"; // Reset to start state
          tokens.push_back(tcurrent); // Store token in the tokens list
          tcurrent = Token(); // Reset the current token
        }
        break; // After state is found, no need to loop through anymore states.
      }
    }
  }

  // End of file ritual
  tcurrent.set("EOF", "", inputStream.currentLine());
  tokens.push_back(tcurrent);
}

std::string Lexer::toString() {
  std::stringstream ss;
  int listLength = static_cast<int>(tokens.size());

  for (int i = 0; i < listLength; i++) {
    ss << tokens[i].toString();
    ss << std::endl;
  }

  ss << "Total Tokens = " << tokens.size() << std::endl;

  return ss.str();
}
