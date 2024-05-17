#include "GameClass.h"
#include "Cards.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

//checks if either players deck is empty and if so will shuffle their discard pile and put it into their main hand.
//If they have zero cards in both their main hand and in the discard pilem, the other player wins
void winCheck(Deck &a, Deck &b, Deck &p1Discard, Deck &p2Discard, int &i, int &j) {
	if (i == a.hand.size()) {
		if (p1Discard.hand.size() == 0) {
			cout << "Player 2 Wins" << endl;
			exit(1);
		}
		else {
			a.hand.clear();
			a.hand = p1Discard.hand;
			p1Discard.hand.clear();
			a.shuffle();
			i = 0;
		}

	}
	if (j == b.hand.size()) {
		if (p2Discard.hand.size() == 0) {
			cout << "Player 1 Wins" << endl;
			exit(1);
		}
		else {
			b.hand.clear();
			b.hand = p2Discard.hand;
			p2Discard.hand.clear();
			b.shuffle();
			j = 0;
		}
	}
}

void Game::play(Deck a, Deck b) {
	int i = 0;
	int j = 0;
	Deck p1Discard;
	Deck p2Discard;
	while (go == true) {
		round(a, b, p1Discard, p2Discard, i, j);
		Sleep(300);
		winCheck(a, b, p1Discard, p2Discard, i, j);
	}
}

//simulates a war
int Game::war(Deck &a, Deck &b, Deck &p1Discard, Deck &p2Discard, int &i, int &j) {
	Deck warDiscard;
	int warWinner;
	warDiscard.add(a.pos(i));
	warDiscard.add(b.pos(j));

	//plays the three cards and prints them
	for (int x = 0; x < 4; ++x) {
		++i;
		++j;
		Sleep(100);
		winCheck(a, b, p1Discard, p2Discard, i, j);
		cout << "	";
		printCards(a, i, b, j);
		warDiscard.add(a.pos(i));
		warDiscard.add(b.pos(j));
	}

	//checks last card for winner
	if (a.pos(i)->val() == b.pos(j)->val()) {
		warDiscard.hand.pop_back();
		warDiscard.hand.pop_back(); //dont want duplicates
		warWinner = war(a, b, p1Discard, p2Discard, i, j);
		winCheck(a, b, p1Discard, p2Discard, i, j);
	}
	if (a.pos(i)->val() > b.pos(j)->val()) {
		warWinner = 1;	
	}
	if (a.pos(i)->val() < b.pos(j)->val()) {
		warWinner = 2;
	}

	//gives all cards to winner
	switch (warWinner) {
		case 1:
			for (int d = 0; d < warDiscard.hand.size(); ++d) {
				p1Discard.add(warDiscard.pos(d));
			}
		case 2:
			for (int d = 0; d < warDiscard.hand.size(); ++d) {
				p2Discard.add(warDiscard.pos(d));
			}
	}
	warDiscard.hand.clear();
	++i;
	++j;
	Sleep(500);
	return warWinner;
}

//formats and prints
void Game::printCards(Deck a, int posA, Deck b, int posB) {
	string first = to_string(a.pos(posA)->val());
	string second = to_string(b.pos(posB)->val());

	if (first == "11") {
		first = "J";
	}
	if (second == "11") {
		second = "J";
	}
	if (first == "12") {
		first = "Q";
	}
	if (second == "12") {
		second = "Q";
	}
	if (first == "13") {
		first = "K";
	}
	if (second == "13") {
		second = "K";
	}
	if (first == "100") {
		first = "A";
	}
	if (second == "100") {
		second = "A";
	}

	cout << first << "		" << second << endl;
}

//compare played cards and calls functions accordingly
void Game::round(Deck &a, Deck &b, Deck &p1Discard, Deck &p2Discard, int &i, int &j) {
	system("cls");
	cout << "Player 1        Player 2" << endl;
	printCards(a, i, b, j);
	int uselessNum;
	if (a.pos(i)->val() > b.pos(j)->val()) {
		p1Discard.add(a.pos(i));
		p1Discard.add(b.pos(j));	
		++i;
		++j;
	}
	else if (a.pos(i)->val() < b.pos(j)->val()) {
		p2Discard.add(a.pos(i));
		p2Discard.add(b.pos(j));
		++i;
		++j;
	}
	else {
		uselessNum = war(a, b, p1Discard, p2Discard, i, j);
	}
}