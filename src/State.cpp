#include <utility>

//
// Created by Spencer Tuft on 9/21/18.
//

#include "State.h"
State::State(std::string identifier, bool (&transition)(InputStream* inputStream, Token *token, std::string &state))
    : id(std::move(identifier)), f(transition) {}
