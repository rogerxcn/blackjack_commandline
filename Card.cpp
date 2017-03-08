/*
implementation of Card.h
*/
/* @file Card.cpp */

#include "Card.h"

// constructor implementation
Card::Card() {

  int number = rand()%12 + 1;     //get random number

  switch (number) {               // set card details according to different random results
    case 1:
      typeString = "Ace";
      initial_value = 11;
      break;

    case 2:
      typeString = "Two";
      initial_value = 2;
      break;

    case 3:
      typeString = "Three";
      initial_value = 3;
      break;

    case 4:
      typeString = "Four";
      initial_value = 4;
      break;

    case 5:
      typeString = "Five";
      initial_value = 5;
      break;

    case 6:
      typeString = "Six";
      initial_value = 6;
      break;

    case 7:
      typeString = "Seven";
      initial_value = 7;
      break;

    case 8:
      typeString = "Eight";
      initial_value = 8;
      break;

    case 9:
      typeString = "Nine";
      initial_value = 9;
      break;

    case 10:
      typeString = "Ten";
      initial_value = 10;
      break;

    case 11:
      typeString = "Jack";
      initial_value = 10;
      break;

    case 12:
      typeString = "Queen";
      initial_value = 10;
      break;

    case 13:
      typeString = "King";
      initial_value = 10;
      break;
    }
}

std::string Card::getType() const { return typeString;} // type getter

int Card::getValue() const { return initial_value;}     // value getter
