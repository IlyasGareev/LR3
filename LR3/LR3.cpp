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

class MyStorage
{
private:
    Things** object;                    //массив указателей на объекты типа Things
    int size;
public:
    MyStorage(int i)
    {
        size = i;
        object = new Things * [size];
    }
    void SetObject(int i, Things* obj)     //установка 
    {
        object[i] = obj;
    }
    Things& GetObject(int i)
    {
        return *object[i];
    }
    int getCount()                        //возвращение размера
    {
        return size;
    }
    void AddObject(Things* obj)
    {
        Things** NewObj = new Things * [size + 1];
        if (size != 0) {
            for (int i = 0; i < size; i++)
            {
                NewObj[i] = object[i];
            }
            delete[] object;
        }
        object = NewObj;
        object[size] = obj;
        size = size + 1;
    }
    void delObject(int i)
    {
        object[i] = NULL;
    }
    void DeleteObject(int i)
    {
        if (size != 0 && i < size && size != 1) {
            Things** NewObj = new Things * [size - 1];
            for (int j = 0; j < i; j++)
            {
                NewObj[j] = object[j];
            }
            for (int j = i; j < size - 1; j++)
            {
                NewObj[j] = object[j + 1];
            }
            delete[] object;
            size = size - 1;
            object = NewObj;
        }
        else if (size == 1) {
            object[0] = nullptr;
            size = 0;
        }
    }
    void PrintNameObject(int i) {
        if (size != 0 && size > i) {

            object[i]->PrintName();
        }
    }
    ~MyStorage()
    {
        for (int i = 0; i < size; i++) {
            delete object[i];
        }
        delete[] object;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");
    srand((unsigned)time(NULL));
    
}
