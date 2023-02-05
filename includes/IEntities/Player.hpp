/*
** EPITECH PROJECT, 2023
** Player
** File description:
** don't forget to free at the end
*/

#pragma once
#include "AEntities.hpp"
#include "Block.hpp"
#define SPRITE "assets/images/sprite_square.png"


class Player : public AEntities {
    public:
        Player();
        Player(const std::string &); // set the pathname
        ~Player();
        int init(const std::string &);
        void setBlock(std::vector<Block> &);
        void update();
        int walk();
        int jump();
        int fall();
        int attack();
    private:
        sf::RenderWindow *_win;
        float _floor;
        float _ceiling;
        bool _isFalling;
        int _gravity;
        int _whereCollid;
        std::vector <Block> _someBlocks;
};
