/*
** EPITECH PROJECT, 2023
** Rooms
** File description:
** xkcd.com/378
*/

#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <vector>
#include "../enum.hpp"
#include "../IEntities/Player.hpp"
#include "../IEntities/Block.hpp"

class Rooms {
    public:
        Rooms();
        Rooms(const std::string &, ROOMS room);
        void init(const std::string &, ROOMS room);
        void update();
        void draw(sf::RenderWindow &);
        ~Rooms();
    protected:
        Player _player;
        std::string _roomName;
        ROOMS _room;
        std::vector<Block> _blockList;
};
