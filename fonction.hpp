#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "card.h"
#include "display.hpp"

__int64 score_hand(std::vector<Card *> hand);

Card::VALUE has_amount_of_card(std::map<Card::VALUE, int> map, int number);
std::vector<Card::VALUE> has_double_pair(std::map<Card::VALUE, int> map);
Card::VALUE sequence(std::map<Card::VALUE, int> map);
Card::COLOR color(std::map<Card::COLOR, int> map);

#endif
