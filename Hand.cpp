/*
implementation of Hand.h
*/
/* @file Hand.cpp */

#include "Hand.h"

//constructor def
Hand::Hand(std::string holder) {

  //initialize all informatino
  hand_holder = holder;
  value = 0;
  number_of_aces = 0;
  number_of_cards = 0;

  //initialize pointer array
  for (int i=0; i<11; i++) {
    cards[i] = NULL;
  }
}

//deallocator
Hand::~Hand() {

  for (int i=0; i<number_of_cards; i++)  delete cards[i];   // deallocate all pointers

  /*
  for (auto card : cards) {
    delete card;

  */
}

Hand& Hand::operator++() {

  cards[number_of_cards] = new Card();                              //get new card
  if (cards[number_of_cards]->getType() == "Ace") number_of_aces++; //count aces
  updateValue();                                                    //update hand total value
  number_of_cards++;                                                //increment card count

  return *this;
}

/*
The following block defines (overloads) all comparison operators
*/
bool Hand::operator>(const Hand& rhs) const { return value > rhs.value;}

bool Hand::operator>(int rhs) const { return value > rhs;}

bool Hand::operator<(const Hand& rhs) const { return value < rhs.value;}

bool Hand::operator<(int rhs) const { return value < rhs;}

bool Hand::operator==(const Hand& rhs) const { return value == rhs.value;}

bool Hand::operator==(int rhs) const { return value == rhs;}

//updateValue implementation
void Hand::updateValue() {

  value += cards[number_of_cards]->getValue();

  // special situation: aces
  if (value>21) {
    value -= number_of_aces*10;
    number_of_aces = 0;
  }
}

// output hand info
void Hand::printHand() {
  std::cout << hand_holder << "'s hand is: ";
  for (int i=0; i<number_of_cards; i++) {
    std::cout << cards[i]->getType() << " ";
  }
  std::cout << '\n';

  std::cout << hand_holder << "'s hand value is " << value << '\n';
  std::cout << '\n';
}

// print first card
void Hand::printFirstCard() { std::cout << hand_holder << "'s first card is: " << cards[0]->getType() << '\n';}
