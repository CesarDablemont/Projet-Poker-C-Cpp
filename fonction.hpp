#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "card.h"


bool compareByValue(const Card *card1, const Card *card2);
bool has_amount_of_card(std::vector<Card *> hand, int number);
bool color(std::vector<Card *> hand);
bool sequence(std::vector<Card *> &hand);


#endif
