#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update(int data) = 0;
};

class Subject
{
    vector<Observer*> observers;
public:
    void addObserver(Observer* o)
    {
        observers.push_back(o);
    }
    void notify(int data)
    {
        for (auto o : observers)
            o->update(data);
    }
};

class Logger : public Observer
{
public:
    void update(int data) override
    {
        cout << "Log updated\n";
    }
};

class UI : public Observer
{
public:
    void update(int data) override
    {
        cout << "UI updated\n";
    }
};
 
class UX : public Observer
{
public:
    void update(int data) override
    {
        cout << "UX updated\n";
    }
};

class Data
{
private:
    int d;
    Subject* subject;

public:
    Data(Subject* sub) : d(0), subject(sub) {}
    void setD(int newD)
    {
        if (d != newD)
        {
            d == newD;
            if (subject)
            {
                subject->notify(d);
            }
        }
    }
    int getD() const
    {
        return d;
    }
};

int main()
{
    Subject s;

    Logger l;
    UI i;
    UX x;

    s.addObserver(&l);
    s.addObserver(&i);
    s.addObserver(&x);

    s.notify(50);

    Data da(&s);

    da.setD(10);
    da.setD(15);
    da.setD(20);
    da.setD(20);
    
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
	virtual void update() = 0;
};

class Button
{
	vector <Observer*> observers;
public:
	void addObserver(Observer* o)
	{
		observers.push_back(o);
	}

	void click()
	{
		cout << "Button clicked\n";
		for (auto o : observers) 
		{
			o->update();
		}
	}
};

class Save : public Observer
{
public:
	void update() override
	{
		cout << "Saving\n";
	}
};

class Print : public Observer
{
public:
	void update() override
	{
		cout << "Print\n";
	}
};

class Log : public Observer
{
public:
	void update() override
	{
		cout << "Logging\n";
	}
};

int main()
{
	Button btn;

	Save s;
	Print p;
	Log l;

	btn.addObserver(&s);
	btn.addObserver(&p);
	btn.addObserver(&l);

	btn.click();
}


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Observer
{
public:
	virtual void update(int code) = 0;
};

class Log : public Observer
{
	vector<Observer*> observers;

public:
	void addObserver(Observer* o)
	{
		observers.push_back(o);
	}

    void logEvent(int code)
    {
        cout << "Log in console " << code << endl;

        static ofstream logFile("log.txt", ios::app);
        if (logFile.is_open())
        {
            logFile << "Log in file " << code << endl;
        }
        else
        {
			cerr << "Not found\n";
        }
    }

    void update(int code) override
    {
        logEvent(code);
    }
};

class EventLogger : public Observer
{
public:
	void update(int code) override
	{
		cout << "Event code: " << code << endl;
	}
};

int main()
{
	Log logger;
	EventLogger eventLogger;

	logger.addObserver(&eventLogger);

	int eventCode = 123;

	logger.logEvent(eventCode);

	logger.update(eventCode);

	return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update(double temperature) = 0;
};

class TemperatureSensor
{
private:
    double temperature;
    vector<Observer*> observers;

public:
    void addObserver(Observer* o)
    {
        observers.push_back(o);
    }

    void setTemperature(double newTemp)
    {
        if (newTemp != temperature)
        {
            temperature = newTemp;
            notifyObservers();
        }
    }

    void notifyObservers()
    {
        for (auto o : observers)
        {
            o->update(temperature);
        }
    }
};

class ScreenDisplay : public Observer
{
public:
    void update(double temperature) override
    {
        cout << "Tenp = " << temperature << "C" << endl;
    }
};

class WarningSystem : public Observer
{
private:
    double threshold;

public:
    WarningSystem(double t) : threshold(t) {}

    void update(double temperature) override
    {
        if (temperature > threshold)
        {
            cout << "Be carefule: " << temperature << "°C\n";
        }
        else
        {
            cout << "Ok\n";
        }
    }
};

int main()
{
    TemperatureSensor sensor;

    ScreenDisplay display;
    WarningSystem warning(30.0);

    sensor.addObserver(&display);
    sensor.addObserver(&warning);

    sensor.setTemperature(25.0);
    sensor.setTemperature(35.0);

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update(int damage) = 0;
};

class Player
{
    int hp = 100;
    vector<Observer*> observers;

public:
    void addObserver(Observer* o)
    {
        observers.push_back(o);
    }

    void takeDamage(int dmg)
    {
        hp -= dmg;
        notify(dmg);
    }

    void notify(int dmg)
    {
        for (auto o : observers)
            o->update(dmg);
    }
};

class Animation : public Observer
{
public:
    void update(int dmg) override
    {
        cout << "Play animation\n";
    }
};

class Sound : public Observer
{
public:
    void update(int dmg) override
    {
        cout << "Play sound\n";
    }
};

int main()
{
    Player player;
    Animation anim;
    Sound sound;

    player.addObserver(&anim);
    player.addObserver(&sound);

    player.takeDamage(20);
    player.takeDamage(50);
    player.takeDamage(40);

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class BehaviorStrategy {
public:
    virtual void execute() const = 0;
    virtual ~BehaviorStrategy() = default;
};

class WelcomeStrategy : public BehaviorStrategy {
public:
    void execute() const override {
        cout << "Privet\n";
    }
};

class LogoutStrategy : public BehaviorStrategy {
public:
    void execute() const override {
        cout << "Poka\n";
    }
};

class EventObserver {
    unique_ptr<BehaviorStrategy> strategy;
public:
    EventObserver(unique_ptr<BehaviorStrategy> strat)
        : strategy(move(strat)) {
    }

    void notify()
    {
        strategy->execute();
    }
};

int main() {
    EventObserver loginObserver(make_unique<WelcomeStrategy>());
    EventObserver logoutObserver(make_unique<LogoutStrategy>());

    loginObserver.notify();
    logoutObserver.notify();

    return 0;
}


#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Observer
{
public:
    virtual void update() = 0;
};

class LoggerObserver : public Observer
{
public:
    void update() override { cout << "Log\n"; }
};

class AnalyticsObserver : public Observer
{
public:
    void update() override { cout << "Event\n"; }
};

class ObserverFactory
{
public:
    static unique_ptr<Observer> createObserver(const string& type)
    {
        if (type == "logger")
            return make_unique<LoggerObserver>();
        else if (type == "analytics")
            return make_unique<AnalyticsObserver>();
        else
            return nullptr;
    }
};

int main()
{
    auto observer1 = ObserverFactory::createObserver("logger");
    auto observer2 = ObserverFactory::createObserver("analytics");
    if (observer1) observer1->update();
    if (observer2) observer2->update();
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void update() = 0;
};

class Obs1 : public Observer
{
public:
    void update() override { cout << "Update\n"; }
};

class Obs2 : public Observer
{
public:
    void update() override { cout << "Obs2 update\n"; }
};

int main() {
    vector<Observer*> observers;
    observers.push_back(new Obs1());
    observers.push_back(new Obs2());

    for_each(observers.begin(), observers.end(), [](Observer* o) 
        { o->update(); });

    for (auto o : observers) delete o;

    return 0;
}

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Event
{
public:
    using Handler = function<void()>;

    void subscribe(Handler h) { handlers.push_back(h); }
    void emit()
    {
        for (auto& h : handlers)
            h();
    }
private:
    vector<Handler> handlers;
};

int main()
{
    Event e;

    e.subscribe([] { cout << "Lambda 1\n"; });
    e.subscribe([] { cout << "Lambda 2\n"; });

    e.emit();

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>

using namespace std;

class EventManager
{
public:
    using Handler = function<void()>;

    void subscribe(const string& eventName, Handler handler)
    {
        subscribers[eventName].push_back(handler);
    }

    void emit(const string& eventName)
    {
        auto it = subscribers.find(eventName);
        if (it != subscribers.end())
        {
            for (auto& handler : it->second)
                handler();
        }
    }

private:
    unordered_map<string, vector<Handler>> subscribers;
};

int main()
{
    EventManager manager;

    manager.subscribe("click", [] { cout << "click\n"; });
    manager.subscribe("hover", [] { cout << "hover\n"; });

    manager.emit("click");
    manager.emit("hover");
    manager.emit("click");
    return 0;
}
