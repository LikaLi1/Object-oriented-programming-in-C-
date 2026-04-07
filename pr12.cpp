#include <iostream>
#include <string>
#include <map>
#include <vector>

class Singleton {
private:
    Singleton() {}
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void print() {
        std::cout << "Singleton instance at: " << this << std::endl;
    }
};


void testSingleton() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    std::cout << "Address of s1: " << &s1 << std::endl;
    std::cout << "Address of s2: " << &s2 << std::endl;

    if (&s1 == &s2) {
        std::cout << "Simple\n";
    } else {
        std::cout << "Different\n";
    }
}


void testPrint() {
    auto& instance = Singleton::getInstance();
    instance.print();
    instance.print();
}


class CounterSingleton {
private:
    int count = 0;
    CounterSingleton() {}
public:
    CounterSingleton(const CounterSingleton&) = delete;
    CounterSingleton& operator=(const CounterSingleton&) = delete;

    static CounterSingleton& getInstance() {
        static CounterSingleton instance;
        return instance;
    }

    void increment() {
        ++count;
    }

    int getCount() const {
        return count;
    }
};


class App {
private:
    std::string appName;
    App() : appName("MyApplication") {}

public:
    App(const App&) = delete;
    App& operator=(const App&) = delete;

    static App& getInstance() {
        static App instance;
        return instance;
    }

    void printName() const {
        std::cout << "Application Name: " << appName << std::endl;
    }
};


class Config {
private:
    int volume = 50;
    Config() {}
public:
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    static Config& getInstance() {
        static Config instance;
        return instance;
    }

    void setVolume(int v) {
        volume = v;
    }

    int getVolume() const {
        return volume;
    }
};


void functionA() {
    Config& config = Config::getInstance();
    config.setVolume(75);
    std::cout << "Function A set volume to " << config.getVolume() << std::endl;
}

void functionB() {
    Config& config = Config::getInstance();
    std::cout << "Function B reads volume: " << config.getVolume() << std::endl;
}


class Logger {
public:
    static void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};


void processA() {
    Logger::log("Start process A");
}

void processB() {
    Logger::log("Start process B");
}


class DataManager {
private:
    std::map<std::string, int> data;
    DataManager() {}
public:
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;

    static DataManager& getInstance() {
        static DataManager instance;
        return instance;
    }

    void addValue(const std::string& key, int value) {
        data[key] = value;
    }

    int getValue(const std::string& key) const {
        auto it = data.find(key);
        return (it != data.end()) ? it->second : 0;
    }
};


class UserManager {
private:
    std::vector<std::string> users;
    UserManager() {}

public:
    UserManager(const UserManager&) = delete;
    UserManager& operator=(const UserManager&) = delete;

    static UserManager& getInstance() {
        static UserManager instance;
        return instance;
    }

    void addUser(const std::string& username) {
        users.push_back(username);
    }

    void printUsers() const {
        std::cout << "Users:" << std::endl;
        for (const auto& user : users) {
            std::cout << "- " << user << std::endl;
        }
    }
};


class ObjectCounter {
private:
    int count = 0;
    ObjectCounter() {}
public:
    ObjectCounter(const ObjectCounter&) = delete;
    ObjectCounter& operator=(const ObjectCounter&) = delete;

    static ObjectCounter& getInstance() {
        static ObjectCounter instance;
        return instance;
    }

    void createObject() {
        ++count;
    }

    int getCount() const {
        return count;
    }
};

void createObject() {
    ObjectCounter::getInstance().createObject();
}
