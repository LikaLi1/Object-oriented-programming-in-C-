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

class Book {
private:
    string title;
    int pages;

public:
    Book(string t, int p) : title(t), pages(p) {
        title = t;
        pages = p;
    }

    void print() {
        cout << "Title: " << title << " Pages: " << pages << endl;
    }
};

int main()
{
    Book b1("Kolobok", 10);
    b1.print();
}


#include <iostream>
using namespace std;

class Number {
public:
    int value;

    Number(int v) {
        value = v;
    }

    Number(const Number& n) {
        value = n.value;
    }

    void print() {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Number n1(20);
    n1.print();
}


#include <iostream>
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Object created\n";
    }

    ~Test()
    {
        cout << "Object destroyed\n";
    }
};

int main() {
    {
        Test obj;
    }
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


#include <iostream>
using namespace std;

class Car {
public:
    string model;

    Car(const string& m) : model(m) {
        cout << "Car created " << model << endl;
    }

    ~Car() {
        cout << "Car destroyed " << model << endl;
    }
};

int main() {
    Car c1("LADA");
    Car c2("Toyota");
    Car c3("BMW");
}


#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int* data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int[rows * cols];
    }

    ~Matrix() {
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
    Matrix m(4, 8);
    m.fill();
    m.print();
}



#include <iostream>
using namespace std;

class BankAccount {
public:
    string owner;
    int balance;

    BankAccount() {
        owner = "0";
        balance = 0;
    }

    BankAccount(string a, int b) {
        owner = a;
        balance = b;
    }

    void deposit() {
        int amount;
        cout << "Enter sum: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Ok: " << amount << ". Balance: " << balance << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    void withdraw() {
        int amount;
        cout << "Enter sum: ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Ok: " << amount << ". Balance: " << balance << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    ~BankAccount() {
        cout << "Account closed" << endl;
        
    }


    void print() {
        cout << "Owner: " << owner << " Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1("Valeri", 2000);
    b1.deposit();
    b1.withdraw();
    b1.print();
}
