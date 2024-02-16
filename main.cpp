#include <iostream>
#include <vector>
#include <algorithm>
#include "card.h"

/* ***************************************************************************
  DISPLAY
*************************************************************************** */
#pragma region
void display_game(Game myGame)
{
    std::cout << "game: ";
    for (const Card &card : myGame.game)
    {
        // Utilisez const_cast pour utilisé to_string()
        std::cout << const_cast<Card *>(&card)->to_string() << " ";
    }
    std::cout << std::endl;
}

void display_hand(std::vector<Card *> hand)
{
    if (hand.empty())
    {
        std::cout << "Empty hand" << std::endl;
        return;
    }

    for (Card *i : hand)
        std::cout << i->to_string() << ' ';
    std::cout << std::endl;
}
#pragma endregion

/* ***************************************************************************
  HAND TESTS
*************************************************************************** */
#pragma region

bool has_pair(std::vector<Card *> hand)
{
}

bool color(std::vector<Card *> hand)
{

    if (hand.empty())
    {
        return false;
    }

    hand.begin();

    for (Card *i : hand)
    {

        if (i->get_color() != hand[0]->get_color())
        {
            return false;
        }
    }
    return true;
}

bool compareByValue(const Card *card1, const Card *card2)
{
    return card1->get_value() < card2->get_value();
}

bool sequence(const std::vector<Card *> &hand)
{
    if (hand.empty())
    {
        // Empty hand, not a sequence
        return false;
    }

    // trier d'abord les cartes pour que la fonction fonctionne correctement
    // std::sort(hand.begin(), hand.end(), compareByValue);

    int expectedValue = hand[0]->get_value() + 1; // Expected value for the next card

    for (size_t i = 1; i < hand.size(); i++)
    {
        if (hand[i]->get_value() != expectedValue)
        {
            // Values are not in sequence
            return false;
        }
        expectedValue++; // Update the expected value for the next iteration
    }

    // All values are in sequence
    return true;
}

int best_hand(std::vector<Card *> hand)
{
    return 0;
}
#pragma endregion

/* ***************************************************************************
  TEST HAND TESTS
*************************************************************************** */
#pragma region
void test_best_hand()
{
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
    hand2.push_back(new Card(Card::SIX, Card::TREFLE));

    std::vector<Card *> hand3;
    hand3.push_back(new Card(Card::CINQ, Card::PIQUE));
    hand3.push_back(new Card(Card::DEUX, Card::TREFLE));
    hand3.push_back(new Card(Card::UN, Card::CARREAU));
    hand3.push_back(new Card(Card::QUATRE, Card::COEUR));
    hand3.push_back(new Card(Card::TROIS, Card::PIQUE));

    std::cout << "Debut des test." << std::endl;
    // std::cout << "Hand 1: ";
    // display_hand(hand);
    // std::cout << "Hand 2: ";
    // display_hand(hand2);

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

    for (Card *i : hand)
        delete i;
    for (Card *i : hand2)
        delete i;

    std::cout << "Tout les test ont etais passe" << std::endl;
}

#pragma endregion

/* ***************************************************************************
  MAIN
*************************************************************************** */
#pragma region
int main()
{
    // std::cout << "2 de coeur" << std::endl;
    // Card c1 = Card(Card::DEUX, Card::COEUR); // 2 de coeur
    // std::cout << "value: " << c1.get_value() << ", color: " << c1.get_color() << std::endl;
    // std::cout << "value: " << c1.get_value() << ", color: " << c1.colors[c1.get_color()] << std::endl;

    // Lancer le jeu
    Game myGame;
    // display_game(myGame);

    // Mélanger le jeu
    myGame.shuffe();
    // display_game(myGame);

    // Crée une main et y ajouter les 5 premiere carte du jeu
    std::vector<Card *> hand;
    for (int i = 0; i < 5; i++)
    {
        hand.push_back(&myGame.game[i]);
    }
    // display_hand(hand);

    test_best_hand();

    // // Ne pas oublier de libere la memoire (uniquement si on fait "new ...")
    // for (Card *i : hand)
    //    delete i;

    return 0;
}
#pragma endregion