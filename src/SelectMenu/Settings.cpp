/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Settings
*/

#include "../../includes/ISelectMenu/Settings.hpp"

void Settings::init(const std::string path, sf::Vector2u winSize)
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
}

int Settings::events(sf::RenderWindow &win, sf::Event &event,  std::vector<STATE> &state)
{
    return 0;
}

int Settings::update(sf::RenderWindow &win)
{
    return 0;
}

int Settings::draw(sf::RenderWindow &win)
{
    win.draw(_spriteBg);
    return 0;
}
