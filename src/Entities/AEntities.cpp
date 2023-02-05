/*
** EPITECH PROJECT, 2023
** AEntities
** File description:
** man man
*/

#include "../../includes/IEntities/AEntities.hpp"

int AEntities::init(sf::Sprite entities, const std::string &pathname)
{
    this->_filepath = pathname;
    this->_entities = entities;
    std::cout << "[*] Entities created at : " << this->_filepath << std::endl;
    return 0;
}

sf::Vector2f AEntities::getSize() const
{
    return this->_entities.getScale();
}

bool AEntities::isCollidingLeft(const AEntities &other)
{
    sf::Vector2f thisPos = this->_entities.getPosition();
    sf::Vector2f otherPos = other.getSprite().getPosition();
    sf::Vector2f thisSize = this->getSize();
    sf::Vector2f otherSize = other.getSize();

    if ((thisPos.x < otherPos.x + otherSize.x || thisPos.x == otherPos.x + otherSize.x)
            && (thisPos.y < otherPos.y + otherSize.y || thisPos.y == otherPos.y + otherSize.y)
            && (thisPos.y + thisSize.y > otherPos.y || thisPos.y + thisSize.y == otherPos.y))
        return true;
    return false;
}

bool AEntities::isCollidingRight(const AEntities &other)
{
    sf::Vector2f thisPos = this->_entities.getPosition();
    sf::Vector2f otherPos = other.getSprite().getPosition();
    sf::Vector2f thisSize = this->getSize();
    sf::Vector2f otherSize = other.getSize();

    if ((thisPos.x + thisSize.x > otherPos.x || thisPos.x + thisSize.x == otherPos.x)
            && (thisPos.y < otherPos.y + otherSize.y || thisPos.y == otherPos.y + otherSize.y)
            && (thisPos.y + thisSize.y > otherPos.y || thisPos.y + thisSize.y == otherPos.y))
        return true;
    return false;
}

//bool AEntities::isColliding(const AEntities &other)
//{
//    sf::Vector2f thisPos = this->_entities.getPosition();
//    sf::Vector2f otherPos = other.getSprite().getPosition();
//    sf::Vector2f thisSize = this->getSize();
//    sf::Vector2f otherSize = other.getSize();
//
//    if ((thisPos.x < otherPos.x + otherSize.x || thisPos.x == otherPos.x + otherSize.x)
//            && (thisPos.x + thisSize.x > otherPos.x || thisPos.x + thisSize.x == otherPos.x)
//            && (thisPos.y < otherPos.y + otherSize.y || thisPos.y == otherPos.y + otherSize.y)
//            && (thisPos.y + thisSize.y > otherPos.y || thisPos.y + thisSize.y == otherPos.y))
//            return true;
//    return false;
//}

bool AEntities::isColliding(const AEntities &other, int &where)
{
    sf::FloatRect p_bound = this->_entities.getGlobalBounds();
    sf::FloatRect o_bound = other.getRectangle().getGlobalBounds();
    sf::Vector2f posPlayer = this->_entities.getPosition();
    sf::Vector2f sizePlayer = this->getSize();
    sf::Vector2f posObject = other.getRectangle().getPosition();
    sf::Vector2f sizeObject = other.getSize();

    if (o_bound.intersects(p_bound)) {
        std::cout << "[*] Damn, this block is so haaard" << std::endl;
        if ((posPlayer.x + sizePlayer.x) >= posObject.x && (posPlayer.x + sizePlayer.x) <= posObject.x + (sizeObject.x / 2)) {
            where = RIGHT;
        } else if (posPlayer.x < posObject.x + sizeObject.x) {
            where = LEFT;
        } else if ((posPlayer.y + sizePlayer.y) <= posObject.y) {
            where = TOP;
        } else if (posPlayer.y > (posObject.y + sizeObject.y)) {
            where = BOTTOM;
        }
        if (posPlayer.y + sizePlayer.y < posObject.y)
            where = BOTTOM;
        return true;
    }
    return false;
}

int AEntities::init(sf::RectangleShape rectEntities, const sf::Color &color)
{
    this->_color = color;
    this->_rectEntities = rectEntities;
    this->_rectEntities.setOutlineColor(color);
    this->_rectEntities.setFillColor(sf::Color::Black);
    this->_rectEntities.setOutlineThickness(2.5f);
    this->_size = this->_rectEntities.getScale();
    std::cout << "[*] Entities created, It's a rectangle !" << std::endl;
    return 0;
}

void AEntities::update()
{

}

void AEntities::draw(sf::RenderWindow &win) const
{
    win.draw(this->_entities);
}

sf::Sprite AEntities::getSprite() const
{
    return this->_entities;
}

sf::RectangleShape AEntities::getRectangle() const
{
    return this->_rectEntities;
}
