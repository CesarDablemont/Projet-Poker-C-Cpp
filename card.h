//
// Created by yves on 02/12/2022.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H

#include <vector>

class Card {

public:
    enum COLOR {PIQUE=0, COEUR, CARREAU, TREFLE, NB_COLORS} ;
    enum VALUE {UN=1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI, AS, NB_VALUES} ;
    const std::string colors[NB_COLORS] = {"P", "C", "K", "T"} ;

    Card() ;
    Card(int value, int color) ;

    Card(const Card& other) ;
    Card(Card&& other) ;

    ~Card() ;

    std::string to_string() ;

    Card& operator=(const Card& other) ;
    Card& operator=(Card&& other) ;

    int get_color() const { return this->color ; }
    int get_value() const { return this->value ; }

    bool operator<(const Card& other) const { return this->get_value() < other.get_value() ; }

    static bool comp(const Card& c1, const Card& c2) { return c1 < c2 ; }


private:
    int value ;
    int color ;
} ;

class Game {
 enum _ {NB_CARDS=Card::NB_COLORS*Card::NB_VALUES};
public:
    Game() ;
    ~Game() ;

    void shuffe() ;

public:
    std::vector<Card> game ;
};
#endif //POKER_CARD_H
