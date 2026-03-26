#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}

    friend ostream& operator<<(ostream& out, const Number& n);
};

ostream& operator<<(ostream& out, const Number& n) {
    out << "Value: " << n.value;
    return out;
}

int main()
{
    Number n(6);
    cout << n;
}


#include <iostream>
using namespace std;

class Value 
{
private:
    int SumValue;
public:
    Value(int v) { this->SumValue = v; }

    friend int sum(Value a, Value b);
};

int sum(Value a, Value b) 
{
    return a.SumValue + b.SumValue;
}

int main()
{
    Value v1(10);
    Value v2(20);

    std::cout << "Sum: " << sum(v1, v2) << std::endl;
}


#include <iostream>
using namespace std;

class Data
{
private:
    int MaxNum;
public:
    Data(int m) : MaxNum(m) {}

    friend bool comparison(Data a1, Data a2);
};

bool comparison(Data a1, Data a2)
{
    return a1.MaxNum > a2.MaxNum;
}

int main()
{
    Data a1(1000);
    Data a2(20);

    if (comparison(a1, a2))
        cout << "First number is max\n";
    else 
        cout << "Second number is max\n";
}


#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    friend double distance(Point p1, Point p2);
};

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    Point p1(0, 0);
    Point p2(5, 9);

    cout << distance(p1, p2);
}


#include <iostream>
using namespace std;

class Multiplier
{
private:
    int TwoMul;
public:
    Multiplier(int m) { this->TwoMul = m; }

    friend int mul(Multiplier a, Multiplier b);
};

int mul(Multiplier a, Multiplier b)
{
    return a.TwoMul * b.TwoMul;
}

int main()
{
    Multiplier m1(2);
    Multiplier m2(50);

    cout << mul(m1, m2);
}


#include <iostream>
using namespace std;

class Number
{
private:
    int value;
public:
    Number(int v) : value(v) {}

    int getValue() const { return value; }

    friend ostream& operator<<(ostream& out, const Number& n);
    friend Number operator -(const Number& n1, const Number& n2);
};

ostream& operator<<(ostream& out, const Number& n) {
    out << n.value;
    return out;
}

Number operator -(const Number& n1, const Number& n2) {
    return Number(n1.value - n2.value);
}

int main()
{
    Number n1(2);
    Number n2(50);
    Number result = n1 - n2;

    std::cout << "Difference: " << result << std::endl;
}


#include <iostream>
using namespace std;

class Container
{
private:
    int value;
public:
    Container(int v) : value(v) {}

    friend void swap(Container& a, Container& b);
};

void swap(Container& a, Container& b) 
{
    int temp = a.value;
    a.value = b.value;
    b.value = temp;
}

int main()
{
    Container b1(4);
    Container b2(5);

    swap(b1, b2);
}


#include <iostream>
using namespace std;

class Value
{
private:
    double MinValue;
public:
    Value(int mv) : MinValue(mv) {}

    friend Value min(Value a1, Value a2, Value a3);

    double getMinValue() const { return MinValue; }
};

Value min(Value a1, Value a2, Value a3)
{
    if (a1.MinValue <= a2.MinValue && a1.MinValue <= a3.MinValue) {
        return a1;
    }
    else if (a2.MinValue <= a1.MinValue && a2.MinValue <= a3.MinValue) {
        return a2;
    }
    else {
        return a3;
    }
}

int main()
{
    Value a1(9);
    Value a2(40);
    Value a3(6);

    Value minimum = min(a1, a2, a3);
    cout << "Min: " << minimum.getMinValue() << endl;
}


#include <iostream>
using namespace std;

class Employee
{
private:
    int salary;
public:
    Employee(int mv) : salary(mv) {}

    friend Employee min(Employee a1, Employee a2, Employee a3);

    double getMinValue() const { return salary; }
};

Employee min(Employee a1, Employee a2, Employee a3)
{
    if (a1.salary >= a2.salary && a1.salary >= a3.salary) {
        return a1;
    }
    else if (a2.salary >= a1.salary && a2.salary >= a3.salary) {
        return a2;
    }
    else {
        return a3;
    }
}

int main()
{
    Employee a1(90000);
    Employee a2(400000);
    Employee a3(600000);

    Employee minimum = min(a1, a2, a3);
    cout << "Max: " << minimum.getMinValue() << endl;
}


#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    friend double distance(Point p1, Point p2);
};

double distance(Point p1, Point p2) 
{
    return (p1.x + p2.x) + (p1.y + p2.y);
}

int main()
{
    Point p1(8, 6);
    Point p2(4, 9);

    cout << distance(p1, p2);
}
