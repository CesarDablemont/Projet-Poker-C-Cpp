#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "card.h"


bool compareByValue(const Card *card1, const Card *card2);
bool has_amount_of_card(std::vector<Card *> hand, int number);
bool color(std::vector<Card *> hand);
bool sequence(std::vector<Card *> &hand);
bool has_double_pair(std::vector<Card *> hand);

Card::VALUE has_amount_of_card_2(std::vector<Card *> hand, int number);
Card::VALUE sequence_2(std::vector<Card *> &hand);
Card::VALUE hauteur(std::vector<Card *> &hand);
std::vector<Card::VALUE> has_double_pair_2(std::vector<Card *> hand);

#endif
