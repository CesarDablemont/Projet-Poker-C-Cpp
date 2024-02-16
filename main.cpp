#include <iostream>
#include <vector>
#include "card.h"

int best_hand(std::vector<Card *> hand)
{
    return 0;
}

bool couleur(const std::vector<Card>& hand) {
    
    if (hand.empty()) {
        return false;
    }

    int colorReference = hand.begin();

    for (const Card& other : hand) {

        if (hand.colors != hand.begin()) {
            return false;
        }
    }
    return true;
}

int main() {
    
    std::vector<Card> deck = {Card(Card:: PIQUE), Card(Card::PIQUE), Card(Card::PIQUE),Card(Card::PIQUE),Card(Card::PIQUE};

    if (couleur(deck)) {
        std::cout << "Toutes les cartes ont la meme couleur." << std::endl;
    } else {
        std::cout << "Les cartes n'ont pas la meme couleur." << std::endl;
    }

    return 0;
}

int main()
{
    std::cout << "Run ...." << std::endl;

    // std::cout << "2 de coeur" << std::endl;
    // Card c1 = Card(Card::DEUX, Card::COEUR); // 2 de coeur
    // std::cout << "value: " << c1.get_value() << ", color: " << c1.get_color() << std::endl;
    // std::cout << "value: " << c1.get_value() << ", color: " << c1.colors[c1.get_color()] << std::endl;

    std::vector<Card *> hand;
    hand.push_back(new Card(Card::UN, Card::COEUR));
    hand.push_back(new Card(Card::DEUX, Card::COEUR));
    hand.push_back(new Card(Card::DEUX, Card::TREFLE));
    hand.push_back(new Card(Card::TROIS, Card::COEUR));
    hand.push_back(new Card(Card::QUATRE, Card::COEUR));

    for (Card *i : hand)
        std::cout << i << ' ';
    std::cout << std::endl;

    best_hand(hand);

    // Ne pas oublier de libere la memoire
    for (Card *i : hand)
        delete i;

    std::cout << "This is the end, just ..." << std::endl;
}
