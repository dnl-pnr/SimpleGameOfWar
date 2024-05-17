#pragma once
#include "Cards.h"
#include <vector>
using namespace std;

class Deck {
public:
	vector<Cards*> hand;
	void deal();
	void split(Deck a, int player );
	Cards* pos(int i);
	void shuffle();
	void add(Cards* a);
};

