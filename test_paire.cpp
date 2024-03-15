#include <iostream>
#include <cassert>
#include "card.h"
#include "display.hpp"
#include "fonction.hpp"

int main(){

std::vector<Card *> hand;
  hand.push_back(new Card(Card::DEUX, Card::COEUR));
  hand.push_back(new Card(Card::TROIS, Card::COEUR));
  hand.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand.push_back(new Card(Card::CINQ, Card::COEUR));
  hand.push_back(new Card(Card::SIX, Card::COEUR));

  std::vector<Card *> hand2;
  hand2.push_back(new Card(Card::CINQ, Card::COEUR));
  hand2.push_back(new Card(Card::DEUX, Card::COEUR));
  hand2.push_back(new Card(Card::TROIS, Card::COEUR));
  hand2.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand2.push_back(new Card(Card::CINQ, Card::TREFLE));

  std::vector<Card *> hand3;
  hand3.push_back(new Card(Card::CINQ, Card::PIQUE));
  hand3.push_back(new Card(Card::DEUX, Card::TREFLE));
  hand3.push_back(new Card(Card::SIX, Card::CARREAU));
  hand3.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand3.push_back(new Card(Card::TROIS, Card::PIQUE));

  std::vector<Card *> hand4;
  hand4.push_back(new Card(Card::ROI, Card::PIQUE));
  hand4.push_back(new Card(Card::ROI, Card::TREFLE));
  hand4.push_back(new Card(Card::ROI, Card::CARREAU));
  hand4.push_back(new Card(Card::DAME, Card::COEUR));
  hand4.push_back(new Card(Card::DAME, Card::PIQUE));

  std::vector<Card *> hand5;
  hand5.push_back(new Card(Card::ROI, Card::PIQUE));
  hand5.push_back(new Card(Card::ROI, Card::TREFLE));
  hand5.push_back(new Card(Card::ROI, Card::CARREAU));
  hand5.push_back(new Card(Card::ROI, Card::COEUR));
  hand5.push_back(new Card(Card::DAME, Card::PIQUE));


  std::cout << "Debut des tests de la paire." << std::endl;

  assert(has_amount_of_card(hand, 2) == false);
  assert(has_amount_of_card(hand2, 2) == true);
  assert(has_amount_of_card(hand3, 2) == false);
  assert(has_amount_of_card(hand4, 2) == true); // on detecte bien une paire dans le full
  assert(has_amount_of_card(hand5, 2) == false);

  std::cout << "Tout les test ont etais passe" << std::endl;

  for (Card *i : hand) delete i;
  for (Card *i : hand2) delete i;
  for (Card *i : hand3) delete i;
  for (Card *i : hand4) delete i;
  for (Card *i : hand5) delete i;
}