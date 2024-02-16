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

bool couleur(std::vector<Card *> hand)
{

    if (hand.empty())
    {
        return false;
    }

    hand.begin();

    for (Card *i : hand)
    {

        if (i->get_color() != hand[0]->get_color()) {
            return false;
        }
    }
    return true;
}

bool sequence(std::vector<Card *> hand)
{

    hand.begin();
    for(Card *i : hand)
    {
        if (i->get_value() != hand[0+1]->get_value()) {
            return true;
        }
        else 
        {
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
    { // ajouter les 5 premiere carte du jeu a la main
        hand.push_back(&myGame.game[i]);
    }

    display_hand(hand);

    best_hand(hand);

    if (couleur(hand)) {
        std::cout << "Toutes les cartes ont la meme couleur." << std::endl;
    } else {
        std::cout << "Les cartes n'ont pas la meme couleur." << std::endl;
    }


    // // Ne pas oublier de libere la memoire (uniquement si on fait "new ...")
    // for (Card *i : hand)
    //    delete i;

    return 0;
}
