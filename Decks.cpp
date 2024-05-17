#include "Decks.h"
#include "Cards.h"
#include <time.h>
#include <vector>
using namespace std;

//creates a "deck" full of 52 "cards"
void Deck::deal() {
	int counter[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	vector<Cards*> deck;
	for (int i = 0; i < 52; ++i) {
		deck.push_back(new Cards());
		if (counter[deck[i]->val() - 1] >= 4) { //no more than 4 cards of a kind
			--i;
			deck.pop_back();
		}
		else {
			counter[deck[i]->val() - 1] += 1;
			if (deck[i]->val() == 1) {
				deck[i]->number = 100; //Aces are the highest
			}
		}
	}
	hand = deck;
}

//splits the main deck into two even decks for the two players
void Deck::split(Deck a, int player) {
	vector<Cards*> b;
	if (player == 1) {
		for (int i = 0; i < 52; i += 2) { //evens
			b.push_back(a.pos(i));
		}
	}
	else {
		for (int i = 1; i < 52; i += 2) { //odds
			b.push_back(a.pos(i));
		}
	}
	hand = b;
}

Cards* Deck::pos(int i) {
	return hand.at(i);
}
void Deck::add(Cards* a) {
	hand.push_back(a);
}

//shuffles deck by picking a random card in the deck and putting it at the top of the shuffled pile
void Deck::shuffle() {
	srand((int)time(nullptr));
	vector<Cards*> shuffled;
	int limit = hand.size();
	for (int i = 0; i < limit - 1; ++i) {
		int ranPos = rand() % (hand.size() - 1) + 1;
		shuffled.push_back(hand.at(ranPos));
		hand.erase(hand.begin() + ranPos);
	}
	shuffled.push_back(hand.at(0));
	hand = shuffled;
}