/*
** EPITECH PROJECT, 2023
** Rooms
** File description:
** hello world?
*/

#include "../../includes/Rooms/Rooms.hpp"

Rooms::Rooms()
{

}

Rooms::Rooms(const std::string &roomName, ROOMS room)
{
    this->init(roomName, room);
}

void Rooms::init(const std::string &roomName, ROOMS room)
{
    this->_roomName = roomName;
    this->_room = room;
    this->_player.init(SPRITE);
    if (room == ROOMS::ROOM_ONE) {

        for (size_t i = 0; i < 8; i++) {
            Block block;
            this->_blockList.push_back(block);
        }

        this->_blockList[0].init(sf::Vector2f(85.f, 72.f), sf::Vector2f(602.f, 944.f));
        this->_blockList[1].init(sf::Vector2f(148.f, 78.f), sf::Vector2f(108.f, 338.f));
        this->_blockList[2].init(sf::Vector2f(128.f, 6.f), sf::Vector2f(535.f, 772.f));
        this->_blockList[3].init(sf::Vector2f(106.f, 118.f), sf::Vector2f(843.f, 136.f));
        this->_blockList[4].init(sf::Vector2f(187.f, 60.f), sf::Vector2f(304.f, 413.f));
        this->_blockList[5].init(sf::Vector2f(162.f, 19.f), sf::Vector2f(479.f, 384.f));
        this->_blockList[6].init(sf::Vector2f(99.f, 22.f), sf::Vector2f(378.f, 554.f));
        this->_blockList[7].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(320.f, 373.f));
    }
    else if (room == ROOMS::ROOM_TWO) {
        for (size_t i = 0; i < 12; i++) {
            Block block;
            this->_blockList.push_back(block);
        }

        this->_blockList[0].init(sf::Vector2f(85.f, 72.f), sf::Vector2f(944.f, 602.f));
        this->_blockList[1].init(sf::Vector2f(148.f, 78.f), sf::Vector2f(338.f, 108.f));
        this->_blockList[2].init(sf::Vector2f(128.f, 6.f), sf::Vector2f(772.f, 535.f));
        this->_blockList[3].init(sf::Vector2f(106.f, 118.f), sf::Vector2f(136.f, 843.f));
        this->_blockList[4].init(sf::Vector2f(187.f, 60.f), sf::Vector2f(443.f, 304.f));
        this->_blockList[5].init(sf::Vector2f(162.f, 19.f), sf::Vector2f(384.f, 479.f));
        this->_blockList[6].init(sf::Vector2f(99.f, 22.f), sf::Vector2f(554.f, 378.f));
        this->_blockList[7].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(373.f, 320.f));
        this->_blockList[8].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(991.f, 976.f));
        this->_blockList[9].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(340.f, 479.f));
        this->_blockList[10].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(322.f, 150.f));
        this->_blockList[11].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(246.f, 979.f));
        std::cout << "init the second one" << std::endl;
    } else if (room == ROOMS::ROOM_THREE) {
        for (size_t i = 0; i < 15; i++) {
            Block block;
            this->_blockList.push_back(block);
        }

        this->_blockList[0].init(sf::Vector2f(85.f, 72.f), sf::Vector2f(602.f, 944.f));
        this->_blockList[1].init(sf::Vector2f(148.f, 78.f), sf::Vector2f(108.f, 338.f));
        this->_blockList[2].init(sf::Vector2f(128.f, 6.f), sf::Vector2f(535.f, 772.f));
        this->_blockList[3].init(sf::Vector2f(106.f, 118.f), sf::Vector2f(843.f, 136.f));
        this->_blockList[4].init(sf::Vector2f(187.f, 60.f), sf::Vector2f(304.f, 413.f));
        this->_blockList[5].init(sf::Vector2f(162.f, 19.f), sf::Vector2f(479.f, 384.f));
        this->_blockList[6].init(sf::Vector2f(99.f, 22.f), sf::Vector2f(378.f, 554.f));
        this->_blockList[7].init(sf::Vector2f(89.f, 64.f), sf::Vector2f(320.f, 373.f));
        std::cout << "init the last room" << std::endl;
    } else {
        std::cerr << "/!\\ Error, not good format for rooms" << std::endl;
        return;
    }
    this->_player.setBlock(this->_blockList);
}

void Rooms::update()
{
    this->_player.update();
}

void Rooms::draw(sf::RenderWindow &window)
{
    this->_player.draw(window);
    if (this->_room == ROOMS::ROOM_ONE) {
        for (Block block : this->_blockList) {
            window.draw(block.getRectangle());
        }
    }
}

Rooms::~Rooms()
{

}
