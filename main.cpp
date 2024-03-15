#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "card.h"
#include "display.hpp"
#include "fonction.hpp"


/* ***************************************************************************
  HAND TESTS
*************************************************************************** */
#pragma region


int best_hand(std::vector<Card *> hand) {
  std::sort(hand.begin(), hand.end(), compareByValue);

  int score = 0;

  if (color(hand) && sequence(hand)) score += 100000000;
  else if (has_amount_of_card(hand, 4)) score += 90000000;
  else if (has_amount_of_card(hand, 3) && has_amount_of_card(hand, 2))
    score += 80000000;
  else if (color(hand)) score += 70000000;
  else if (sequence(hand)) score += 60000000;
  else if (has_amount_of_card(hand, 3)) score += 50000000;
  else if(has_double_pair(hand)) score += 40000000;
  else if (has_amount_of_card(hand, 2)) score += 30000000;

  else score += static_cast<int>(hauteur(hand));

  return score;
}

int best_hand_text(){

  
}

#pragma endregion


/* ***************************************************************************
  MAIN
*************************************************************************** */
#pragma region

int main() {
  // std::cout << "2 de coeur" << std::endl;
  // Card c1 = Card(Card::DEUX, Card::COEUR); // 2 de coeur
  // std::cout << "value: " << c1.get_value() << ", color: " << c1.get_color()
  // << std::endl; std::cout << "value: " << c1.get_value() << ", color: " <<
  // c1.colors[c1.get_color()] << std::endl;

  // Lancer le jeu
  Game myGame;
  display_game(myGame);

  // Mélanger le jeu
  myGame.shuffe();
  display_game(myGame);

  // Crée une main et y ajouter les 5 premiere carte du jeu
  std::vector<Card *> hand;
  for (int i = 0; i < 5; i++) {
    hand.push_back(&myGame.game[i]);
  }
  display_hand(hand);

  // // Ne pas oublier de libere la memoire (uniquement si on fait "new ...")
  // for (Card *i : hand)
  //    delete i;

  return 0;
}

#pragma endregion