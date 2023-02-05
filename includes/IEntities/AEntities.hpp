/*
** EPITECH PROJECT, 2023
** includes/AEntities
** File description:
** no, real programmers use cat
*/

#pragma once
#include "IEntities.hpp"
#include <string>
#include <iostream>

#define TOP 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 3

class AEntities : public IEntities {
    public:
        AEntities() = default;
        ~AEntities() = default;
        virtual int init(sf::Sprite , const std::string &);
        virtual int init(sf::RectangleShape rectEntities, const sf::Color& color);
        virtual void update();
        virtual void draw(sf::RenderWindow&) const;
        virtual sf::Sprite getSprite() const;
        virtual sf::Vector2f getSize() const;
        virtual int walk() = 0;
        virtual int jump() = 0;
        virtual int attack() = 0;
        virtual bool isCollidingLeft(const AEntities &);
        virtual bool isCollidingRight(const AEntities &);
        virtual bool isColliding(const AEntities &, int &);
        virtual sf::RectangleShape getRectangle() const;
    protected:
        sf::RectangleShape _rectEntities;
        std::string _filepath;
        sf::Sprite _entities;
        sf::Texture _texture;
        sf::Color _color;
        sf::Vector2f _size;
};
