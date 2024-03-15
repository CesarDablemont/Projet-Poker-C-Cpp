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

int best_hand_2(std::vector<Card *> hand){
  std::sort(hand.begin(), hand.end(), compareByValue);

  int score = 0;

  if (color(hand) &&( sequence_2(hand) != Card::NB_VALUES)){
    score += 100000000; // +100000000 pour avoir une quinte flush
    score += static_cast<int>(sequence_2(hand))*1000; // +1000*l'index de la carte la plus haute de la suite
    score += static_cast<int>(hauteur(hand)); // l'index de la carte la plus haute de la suite
    // facultatif puisque la suite utilise les 5 cartes donc sequence_2(hand) renvoie la meme valeur

    std::cout << "Quinte flush au " << valeur_to_string(sequence_2(hand)) << std::endl;
    std::cout << "score = " << score << std::endl;
  }

  else if (has_amount_of_card(hand, 4)){
    int hauteur = 0;

    score += 90000000;
    score += static_cast<int>(has_amount_of_card_2(hand, 4))*1000;
    // for(int i = 0; i < 5; i++){
    //     if(hand[i]->get_value() != has_amount_of_card_2(hand, 4)){
    //         if(hand[i]->get_value() > hauteur) {
    //             hauteur = hand[i]->get_value();
    //         }
    //     }
    // }
    for (int i = 0; i < 5; i++) {
    if (hand[i]->get_value() != has_amount_of_card_2(hand, 4)) {
        hauteur = hand[i]->get_value();
        break;
        }
    }

    score += hauteur;

    std::cout << "Carre de " << valeur_to_string(has_amount_of_card_2(hand, 4)) << " avec hauteur " << valeur_to_string(hauteur) << std::endl;
    std::cout << "score = " << score << std::endl;
  } 
  
  else if(has_amount_of_card(hand, 3) && has_amount_of_card(hand, 2)){

    score += 80000000;
    score += static_cast<int>(has_amount_of_card_2(hand, 3))*10000;
    score += static_cast<int>(has_amount_of_card_2(hand, 2))*100;

    std::cout << "full de " << valeur_to_string(has_amount_of_card_2(hand, 3)) 
    << " et " << valeur_to_string(has_amount_of_card_2(hand, 2)) << std::endl; 

    std::cout << "score = " << score << std::endl;
  }
  
  else if(color(hand)){
    score += 70000000;
    score += hauteur(hand)*1000;

    std::cout << "Couleur avec hauteur " << valeur_to_string(hauteur(hand)) << std::endl;
    std::cout << "score = " << score << std::endl;
  }

  else if (sequence(hand)){
    score += 60000000;
    score += sequence_2(hand)*1000;

    std::cout << "Suite au " << valeur_to_string(sequence_2(hand)) << std::endl;
    std::cout << "score = " << score << std::endl;
  }

  else if (has_amount_of_card(hand, 3)){
    int hauteur = 0;

    score += 50000000;
    score += static_cast<int>(has_amount_of_card_2(hand, 3))*1000;
    for(int i = 0; i < 5; i++){
        if(hand[i]->get_value() != has_amount_of_card_2(hand, 3)){
            if(hand[i]->get_value() > hauteur) {
                hauteur = hand[i]->get_value();
            }
        }
    }

    score += hauteur;
    std::cout << "Brelan de " << valeur_to_string(has_amount_of_card_2(hand, 3)) << " avec hauteur " << valeur_to_string(hauteur) << std::endl;
    std::cout << "score = " << score << std::endl;
  }

  else if (has_double_pair(hand)){

  }


}

#pragma endregion

/* ***************************************************************************
  TEST best_hand_2
*************************************************************************** */
#pragma region

void test_best_hand_2(){

  std::vector<Card *> hand1;
  hand1.push_back(new Card(Card::DEUX, Card::COEUR));
  hand1.push_back(new Card(Card::TROIS, Card::COEUR));
  hand1.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand1.push_back(new Card(Card::CINQ, Card::COEUR));
  hand1.push_back(new Card(Card::SIX, Card::COEUR));

  std::vector<Card *> hand2;
  hand2.push_back(new Card(Card::ROI, Card::PIQUE));
  hand2.push_back(new Card(Card::ROI, Card::TREFLE));
  hand2.push_back(new Card(Card::ROI, Card::CARREAU));
  hand2.push_back(new Card(Card::ROI, Card::COEUR));
  hand2.push_back(new Card(Card::DAME, Card::PIQUE));

  std::vector<Card *> hand3;
  hand3.push_back(new Card(Card::ROI, Card::PIQUE));
  hand3.push_back(new Card(Card::ROI, Card::TREFLE));
  hand3.push_back(new Card(Card::ROI, Card::CARREAU));
  hand3.push_back(new Card(Card::DAME, Card::COEUR));
  hand3.push_back(new Card(Card::DAME, Card::PIQUE));

  std::vector<Card *> hand4;
  hand4.push_back(new Card(Card::DEUX, Card::COEUR));
  hand4.push_back(new Card(Card::TROIS, Card::COEUR));
  hand4.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand4.push_back(new Card(Card::CINQ, Card::COEUR));
  hand4.push_back(new Card(Card::DIX, Card::COEUR));

  std::vector<Card *> hand5;
  hand5.push_back(new Card(Card::DEUX, Card::COEUR));
  hand5.push_back(new Card(Card::TROIS, Card::COEUR));
  hand5.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand5.push_back(new Card(Card::CINQ, Card::COEUR));
  hand5.push_back(new Card(Card::SIX, Card::TREFLE));

  std::vector<Card *> hand6;
  hand6.push_back(new Card(Card::ROI, Card::PIQUE));
  hand6.push_back(new Card(Card::ROI, Card::TREFLE));
  hand6.push_back(new Card(Card::ROI, Card::CARREAU));
  hand6.push_back(new Card(Card::CINQ, Card::COEUR));
  hand6.push_back(new Card(Card::SIX, Card::TREFLE));

  best_hand_2(hand1);
  best_hand_2(hand2);
  best_hand_2(hand3);
  best_hand_2(hand4);
  best_hand_2(hand5);
  best_hand_2(hand6);

  // // Ne pas oublier de libere la memoire (uniquement si on fait "new ...")
  for (Card *i : hand1) delete i;
  for (Card *i : hand2) delete i;
  for (Card *i : hand3) delete i;
  for (Card *i : hand4) delete i;
  for (Card *i : hand5) delete i;
  for (Card *i : hand6) delete i;

}

#pragma endregion

/* ***************************************************************************
  MAIN
*************************************************************************** */
#pragma region

int main() {

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


  test_best_hand_2();
  
}

#pragma endregion