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
