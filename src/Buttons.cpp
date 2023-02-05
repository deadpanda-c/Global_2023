/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Buttons
*/

#include "../includes/Buttons.hpp"

void Buttons::init(std::string path, sf::Vector2f pos, bool disp)
{
    display = disp;
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(pos);
    _rect = (sf::IntRect){0, 0, static_cast<int>(_sprite.getGlobalBounds().width), static_cast<int>(_sprite.getGlobalBounds().height) / 2};
    _sprite.setTextureRect(_rect);
}

bool Buttons::isClick(sf::RenderWindow &win, sf::Event &event)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
    sf::FloatRect container = _sprite.getGlobalBounds();

    if (container.contains(mousePosition.x, mousePosition.y)) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            return true;
    }
    return false;
}

void Buttons::update(sf::RenderWindow &win)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
    sf::FloatRect container = _sprite.getGlobalBounds();

    if (container.contains(mousePosition.x, mousePosition.y))
        _rect.top = _sprite.getGlobalBounds().height;
    else
        _rect.top = 0;
    _sprite.setTextureRect(_rect);
}

void Buttons::draw(sf::RenderWindow &win)
{
    if (display)
        win.draw(_sprite);
}
