#include <iostream>
#include <vector>
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

  std::vector<Card *> hand6;
  hand6.push_back(new Card(Card::DEUX, Card::PIQUE));
  hand6.push_back(new Card(Card::ROI, Card::TREFLE));
  hand6.push_back(new Card(Card::ROI, Card::CARREAU));
  hand6.push_back(new Card(Card::DAME, Card::COEUR));
  hand6.push_back(new Card(Card::DAME, Card::PIQUE));


  std::cout << "Debut des tests du brelan." << std::endl;

  assert(has_amount_of_card_2(hand, 3) == Card::NB_VALUES);
  assert(has_amount_of_card_2(hand2, 3) ==  Card::NB_VALUES);
  assert(has_amount_of_card_2(hand3, 3) ==  Card::NB_VALUES);
  assert(has_amount_of_card_2(hand4, 3) == Card::ROI);
  assert(has_amount_of_card_2(hand5, 3) ==  Card::NB_VALUES);

  assert(sequence_2(hand) == Card::SIX);
  assert(sequence_2(hand2) ==  Card::NB_VALUES);
  assert(sequence_2(hand3) ==  Card::SIX);
  assert(sequence_2(hand4) == Card::NB_VALUES);
  assert(sequence_2(hand5) ==  Card::NB_VALUES);

  std::vector<Card::VALUE> result = has_double_pair_2(hand6);
  for (const auto& value : result) {
      std::cout << value << " ";
  }
  std::cout << std::endl;

  std::cout << "Tout les test ont etais passe" << std::endl;

  for (Card *i : hand) delete i;
  for (Card *i : hand2) delete i;
  for (Card *i : hand3) delete i;
  for (Card *i : hand4) delete i;
  for (Card *i : hand5) delete i;
  for (Card *i : hand6) delete i;
}