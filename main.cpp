#include <iostream>
#include "card.h"

int main()
{
    std::cout << "Run ...." << std::endl;
    
    Card c1 = Card(2, 1); // 2 de coeur
    std::cout << "value: " << c1.get_value() << std::endl;
    std::cout << "color: " << c1.get_color() << std::endl;

    std::cout << "This is the end, just ..." << std::endl;
}
