/*
** EPITECH PROJECT, 2023
** src/Player
** File description:
** epitech > 42
*/

#include "../../includes/Game.hpp"
#include "../../includes/IEntities/AEntities.hpp"
#include "../../includes/IEntities/Player.hpp"

Player::Player()
{

}

Player::Player(const std::string &pathname)
{
    if (!this->_texture.loadFromFile(SPRITE))
        return;
    this->_entities.setTexture(this->_texture);
    AEntities::init(this->_entities, pathname);
}

int Player::init(const std::string &pathname)
{
    if (!this->_texture.loadFromFile(SPRITE))
        return -1;
    this->_entities.setTexture(this->_texture);
    std::cout << "[*] SPRITE IS INIT !" << std::endl;
    AEntities::init(this->_entities, pathname);
    this->_floor = 800.f;
    this->_ceiling = this->_floor - 120;
    this->_isFalling = false;
    this->_gravity = 40;
    this->_whereCollid = -1;
    return 0;
}

void Player::setBlock(std::vector<Block> &someBlocks)
{
    this->_someBlocks = someBlocks;
    std::cout << "[*] Blocks are set up for the player" << std::endl;
}

void Player::update()
{
    this->walk();
    this->jump();
}

int Player::walk()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        for (Block block : this->_someBlocks) {
            if (this->isColliding(block, _whereCollid))
                if (this->_whereCollid == RIGHT) {
                    this->_entities.move(-5, 0);
                    return -1;
                }
        }
        this->_entities.move(7, 0);
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        for (Block block : this->_someBlocks) {
            if (this->isColliding(block, _whereCollid))
                if (this->_whereCollid == LEFT) {
                    this->_entities.move(5, 0);
                    return -1;
                }
        }
        this->_entities.move(-7, 0);
    }
    return 0;
}

int Player::jump()
{
    sf::Vector2f pos = this->_entities.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->_isFalling) {
        std::cout << "OMG he's flying" << std::endl;
        for (Block block : this->_someBlocks) {
            if (this->isColliding(block, _whereCollid)) {
                if (this->_whereCollid == TOP) {
                    this->_entities.move(0, -3);
                    return -1;
                }
            }
        }
        if (pos.y > this->_ceiling) {
            this->_entities.move(0, (this->_gravity * 0.3) * -1);
            this->_gravity--;
        } else {
            std::cout << "Ouch, it's the ceiling !" << std::endl;
            this->_isFalling = true;
            return this->fall();
        }
    } else {
        return this->fall();
    }
    return 0;
}

int Player::fall()
{
    sf::Vector2f pos = this->_entities.getPosition();
    this->_isFalling = true;
    this->_gravity = 40;
    if (this->_isFalling) {
        for (Block block : this->_someBlocks)
            if (this->isColliding(block, _whereCollid)) {
                if (this->_whereCollid == BOTTOM) {
                    std::cout << "Bro what do you mean" << std::endl;
                    return -1;
                }
            }
        if (pos.y < this->_floor) { // is higher than the floor
            std::cout << "HIGHER" << std::endl;
            this->_entities.move(0, (this->_gravity * 0.3));
            this->_gravity++;
        } else {
            this->_isFalling = false;
        }
    }
    return 0;
}

int Player::attack()
{
    return 0;
}

Player::~Player()
{

}
