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


std::string valeur_to_string(int valeur) {
    switch (valeur) {
        case 1: return "UN";
        case 2: return "DEUX";
        case 3: return "TROIS";
        case 4: return "QUATRE";
        case 5: return "CINQ";
        case 6: return "SIX";
        case 7: return "SEPT";
        case 8: return "HUIT";
        case 9: return "NEUF";
        case 10: return "DIX";
        case 11: return "VALET";
        case 12: return "DAME";
        case 13: return "ROI";
        case 14: return "AS";
        default: return "Valeur invalide";
    }
}