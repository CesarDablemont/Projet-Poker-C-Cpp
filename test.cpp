#include <iostream>
#include <vector>
#include <cassert>

#include "card.h"
#include "display.hpp"
#include "fonction.hpp"

int main(){


  std::vector<Card *> in_0;
  in_0.push_back(new Card(Card::DEUX, Card::CARREAU));
  in_0.push_back(new Card(Card::TROIS, Card::COEUR));
  in_0.push_back(new Card(Card::QUATRE, Card::COEUR));
  in_0.push_back(new Card(Card::CINQ, Card::TREFLE));
  in_0.push_back(new Card(Card::VALET, Card::PIQUE));
  __int64 out_0 = 1105040302;
  std::string out2_0 = "Hauteur Valet puis 5 puis 4 puis 3 puis 2.";

  std::vector<Card *> in_1;
  in_1.push_back(new Card(Card::CINQ, Card::COEUR));
  in_1.push_back(new Card(Card::DEUX, Card::COEUR));
  in_1.push_back(new Card(Card::TROIS, Card::COEUR));
  in_1.push_back(new Card(Card::QUATRE, Card::COEUR));
  in_1.push_back(new Card(Card::CINQ, Card::TREFLE));
  __int64 out_1 = 105000403020000;
  std::string out2_1 = "Paire de 5 avec hauteur 4 puis 3 puis 2.";

  std::vector<Card *> in_2;
  in_2.push_back(new Card(Card::DEUX, Card::PIQUE));
  in_2.push_back(new Card(Card::ROI, Card::TREFLE));
  in_2.push_back(new Card(Card::ROI, Card::CARREAU));
  in_2.push_back(new Card(Card::DAME, Card::COEUR));
  in_2.push_back(new Card(Card::DAME, Card::PIQUE));
  __int64 out_2 = 213120200000000;
  std::string out2_2 = "Double paire de Roi et de Dame avec hauteur 2.";

  std::vector<Card *> in_3;
  in_3.push_back(new Card(Card::ROI, Card::PIQUE));
  in_3.push_back(new Card(Card::ROI, Card::TREFLE));
  in_3.push_back(new Card(Card::ROI, Card::CARREAU));
  in_3.push_back(new Card(Card::DAME, Card::PIQUE));
  in_3.push_back(new Card(Card::DEUX, Card::COEUR));
  __int64 out_3 = 313001202000000;
  std::string out2_3 = "Brelan de Roi avec hauteur Dame puis 2.";

  std::vector<Card *> in_4;
  in_4.push_back(new Card(Card::CINQ, Card::PIQUE));
  in_4.push_back(new Card(Card::DEUX, Card::TREFLE));
  in_4.push_back(new Card(Card::SIX, Card::CARREAU));
  in_4.push_back(new Card(Card::QUATRE, Card::COEUR));
  in_4.push_back(new Card(Card::TROIS, Card::PIQUE));
  __int64 out_4 = 406000000000000;
  std::string out2_4 = "Suite en 6.";

  std::vector<Card *> in_5;
  in_5.push_back(new Card(Card::TROIS, Card::COEUR));
  in_5.push_back(new Card(Card::NEUF, Card::COEUR));
  in_5.push_back(new Card(Card::VALET, Card::COEUR));
  in_5.push_back(new Card(Card::DAME, Card::COEUR));
  in_5.push_back(new Card(Card::SEPT, Card::COEUR));
  __int64 out_5 = 500001211090703;
  std::string out2_5 = "Couleur avec hauteur Dame puis Valet puis 9 puis 7 puis 3.";

  std::vector<Card *> in_6;
  in_6.push_back(new Card(Card::ROI, Card::PIQUE));
  in_6.push_back(new Card(Card::ROI, Card::TREFLE));
  in_6.push_back(new Card(Card::ROI, Card::CARREAU));
  in_6.push_back(new Card(Card::DAME, Card::COEUR));
  in_6.push_back(new Card(Card::DAME, Card::PIQUE));
  __int64 out_6 = 613120000000000;
  std::string out2_6 = "Full de Roi et de Dame.";

  std::vector<Card *> in_7;
  in_7.push_back(new Card(Card::ROI, Card::PIQUE));
  in_7.push_back(new Card(Card::ROI, Card::TREFLE));
  in_7.push_back(new Card(Card::ROI, Card::CARREAU));
  in_7.push_back(new Card(Card::ROI, Card::COEUR));
  in_7.push_back(new Card(Card::DAME, Card::PIQUE));
  __int64 out_7 = 713001200000000;
  std::string out2_7 = "Carre de Roi avec hauteur Dame.";

  std::vector<Card *> in_8;
  in_8.push_back(new Card(Card::DEUX, Card::COEUR));
  in_8.push_back(new Card(Card::TROIS, Card::COEUR));
  in_8.push_back(new Card(Card::QUATRE, Card::COEUR));
  in_8.push_back(new Card(Card::CINQ, Card::COEUR));
  in_8.push_back(new Card(Card::SIX, Card::COEUR));
  __int64 out_8 = 806000000000000;
  std::string out2_8 = "Quinte flush en 6.";



  std::vector<std::vector<Card *>> inputs = {
    in_0, in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8
  };
  std::vector<__int64> outputs = {
    out_0, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8
  };
  std::vector<std::string> outputs2 = {
    out2_0, out2_1, out2_2, out2_3, out2_4, out2_5, out2_6, out2_7, out2_8
  };

  std::cout << "Debut des tests de score_hand()" << std::endl;
  for(int i = 0; i < inputs.size(); i++){
    assert(score_hand(inputs[i]) == outputs[i]);
  }

  std::cout << "Debut des tests de score_to_text()" << std::endl;
  for(int i = 0; i < inputs.size(); i++){
    assert(score_to_text(outputs[i]) == outputs2[i]);
  }

  std::cout << "Debut des tests de score_hand() et score_to_text() simultanement" << std::endl;
  for(int i = 0; i < inputs.size(); i++){
    assert(score_to_text(score_hand(inputs[i])) == outputs2[i]);
  }

  std::cout << "Tout les test ont etais passe" << std::endl;

  for (Card *i : in_0) delete i;
  for (Card *i : in_1) delete i;
  for (Card *i : in_2) delete i;
  for (Card *i : in_3) delete i;
  for (Card *i : in_4) delete i;
  for (Card *i : in_5) delete i;
  for (Card *i : in_6) delete i;
  for (Card *i : in_7) delete i;
  for (Card *i : in_8) delete i;
}