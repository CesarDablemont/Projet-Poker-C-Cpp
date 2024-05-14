#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#include "fonction.hpp"


/*
Logique best_hand

conbinaison: 0-8 (paire, carré, ...)
0: hauteur
1: paire
2: double paire
3: brelan
4: suite
5: couleur
6: full
7: carré
8: quinte flush

1e valeur combinaison (1-15) si carré carré de quoi ?
2e valeur combinaison (1-15) si cas double paire ou full besoin 2 valeur
1e valeur hauteur
2e valeur hauteur
3e valeur hauteur
4e valeur hauteur 
5e valeur hauteur // jusque 5 si commun :as, roi, dame, valet puis la 5e differente entre les 2 joueur

ou score en int mis bout a bout
{0-8}{0-14}{0-14}{0-14}{0-14}{0-14}{0-14}{0-14} = 15 chiffre

ex de main: (R/T) (A/K) (R/C) (6/C) (10/C) = Paire de ROI avec hauteur AS puis hauteur 10 puis hauteur 6
score = 1 13 00 14 10 06 00 00
1: paire, 13: roi, 00: pas de 2e paire, 14: hauteur As, 10: 2e hauteur, 06: 3e hauteur, 00: 4e, 00: 5e
score final unique = 113001410060000


nécessite: __int64 score = 0;

utiliser une map dans les fonctions plutot que le vecteur
https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

*/


__int64 score_hand(std::vector<Card *> hand){
  __int64 score = 0;

  std::map<Card::VALUE, int> valueMap;
  std::map<Card::COLOR, int> colorMap;

  // map pour les valeurs
  for (int i = 0; i < hand.size(); i++) {
    auto value = hand[i]->get_value();
    Card::VALUE cardValue = static_cast<Card::VALUE>(value);
    valueMap[cardValue]++;
  }

  // map pour les couleurs
  for (int i = 0; i < hand.size(); i++) {
    auto color = hand[i]->get_color();
    Card::COLOR cardColor = static_cast<Card::COLOR>(color);
    colorMap[cardColor]++;
  }

  // display_map(valueMap);
  // display_map(colorMap);

  Card::VALUE paire = has_amount_of_card(valueMap, 2);
  Card::VALUE brelan = has_amount_of_card(valueMap, 3);
  Card::VALUE carre = has_amount_of_card(valueMap, 4);
  std::vector<Card::VALUE> double_paire = has_double_pair(valueMap);
  Card::VALUE suite = sequence(valueMap);
  Card::COLOR couleur = color(colorMap);


  // Quinte flush
  if((suite != Card::NB_VALUES) && (couleur != Card::NB_COLORS)){
    score += 8e14;
    score += suite * 1e12;
    valueMap.clear();
  }

  // Carré
  else if(carre != Card::NB_VALUES){
    score += 7e14;
    score += carre * 1e12;
    valueMap.erase(carre);
  }

  // Full
  else if((brelan != Card::NB_VALUES) && (paire != Card::NB_VALUES)){
    score += 6e14;
    score += brelan * 1e12;
    score += paire * 1e10;
    valueMap.erase(brelan);
    valueMap.erase(paire);
  }

  // Couleur
  else if(couleur != Card::NB_COLORS){
    score += 5e14;
  }

  // Suite
  else if(suite != Card::NB_VALUES){
    score += 4e14;
    score += suite * 1e12;
    valueMap.clear();
  }

  // Brelan
  else if(brelan != Card::NB_VALUES){
    score += 3e14;
    score += brelan * 1e12;
    valueMap.erase(brelan);
  }

  // Double paire
  else if(!double_paire.empty()){
    score += 2e14;
    score += double_paire[0] * 1e10;
    score += double_paire[1] * 1e12;
    valueMap.erase(double_paire[0]);
    valueMap.erase(double_paire[1]);
  }

  // Paire
  else if(paire != Card::NB_VALUES){
    score += 1e14;
    score += paire * 1e12;
    valueMap.erase(paire);
  }


  // Hauteur avec toute les cartes qui ne sont pas compris dans les combinaisons
  int multiplicateur = 100000000;
  for (auto itr = valueMap.rbegin(); itr != valueMap.rend(); ++itr) { // rbegin et rend pour reverse begin et end
      score += itr->first * multiplicateur;
      multiplicateur /= 100;
  }

  return score;
}



Card::VALUE has_amount_of_card(std::map<Card::VALUE, int> map, int number) {

  // a-t-on une valeur qui vaux number
  auto it = std::find_if(map.begin(), map.end(), [number](const auto &pair) {
    return pair.second == number;
  });

  // Si oui on renvoie la clé
  if (it != map.end()){
    return it->first;
  }

  return Card::NB_VALUES;
}


std::vector<Card::VALUE> has_double_pair(std::map<Card::VALUE, int> map) {

    // Recherche des deux paires
    std::vector<Card::VALUE> doublePairs;
    for (const auto& pair : map) {
        if (pair.second == 2) {
            doublePairs.push_back(pair.first);
        }
    }

    // Renvoi des valeurs des deux paires
    if (doublePairs.size() == 2) {
        return doublePairs;
    } else {
        // sinon un vecteur vide
        return std::vector<Card::VALUE>();
    }
}

Card::VALUE sequence(std::map<Card::VALUE, int> map) {

  if(map.size() < 5) return Card::NB_VALUES;
  // std::next(itr) != map.end() jusqu'a l'avant dernier
  for (auto itr = map.begin(); std::next(itr) != map.end(); ++itr) {
    if ((itr->first + 1) != std::next(itr)->first) return Card::NB_VALUES;
  }

  return map.rbegin()->first;
}

Card::COLOR color(std::map<Card::COLOR, int> map) {

  if(map.size() > 1) return Card::NB_COLORS;
  return map.begin()->first;
}