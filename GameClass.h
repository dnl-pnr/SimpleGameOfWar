#pragma once
#include "Decks.h"

class Game {
public:
	bool go = true;
	void play(Deck a, Deck b);
	int war(Deck& a, Deck& b, Deck& p1Discard, Deck& p2Discard, int& i, int& j);
	void printCards(Deck a, int posA, Deck b, int posB);
	void round(Deck& a, Deck& b, Deck& p1Discard, Deck& p2Discard, int& i, int& j);
};