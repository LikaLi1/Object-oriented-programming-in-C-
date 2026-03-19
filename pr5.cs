#include <iostream>
using namespace std;

class Transport
{
public:
    virtual void move() = 0;
    virtual ~Transport() {}
};

class Car : public Transport
{
public:
    void move() override
    {
        cout << "Car is moving" << endl;
    }

    void honk()
    {
        cout << "Car honks" << endl;
    }
};

class Bike : public Transport 
{
public:
    void move() override
    {
        cout << "Car is moving" << endl;
    }

    void ringBell() {
        cout << "Bike ringing" << endl;
    }
};

int main()
{
    Transport* t;

    Car c;
    Bike b;

    t = &c;
    t->move();

    t = &b;
    t->move();
}


#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound() = 0;
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }

    void drink()
    {
        cout << "The dog drinks water" << endl;
    }
};

class Cow : public Animal
{
public:
    void sound() override
    {
        cout << "Cow hums" << endl;
    }

    void eat() 
    {
        cout << "The cow eats grass" << endl;
    }
};

int main()
{
    Animal* a;

    Dog d;
    Cow c;

    a = &d;
    a->sound();

    a = &c;
    a->sound();
}


#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual ~Shape() {}
};

class Square : public Shape
{
public:
    void area() override
    {
        cout << "This is the product of the length of its side and itself" << endl;
    }
};

class Triangle : public Shape
{
public:
    void area() override
    {
        cout << "Half the product of the base and the height dropped to it" << endl;
    }
};

int main()
{
    Shape* s;

    Square sq;
    Triangle t;

    s = &sq;
    s->area();

    s = &t;
    s->area();
}


#include <iostream>
using namespace std;

class Drink
{
public:
    virtual void prepare() = 0;
    virtual ~Drink() {}
};

class Tea : public Drink
{
public:
    void prepare() override
    {
        cout << "Tea is ready" << endl;
    }
};

class Coffee : public Drink
{
public:
    void prepare() override
    {
        cout << "Coffee is ready" << endl;
    }
};

int main()
{
    Drink* d;

    Tea t;
    Coffee c;

    d = &t;
    d->prepare();

    d = &c;
    d->prepare();
}


#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay() = 0;
    virtual ~Payment() {}
};

class Card : public Payment
{
public:
    void pay() override
    {
        cout << "Payment by card" << endl;
    }
};

class Cash : public Payment
{
public:
    void pay() override
    {
        cout << "Payment by cash" << endl;
    }
};

class Crypto : public Payment
{
public:
    void pay() override
    {
        cout << "Payment by crypto" << endl;
    }
};

int main()
{
    Payment* payments[3];

    Card c;
    Cash cs;
    Crypto cr;

    payments[0] = &c;
    payments[1] = &cs;
    payments[2] = &cr;

    for (int i = 0; i < 3; i++) 
    {
        payments[i]->pay();
    }
}


#include <iostream>
using namespace std;

class Employee
{
public:
    virtual void salary() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee
{
public:
    void salary() override
    {
        cout << "Manager" << endl;
    }
};

class Developer : public Employee
{
public:
    void salary() override
    {
        cout << "Developer" << endl;
    }
};

int main()
{
    Employee* employees[2];

    Manager m;
    Developer d;

    employees[0] = &m;
    employees[1] = &d;

    for (int i = 0; i < 2; i++) 
    {
        employees[i]->salary();
    }
}


#include <iostream>
using namespace std;

class File
{
public:
    virtual void open() = 0;
    virtual ~File() {}
};

class TextFile : public File
{
public:
    void open() override
    {
        cout << "TextFile" << endl;
    }
};

class ImageFile : public File
{
public:
    void open() override
    {
        cout << "ImageFile" << endl;
    }
};

int main()
{
    File* files[2];

    TextFile t;
    ImageFile i;

    files[0] = &t;
    files[1] = &i;

    for (int i = 0; i < 2; i++) 
    {
        files[i]->open();
    }
}


#include <iostream>
using namespace std;

class Message
{
public:
    virtual void send() = 0;
    virtual ~Message() {}
};

class Email : public Message
{
public:
    void send() override
    {
        cout << "TextFile" << endl;
    }
};

class SMS : public Message
{
public:
    void send() override
    {
        cout << "ImageFile" << endl;
    }
};

int main()
{
    Message* messages[2];

    Email e;
    SMS s;

    messages[0] = &e;
    messages[1] = &s;

    for (int i = 0; i < 2; i++) 
    {
        messages[i]->send();
    }
}


#include <iostream>
using namespace std;

class Enemy
{
public:
    virtual void attack() = 0;
    virtual ~Enemy() {}
};

class Zombie : public Enemy
{
public:
    void attack() override
    {
        cout << "TextFile" << endl;
    }
};

class Alien : public Enemy
{
public:
    void attack() override
    {
        cout << "ImageFile" << endl;
    }
};

int main()
{
    Enemy* enemys[2];

    Zombie z;
    Alien a;

    enemys[0] = &z;
    enemys[1] = &a;

    for (int i = 0; i < 2; i++) 
    {
        enemys[i]->attack();
    }
}
