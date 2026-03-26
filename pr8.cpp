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
