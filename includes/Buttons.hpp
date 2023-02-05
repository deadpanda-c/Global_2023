/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Buttons
*/

#ifndef BUTTONS_HPP_
#define BUTTONS_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Buttons {
    public:
        Buttons() {};
        ~Buttons() {};

        void init(std::string path, sf::Vector2f pos, bool display);
        bool isClick(sf::RenderWindow &win, sf::Event &event);
        void update(sf::RenderWindow &win);
        void draw(sf::RenderWindow &win);

        bool display;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::IntRect _rect;
};

#endif /* !BUTTONS_HPP_ */
