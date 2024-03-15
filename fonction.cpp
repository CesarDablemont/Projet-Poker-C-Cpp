#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

#include "fonction.hpp"


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

bool has_double_pair(std::vector<Card *> hand) {
    // Une map pour le nombre de fréquences de chaque valeur dans le vecteur
    std::unordered_map<Card::VALUE, int> freqMap;

    for (int i = 0; i < hand.size(); i++) {
        auto value = hand[i]->get_value();
        Card::VALUE cardValue = static_cast<Card::VALUE>(value);
        freqMap[cardValue]++;
    }

    // comme pour has_amount_of_card mais on test si on a 2 occurence
    int pairCount = 0;
    for (const auto &pair : freqMap) {
        if (pair.second == 2) {
            pairCount++;
        }
    }

    // vrai si il y en a 2
    return pairCount == 2;
}

std::vector<Card::VALUE> has_double_pair_2(std::vector<Card *> hand) {
    std::unordered_map<Card::VALUE, int> freqMap;

    // Comptage des fréquences de chaque valeur de carte
    for (const auto& cardPtr : hand) {
        Card::VALUE cardValue = static_cast<Card::VALUE>(cardPtr->get_value());
        freqMap[cardValue]++;
    }

    // Recherche des deux paires
    std::vector<Card::VALUE> doublePairs;
    for (const auto& pair : freqMap) {
        if (pair.second == 2) {
            doublePairs.push_back(pair.first);
        }
    }

    // Renvoi des valeurs des deux paires
    if (doublePairs.size() == 2) {
        return doublePairs;
    } else {
        // Retourner un vecteur vide si deux paires ne sont pas trouvées
        return std::vector<Card::VALUE>();
    }
}



Card::VALUE has_amount_of_card_2(std::vector<Card *> hand, int number) {
  std::unordered_map<Card::VALUE, int> freqMap;

  // Parcourez la main pour compter les fréquences de chaque valeur de carte
  for (const auto& cardPtr : hand) {
    Card::VALUE cardValue = static_cast<Card::VALUE>(cardPtr->get_value());
    freqMap[cardValue]++;
  }

  // Recherchez la première clé correspondant au nombre donné
  auto it = std::find_if(freqMap.begin(), freqMap.end(), [number](const auto &pair) {
    return pair.second == number;
  });

  // Si une clé correspondante est trouvée, retournez-la
  if (it != freqMap.end())
      return it->first;

  // Sinon, retournez une valeur hors limites pour indiquer qu'aucune clé correspondante n'a été trouvée
  return Card::NB_VALUES;
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

Card::VALUE sequence_2(std::vector<Card *> &hand) {
  if (hand.empty()) return Card::NB_VALUES;

  // trier d'abord les cartes pour que la fonction fonctionne correctement
  std::sort(hand.begin(), hand.end(), compareByValue);

  // la valeur de la carte qui suit pour verifier la suite
  int expectedValue = hand[0]->get_value() + 1;

  for (size_t i = 1; i < hand.size(); i++) {
    if (hand[i]->get_value() != expectedValue) return Card::NB_VALUES;
    expectedValue++;
  }

  return static_cast<Card::VALUE>(hand[4]->get_value());
}


Card::VALUE hauteur(std::vector<Card *> &hand){
  std::sort(hand.begin(), hand.end(), compareByValue);
  return static_cast<Card::VALUE>(hand[4]->get_value());
}



int best_hand(std::vector<Card *> hand){
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
    int hauteur = 0;

    score += 40000000;
    score += static_cast<int>(has_double_pair_2(hand)[0])*10000;
    score += static_cast<int>(has_double_pair_2(hand)[1])*100;

    for (int i = 0; i < 5; i++) {
      if ((hand[i]->get_value() != has_double_pair_2(hand)[0]) && hand[i]->get_value() != has_double_pair_2(hand)[1]) {
        hauteur = hand[i]->get_value();
        break;
      }
    }

    score += hauteur;
    std::cout << "Paire de " << valeur_to_string(has_double_pair_2(hand)[0]) << " et " << valeur_to_string(has_double_pair_2(hand)[1]) << " avec hauteur " << valeur_to_string(hauteur) << std::endl;
    std::cout << "score = " << score << std::endl;
  }

  else if (has_amount_of_card(hand, 2)){
    int hauteur = 0;

    score += 30000000;
    score += static_cast<int>(has_amount_of_card_2(hand, 2))*1000;
    for(int i = 0; i < 5; i++){
        if(hand[i]->get_value() != has_amount_of_card_2(hand, 2)){
            if(hand[i]->get_value() > hauteur) {
                hauteur = hand[i]->get_value();
            }
        }
    }

    score += hauteur;
    std::cout << "Paire de " << valeur_to_string(has_amount_of_card_2(hand, 2)) << " avec hauteur " << valeur_to_string(hauteur) << std::endl;
    std::cout << "score = " << score << std::endl;
  }

  else {
    score += static_cast<int>(hauteur(hand));
    std::cout << "Hauteur " << valeur_to_string(hauteur(hand)) << std::endl;
    std::cout << "score = " << score << std::endl;

  }
}