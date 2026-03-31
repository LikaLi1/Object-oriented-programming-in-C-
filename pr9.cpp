#include <iostream>
using namespace std;

class Box
{
private:
    double x;
    double y;
    double z;
public:
    Box(double x, double y, double z) : x(x), y(y), z(z) {}

    void show() {
        cout << "Length: " << x << " Width: " << y << " Height: " << z << endl;
    }

    friend Box operator+(const Box& b1, const Box& b2);
};

Box operator+(const Box& b1, const Box& b2) {
    return Box(b1.x + b2.x, b1.y + b2.y, b1.z + b2.z);
}

int main() {
    Box b1(5, 9, 8);
    Box b2(7, 2, 3);

    Box result = b1 + b2;
    result.show();

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string name;
public:
    User(string n) : name(n) {}

    friend bool operator==(const User& u1, const User& u2);

    friend ostream& operator<<(ostream& os, const User& u);
};

bool operator==(const User& u1, const User& u2) {
    return u1.name == u2.name;
}

ostream& operator<<(ostream& os, const User& u) {
    os << "User: " << u.name;
    return os;
}

int main() {
    User u1("Ivan");
    User u2("Ivan");
    User u3("Peter");

    cout << u1 << endl;
    cout << u2 << endl;
    cout << u3 << endl;

    cout << "u1 == u2? " << (u1 == u2 ? "Да" : "Нет") << endl;
    cout << "u1 == u3? " << (u1 == u3 ? "Да" : "Нет") << endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string name;
    int age;
public:
    User(string n, int a) : name(n), age(a) {}

    friend ostream& operator<<(ostream& os, const User& u);
};

ostream& operator<<(ostream& os, const User& u) {
    return os << "User: " << u.name << ", Age: " << u.age;
}

int main() {
    User u1("Ivan", 30);
    User u2("Ivan", 28);
    User u3("Peter", 16);

    cout << u1 << endl;
    cout << u2 << endl;
    cout << u3 << endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;
public:
    Student() : name(""), age(0) {}

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);
};

ostream& operator<<(ostream& os, const Student& s) {
    return os << "User: " << s.name << ", Age: " << s.age;
}
istream& operator>>(istream& is, Student& s) {
    cout << "Enter name: ";
    is >> s.name;
    cout << "Enter age: ";
    is >> s.age;
}

int main() {
    Student s1, s2;

    cout << "S1:" << endl;
    cin >> s1;
    cout << "S2" << endl;
    cin >> s2;

    cout << "Student 1: " << s1 << endl;
    cout << "Student 2: " << s2 << endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Score
{
private:
    int num;
public:
    Score(int n) : num(n) {}

    bool operator>(const Score& s) const { return this->num > s.num; }
    
    int getNum() const { return num; }
};

Score Max(const Score s1, const Score s2, const Score s3) {
    if (s1 > s2 && s1 > s3) {
        return s1;
    }
    else if (s2 > s1 && s2 > s3) {
        return s2;
    }
    else {
        return s3;
    }
}

int main() {
    Score s1(458);
    Score s2(896);
    Score s3(764);

    Score max = Max(s1, s2, s3);
    cout << "Max score: " << max.getNum() << endl;
    
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Database
{
private:
    string data;
public:
    Database(const string& d) : data(d) {}

    void Info() const {
        cout << "Database info: " << data << endl;
    }

    friend class Admin;
};

class Admin {
public:
    void AdminDatabase(const Database& ad) {
        cout << "Admin database: " << ad.data << endl;
    }
};

int main() {
    Database ad("Server: ");
    Admin a;
    
    a.AdminDatabase(ad);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class System
{
private:
    int status = 200;
    string message = "OK";

    friend class Logger;
};

class Logger {
public:
    void log(const System& s) {
        cout << "Status: " << s.status << ", Message: " << s.message << endl;
    }
};

int main() {
    System s;
    Logger l;
    
    l.log(s);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Student;

class Teacher {
public:
    void showStudentDetails(const Student& s);
};

class Student {
private:
    string name;
    int age;

public:
    Student(const string& n, int a) : name(n), age(a) {}

    friend class Teacher;
};

void Teacher::showStudentDetails(const Student& s) {
    cout << "Student Name: " << s.name << endl;
    cout << "Student Age: " << s.age << endl;
}

int main() {
    Student s("Alice", 20);
    Teacher t;

    t.showStudentDetails(s);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class SecurityManager;

class SecureData {
private:
    string secretInfo;

public:
    SecureData(const string& info) : secretInfo(info) {}

    friend class SecurityManager;
};

class SecurityManager {
public:
    void accessSecureData(const SecureData& sd) {
        cout << "Accessing secure info: " << sd.secretInfo << endl;
    }
};

int main() {
    SecureData sd("Top Secret Data");
    SecurityManager sm;

    sm.accessSecureData(sd);

    return 0;
}


#include <iostream>
using namespace std;

class BankManager;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    friend class BankManager;
};

class BankManager {
public:
    void viewBalance(const Account& acc) {
        cout << "Current balance: " << acc.balance << endl;
    }

    void changeBalance(Account& acc, double amount) {
        acc.balance += amount;
        cout << "Balance updated. New balance: " << acc.balance << endl;
    }
};

int main() {
    Account myAccount(1000.0);
    BankManager manager;

    manager.viewBalance(myAccount);
    manager.changeBalance(myAccount, 250.0);
    manager.viewBalance(myAccount);

    return 0;
}
