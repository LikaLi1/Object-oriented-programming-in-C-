#include <iostream>
using namespace std;

class Vehicle 
{
public: 
    int speed;

    void move() 
    {
        cout << "Vehicle is moving, " << speed << endl;
    }
};

class Car : public Vehicle 
{
public:
    void honk() 
    {
        cout << "Car honks" << endl;
    }
};

class Bicycle : public Vehicle {
public:
    void ringBell() {
        cout << "Bicycle ringing" << endl;
    }
};

int main()
{
    Car c;

    c.speed = 200;
    c.move();
    c.honk();

    Bicycle b;

    b.speed = 60;
    b.move();
    b.ringBell();
}


#include <iostream>
using namespace std;

class Animal 
{
public: 
    void sound()
    {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() 
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal* animals[2];

    animals[0] = new Dog();
    animals[1] = new Cat();

    animals[0]->sound();
    animals[1]->sound();
}


#include <iostream>
#include <cmath>
using namespace std;

class Shape 
{
public: 
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}

    double area()
    {
        double res = width * height;
        cout << "Square rectangle = " << res << endl;
        return res;
    }
};

class Circle : public Shape {
public:
    double radius;

    Circle(double r) : radius(r) {}

    double area() override {
        double res = 3.14 * pow(radius, 2);
        cout << "Square circle = " << res << endl;
        return res;
    }
};

int main()
{
    Shape* shapes[2];

    shapes[0] = new Rectangle(8.9, 9.0);
    shapes[1] = new Circle(5.0);

    for (int i = 0; i < 2; ++i) {
        shapes[i]->area();
        delete shapes[i];
    }
}


#include <iostream>
#include <cmath>
using namespace std;

class Character
{
public: 
    virtual void attack() = 0;
    virtual ~Character() {}
};

class Warrior : public Character
{
public:
    void attack()
    {
        cout << "Warrior attacks with sword" << endl;
    }
};

class Mage : public Character {
public:
    void attack()
    {
        cout << "Mage casts spell" << endl;
    }
};

int main()
{
    Character* characters[2];

    characters[0] = new Warrior();
    characters[1] = new Mage();

    characters[0]->attack();
    characters[1]->attack();

    delete characters[0];
    delete characters[1];
}


#include <iostream>
using namespace std;

class BankAccount
{
public: 
    virtual void calculateInterest() = 0;
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
public:
    void calculateInterest()
    {
        cout << "5%" << endl;
    }
};

class CurrentAccount : public BankAccount {
public:
    void calculateInterest()
    {
        cout << "2%" << endl;
    }
};

int main()
{
    BankAccount* bankAccounts[2];

    bankAccounts[0] = new SavingsAccount();
    bankAccounts[1] = new CurrentAccount();

    bankAccounts[0]->calculateInterest();
    bankAccounts[1]->calculateInterest();

    delete bankAccounts[0];
    delete bankAccounts[1];
}
