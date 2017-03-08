all: main

main: main.cpp Card.cpp Hand.cpp Blackjack.cpp
	g++ -std=c++11 main.cpp Card.cpp Hand.cpp Blackjack.cpp -o blackjack
