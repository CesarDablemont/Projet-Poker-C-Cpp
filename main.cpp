#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "card.h"
#include "display.hpp"
#include "fonction.hpp"

int main() {

  // Lancer le jeu
  Game myGame;
  // display_game(myGame);

  // Mélanger le jeu
  myGame.shuffe();
  display_game(myGame);

  // Crée une main et y ajouter les 5 premiere carte du jeu
  std::vector<Card *> hand;
  for (int i = 0; i < 5; i++) {
    hand.push_back(&myGame.game[i]);
  }
  
  std::cout << "Ma main : ";
  display_hand(hand);
  best_hand(hand);
  
}