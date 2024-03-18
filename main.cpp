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
  std::cout << std::endl;

  // Crée une main et y ajouter les 5 premiere carte du jeu
  std::vector<Card *> hand;
  for (int i = 0; i < 5; i++) {
    hand.push_back(&myGame.game[i]);
  }
  
  std::cout << "Ma main : ";
  display_hand(hand);


  __int64 score = score_hand(hand);
  std::cout << "score : " << score <<  std::endl;
  std::cout << score_to_text(score) <<  std::endl;



  // 2e main
  std::vector<Card *> hand2;
  for (int i = 5; i < 10; i++) {
    hand2.push_back(&myGame.game[i]);
  }
  
  std::cout << std::endl;
  std::cout << "Main adverse : ";
  display_hand(hand2);

  __int64 score2 = score_hand(hand2);
  std::cout << "score : " << score2 <<  std::endl;
  std::cout << score_to_text(score2) <<  std::endl;

  std::cout << std::endl;
  if(score > score2) std::cout << "J'ai gagne" <<  std::endl;
  else if(score2 > score) std::cout << "J'ai perdu" <<  std::endl;
  else std::cout << "Egalite" <<  std::endl;

}