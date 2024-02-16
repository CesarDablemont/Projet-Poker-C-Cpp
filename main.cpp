#include <iostream>
#include <vector>
#include "card.h"

/* ***************************************************************************
  Display
*************************************************************************** */
void display_game(Game myGame)
{
    std::cout << "game: ";
    for (const Card &card : myGame.game)
    {
        // Use const_cast to call to_string() on const object
        std::cout << const_cast<Card *>(&card)->to_string() << " ";
    }
    std::cout << std::endl;
}

void display_hand(std::vector<Card *> hand)
{
    std::cout << "hand: ";
    for (Card *i : hand)
        std::cout << i->to_string() << ' ';
    std::cout << std::endl;
}

/* ***************************************************************************
  Hand tests
*************************************************************************** */
bool has_pair(std::vector<Card *> hand)
{
}

bool couleur(const std::vector<Card> &hand)
{

    if (hand.empty())
    {
        return false;
    }

    hand.begin();

    for (const Card &other : hand)
    {

        if (hand.Card.COLOR != hand.begin()) {
            return false;
        }
    }
    return true;
}

int best_hand(std::vector<Card *> hand)
{
    return 0;
}

/* ***************************************************************************
  MAIN
*************************************************************************** */
int main()
{
    // std::cout << "2 de coeur" << std::endl;
    // Card c1 = Card(Card::DEUX, Card::COEUR); // 2 de coeur
    // std::cout << "value: " << c1.get_value() << ", color: " << c1.get_color() << std::endl;
    // std::cout << "value: " << c1.get_value() << ", color: " << c1.colors[c1.get_color()] << std::endl;

    // init the game
    Game myGame;
    display_game(myGame);

    // Shuffle the deck
    myGame.shuffe();
    display_game(myGame);

    std::vector<Card *> hand;
    for (int i = 0; i < 5; i++)
    {
        // hand.push_back(myGame.game[i]);
    }
    // hand.push_back(new Card(Card::UN, Card::COEUR));
    // hand.push_back(new Card(Card::DEUX, Card::COEUR));
    // hand.push_back(new Card(Card::DEUX, Card::TREFLE));
    // hand.push_back(new Card(Card::TROIS, Card::COEUR));
    // hand.push_back(new Card(Card::QUATRE, Card::COEUR));
    display_hand(hand);

    best_hand(hand);

    // Ne pas oublier de libere la memoire
    for (Card *i : hand)
        delete i;

    std::cout << "This is the end, just ..." << std::endl;

    std::vector<Card> deck = {Card(Card:: PIQUE), Card(Card::PIQUE), Card(Card::PIQUE),Card(Card::PIQUE),Card(Card::PIQUE)};

    if (couleur(deck)) {
        std::cout << "Toutes les cartes ont la meme couleur." << std::endl;
    } else {
        std::cout << "Les cartes n'ont pas la meme couleur." << std::endl;
    }

    return 0;
}
