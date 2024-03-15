#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

#include "fonction.hpp"


bool compareByValue(const Card *card1, const Card *card2) {
  return card1->get_value() < card2->get_value();
}

bool has_amount_of_card(std::vector<Card *> hand, int number) {
  // std::sort(hand.begin(), hand.end(), compareByValue);

  // Une map poure le nombre de fréquences de chaque valeur dans le vecteur
  std::unordered_map<Card::VALUE, int> freqMap;

  for (int i = 0; i < 5; i++) {
    auto value = hand[i]->get_value();
    Card::VALUE cardValue = static_cast<Card::VALUE>(value);
    freqMap[cardValue]++;
  }

  // display_unordered_map(freqMap);

  return std::any_of(
      freqMap.begin(), freqMap.end(),
      [number](const auto &pair) { return pair.second == number; });
}

bool color(std::vector<Card *> hand) {
  if (hand.empty()) return false;

  hand.begin();

  for (Card *i : hand) {
    if (i->get_color() != hand[0]->get_color()) {
      return false;
    }
  }
  return true;
}

bool sequence(std::vector<Card *> &hand) {
  if (hand.empty()) return false;

  // trier d'abord les cartes pour que la fonction fonctionne correctement
  std::sort(hand.begin(), hand.end(), compareByValue);

  // la valeur de la carte qui suit pour verifier la suite
  int expectedValue = hand[0]->get_value() + 1;

  for (size_t i = 1; i < hand.size(); i++) {
    if (hand[i]->get_value() != expectedValue) return false;
    expectedValue++;
  }

  return true;
}
