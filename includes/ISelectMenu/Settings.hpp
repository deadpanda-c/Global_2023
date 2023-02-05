/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_

    #include "ASelectMenu.hpp"

class Settings : public ASelectMenu {
    public:
        Settings() {};
        ~Settings() {};

        void init(const std::string path, sf::Vector2u winSize);
        int events(sf::RenderWindow &win, sf::Event &event,  std::vector<STATE> &state);
        int update(sf::RenderWindow &win);
        int draw(sf::RenderWindow &win);

    protected:

        sf::Vector2f _sizeBg;
        sf::Texture _textureBg;
        sf::Sprite _spriteBg;
};

#endif /* !SETTINGS_HPP_ */
