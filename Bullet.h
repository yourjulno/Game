//
// Created by 79096 on 15.04.2022.
//


#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H
#include "Creature.h"
#include "Player.h"
class Bullet{
protected:
    Clock clock;
    int direction;
    float bullet_x;
    float bullet_y;
    float SpeedX;
    float x_player;
    float y_player;
    float x_monster;
    float y_monster;
    float X;
    float Y;

    String  file{};         //файл с расширением
    Image   image{};        //sfml изображение
    Texture texture{};      //sfml текстура
    float dx = 0;
public:
    bool life = true;
    Sprite  sprite{};
    Bullet(String file, float speedX, int direction, float bullet_x, float bullet_y);
    void getBulletcoord();
    FloatRect getRect();
    float GetPositionX();
    float GetPositionY();
    ~Bullet();
};



#endif //GAAME_MAIN_BULLET_H
