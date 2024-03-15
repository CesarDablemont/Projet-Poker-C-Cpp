#include <iostream>
#include <vector>
#include <cassert>

#include "card.h"
#include "display.hpp"
#include "fonction.hpp"

int main(){

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

  std::vector<Card *> hand7;
  hand7.push_back(new Card(Card::ROI, Card::PIQUE));
  hand7.push_back(new Card(Card::ROI, Card::TREFLE));
  hand7.push_back(new Card(Card::DEUX, Card::CARREAU));
  hand7.push_back(new Card(Card::DEUX, Card::COEUR));
  hand7.push_back(new Card(Card::SIX, Card::TREFLE));

  std::vector<Card *> hand8;
  hand8.push_back(new Card(Card::ROI, Card::PIQUE));
  hand8.push_back(new Card(Card::ROI, Card::TREFLE));
  hand8.push_back(new Card(Card::DEUX, Card::CARREAU));
  hand8.push_back(new Card(Card::SIX, Card::TREFLE));
  hand8.push_back(new Card(Card::TROIS, Card::COEUR));

  std::vector<Card *> hand9;
  hand9.push_back(new Card(Card::QUATRE, Card::PIQUE));
  hand9.push_back(new Card(Card::ROI, Card::TREFLE));
  hand9.push_back(new Card(Card::DEUX, Card::CARREAU));
  hand9.push_back(new Card(Card::AS, Card::TREFLE));
  hand9.push_back(new Card(Card::TROIS, Card::COEUR));


  std::cout << "Debut des tests de la meilleur main." << std::endl;

  best_hand(hand1);
  best_hand(hand2);
  best_hand(hand3);
  best_hand(hand4);
  best_hand(hand5);
  best_hand(hand6);
  best_hand(hand7);
  best_hand(hand8);
  best_hand(hand9);

  std::cout << "Tout les test ont etais passe" << std::endl;
  
  // // Ne pas oublier de libere la memoire (uniquement si on fait "new ...")
  for (Card *i : hand1) delete i;
  for (Card *i : hand2) delete i;
  for (Card *i : hand3) delete i;
  for (Card *i : hand4) delete i;
  for (Card *i : hand5) delete i;
  for (Card *i : hand6) delete i;
  for (Card *i : hand7) delete i;
  for (Card *i : hand8) delete i;
  for (Card *i : hand9) delete i;

}