#include <iostream>
#include <cmath> // pow la methode pow()

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

template<typename MapType>
void display_map(const MapType &Map) {
  if (Map.empty()) {
    std::cout << "Empty map" << std::endl;
    return;
  }

  for (const auto &pair : Map)
    std::cout << "key " << static_cast<int>(pair.first) << ": value " << pair.second << ", ";
  std::cout << std::endl;
}

template void display_map<std::map<Card::VALUE, int>>(const std::map<Card::VALUE, int>& Map);
template void display_map<std::map<Card::COLOR, int>>(const std::map<Card::COLOR, int>& Map);
template void display_map<std::unordered_map<Card::VALUE, int>>(const std::unordered_map<Card::VALUE, int>& Map);

std::string valeur_to_string(int valeur) {
  switch (valeur) {
    case 11: return "Valet";
    case 12: return "Dame";
    case 13: return "Roi";
    case 14: return "AS";
    default: return std::to_string(valeur);
  }
}


std::string score_to_text(__int64 score){

  int powers[] = {14, 12, 10, 8, 6, 4, 2, 0}; // Les puissances à utiliser
  int parts[8]; // Les parties du score
  std::string text = "";

  for (int i = 0; i < 8; ++i) {
      __int64 divisor = 1;
      for (int j = 0; j < powers[i]; ++j) {
          divisor *= 10;
      }
      parts[i] = (score / divisor) % 100;
  }

  // std::cout << "n1 = " << parts[0] << std::endl;
  // std::cout << "n2 = " << parts[1] << std::endl;
  // std::cout << "n3 = " << parts[2] << std::endl;
  // std::cout << "n4 = " << parts[3] << std::endl;
  // std::cout << "n5 = " << parts[4] << std::endl;
  // std::cout << "n6 = " << parts[5] << std::endl;
  // std::cout << "n7 = " << parts[6] << std::endl;
  // std::cout << "n8 = " << parts[7] << std::endl;

  switch (parts[0]) {
    case 1: text += "Paire"; break;
    case 2: text += "Double paire"; break;
    case 3: text += "Brelan"; break;
    case 4: text += "Suite"; break;
    case 5: text += "Couleur"; break;
    case 6: text += "Full"; break;
    case 7: text += "Carre"; break;
    case 8: text += "Quinte flush"; break;
    default: break;
  }

  if(parts[0] == 4 || parts[0] == 8){  // écriture particulière pour les suites.
    switch (parts[1]) {
      case 14: return text += " a l' AS.";
      case 13: return text += " au Roi.";
      case 12: return text += " a la Dame.";
      case 11: return text += " au Valet.";
      default: return text += " en " + valeur_to_string(parts[1]) + ".";
    }
  } else {
    switch (parts[1]) {
      case 14: text += " d' AS"; break;
      case 0: break;
      default: text += " de " + valeur_to_string(parts[1]); break;
    }
  }

  switch (parts[2]) {
    case 14: text += " et d' AS"; break;
    case 0: break;
    default: text += " et de " + valeur_to_string(parts[2]); break;
  }

  if(parts[0] == 6) return text += "."; // pas de hauteur pour le full
  if(parts[0] != 0) text += " avec hauteur ";
  else text += "Hauteur "; // pas de combinaison

  switch (parts[3]) {
    case 0: break;
    default: text += valeur_to_string(parts[3]); break;
  }

  for(int i = 4; i < 8; i++){
    switch (parts[i]) {
      case 0: break;
      default: text += " puis " + valeur_to_string(parts[i]); break;
    }
  }

  return text += ".";
}