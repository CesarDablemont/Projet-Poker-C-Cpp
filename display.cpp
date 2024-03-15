#include <iostream>

#include "display.hpp"


void display_game(Game myGame) {
  std::cout << "game: ";
  for (const Card &card : myGame.game) {
    // Utilisez const_cast pour utilisé to_string()
    std::cout << const_cast<Card *>(&card)->to_string() << " ";
  }
  std::cout << std::endl;
}

void display_hand(std::vector<Card *> hand) {
  if (hand.empty()) {
    std::cout << "Empty hand" << std::endl;
    return;
  }

  for (Card *i : hand) std::cout << i->to_string() << ' ';
  std::cout << std::endl;
}

void display_unordered_map(const std::unordered_map<Card::VALUE, int> &uMap) {
  if (uMap.empty()) {
    std::cout << "Empty unordered_map" << std::endl;
    return;
  }

  for (const auto &pair : uMap)
    std::cout << "key " << static_cast<int>(pair.first) << ": value "
              << pair.second << ", ";

  std::cout << std::endl;
}