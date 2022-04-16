#include "Player.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "Monster.h"
#include "Bullet.h"
//using namespace sf;

int main()
{   //Задали размер окна

    Player hero("C:\\Users\\79096\\Downloads\\Gaame-main\\Gaame-main\\astronaut.png", 0.2f, 3, 1000, 400);

    Monster aliens[100];
    for (int i = 0; i < 2; i++)
    {
        Monster alien("C:\\Users\\79096\\Downloads\\Gaame-main\\Gaame-main\\ALIEN_big.png", 2.5, 1000, 400);
        aliens[i] = (alien);
   }
//
    
    Clock clock; //создаем переменную для привязки персонажа ко времени.
    float time;
    std::list<Creature*> creatures(3);
    std::list<Bullet*>  bullets;
//    std::list<Monster*> aliens(2);
//    for (auto i = 0; i < aliens.size(); i++){
//        aliens.push_back(new Monster("C:\\Users\\79096\\Downloads\\Gaame-main\\Gaame-main\\ALIEN_big.png", 2.5, 1000, 400));
//    }
    //Monster *m;
    RenderWindow window(sf::VideoMode(1376, 764), "SFML works!");

    while (window.isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asMicroseconds(); 
        
        time /= 800;
        hero.SetTime(time);
//        for (auto it = aliens.begin(); it != aliens.end();)//говорим что проходимся от начала до конца
//        {
//            Monster *m = *it;
//            //Monster *m = *it;//для удобства, чтобы не писать (*it)->
//
//            m->SetTime(time);//вызываем ф-цию для оставшихся пуль
//
//        }
        aliens[0].SetTime(time);
        aliens[1].SetTime(time);

        clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    //if ((bullets.back()->life) && bullets.size() >= 1 ) break;
                    bullets.push_back(new Bullet("C:\\Users\\79096\\Downloads\\Gaame-main\\Gaame-main\\m_bullet.png", 5, hero.directionMove, hero.GetPositionX(), hero.GetPositionY()));

                }
            }
        }
        hero.SavePosition();
        hero.Keyboard();
        hero.Move();
//        for (auto it = aliens.begin(); it != aliens.end();)//говорим что проходимся от начала до конца
//        {
//
//            Monster *m = *it;//для удобства, чтобы не писать (*it)->
//
//            m->SavePosition();
//            m->DistanceToHero(hero.GetPositionX());//вызываем ф-цию для оставшихся пуль
//            m->Move();
//            m->Attack();
//        }
       for (auto i = 0; i < 2; i++)
       {
            aliens[i].SavePosition();
            aliens[i].DistanceToHero(hero.GetPositionX());
            aliens[i].Move();
            aliens[i].Attack();
       }
        for (auto it = bullets.begin(); it != bullets.end(); it ++){
            if ((*it)->getRect().intersects(hero.getRect()))//если прямоугольник спрайта объекта пересекается с игроком
            {
                (*it)->life = false;
            }
        }
            for (auto it = bullets.begin(); it != bullets.end();)//говорим что проходимся от начала до конца
            {

                Bullet *b = *it;//для удобства, чтобы не писать (*it)->

                b->getBulletcoord();//вызываем ф-цию для оставшихся пуль

                if (b->life == false) {

                    it = bullets.erase(it);
                    delete b;

                }// если у пули life = false то удаляем её
                //else it++;
                else it++;
            }





        window.clear();

        hero.Draw(window);
//        for (auto it = aliens.begin(); it != aliens.end(); it++){
//            Monster *m = *it;
//            m->Draw(window);
//        }
        aliens[0].Draw(window);
        aliens[1].Draw(window);
        for (auto it = bullets.begin(); it != bullets.end(); it++){

            window.draw((*it)->sprite);
        }
        window.display();
    }
    
}