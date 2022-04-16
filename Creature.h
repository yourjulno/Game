#ifndef ALIEN_CREATURE_H
#define ALIEN_CREATURE_H
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;


class Creature
{
protected:

    int Width{};
    int Height{};  // ������, ������
    float SpeedX{};
    float SpeedY{}; //�������� �� x, y

    //����������� �������� �������

    float time{};
    float timeBoost{};
    float X{};
    float Y{};

    int WindowWidth{};
    int WindowHeight{};

    float CurrentFrame{};//������ ������� ����
    float CurrentFrame2{};

    String  file{};         //���� � �����������
    Image   image{};        //sfml �����������
    Texture texture{};      //sfml ��������
    Sprite  sprite{};       //sfml ������

    //double   hp;
    //unsigned strength;

    //std::vector <sf::Sprite> sprites;

public:
    int   directionMove{};
    virtual void Move() = 0;
    virtual void Attack() = 0;
    void SavePosition();
    void SetTime(float time);
    float GetTime();
    FloatRect getRect(){
        return FloatRect (X, Y, 100, 100);
    }
    float GetPositionX();
    float GetPositionY();

    void Draw(RenderWindow& window);
    virtual void IncrementTime() = 0;

    Creature();
	//virtual ~Creature()  = 0;

};

#endif //ALIEN_CREATURE_H