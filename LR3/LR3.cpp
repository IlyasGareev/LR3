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
    MyStorage storage(100);
    for (int i = 0; i < storage.getCount(); i++)
    {
        int a = rand() % 2;
        if (a == 0) {
            storage.SetObject(i, new Car());
        }
        else {
            storage.SetObject(i, new SuperCar());
        }
    }



    unsigned int s = clock();
    for (int i = 0; i < 100; i++) {
        int a = rand() % 3;
        int b;
        if (storage.getCount() != 0) {
            b = rand() % storage.getCount();
        }
        else {
            b = 0;
        }
        int k = rand() % 2;
        switch (a) {
        case 0:
            if (k == 0)
                storage.AddObject(new Car);
            else
                storage.AddObject(new Car);

            printf("addObject ");
            break;
        case 1:
            storage.DeleteObject(b);
            printf("removeObject ");
            break;
        case 2:
            storage.PrintNameObject(b);
            break;
        }
    }

    unsigned int e = clock();
    unsigned int time = e - s;
    printf("\nВремя: %d миллисекунд\n", time);
    system("pause");
    s = clock();
    for (int i = 0; i < 1000; i++) {
        int a = rand() % 3;
        int b;
        if (storage.getCount() != 0) {
            b = rand() % storage.getCount();
        }
        else {
            b = 0;
        }
        int k = rand() % 2;
        switch (a) {
        case 0:
            if (k == 0)
                storage.AddObject(new Car);
            else
                storage.AddObject(new Car);

            printf("addObject ");
            break;
        case 1:
            storage.DeleteObject(b);
            printf("removeObject ");
            break;
        case 2:
            storage.PrintNameObject(b);
            break;
        }
    }

    e = clock();
    time = e - s;
    printf("\nВремя: %d миллисекунд\n", time);
    system("pause");
    s = clock();
    for (int i = 0; i < 10000; i++) {
        int a = rand() % 3;
        int b;
        if (storage.getCount() != 0) {
            b = rand() % storage.getCount();
        }
        else {
            b = 0;
        }
        int k = rand() % 2;
        switch (a) {
        case 0:
            if (k == 0)
                storage.AddObject(new Car);
            else
                storage.AddObject(new Car);

            printf("addObject ");
            break;
        case 1:
            storage.DeleteObject(b);
            printf("removeObject ");
            break;
        case 2:
            storage.PrintNameObject(b);
            break;
        }
    }
    e = clock();
    time = e - s;
    printf("\nВремя: %d миллисекунд\n", time);
    system("pause");
}
