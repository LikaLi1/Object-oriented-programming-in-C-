#include <iostream>
using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    void print() {
        cout << "Point cordinates: " << x << " " << y << endl;
    }
};

int main()
{
    Point p1;
    p1.print();
}


#include <iostream>
using namespace std;

class Rectangle {
public:
    int width;
    int height;

    Rectangle(int a, int b) {
        width = a;
        height = b;
    }

    void area() {
        cout << "Area: " << width * height << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << (width + height) * 2 << endl;
    }
};

int main()
{
    Rectangle r1(10, 5);
    r1.area();
    r1.perimeter();
}


#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student() {
        name = "0";
        age = 0;
    }

    Student(string a, int b) {
        name = a;
        age = b;
    }

    void print() {
        cout << "Student: " << name << " " << age << endl;
    }
};

int main()
{
    Student s1("Unknown", 0);
    s1.print();
}


#include <iostream>
using namespace std;

class Array {
private:
    int* data;

public:
    Array() {
        data = new int[10];
    }

    ~Array() {
        delete[] data;
    }

    void fill() {
        std::cout << "Enter array:\n";
        for (int i = 0; i < 10; ++i) {
            std::cin >> data[i];
        }
    }

    void print() const {
        std::cout << "Array: ";
        for (int i = 0; i < 10; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;
    }
};

int main()
{
    Array arr;
    arr.fill();
    arr.print();
}
