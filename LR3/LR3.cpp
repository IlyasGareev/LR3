#include <iostream>
#include<conio.h>
#include <time.h>
#include <ctime>
#include<stdlib.h>

class Things  //базовый класс
{
public:
    virtual void PrintName()
    {
        printf("Things ");
    }
    virtual ~Things()
    {
    }

};

class Car : public Things            //класс потомок
{
private:
    int x;
    int y;
public:
    Car()
    {
        x = 0;
        y = 0;
    }

    Car(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Car(const Car& t)
    {
        x = t.x;
        y = t.x;
    }
    void PrintName()
    {
        printf("Car ");
    }
    ~Car()
    {
    }

};

class SuperCar : public Things                 //класс потомок 
{
private:
    int color;
public:
    SuperCar()
    {
        color = 0;
    }
    SuperCar(int color)
    {
        this->color = color;
    }
    SuperCar(const SuperCar& c)
    {
        color = c.color;
    }
    void PrintName()
    {
        printf("SuperCar ");
    }
    ~SuperCar()
    {
    }
};




int main()
{
    setlocale(LC_ALL, "ru");
    srand((unsigned)time(NULL));
    
}
