#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    virtual string reading() = 0;
    virtual ~Book() {}
};

class Electronic : public Book
{
private:
    string text;

public:
    Electronic(const string& t) : text(t) {}

    string reading() override
    {
        return text;
    }
};

class BookDecorator : public Book
{
protected:
    Book* wrapped;

public:
    BookDecorator(Book* b) : wrapped(b) {}
};

class WrappingFirst : public BookDecorator
{
public:
    WrappingFirst(Book* b) : BookDecorator(b) {}

    string reading() override
    {
        return "<i>" + wrapped->reading() + "<i>";
    }
};

class WrappingSecond : public BookDecorator
{
public:
    WrappingSecond(Book* b) : BookDecorator(b) {}

    string reading() override
    {
        return wrapped->reading() + ", new text";
    }
};

int main()
{
    Book* book = new Electronic("New book");
    Book* ibook = new WrappingFirst(book);

    book = new WrappingFirst(book);
    book = new WrappingSecond(book);

    cout << book->reading() << endl;
}


#include <iostream>
#include <string>
using namespace std;

class Text
{
public:
    virtual string render() = 0;
    virtual ~Text() {}
};

class PlainText : public Text
{
private:
    string value;

public:
    PlainText(const string& v) : value(v) {}

    string render() override
    {
        return value;
    }
};

class TextDecorator : public Text
{
protected:
    Text* wrapped;

public:
    TextDecorator(Text* t) : wrapped(t) {}
};

class BoldDecorator : public TextDecorator
{
public:
    BoldDecorator(Text* t) : TextDecorator(t) {}

    string render() override
    {
        return "<b>" + wrapped->render() + "</b>";
    }
};

class ItalicDecorator : public TextDecorator
{
public:
    ItalicDecorator(Text* t) : TextDecorator(t) {}

    string render() override
    {
        return "<i>" + wrapped->render() + "</i>";
    }
};

class UnderlineDecorator : public TextDecorator
{
public:
    UnderlineDecorator(Text* t) : TextDecorator(t) {}

    string render() override
    {
        return "<u>" + wrapped->render() + "</u>";
    }
};

int main()
{
    Text* text = new PlainText("Hello");
    Text* bold = new BoldDecorator(text);
    Text* boldItalic = new ItalicDecorator(bold);
    Text* underline = new UnderlineDecorator(boldItalic);

    cout << underline->render() << endl;
}


#include <iostream>
#include <string>
using namespace std;

class Coffee
{
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee
{
public:
    string getDescription() override
    {
        return "Coffee";
    }

    double getCost() override
    {
        return 100.0;
    }
};

class CoffeeDecorator : public Coffee
{
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
};

class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override
    {
        return coffee->getDescription() + ", milk";
    }

    double getCost() override
    {
        return coffee->getCost() + 20.0;
    }
};

class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override
    {
        return coffee->getDescription() + ", sugar";
    }

    double getCost() override
    {
        return coffee->getCost() + 10.0;
    }
};

int main()
{
    Coffee* coffee = new SimpleCoffee();
    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);

    cout << coffee->getDescription() << endl;
    cout << coffee->getCost() << endl;
}


#include <iostream>
#include <memory>
using namespace std;

class Service
{
public:
    virtual void execute() = 0;
};

class BaseService : public Service
{
public:
    void execute() override
    {
        cout << "Main logic\n";
    }
};

class LoggingDecorator : public Service
{
    Service* service;

public:
    LoggingDecorator(Service* s) : service(s) {}

    void execute() override
    {
        cout << "Log start\n";
        service->execute();
        cout << "Log end\n";
    }
};

class DataSource
{
public:
    virtual int getData() = 0;
};

class RealData : public DataSource
{
public:
    int getData() override
    {
        cout << "Load data\n";
        return 42;
    }
};

class CacheDecorator : public DataSource
{
    DataSource* source;
    bool cached = false;
    int value;

public:
    CacheDecorator(DataSource* s) : source(s) {}

    int getData() override
    {
        if (!cached)
        {
            value = source->getData();
            cached = true;
        }
        return value;
    }
};

int main()
{
    shared_ptr<Service> service = make_shared<BaseService>();
    shared_ptr<Service> loggedService = make_shared<LoggingDecorator>(service.get());

    loggedService->execute();

    shared_ptr<DataSource> dataSource = make_shared<RealData>();
    shared_ptr<DataSource> cachedDataSource = make_shared<CacheDecorator>(dataSource.get());

    cout << "Data: " << cachedDataSource->getData() << endl;

    cout << "Data: " << cachedDataSource->getData() << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Character
{
public:
    virtual int damage() = 0;
    virtual ~Character() {}
};

class BaseCharacter : public Character
{
public:
    int damage() override
    {
        return 10;
    }
};

class DamageDecorator : public Character
{
protected:
    shared_ptr<Character> ch;
    int boost;

public:
    DamageDecorator(shared_ptr<Character> c, int b) : ch(c), boost(b) {}

    int damage() override
    {
        return ch->damage() + boost;
    }
};

int main()
{
    auto baseChar = make_shared<BaseCharacter>();

    vector<shared_ptr<Character>> decorators;

    decorators.push_back(make_shared<DamageDecorator>(baseChar, 5));

    decorators.push_back(make_shared<DamageDecorator>(decorators.back(), 3));

    int totalDamage = decorators.back()->damage();

    cout << "Total damage: " << totalDamage << endl;

    return 0;
}


#include <iostream>
#include <memory>
using namespace std;

class Decorator : public Text
{
protected:
    shared_ptr<Text> text;

public:
    Decorator(shared_ptr<Text> t) : text(t) {}
};


#include <iostream>
#include <string>
#include <memory>

struct IMessage {
    virtual std::string process(const std::string& data) = 0;
    virtual ~IMessage() {}
};

class Message : public IMessage {
public:
    std::string process(const std::string& data) override {
        return data;
    }
};

class EncryptDecorator : public IMessage {
    std::shared_ptr<IMessage> inner;
public:
    EncryptDecorator(std::shared_ptr<IMessage> obj) : inner(obj) {}

    std::string process(const std::string& data) override {
        std::string encrypted = "[ENCRYPT]" + data + "[/ENCRYPT]";
        return inner->process(encrypted);
    }
};

class CompressDecorator : public IMessage {
    std::shared_ptr<IMessage> inner;
public:
    CompressDecorator(std::shared_ptr<IMessage> obj) : inner(obj) {}

    std::string process(const std::string& data) override {
        std::string compressed = "[COMPRESS]" + data + "[/COMPRESS]";
        return inner->process(compressed);
    }
};

class LogDecorator : public IMessage {
    std::shared_ptr<IMessage> inner;
public:
    LogDecorator(std::shared_ptr<IMessage> obj) : inner(obj) {}

    std::string process(const std::string& data) override {
        std::cout << "Лог: Обработка данных: " << data << std::endl;
        return inner->process(data);
    }
};

int main() {
    std::string rawMessage = "Привет, мир!";

    auto baseMessage = std::make_shared<Message>();

    auto encrypted = std::make_shared<EncryptDecorator>(baseMessage);
    auto compressed = std::make_shared<CompressDecorator>(encrypted);
    auto logged = std::make_shared<LogDecorator>(compressed);

    std::string result = logged->process(rawMessage);
    std::cout << "Итоговое сообщение: " << result << std::endl;

    auto simpleLogged = std::make_shared<LogDecorator>(encrypted);
    std::string result2 = simpleLogged->process(rawMessage);
    std::cout << "Обработка без сжатия: " << result2 << std::endl;

    return 0;
}
