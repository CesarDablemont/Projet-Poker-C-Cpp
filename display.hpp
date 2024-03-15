#ifndef DISPLAY_H
#define DISPLAY_H

#include "card.h"
#include <iostream>
#include <vector>
#include <unordered_map>


void display_game(Game myGame);
void display_hand(std::vector<Card *> hand);
void display_unordered_map(const std::unordered_map<Card::VALUE, int> &uMap);
std::string valeur_to_string(int valeur);

#endif
