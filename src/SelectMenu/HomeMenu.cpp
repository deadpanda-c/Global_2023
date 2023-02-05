/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** HomeMeu
*/

#include "../../includes/ISelectMenu/HomeMenu.hpp"

void HomeMenu::init(const std::string path, sf::Vector2u winSize)
{
    _textureBg.loadFromFile(path);
    _spriteBg.setTexture(_textureBg);
    _spriteBg.setScale(
        static_cast<float>(winSize.x) / _spriteBg.getLocalBounds().width,
        static_cast<float>(winSize.y) / _spriteBg.getLocalBounds().height
    );
    _spriteBg.setOrigin(
        _spriteBg.getLocalBounds().width / 2.f,
        _spriteBg.getLocalBounds().height / 2.f
    );
    _spriteBg.setPosition(winSize.x / 2.f, winSize.y / 2.f);
    _start.init("assets/images/btn_play.png", sf::Vector2f((winSize.x / 2) - 168, winSize.y / 2 - 100), true);
    _opt.init("assets/images/btn_opt.png", sf::Vector2f((winSize.x / 2) - 168, winSize.y / 2), true);
    _quit.init("assets/images/btn_quit.png", sf::Vector2f((winSize.x / 2) - 168, winSize.y / 2 + 100), true);
}

int HomeMenu::events(sf::RenderWindow &win, sf::Event &event,  std::vector<STATE> &state)
{
    if (_quit.isClick(win, event))
        win.close();
    if (_opt.isClick(win, event)) {
        state.push_back(SETTINGS);
    }
    if (_start.isClick(win, event)) {
        state.push_back(C_PLAYER);
    }
    return 0;
}

int HomeMenu::update(sf::RenderWindow &win)
{
    _start.update(win);
    _opt.update(win);
    _quit.update(win);
    return 0;
}

int HomeMenu::draw(sf::RenderWindow &win)
{
    win.draw(_spriteBg);
    _start.draw(win);
    _opt.draw(win);
    _quit.draw(win);
    return 0;
}
