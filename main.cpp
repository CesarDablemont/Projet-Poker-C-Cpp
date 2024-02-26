#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "card.h"

/* ***************************************************************************
  DISPLAY
*************************************************************************** */
#pragma region

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

#pragma endregion

/* ***************************************************************************
  HAND TESTS
*************************************************************************** */
#pragma region

bool compareByValue(const Card *card1, const Card *card2) {
  return card1->get_value() < card2->get_value();
}

bool has_amount_of_card(std::vector<Card *> hand, int number) {
  // std::sort(hand.begin(), hand.end(), compareByValue);

  // Une map poure le nombre de fréquences de chaque valeur dans le vecteur
  std::unordered_map<Card::VALUE, int> freqMap;

  for (int i = 0; i < 5; i++) {
    auto value = hand[i]->get_value();
    Card::VALUE cardValue = static_cast<Card::VALUE>(value);
    freqMap[cardValue]++;
  }

  // display_unordered_map(freqMap);

  return std::any_of(
      freqMap.begin(), freqMap.end(),
      [number](const auto &pair) { return pair.second == number; });
}

bool color(std::vector<Card *> hand) {
  if (hand.empty()) return false;

  hand.begin();

  for (Card *i : hand) {
    if (i->get_color() != hand[0]->get_color()) {
      return false;
    }
  }
  return true;
}

bool sequence(std::vector<Card *> &hand) {
  if (hand.empty()) return false;

  // trier d'abord les cartes pour que la fonction fonctionne correctement
  std::sort(hand.begin(), hand.end(), compareByValue);

  // la valeur de la carte qui suit pour verifier la suite
  int expectedValue = hand[0]->get_value() + 1;

  for (size_t i = 1; i < hand.size(); i++) {
    if (hand[i]->get_value() != expectedValue) return false;
    expectedValue++;
  }

  return true;
}

int best_hand(std::vector<Card *> hand) {
  std::sort(hand.begin(), hand.end(), compareByValue);

  if (color(hand) && sequence(hand)) return 100000000;
  if (has_amount_of_card(hand, 4)) return 90000000;
  if (has_amount_of_card(hand, 3) && has_amount_of_card(hand, 2))
    return 80000000;
  if (color(hand)) return 70000000;
  if (sequence(hand)) return 60000000;
  if (has_amount_of_card(hand, 3)) return 50000000;

  // double paire return 40000000;

  if (has_amount_of_card(hand, 2)) return 30000000;

  // hauteur return 20000000;

  return 0;
}

#pragma endregion

/* ***************************************************************************
  TEST HAND TESTS
*************************************************************************** */
#pragma region

void test_best_hand_sub_function() {
  std::vector<Card *> hand;
  hand.push_back(new Card(Card::UN, Card::COEUR));
  hand.push_back(new Card(Card::DEUX, Card::COEUR));
  hand.push_back(new Card(Card::TROIS, Card::COEUR));
  hand.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand.push_back(new Card(Card::CINQ, Card::COEUR));

  std::vector<Card *> hand2;
  hand2.push_back(new Card(Card::UN, Card::COEUR));
  hand2.push_back(new Card(Card::DEUX, Card::COEUR));
  hand2.push_back(new Card(Card::TROIS, Card::COEUR));
  hand2.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand2.push_back(new Card(Card::UN, Card::TREFLE));

  std::vector<Card *> hand3;
  hand3.push_back(new Card(Card::CINQ, Card::PIQUE));
  hand3.push_back(new Card(Card::DEUX, Card::TREFLE));
  hand3.push_back(new Card(Card::UN, Card::CARREAU));
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

  std::cout << "Debut des test (test_best_hand_sub_function)." << std::endl;

  if (!color(hand) == true)
    std::cout << "Echec du test de la 1e couleur." << std::endl;
  if (!color(hand2) == false)
    std::cout << "Echec du test de la 2e couleur." << std::endl;

  if (!sequence(hand) == true)
    std::cout << "Echec du test de la 1e suite." << std::endl;
  if (!sequence(hand2) == false)
    std::cout << "Echec du test de la 2e suite." << std::endl;
  if (!sequence(hand3) == true)
    std::cout << "Echec du test de la 3e suite." << std::endl;

  if (!has_amount_of_card(hand2, 2) == true)
    std::cout << "Echec du 1e test de la paire." << std::endl;
  if (!has_amount_of_card(hand, 2) == false)
    std::cout << "Echec du 2e test de la paire." << std::endl;

  if (!has_amount_of_card(hand4, 3) == true)
    std::cout << "Echec du 1e test du brelan." << std::endl;
  if (!has_amount_of_card(hand2, 3) == false)
    std::cout << "Echec du 2e test du brelan." << std::endl;

  if (!has_amount_of_card(hand5, 4) == true)
    std::cout << "Echec du 1e test du carrE." << std::endl;
  if (!has_amount_of_card(hand4, 4) == false)
    std::cout << "Echec du 2e test du carrE." << std::endl;

  for (Card *i : hand) delete i;
  for (Card *i : hand2) delete i;
  for (Card *i : hand3) delete i;
  for (Card *i : hand4) delete i;
  for (Card *i : hand5) delete i;

  std::cout << "Tout les test ont etais passe" << std::endl;
}

void test_best_hand() {
  std::vector<Card *> hand;
  hand.push_back(new Card(Card::UN, Card::COEUR));
  hand.push_back(new Card(Card::DEUX, Card::COEUR));
  hand.push_back(new Card(Card::TROIS, Card::COEUR));
  hand.push_back(new Card(Card::QUATRE, Card::COEUR));
  hand.push_back(new Card(Card::CINQ, Card::COEUR));

  std::cout << "Debut des test (test_best_hand)." << std::endl;

  if (!best_hand(hand) == 100000000)
    std::cout << "Echec du 1er test." << std::endl;

  for (Card *i : hand) delete i;
  std::cout << "Tout les test ont etais passe" << std::endl;
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
  // display_game(myGame);

  // Mélanger le jeu
  myGame.shuffe();
  // display_game(myGame);

  // Crée une main et y ajouter les 5 premiere carte du jeu
  std::vector<Card *> hand;
  for (int i = 0; i < 5; i++) {
    hand.push_back(&myGame.game[i]);
  }
  // display_hand(hand);

  test_best_hand_sub_function();
  test_best_hand();

  // // Ne pas oublier de libere la memoire (uniquement si on fait "new ...")
  // for (Card *i : hand)
  //    delete i;

  return 0;
}

#pragma endregion