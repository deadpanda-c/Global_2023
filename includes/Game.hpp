/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
#define GROUND 800

#include "IGame.hpp"
#include "ISelectMenu/HomeMenu.hpp"
#include "ISelectMenu/Settings.hpp"
#include "ISelectMenu/SelectCharacters.hpp"
#include "IEntities/AEntities.hpp"
#include "IEntities/Player.hpp"
#include "IEntities/Block.hpp"
#include "Rooms/Rooms.hpp"

class Game : public IGame {
    public:
        Game();
        ~Game();

        void gameLoop();

    protected:
        sf::RenderWindow _window;
        unsigned short _fps;
        sf::Clock _clock;
        sf::Event _event;
        sf::Vector2u _winSize;

        std::vector<STATE> _state;

        HomeMenu _menu = HomeMenu();
        Settings _opt = Settings();
        SelectCharacters _selectChars = SelectCharacters();

        Rooms _rooms_one;
        Rooms _rooms_two;
        Rooms _rooms_three;
        ROOMS _currentRoom;
        Player _player;
        Block _block;
        std::vector<Block> _someBlocks;

        Buttons _back = Buttons();
        Buttons _settings = Buttons();

        void init();
        void events();
        void update();
        void draw();
};

#endif /* !GAME_HPP_ */
