#include <iostream>
using namespace std;

class Implementor
{
public:
    virtual void implementorFirst(int numfirst) = 0;
    virtual void implementorSecond(int numsecond) = 0;
    virtual ~Implementor() {}
};

class ImplementorFirst : public Implementor
{
public:
    void implementorFirst(int numfirst) override
    {
        cout << "First" << endl;
    }
    void implementorSecond(int numsecond) override
    {
        cout << "Second" << endl;
    }
};

class ImplementorSecond : public Implementor
{
    void implementorFirst(int numfirst) override
    {
        cout << "Number first: " << numfirst << endl;
    }
    void implementorSecond(int numsecond) override
    {
        cout << "Number second: " << numsecond << endl;
    }
};

class Abstraction
{
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* i) : implementor(i) {}
    virtual void print() = 0;
    virtual ~Abstraction() {}
};

class PrintFirst : public Abstraction
{
private:
    int numfirst;

public:
    PrintFirst(Implementor* i, int numf) : Abstraction(i), numfirst(numf) {}
    void print() override
    {
        implementor->implementorFirst(numfirst);
    }
};

class PrintSecond : public Abstraction
{
private:
    int numsecond;

public:
    PrintSecond(Implementor* i, int nums) : Abstraction(i), numsecond(nums) {}
    void print() override
    {
        implementor->implementorSecond(numsecond);
    }
};

int main()
{
    ImplementorFirst implementorf;
    ImplementorSecond implementors;

    PrintFirst pf1(&implementorf, 10);
    PrintFirst pf2(&implementors, 10);

    PrintSecond ps1(&implementorf, 10);
    PrintSecond ps2(&implementors, 10);

    pf1.print();
    pf2.print();
    ps1.print();
    ps2.print();

    return 0;
}


#include <iostream>
using namespace std;

class Renderer
{
public:
    virtual void renderCircle(int radius) = 0;
    virtual void renderRectangle(int width, int height) = 0;
    virtual ~Renderer() {}
};

class RasterRenderer : public Renderer
{
public:
    void renderCircle(int radius) override
    {
        cout << "Drawing circle; Radius: " << radius << endl;
    }
    void renderRectangle(int width, int height) override
    {
        cout << "Drawing rectangle; Width: " << width << ", Height: " << height << endl;
    }
};

class VectorRenderer : public Renderer
{
    void renderCircle(int radius) override
    {
        cout << "Drawing circle; Radius: " << radius << endl;
    }
    void renderRectangle(int width, int height) override
    {
        cout << "Drawing rectangle; Width: " << width << ", Height: " << height << endl;
    }
};

class Shape
{
protected:
    Renderer* renderer;

public:
    Shape(Renderer* r) : renderer(r) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(Renderer* r, int rad) : Shape(r), radius(rad) {}
    void draw() override
    {
        renderer->renderCircle(radius);
    }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(Renderer* r, int w, int h) : Shape(r), width(w), height(h) {}
    void draw() override
    {
        renderer->renderRectangle(width, height);
    }
};

int main()
{
    RasterRenderer raster;
    VectorRenderer vector;

    Circle c1(&raster, 10);
    Circle c2(&vector, 10);

    Rectangle r1(&raster, 10, 5);
    Rectangle r2(&vector, 10, 5);

    c1.draw();
    c2.draw();
    r1.draw();
    r2.draw();

    return 0;
}


#include <iostream>
using namespace std;

class Renderer
{
public:
    virtual void renderCircle(int radius) = 0;
    virtual void renderRectangle(int width, int height) = 0;
    virtual ~Renderer() {}
};

class RasterRenderer : public Renderer
{
public:
    void renderCircle(int radius) override
    {
        cout << "Drawing circle; Radius: " << radius << endl;
    }
    void renderRectangle(int width, int height) override
    {
        cout << "Drawing rectangle; Width: " << width << ", Height: " << height << endl;
    }
};

class VectorRenderer : public Renderer
{
public:
    void renderCircle(int radius) override
    {
        cout << "Drawing circle; Radius: " << radius << " (vector)" << endl;
    }
    void renderRectangle(int width, int height) override
    {
        cout << "Drawing rectangle; Width: " << width << ", Height: " << height << " (vector)" << endl;
    }
};

class Shape
{
protected:
    Renderer* renderer;

public:
    Shape(Renderer* r) : renderer(r) {}
    virtual void draw() = 0;

    void setRenderer(Renderer* r)
    {
        renderer = r;
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(Renderer* r, int rad) : Shape(r), radius(rad) {}
    void draw() override
    {
        renderer->renderCircle(radius);
    }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(Renderer* r, int w, int h) : Shape(r), width(w), height(h) {}
    void draw() override
    {
        renderer->renderRectangle(width, height);
    }
};

int main()
{
    RasterRenderer raster;
    VectorRenderer vector;

    Circle c(&raster, 10);
    Rectangle r(&raster, 20, 10);

    c.draw();
    r.draw();

    c.setRenderer(&vector);
    c.draw();

    r.setRenderer(&vector);
    r.draw();

    return 0;
}


#include <iostream>
using namespace std;

class Renderer
{
public:
    virtual void renderCircle(int radius) = 0;
    virtual void renderRectangle(int width, int height) = 0;
    virtual void openGlRender(const string& text) = 0;
    virtual ~Renderer() {}
};

class RasterRenderer : public Renderer
{
public:
    void renderCircle(int radius) override
    {
        cout << "Drawing circle; Radius: " << radius << endl;
    }
    void renderRectangle(int width, int height) override
    {
        cout << "Drawing rectangle; Width: " << width << ", Height: " << height << endl;
    }
    void openGlRender(const string& text) override
    {
        cout << "OpenGL raster render: " << text << endl;
    }
};

class VectorRenderer : public Renderer
{
public:
    void renderCircle(int radius) override
    {
        cout << "Drawing circle; Radius: " << radius << " (vector)" << endl;
    }
    void renderRectangle(int width, int height) override
    {
        cout << "Drawing rectangle; Width: " << width << ", Height: " << height << " (vector)" << endl;
    }
    void openGlRender(const string& text) override
    {
        cout << "OpenGL vector render: " << text << endl;
    }
};

class Shape
{
protected:
    Renderer* renderer;

public:
    Shape(Renderer* r) : renderer(r) {}
    virtual void draw() = 0;
    void setRenderer(Renderer* r)
    {
        renderer = r;
    }
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    int radius;
    string text;

public:
    Circle(Renderer* r, int rad, const string& t) : Shape(r), radius(rad), text(t) {}
    void draw() override
    {
        renderer->renderCircle(radius);
        renderer->openGlRender(text);
    }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;
    string text;

public:
    Rectangle(Renderer* r, int w, int h, const string& t) : Shape(r), width(w), height(h), text(t) {}
    void draw() override
    {
        renderer->renderRectangle(width, height);
        renderer->openGlRender(text);
    }
};

int main()
{
    RasterRenderer raster;
    VectorRenderer vector;

    Circle c1(&raster, 10, "Raster");
    Circle c2(&vector, 10, "Vector");
    Rectangle r1(&raster, 20, 10, "Raster");
    Rectangle r2(&vector, 20, 10, "Vector");

    c1.draw();
    r1.draw();
    c2.draw();
    r2.draw();

    return 0;
}


#include <iostream>
using namespace std;

class Device
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setValume(int value) = 0;
    virtual ~Device() {}
};

class TV : public Device
{
public:
    void turnOn() override
    {
        cout << "TV turn on" << endl;
    }
    void turnOff() override
    {
        cout << "TV turn off" << endl;
    }
    void setValume(int value) override
    {
        cout << "TV value: " << value << endl;
    }
};

class Projector : public Device
{
public:
    void turnOn() override
    {
        cout << "Projector turn on" << endl;
    }
    void turnOff() override
    {
        cout << "Projector turn off" << endl;
    }
    void setValume(int value) override
    {
        cout << "Projector value: " << value << endl;
    }
};

class Radio : public Device
{
public:
    void turnOn() override
    {
        cout << "Radio turn on" << endl;
    }
    void turnOff() override
    {
        cout << "Radio turn off" << endl;
    }
    void setValume(int value) override
    {
        cout << "Radio value: " << value << endl;
    }
};

class Remote
{
protected:
    Device* device;

public:
    Remote(Device* d) : device(d) {}
    virtual void powerOn() 
    {
        device->turnOn();
    }
    virtual void powerOff()
    {
        device->turnOff();
    }
    virtual ~Remote() {}
};

class SmartRemote : public Remote
{
private:

public:
    SmartRemote(Device* d) : Remote(d) {}
    void mute()
    {
        device->setValume(0);
    }
};

class VoiceRemote : public Remote
{
private:

public:
    VoiceRemote(Device* d) : Remote(d) {}
    void mute()
    {
        device->setValume(0);
    }
};

int main()
{
    TV tv;
    Projector projector;
    Radio radio;

    SmartRemote s1(&tv);
    SmartRemote s2(&projector);
    SmartRemote s3(&radio);
    VoiceRemote v1(&tv);
    VoiceRemote v2(&projector);
    VoiceRemote v3(&radio);

    s1.mute();
    v1.mute();
    s2.mute();
    v2.mute();
    s3.mute();
    v3.mute();

    return 0;
}


#include <iostream>
using namespace std;

class Sender
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setValume(int value) = 0;
    virtual ~Sender() {}
};

class EmailSender : public Sender
{
public:
    void turnOn() override
    {
        cout << "TV turn on" << endl;
    }
    void turnOff() override
    {
        cout << "TV turn off" << endl;
    }
    void setValume(int value) override
    {
        cout << "TV value: " << value << endl;
    }
};

class Projector : public Sender
{
public:
    void turnOn() override
    {
        cout << "Projector turn on" << endl;
    }
    void turnOff() override
    {
        cout << "Projector turn off" << endl;
    }
    void setValume(int value) override
    {
        cout << "Projector value: " << value << endl;
    }
};

class Radio : public Sender
{
public:
    void turnOn() override
    {
        cout << "Radio turn on" << endl;
    }
    void turnOff() override
    {
        cout << "Radio turn off" << endl;
    }
    void setValume(int value) override
    {
        cout << "Radio value: " << value << endl;
    }
};

class Remote
{
protected:
    Sender* sender;

public:
    Remote(Sender* s) : sender(s) {}
    virtual void powerOn() 
    {
        sender->turnOn();
    }
    virtual void powerOff()
    {
        sender->turnOff();
    }
    virtual ~Remote() {}
};

class SmartRemote : public Remote
{
private:

public:
    SmartRemote(Sender* d) : Remote(d) {}
    void mute()
    {
        sender->setValume(0);
    }
};

class VoiceRemote : public Remote
{
private:

public:
    VoiceRemote(Sender* d) : Remote(d) {}
    void mute()
    {
        sender->setValume(0);
    }
};

int main()
{
    EmailSender EmailSender;
    Projector projector;
    Radio radio;

    SmartRemote s1(&tv);
    SmartRemote s2(&projector);
    SmartRemote s3(&radio);
    VoiceRemote v1(&tv);
    VoiceRemote v2(&projector);
    VoiceRemote v3(&radio);

    s1.mute();
    v1.mute();
    s2.mute();
    v2.mute();
    s3.mute();
    v3.mute();

    return 0;
}


#include <iostream>
using namespace std;

class Sender
{
public:
    virtual void send(string text) = 0;
    virtual ~Sender() {}
};

class EmailSender : public Sender
{
public:
    void send(string text) override
    {
        cout << "Email: " << text << endl;
    }
};

class SMSSender : public Sender
{
public:
    void send(string text) override
    {
        cout << "SMS: " << text << endl;
    }
};

class PushSender : public Sender
{
public:
    void send(string text) override
    {
        cout << "Push: " << text << endl;
    }
};

class Notification
{
protected:
    Sender* sender;

public:
    Notification(Sender* s) : sender(s) {}
    virtual void notify(string text)
    {
        sender->send(text);
    }
    virtual ~Notification() {}
};

class UrgentNotification : public Notification
{
public:
    UrgentNotification(Sender* s) : Notification(s) {}
    void notify(string text) override
    {
        sender->send("Urgent: " + text);
    }
};

class MarketingNotification : public Notification
{
public:
    MarketingNotification(Sender* s) : Notification(s) {}
    void notify(string text) override
    {
        sender->send("Marketing: " + text);
    }
};

int main()
{
    EmailSender emailSender;
    SMSSender smsSender;
    PushSender pushSender;

    Notification n1(&emailSender);
    UrgentNotification n2(&smsSender);
    MarketingNotification n3(&pushSender);

    n1.notify("Your email message");
    n2.notify("Your urgent SMS");
    n3.notify("New marketing offer");

    return 0;
}
