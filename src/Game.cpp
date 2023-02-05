/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Game
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "../includes/Game.hpp"


Game::Game()
{
    _state.push_back(MENU);
    _window.create(sf::VideoMode::getDesktopMode(), "Game");
   _winSize = _window.getSize();
    _fps = 60;
    _window.setFramerateLimit(_fps);
    init();
}

Game::~Game()
{}

void Game::init()
{
    _menu.init("assets/images/bg_menu.png", _winSize);
    _opt.init("assets/images/bg_settings.jpg", _winSize);
    _back.init("assets/images/btn_back.png", sf::Vector2f(20, 20), false);

    this->_rooms_one.init("First Room", ROOMS::ROOM_ONE);
    this->_rooms_two.init("Second Room", ROOMS::ROOM_TWO);
    this->_rooms_three.init("Third Room", ROOMS::ROOM_THREE);
    this->_currentRoom = ROOMS::ROOM_ONE;
}

void Game::update()
{
    if (_state.back() != MENU)
        _back.display = true;
    else
        _back.display = false;
    (_state.back() == MENU) ? _menu.update(_window) : 0;
    (_state.back() == SETTINGS) ? _opt.update(_window) : 0;
    // (_state == C_PLAYER) ? _selectChars.update(_window) : 0;
    (_state.back() == C_PLAYER && this->_currentRoom == ROOMS::ROOM_ONE) ? this->_rooms_one.update() : void();
    (_state.back() == C_PLAYER && this->_currentRoom == ROOMS::ROOM_TWO) ? this->_rooms_one.update() : void();
    (_state.back() == C_PLAYER && this->_currentRoom == ROOMS::ROOM_THREE) ? this->_rooms_one.update() : void();
}

void Game::draw()
{
    (_state.back() == MENU) ? _menu.draw(_window) : 0;
    (_state.back() == SETTINGS) ? _opt.draw(_window) : 0;
    _back.draw(_window);
     //(_state.back() == C_PLAYER) ? _selectChars.draw(_window) : 0;
     (_state.back() == C_PLAYER && this->_currentRoom == ROOMS::ROOM_ONE) ?  this->_rooms_one.draw(this->_window) :void();
}

void Game::events()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Delete)
            _window.close();
    }
    if (_back.isClick(_window, _event) && _state.back() != MENU)
        _state.pop_back();
    (_state.back() == MENU) ? _menu.events(_window, _event, _state) : 0;
    (_state.back() == SETTINGS) ? _opt.events(_window, _event, _state) : 0;
//     (_state.back() == C_PLAYER) ? _selectChars.events(_window, _event) : 0;
}

void Game::gameLoop()
{
    while (_window.isOpen()) {
        events();
        _window.clear();
        update();
        draw();
        _window.display();
    }
}
