/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** ASelectMenu
*/

#include "../../includes/ISelectMenu/ASelectMenu.hpp"

void ASelectMenu::init(const std::string path, sf::Vector2u winSize)
{
    _textureBg.loadFromFile(path);
    _spriteBg.setTexture(_textureBg);
}

int ASelectMenu::draw(sf::RenderWindow &win)
{
    win.draw(_spriteBg);
    return 0;
}
