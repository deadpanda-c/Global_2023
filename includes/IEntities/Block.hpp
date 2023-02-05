/*
** EPITECH PROJECT, 2023
** Block
** File description:
** C-x C-c
*/

#pragma once
#include "AEntities.hpp"

class Block : public AEntities {
    public:
        Block();
        ~Block();
        int init(sf::Vector2f, sf::Vector2f);
        int walk() { return 0; };
        int jump() { return 0; };
        int attack() { return 0; };
    private:
        sf::RenderWindow *_win;
        sf::Vector2f _size;
        float _floor;

};
