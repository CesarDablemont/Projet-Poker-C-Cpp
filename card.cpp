//
// Created by yves on 02/12/2022.
//
#include <random>
#include <algorithm>
#include <ctime>
#include <chrono>

#include "card.h"

Card::Card()
{
    this->value = 0;
    this->color = 0;
}

Card::Card(int value, int color)
{
    this->value = value;
    this->color = color;
}

Card::Card(const Card &other)
{
    this->value = other.get_value();
    this->color = other.get_color();
}

Card::Card(Card &&other)
{
    this->value = other.get_value();
    this->color = other.get_color();
}

Card &Card::operator=(const Card &other)
{

    if (this != &other)
    {
        this->value = other.get_value();
        this->color = other.get_color();
    }
    return *this;
}

Card &Card::operator=(Card &&other)
{

    if (this != &other)
    {
        this->value = other.get_value();
        this->color = other.get_color();
    }
    return *this;
}

Card::~Card()
{
}

std::string Card::to_string()
{
    std::string sv;
    switch (this->value)
    {
    case Card::VALET:
        sv = std::string("V");
        break;
    case Card::DAME:
        sv = std::string("D");
        break;
    case Card::ROI:
        sv = std::string("R");
        break;
    case Card::AS:
        sv = std::string("A");
        break;
    default:
        sv = std::to_string(this->value);
        break;
    }
    return "(" + sv + "/" + Card::colors[this->color] + ")";
}

Game::Game()
{
    for (int i = 0; i < Card::NB_COLORS; i++)
    {
        for (int j = Card::DEUX; j < Card::NB_VALUES; j++)
        {
            this->game.push_back(Card(j, i));
        }
    }
}
Game::~Game()
{
}

void Game::shuffe()
{
    // Card c;

    // srand((unsigned)time(NULL));
    // for (int i = 0; i < 128 * 16; i++)
    // {
    //     std::shuffle(this->game.begin(), this->game.end(), std::random_device());
    // }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 g(seed);

    for (int i = 0; i < 128 * 16; i++)
    {
        std::shuffle(this->game.begin(), this->game.end(), g);
    }
}
