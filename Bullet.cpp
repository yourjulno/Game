//
// Created by 79096 on 14.04.2022.
//
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(String file, float speedX, int direction, float bullet_x, float bullet_y) {
    this->direction = direction;
    this->bullet_x = 0;
    this->SpeedX = speedX;
    this->file = file;
    this->x_player = bullet_x;
    this->y_player = bullet_y;
    this->x_monster = x_monster;
    this->y_monster = y_monster;

    image.loadFromFile("C:/Users/79096/Downloads/Alien-kirill-s (1)/Alien-kirill-s/m_bullet.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    if(direction > 0)
        sprite.setPosition((float) (bullet_x + 60 ), (float) (bullet_y + 31  ));
    else sprite.setPosition((float) (bullet_x + 15), (float) (bullet_y + 55 ));
}
void Bullet::getBulletcoord() {

        float time = clock.getElapsedTime().asMicroseconds() ;
                time = time / 800;


        if(direction > 0) {

            sprite.move(4, 0);
        }
        else {
            sprite.setRotation(180);
            sprite.move(-4, 0);
        }
        //sprite.setPosition(bullet_x + 10, bullet_y);

        if(bullet_x +dx > 1700){

            life = false;
        }
        std::cout << "Bullet draw" << " ";
        std::cout << time << " ";

       clock.restart();
    }

float Bullet::GetPositionX() {
    this->X = (float)sprite.getPosition().x;
    return this->X;
}
float Bullet::GetPositionY() {
    this->Y = (float)sprite.getPosition().y;
    return this->Y;
}
FloatRect Bullet::getRect(){
    return FloatRect (this->X, this->Y, 100, 100);
}



Bullet::~Bullet(){}
//
// Created by 79096 on 15.04.2022.
//


