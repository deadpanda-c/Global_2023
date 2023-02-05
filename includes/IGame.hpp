/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Game
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>

    #include "enum.hpp"

class IGame {
    public:
        IGame() = default;
        virtual ~IGame() = default;

        virtual void init() = 0;
        virtual void events() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
};

#endif /* !IGAME_HPP_ */
