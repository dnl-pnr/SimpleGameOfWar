#include <iostream>
#include "Decks.h"
#include "GameClass.h"
using namespace std;

int main()
{
    srand((int)time(nullptr));
    Deck newDeck;
    newDeck.deal();
    Deck p1Deck;
    Deck p2Deck;
    p1Deck.split(newDeck, 1);
    p2Deck.split(newDeck, 2);
    Game GameOfWar;
    GameOfWar.play(p1Deck, p2Deck);
}