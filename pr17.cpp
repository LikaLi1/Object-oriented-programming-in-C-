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


#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class Player
{
private:
    int x;
    int y;
    int hp;

public:
    Player() : x(0), y(0), hp(100) {}

    void moveUp()
    {
        y++;
        cout << "Player move up. Position: " << x << ", " << y << endl;
    }

    void moveDown()
    {
        y--;
        cout << "Player move down. Position: " << x << ", " << y << endl;
    }

    void moveLeft()
    {
        x--;
        cout << "Player move left. Position: " << x << ", " << y << endl;
    }

    void moveRight()
    {
        x++;
        cout << "Player move right. Position: " << x << ", " << y << endl;
    }

    void attack()
    {
        cout << "Player attacked\n";
    }

    void help()
    {
        hp += 10;
        if (hp > 100)
        {
            hp = 100;
        }
        cout << "Player helped\n";
    }

    void defend()
    {
        cout << "Player defended\n";
    }
};

class MoveUpCommand : public Command
{
private:
    Player* player;

public:
    MoveUpCommand(Player* p) : player(p) {}

    void execute() override
    {
        player->moveUp();
    }
};

class MoveDownCommand : public Command
{
private:
    Player* player;

public:
    MoveDownCommand(Player* p) : player(p) {}

    void execute() override
    {
        player->moveDown();
    }
};

class MoveLeftCommand : public Command
{
private:
    Player* player;

public:
    MoveLeftCommand(Player* p) : player(p) {}

    void execute() override
    {
        player->moveLeft();
    }
};

class MoveRightCommand : public Command
{
private:
    Player* player;

public:
    MoveRightCommand(Player* p) : player(p) {}

    void execute() override
    {
        player->moveRight();
    }
};

class PosihionButton
{
private:
    Command* buttonW;
    Command* buttonS;
    Command* buttonA;
    Command* buttonD;

public:
    void setCommands(Command* w, Command* s, Command* a, Command* d)
    {
        buttonW = w;
        buttonS = s;
        buttonA = a;
        buttonD = d;
    }
    void pressW()
    {
        buttonW->execute();
    }

    void pressS()
    {
        buttonS->execute();
    }
    void pressA()
    {
        buttonA->execute();
    }
    void pressD()
    {
        buttonD->execute();
    }
};

class AttackCommand : public Command
{
private:
    Player* player;

public:
    AttackCommand(Player* p) : player(p) {}
    void execute() override
    {
        player->attack();
    }
};

class HelpCommand : public Command
{
private:
    Player* player;

public:
    HelpCommand(Player* p) : player(p) {}
    void execute() override
    {
        player->help();
    }
};

class DefendCommand : public Command
{
private:
    Player* player;

public:
    DefendCommand(Player* p) : player(p) {}
    void execute() override
    {
        player->defend();
    }
};

class Controller
{
private:
    Command* button1;
    Command* button2;
    Command* button3;

public:
    Controller(Command* b1, Command* b2, Command* b3)
    {
        button1 = b1;
        button2 = b2;
        button3 = b3;
    }

    void pressButton1()
    {
        button1->execute();
    }

    void pressButton2()
    {
        button2->execute();
    }

    void pressButton3()
    {
        button3->execute();
    }
};

int main()
{
    Player player;

    MoveUpCommand up(&player);
    MoveDownCommand down(&player);
    MoveLeftCommand left(&player);
    MoveRightCommand right(&player);

    AttackCommand attack(&player);
    HelpCommand help(&player);
    DefendCommand defend(&player);

    PosihionButton input;
    input.setCommands(&up, &down, &left, &right);

    Controller controller (&attack, &help, &defend);

    input.pressW();
    input.pressD();
    input.pressA();
    input.pressS();

    controller.pressButton1();
    controller.pressButton2();
    controller.pressButton3();

    return 0;
}
