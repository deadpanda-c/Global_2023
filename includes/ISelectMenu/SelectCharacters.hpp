/*
** EPITECH PROJECT, 2023
** GGJ_2023
** File description:
** SelectCharacters
*/

#ifndef SELECTCHARACTERS_HPP_
    #define SELECTCHARACTERS_HPP_

    #include "ASelectMenu.hpp"

class SelectCharacters : public ASelectMenu {
    public:
        SelectCharacters() {};
        ~SelectCharacters() {};

        void init(const std::string path, sf::Vector2u winSize);
        int events(sf::RenderWindow &win, sf::Event &event,  std::vector<STATE> &state);
        int update(sf::RenderWindow &win);
        int draw(sf::RenderWindow &win);

    protected:
        sf::Vector2f _sizeBg;
        sf::Texture _textureBg;
        sf::Sprite _spriteBg;
};

#endif /* !SELECTCHARACTERS_HPP_ */
