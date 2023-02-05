/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** HomeMenu
*/

#ifndef HOMEMENU_HPP_
#define HOMEMENU_HPP_

    #include "ASelectMenu.hpp"
    #include "../Buttons.hpp"

class HomeMenu : public ASelectMenu {
    public:
        HomeMenu() {};
        ~HomeMenu() {};

        void init(const std::string path, sf::Vector2u winSize);
        int events(sf::RenderWindow &win, sf::Event &event, std::vector<STATE> &);
        int update(sf::RenderWindow &win);
        int draw(sf::RenderWindow &win);

    protected:
        sf::Vector2f _sizeBg;
        sf::Texture _textureBg;
        sf::Sprite _spriteBg;

        Buttons _start = Buttons();
        Buttons _opt = Buttons();
        Buttons _quit = Buttons();
};

#endif /* !HOMEMENU_HPP_ */
