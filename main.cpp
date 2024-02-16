#include <iostream>
#include "card.h"

int best_hand()
{
    return 0;
}

int main()
{
    std::cout << "Run ...." << std::endl;

    std::cout << "2 de coeur" << std::endl;
    Card c1 = Card(Card::DEUX, Card::COEUR); // 2 de coeur
    std::cout << "value: " << c1.get_value() << ", color: " << c1.get_color() << std::endl;
    std::cout << "value: " << c1.get_value() << ", color: " << c1.colors[c1.get_color()] << std::endl;

    std::cout << "This is the end, just ..." << std::endl;
}
