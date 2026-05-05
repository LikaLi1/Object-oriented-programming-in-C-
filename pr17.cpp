#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class HelloCommand
{
public:
    void message() {
        cout << "Message was send\n";
    }
};

class Light
{
public:
    void turnOn() {
        cout << "Turn On\n";
    }

    void turnOff() {
        cout << "Turn Off\n";
    }

    void turnPause()
    {
        cout << "Turn Pause\n";
    }
};

class TurnOnCommand : public Command
{
private:
    Light* light;

public:
    TurnOnCommand(Light* l) : light(l) {}

    void execute() override
    {
        light->turnOn();
    }
};

class TurnOffCommand : public Command
{
private:
    Light* light;

public:
    TurnOffCommand(Light* l) : light(l) {}

    void execute() override
    {
        light->turnOff();
    }
};

class TurnPauseCommand : public Command
{
private:
    Light* light;

public:
    TurnPauseCommand(Light* l) : light(l) {}

    void execute() override
    {
        light->turnPause();
    }
};

class Button 
{
private:
    Command* command;

public:
    void setCommand(Command* c)
    {
        command = c;
    }

    void pressButton()
    {
        command->execute();
    }
};

int main()
{
    Light lamp;

    TurnOnCommand on(&lamp);
    TurnOffCommand off(&lamp);
    TurnPauseCommand pause(&lamp);

    Button remote;

    remote.setCommand(&on);
    remote.pressButton();

    remote.setCommand(&off);
    remote.pressButton();

    remote.setCommand(&pause);
    remote.pressButton();

    return 0;
}
