#include <iostream>
using namespace std;

class Vector2D
{
private:
    int x;
    int y;

public:
    Vector2D(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2D operator+(const Vector2D& v)
    {
        return Vector2D(x + v.x, y + v.y);
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Vector2D v1(2, 3);
    Vector2D v2(4, 5);

    Vector2D v3 = v1 + v2;

    v3.print();
}


#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    bool operator==(const Student& s)
    {
        return name == s.name && age == s.age;
    }
};

int main()
{
    Student s1("Ivan", 20);
    Student s2("Ivan", 20);

    if (s1 == s2)
        cout << "Students are equal";
}


#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "Point: " << p.x << ", " << p.y;
        return out;
    }
};

int main()
{
    Point p(5, 7);

    cout << p;
}


#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "Point: " << p.x << ", " << p.y;
        return out;
    }
};

int main()
{
    Point p(5, 7);

    cout << p;
}


#include <iostream>
using namespace std;

class Money
{
private:
    int amount;

public:
    Money(int a)
    {
        amount = a;
    }

    Money operator+(const Money& m)
    {
        return Money(amount + m.amount);
    }

    Money operator-(const Money& m)
    {
        return Money(amount - m.amount);
    }

    bool operator==(const Money& m)
    {
        return amount == m.amount;
    }

    void print()
    {
        cout << amount << endl;
    }
};

int main()
{
    Money m1(100);
    Money m2(50);

    Money m3 = m1 + m2;
    Money m4 = m1 - m2;

    m3.print();
    m4.print();
}
