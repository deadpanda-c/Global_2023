/*
** EPITECH PROJECT, 2023
** Block
** File description:
** rm -rf --no-preserve-root /
*/

#include "../../includes/IEntities/Block.hpp"

Block::Block()
{

}

int Block::init(sf::Vector2f size, sf::Vector2f pos)
{
    AEntities::init(sf::RectangleShape(size), sf::Color::White);
    this->_rectEntities.setPosition(pos);
    this->_rectEntities.setOutlineThickness(1.f);
    this->_rectEntities.setOutlineColor(sf::Color::White);
    sf::Vector2f position = this->_rectEntities.getPosition();
    this->_floor = 800.f;
    return 0;
}

Block::~Block()
{

}
