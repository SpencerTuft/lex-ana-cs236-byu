//
// Created by Spencer Tuft on 9/18/18.
//

#ifndef LEX_ANA_CS236_BYU_DATALOG_H
#define LEX_ANA_CS236_BYU_DATALOG_H

#include <iostream>
#include <string>

void handlePeriod(int &state) {
  std::cout << "Invoked handlePeriod" << std::endl;
}

void handleIdentifier(int &state) {
  std::cout << "Invoked handleIdentifier" << std::endl;
  switch (state) {
    default:
      std::cout << "Went to default state" << std::endl;
  }
}

#endif //LEX_ANA_CS236_BYU_DATALOG_H
