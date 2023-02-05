/*
** EPITECH PROJECT, 2023
** IEntities
** File description:
** code on paper!
*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class IEntities {
    public:
        IEntities() = default;
        ~IEntities() = default;
        virtual int init(sf::Sprite, const std::string &) = 0;
        virtual void update() = 0;
        virtual void draw(sf::RenderWindow &win) const = 0;
        virtual int walk() = 0;
        virtual int jump() = 0;
        virtual int attack() = 0;
};
