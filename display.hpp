#ifndef DISPLAY_H
#define DISPLAY_H

#include "card.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

void display_game(Game myGame);
void display_hand(std::vector<Card *> hand);

template<typename MapType> void display_map(const MapType &Map);

std::string valeur_to_string(int valeur);
std::string score_to_text(__int64 score);

#endif
