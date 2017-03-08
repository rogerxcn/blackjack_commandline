/*
implementation of Blackjack.h
*/
/* @file Blackjack.cpp */

#include "Blackjack.h"

// main play member function
double Blackjack::play(double bet) {

  // give 2 cards to each holder
  ++playerHand;
  ++playerHand;
  ++dealerHand;
  ++dealerHand;

  // determine if first round (?can double down)
  bool init = true;

  // print first card of dealer
  dealerHand.printFirstCard();
  std::cout << '\n';

  // main loop: execute until stand/double down
  bool go_on = true;        //exit condition 1: player choice
  bool busted = false;      //exit condition 2: bust
  char response;            // char: player response
  playerHand.printHand();   // situation print
  std::cout << '\n';

  while (go_on && !busted) {

    if (init){  //initial -> can double down

      std::cout << "What would you like to do? Enter (h)it, (s)tand, or (d)ouble down: ";
      std::cin >> response;

      // input analysis
      if (response == 'h') {
        ++playerHand;
        go_on = true;
      }else if (response == 's') {
        go_on = false;
      }else if (response == 'd') {
        go_on = false;
        bet *= 2;
        ++playerHand;
      }else{
        std::cout << "Invalid Input!" << '\n';
      }

      // situation print
      playerHand.printHand();
      // if bust
      if (playerHand>21) busted = true;
      init = false;

    }else{  // rounds that are not init -> cannot double down

      std::cout << "What would you like to do? Enter (h)it or (s)tand: ";
      std::cin >> response;
      if (response == 'h') {
        ++playerHand;
        go_on = true;
      }else if (response == 's') {
        go_on = false;
      }else{
        std::cout << "Invalid Input!" << '\n';
      }
      playerHand.printHand();
      if (playerHand>21) busted = true;
    }
  } // end of loop

  // print initial dealer hand
  dealerHand.printHand();
  // loop until dealer's hand reaches 17
  while (dealerHand<17) {
    ++dealerHand;
    dealerHand.printHand();
  }

  // outcome output
  int netGain = 0;
  if (dealerHand>21 && !(playerHand>21)) {
    std::cout << "Dealer's hand is bust. Player wins!" << '\n';
    netGain = bet;
  }else if (playerHand>21) {
    std::cout << "Player's hand is bust." << '\n';
    netGain = -bet;
  }else if (playerHand<dealerHand) {
    std::cout << "Dealer wins." << '\n';
    netGain = -bet;
  }else if (playerHand == 21) {
    std::cout << "Blackjack! Player wins" << '\n';
    netGain = bet*1.5;
  }else if (playerHand==dealerHand) {
    std::cout << "It's a tie." << '\n';
    netGain = 0;
  }else if (playerHand>dealerHand){
    std::cout << "Player wins." << '\n';
    netGain = bet;
  }else {
    std::cout << "Invalid scheme!" << '\n';
    netGain = 0;
  }

  //update player money
  playerMoney += netGain;
  std::cout << "Player has " << playerMoney << " dollars." << '\n';

  //return value
  return playerMoney;
}
