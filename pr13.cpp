#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Feed() = 0;
    virtual ~Animal() {}
};

class Creator {
public:
    virtual Animal* create() = 0;
    virtual ~Creator() {}
};

class Bird : public Animal {
public:
    void Feed() override {
        cout << "Nuts\n";
    }
};

class BirdFactory : public Creator {
public:
    Animal* create() override {
        return new Bird();
    }
};

class Dog : public Animal {
public:
    void Feed() override {
        cout << "Meal\n";
    }
};

class Cat : public Animal {
public:
    void Feed() override {
        cout << "Fish\n";
    }
};

class AnimalFactory {
public:
    static Animal* createAnimal(int type) {
        if (type == 1) {
            return new Dog();
        }
        else if (type == 2) {
            return new Cat();
        }
        return nullptr;
    }
};

int main() {
    int type;
    cin >> type;

    Animal* a = nullptr;

    a = AnimalFactory::createAnimal(type);
    if (a) {
        a->Feed();
        delete a;
    }

    Creator* factory = new BirdFactory();
    a = factory->create();
    a->Feed();

    delete a;
    delete factory;

    return 0;
}




#include <iostream>
using namespace std;

class Transport {
public:
    virtual void Speed() = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
public:
    void Speed() override {
        cout << "200m\n";
    }
};

class Bike : public Transport {
public:
    void Speed() override {
        cout << "100m\n";
    }
};

class TransportFactory {
public:
    static Transport* createTransport(int type) {
        if (type == 1) {
            return new Car();
        }
        else if (type == 2) {
            return new Bike();
        }
        return nullptr;
    }
};

int main() {
    int type;
    cin >> type;

    Transport* t = nullptr;

    t = TransportFactory::createTransport(type);
    if (t) {
        t->Speed();
        delete t;
    }

    return 0;
}
