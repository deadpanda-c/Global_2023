/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** ASelectMenu
*/

#ifndef ASELECTMENU_HPP_
#define ASELECTMENU_HPP_

    #include "ISelectMenu.hpp"
    #include "../Buttons.hpp"

class ASelectMenu : public ISelectMenu {
    public:
        ASelectMenu() = default;
        ~ASelectMenu() = default;

        virtual void init(const std::string path, sf::Vector2u winSize);
        virtual int events(sf::RenderWindow &win, sf::Event &event, std::vector<STATE> &) = 0;
        virtual int update(sf::RenderWindow &win) = 0;
        virtual int draw(sf::RenderWindow &win);

    protected:
        sf::Texture _textureBg;
        sf::Sprite _spriteBg;
};

#endif /* !ASELECTMENU_HPP_ */
