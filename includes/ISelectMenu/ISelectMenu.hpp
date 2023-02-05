/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** ISelectMenu
*/

#ifndef SELECTMENU_HPP_
    #define SELECTMENU_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>

    #include "../enum.hpp"

class ISelectMenu {
    public:
        ISelectMenu() = default;
        virtual ~ISelectMenu() = default;

        virtual void init(const std::string, sf::Vector2u) = 0;
        virtual int events(sf::RenderWindow &, sf::Event &, std::vector<STATE> &) = 0;
        virtual int update(sf::RenderWindow &) = 0;
        virtual int draw(sf::RenderWindow &) = 0;

};

#endif /* !SELECTMENU_HPP_ */
