#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Feed() = 0;
    virtual ~Animal() {}
};

class Creator {
public:
    virtual Animal* createAnimal() = 0;
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
    Animal* createAnimal() override {
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
    a = factory->createAnimal();
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

class Payment {
public:
    virtual void Pay() = 0;
    virtual ~Payment() {}
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

class Card : public Payment {
public:
    void Pay() override {
        cout << "Card\n";
    }
};

class Cash : public Payment {
public:
    void Pay() override {
        cout << "Cash\n";
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

class PaymentFactory {
public:
    static Payment* createPayment(int type)
    {
        if (type == 1) {
            return new Card();
        }
        else if (type == 2) {
            return new Cash();
        }
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

    Payment* p = nullptr;

    p = PaymentFactory::createPayment(type);
    if (p) {
        p->Pay();
        delete p;
    }

    return 0;
}


#include <iostream>
using namespace std;

class Document {
public:
    virtual void Open() = 0;
    virtual ~Document() {}
};

class PDF : public Document {
public:
    void Open() override {
        cout << "PDF\n";
    }
};

class DOX : public Document {
public:
    void Open() override {
        cout << "DOX\n";
    }
};

class DocumentFactory {
public:
    static Document* createDocument(string type) {
        if (type == "pdf") {
            return new PDF();
        }
        else if (type == "dox") {
            return new DOX();
        }
    }
};

int main() {
    string type;
    cin >> type;

    Document* d = nullptr;

    d = DocumentFactory::createDocument(type);
    if (d) {
        d->Open();
        delete d;
    }

    return 0;
}


#include <iostream>
using namespace std;

class Product {
public:
    virtual void Data() = 0;
    virtual ~Product() {}
};

class Creator {
public:
    virtual Product* createProduct() = 0; 
    virtual ~Creator() {}
};

class Dog : public Product {
public:
    void Data() override {
        cout << "Dog" << endl;
    }
};

class DogFactory : public Creator {
public:
    Product* createProduct() override {
        return new Dog();
    }
};

class Cat : public Product {
public:
    void Data() override {
        cout << "Cat" << endl;
    }
};

class CatFactory : public Creator {
public:
    Product* createProduct() override {
        return new Cat();
    }
};

class Bird : public Product {
public:
    void Data() override {
        cout << "Bird" << endl;
    }
};

class BirdFactory : public Creator {
public:
    Product* createProduct() override {
        return new Bird();
    }
};

int main() {
    Creator* factory = new DogFactory();
    Product* product = factory->createProduct();
    product->Data();

    delete product;
    delete factory;

    factory = new CatFactory();
    product = factory->createProduct();
    product->Data();

    delete product;
    delete factory;

    factory = new BirdFactory();
    product = factory->createProduct();
    product->Data();

    delete product;
    delete factory;

    return 0;
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
        cout << "Zombie attack\n";
    }
};

class Vampire : public Enemy
{
public:
    void attack() override
    {
        cout << "Vampire attack\n";
    }
};

class EnemyFactory
{
public:
    static Enemy* create(int level)
    {
        if (level < 5) return new Zombie();
        return new Vampire();
    }
};


#include <memory>
#include <string>
#include <vector>
#include <iostream>

class UIElement {
public:
    virtual void draw() const = 0;
    virtual ~UIElement() = default;
};

class Button : public UIElement {
public:
    void draw() const override {
        std::cout << "Рисуем кнопку" << std::endl;
    }
};

class TextBox : public UIElement {
public:
    void draw() const override {
        std::cout << "Рисуем текстовое поле" << std::endl;
    }
};

class UIFactory {
public:
    std::unique_ptr<UIElement> createButton() {
        return std::make_unique<Button>();
    }

    std::unique_ptr<UIElement> createTextBox() {
        return std::make_unique<TextBox>();
    }
};

int main() {
    UIFactory factory;

    auto button = factory.createButton();
    auto textBox = factory.createTextBox();

    button->draw();
    textBox->draw();

    return 0;
}


#include <memory>
#include <string>
#include <iostream>

class Message {
public:
    virtual void send() const = 0;
    virtual ~Message() = default;
};

class Email : public Message {
public:
    void send() const override {
        std::cout << "Отправка Email" << std::endl;
    }
};

class SMS : public Message {
public:
    void send() const override {
        std::cout << "Отправка SMS" << std::endl;
    }
};

class MessageFactory {
public:
    std::unique_ptr<Message> createEmail() {
        return std::make_unique<Email>();
    }

    std::unique_ptr<Message> createSMS() {
        return std::make_unique<SMS>();
    }
};

int main() {
    MessageFactory factory;

    auto email = factory.createEmail();
    auto sms = factory.createSMS();

    email->send();
    sms->send();

    return 0;
}


#include <memory>
#include <vector>
#include <list>
#include <iostream>

class ContainerBase {
public:
    virtual void add(int value) = 0;
    virtual void print() const = 0;
    virtual ~ContainerBase() = default;
};

class VectorContainer : public ContainerBase {
    std::vector<int> vec;
public:
    void add(int value) override {
        vec.push_back(value);
    }
    void print() const override {
        for (int v : vec)
            std::cout << v << " ";
        std::cout << std::endl;
    }
};

class ListContainer : public ContainerBase {
    std::list<int> lst;
public:
    void add(int value) override {
        lst.push_back(value);
    }
    void print() const override {
        for (int v : lst)
            std::cout << v << " ";
        std::cout << std::endl;
    }
};

class ContainerFactory {
public:
    enum class Type { VECTOR, LIST };

    std::unique_ptr<ContainerBase> createContainer(Type type) {
        if (type == Type::VECTOR) {
            return std::make_unique<VectorContainer>();
        }
        else {
            return std::make_unique<ListContainer>();
        }
    }
};

int main() {
    ContainerFactory factory;
    auto container = factory.createContainer(ContainerFactory::Type::VECTOR);

    container->add(1);
    container->add(2);
    container->add(3);

    container->print();

    return 0;
}#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Feed() = 0;
    virtual ~Animal() {}
};

class Creator {
public:
    virtual Animal* createAnimal() = 0;
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
    Animal* createAnimal() override {
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
    a = factory->createAnimal();
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

class Payment {
public:
    virtual void Pay() = 0;
    virtual ~Payment() {}
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

class Card : public Payment {
public:
    void Pay() override {
        cout << "Card\n";
    }
};

class Cash : public Payment {
public:
    void Pay() override {
        cout << "Cash\n";
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

class PaymentFactory {
public:
    static Payment* createPayment(int type)
    {
        if (type == 1) {
            return new Card();
        }
        else if (type == 2) {
            return new Cash();
        }
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

    Payment* p = nullptr;

    p = PaymentFactory::createPayment(type);
    if (p) {
        p->Pay();
        delete p;
    }

    return 0;
}


#include <iostream>
using namespace std;

class Document {
public:
    virtual void Open() = 0;
    virtual ~Document() {}
};

class PDF : public Document {
public:
    void Open() override {
        cout << "PDF\n";
    }
};

class DOX : public Document {
public:
    void Open() override {
        cout << "DOX\n";
    }
};

class DocumentFactory {
public:
    static Document* createDocument(string type) {
        if (type == "pdf") {
            return new PDF();
        }
        else if (type == "dox") {
            return new DOX();
        }
    }
};

int main() {
    string type;
    cin >> type;

    Document* d = nullptr;

    d = DocumentFactory::createDocument(type);
    if (d) {
        d->Open();
        delete d;
    }

    return 0;
}


#include <iostream>
using namespace std;

class Product {
public:
    virtual void Data() = 0;
    virtual ~Product() {}
};

class Creator {
public:
    virtual Product* createProduct() = 0; 
    virtual ~Creator() {}
};

class Dog : public Product {
public:
    void Data() override {
        cout << "Dog" << endl;
    }
};

class DogFactory : public Creator {
public:
    Product* createProduct() override {
        return new Dog();
    }
};

class Cat : public Product {
public:
    void Data() override {
        cout << "Cat" << endl;
    }
};

class CatFactory : public Creator {
public:
    Product* createProduct() override {
        return new Cat();
    }
};

class Bird : public Product {
public:
    void Data() override {
        cout << "Bird" << endl;
    }
};

class BirdFactory : public Creator {
public:
    Product* createProduct() override {
        return new Bird();
    }
};

int main() {
    Creator* factory = new DogFactory();
    Product* product = factory->createProduct();
    product->Data();

    delete product;
    delete factory;

    factory = new CatFactory();
    product = factory->createProduct();
    product->Data();

    delete product;
    delete factory;

    factory = new BirdFactory();
    product = factory->createProduct();
    product->Data();

    delete product;
    delete factory;

    return 0;
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
        cout << "Zombie attack\n";
    }
};

class Vampire : public Enemy
{
public:
    void attack() override
    {
        cout << "Vampire attack\n";
    }
};

class EnemyFactory
{
public:
    static Enemy* create(int level)
    {
        if (level < 5) return new Zombie();
        return new Vampire();
    }
};


#include <memory>
#include <string>
#include <vector>
#include <iostream>

class UIElement {
public:
    virtual void draw() const = 0;
    virtual ~UIElement() = default;
};

class Button : public UIElement {
public:
    void draw() const override {
        std::cout << "Рисуем кнопку" << std::endl;
    }
};

class TextBox : public UIElement {
public:
    void draw() const override {
        std::cout << "Рисуем текстовое поле" << std::endl;
    }
};

class UIFactory {
public:
    std::unique_ptr<UIElement> createButton() {
        return std::make_unique<Button>();
    }

    std::unique_ptr<UIElement> createTextBox() {
        return std::make_unique<TextBox>();
    }
};

int main() {
    UIFactory factory;

    auto button = factory.createButton();
    auto textBox = factory.createTextBox();

    button->draw();
    textBox->draw();

    return 0;
}


#include <memory>
#include <string>
#include <iostream>

class Message {
public:
    virtual void send() const = 0;
    virtual ~Message() = default;
};

class Email : public Message {
public:
    void send() const override {
        std::cout << "Отправка Email" << std::endl;
    }
};

class SMS : public Message {
public:
    void send() const override {
        std::cout << "Отправка SMS" << std::endl;
    }
};

class MessageFactory {
public:
    std::unique_ptr<Message> createEmail() {
        return std::make_unique<Email>();
    }

    std::unique_ptr<Message> createSMS() {
        return std::make_unique<SMS>();
    }
};

int main() {
    MessageFactory factory;

    auto email = factory.createEmail();
    auto sms = factory.createSMS();

    email->send();
    sms->send();

    return 0;
}


#include <memory>
#include <vector>
#include <list>
#include <iostream>

class ContainerBase {
public:
    virtual void add(int value) = 0;
    virtual void print() const = 0;
    virtual ~ContainerBase() = default;
};

class VectorContainer : public ContainerBase {
    std::vector<int> vec;
public:
    void add(int value) override {
        vec.push_back(value);
    }
    void print() const override {
        for (int v : vec)
            std::cout << v << " ";
        std::cout << std::endl;
    }
};

class ListContainer : public ContainerBase {
    std::list<int> lst;
public:
    void add(int value) override {
        lst.push_back(value);
    }
    void print() const override {
        for (int v : lst)
            std::cout << v << " ";
        std::cout << std::endl;
    }
};

class ContainerFactory {
public:
    enum class Type { VECTOR, LIST };

    std::unique_ptr<ContainerBase> createContainer(Type type) {
        if (type == Type::VECTOR) {
            return std::make_unique<VectorContainer>();
        }
        else {
            return std::make_unique<ListContainer>();
        }
    }
};

int main() {
    ContainerFactory factory;
    auto container = factory.createContainer(ContainerFactory::Type::VECTOR);

    container->add(1);
    container->add(2);
    container->add(3);

    container->print();

    return 0;
}
