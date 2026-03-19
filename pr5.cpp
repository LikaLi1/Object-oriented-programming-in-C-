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


#include <iostream>
using namespace std;

class Account
{
public:
    virtual void calculateInterest() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account
{
public:
    void calculateInterest() override
    {
        cout << "SavingsAccount" << endl;
    }
};

class FixedDeposit : public Account
{
public:
    void calculateInterest() override
    {
        cout << "FixedDeposit" << endl;
    }
};

int main()
{
    Account* accounts[2];

    SavingsAccount s;
    FixedDeposit f;

    accounts[0] = &s;
    accounts[1] = &f;

    for (int i = 0; i < 2; i++)
    {
        accounts[i]->calculateInterest();
    }
}


#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
    int length, width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    void area() override
    {
        cout << "Rectangle area: " << length * width << endl;
    }
    void perimeter() override
    {
        cout << "Rectangle perimeter: " << 2 * (length + width) << endl;
    }
};

class Circle : public Shape
{
    int radius;

public:
    Circle(int r) : radius(r) {}

    void area() override
    {
        cout << "Circle area: " << 3.14159 * radius * radius << endl;
    }
    void perimeter() override
    {
        cout << "Circle perimeter: " << 2 * 3.14159 * radius << endl;
    }
};

int main()
{
    Shape* shapes[2];

    Rectangle r(5, 6);
    Circle c(5);

    shapes[0] = &r;
    shapes[1] = &c;

    for (int i = 0; i < 2; i++)
    {
        shapes[i]->area();
        shapes[i]->perimeter();
    }
}


#include <iostream>
using namespace std;

class Media
{
public:
    virtual void play() = 0;
    virtual ~Media() {}
};

class Audio : public Media
{
public:
    void play() override
    {
        cout << "Audio play" << endl;
    }
};

class Video : public Media
{
public:
    void play() override
    {
        cout << "Video play" << endl;
    }
};

int main()
{
    Media* medias[2];

    Audio a;
    Video v;

    medias[0] = &a;
    medias[1] = &v;

    for (int i = 0; i < 2; i++)
    {
        medias[i]->play();
    }
}


#include <iostream>
using namespace std;

class Notification
{
public:
    virtual void notify() = 0;
    virtual ~Notification() {}
};

class Push : public Notification
{
public:
    void notify() override
    {
        cout << "You have received a push notification." << endl;
    }
};

class EmailNotification : public Notification
{
public:
    void notify() override
    {
        cout << "You have received a notification by email" << endl;
    }
};

int main()
{
    Notification* notifications[2];

    Push p;
    EmailNotification e;

    notifications[0] = &p;
    notifications[1] = &e;

    for (int i = 0; i < 2; i++)
    {
        notifications[i]->notify();
    }
}


#include <iostream>
using namespace std;

class Robot
{
public:
    virtual void work() = 0;
    virtual ~Robot() {}
};

class CleanerRobot : public Robot
{
public:
    void work() override
    {
        cout << "This robot washes the floor" << endl;
    }
};

class BuilderRobot : public Robot
{
public:
    void work() override
    {
        cout << "This robot builds" << endl;
    }
};

int main()
{
    Robot* robots[2];

    CleanerRobot c;
    BuilderRobot b;

    robots[0] = &c;
    robots[1] = &b;

    for (int i = 0; i < 2; i++)
    {
        robots[i]->work();
    }
}


#include <iostream>
using namespace std;

class Flyable
{
public:
    virtual void Fly() = 0;
    virtual ~Flyable() {}
};

class Swimmable
{
public:
    virtual void Swim() = 0;
    virtual ~Swimmable() {}
};

class Duck : public Flyable, public Swimmable
{
public:
    void Fly() override
    {
        cout << "Duck is flying" << endl;
    }
    void Swim() override
    {
        cout << "Duck is swimming" << endl;
    }
};

int main()
{
    Duck d;

    d.Fly();
    d.Swim();
}


#include <iostream>
using namespace std;

class Logger
{
public:
    virtual void log() = 0;
    virtual ~Logger() {}
};

class FileLogger : public Logger
{
public:
    void log() override
    {
        cout << "FileLogger" << endl;
    }
};

class ConsoleLogger : public Logger
{
public:
    void log() override
    {
        cout << "ConsoleLogger" << endl;
    }
};

int main()
{
    Logger* loggers[2];

    FileLogger f;
    ConsoleLogger c;

    loggers[0] = &f;
    loggers[1] = &c;

    for (int i = 0; i < 2; i++)
    {
        loggers[i]->log();
    }
}


#include <iostream>
using namespace std;

class Delivery
{
public:
    virtual void deliver() = 0;
    virtual ~Delivery() {}
};

class Courier : public Delivery
{
public:
    void deliver() override
    {
        cout << "Courier" << endl;
    }
};

class Drone : public Delivery
{
public:
    void deliver() override
    {
        cout << "Drone" << endl;
    }
};

int main()
{
    Delivery* deliverys[2];

    Courier c;
    Drone d;

    deliverys[0] = &c;
    deliverys[1] = &d;

    for (int i = 0; i < 2; i++)
    {
        deliverys[i]->deliver();
    }
}


#include <iostream>
using namespace std;

class Course
{
public:
    virtual void start() = 0;
    virtual ~Course() {}
};

class OnlineCourse : public Course
{
public:
    void start() override
    {
        cout << "OnlineCourse" << endl;
    }
};

class OfflineCourse : public Course
{
public:
    void start() override
    {
        cout << "OfflineCourse" << endl;
    }
};

int main()
{
    Course* courses[2];

    OnlineCourse on;
    OfflineCourse of;

    courses[0] = &on;
    courses[1] = &of;

    for (int i = 0; i < 2; i++)
    {
        courses[i]->start();
    }
}


#include <iostream>
using namespace std;

class Product
{
public:
    virtual double getPrice() const = 0;
    virtual ~Product() {}
};

class Book : public Product
{
    double price;
public:
    Book(double p) : price(p) {}
    double getPrice() const override { return price; }
};

class Electronics : public Product
{
    double price;
public:
    Electronics(double p) : price(p) {}
    double getPrice() const override { return price; }
};

class Clothing : public Product
{
    double price;
public:
    Clothing(double p) : price(p) {}
    double getPrice() const override { return price; }
};

int main()
{
    Product* products[3];

    Book b(15.99);
    Electronics e(249.99);
    Clothing c(49.99);

    products[0] = &b;
    products[1] = &e;
    products[2] = &c;

    double totalPrice = 0;

    for (int i = 0; i < 3; i++)
    {
        double price = products[i]->getPrice();
        cout << "Price of product " << i + 1 << ": " << price << endl;
        totalPrice += price;
    }

    cout << "Total price: " << totalPrice << endl;

    return 0;
}
