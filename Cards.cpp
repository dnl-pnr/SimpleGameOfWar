#include "Cards.h"
#include <time.h>
#include <iostream>

//number 1 - 13
void Cards::randomize() {
	number = rand() % 13 + 1;
}

//card will automatically get a random number when created
Cards::Cards() {
	randomize();
}

//returns what number the card represents
int Cards::val() {
	return number;
}