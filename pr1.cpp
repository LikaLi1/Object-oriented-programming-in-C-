#include <iostream>
using namespace std;

class Book {
private:
	string title;
	string author;
	int pages;

public:
	Book(string t, string a, int p)
	{
		title = t;
		author = a;
		pages = p;
	}

	void displayInfo() {
		cout << "Title: " << title << "Author: " << author << "Pages: " << pages << endl;
	}
};

int main() {
	Book b1("Капитанская дочка", "Пушкин", 18);

	b1.displayInfo();

	return 0;
}

class Student {
private:
	string name;
	int age;

public:
	Student(string n, int a)
	{
		name = n;
		age = a;
	}

	void display() {
		cout << "Name: " << name << "Age: " << age << endl;
	}
};

int main() {
	Student s1("Катя", 20);

	s1.display();

	return 0;
}

class Car {
private:
	int speed;

public:
	void setSpeed(int s)
	{
		if (s >= 0) {
			speed = s;
			cout << "Машина заведена" << endl;
		}
		else {
			cout << "Машина не заведена" << endl;
		}
	}

	int getSpeed()
	{
		return speed;
	}
};

int main() {
	Car c1;

	c1.setSpeed(50);
	c1.getSpeed();
	cout << "Машина со скорость: " << c1.getSpeed() << endl;

	return 0;
}

class Person {
protected:
	string name;
	int age;

public:
	Person(string n, int a)
	{
		name = n;
		age = a;
	}

	void displayInfoPerson()
	{
		cout << "Name: " << name << "Age: " << age << endl;
	}
};

class Employee : public Person
{
private:
	string position;

public:
	Employee(string n, int a, string p) : Person(n, a)
	{
		position = p;
	}

	void displayInfoEmployee()
	{
		displayInfoPerson();
		cout << "Position: " << position << endl;
	}
};

int main()
{
	Employee e1("Валера", 50, "IT");
	e1.displayInfoEmployee();

	return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	string type;

public:
	Shape(const string& t) : type(t) {}

	virtual double area() const = 0;

	void displayInfo() const
	{
		cout << "Фигура: " << type << endl;
		cout << "Площадь: " << area() << endl;
	}
};

class Rectangle : public Shape {
private:
	int width;
	int length;

public:
	Rectangle(int w, int l) : Shape("Rectangle") {}

	double area() const override
	{
		return width * length;
	}
};

class Circle : public Shape {
private:
	int radius;

public:
	Circle(int r) : Shape("Circle") {}

	double area() const override
	{
		return 3.14159 * radius * radius;
	}
};

int main() {
	Rectangle r(5, 10);
	Circle c(7);

	r.displayInfo();
	cout << endl;
	c.displayInfo();

	return 0;
}


class Point {
private:
	int x;
	int y;

public:
	Point(int x, int y)
	{
		x = x;
		y = y;
	}

	void displayInfo()
	{
		cout << "Point 1: " << x << "Point 2: " << y << endl;
	}
};

int main() {
	Point p1(5, 10);

	p1.displayInfo();

	return 0;
}


class BankAccount {
private:
	int balance;
	int accountNumber;

public:
	BankAccount(int b, int a)
	{
		balance = b;
		accountNumber = a;
	}

	void deposit(int amount)
	{
		if (amount > 0)
		{
			balance += amount;
			cout << "Сумма внесена: " << balance << endl;
		}
		else
		{
			cout << "Сумма должна быть положительной" << endl;
		}
	}

	void withdraw(int amount)
	{
		if (amount > 0 && balance > 0)
		{
			balance -= amount;
		}
		else if (amount <= 0)
		{
			cout << "Сумма должна быть положительной" << endl;
		}
		else if (amount > balance)
		{
			cout << "Недостаточно средств" << endl;
		}
		cout << "Остаток на счёте: " << balance << endl;
	}

	void display()
	{
		cout << "Номер счёта: " << accountNumber << endl;
		cout << "Текущий баланс: " << balance << endl;
	}
};

int main() {
	BankAccount account(1000, 123456);

	account.display();

	account.deposit(500);
	account.withdraw(300);
	account.withdraw(2000);

	account.display();

	return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;

public:
	Student(const string& n) : name(n) {}

	string getName() const {
		return name;
	}

	void setName(const string& n) {
		name = n;
	}
};

void changeName(Student& s, const string& newName) {
	s.setName(newName);
}

int main() {
	Student s1("Иван");
	Student s2("Мария");

	changeName(s1, "Алексей");

	return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
	string name;

public:
	Animal(string n) {}

	string getName() const {
		return name;
	}
};

class Dog : public Animal {
private:
	string breed;

public:
	Dog(string n, string b) : Animal(n), breed(b) {}

	string getBreed() const {
		return breed;
	}
};

int main() {
	Dog d1("Тузик", "Овчарка");

	return 0;
}


#include <iostream>
using namespace std;

class Rectangle {
private:
	double length;
	double width;

public:
	Rectangle(double l, double w) : length(l), width(w) {}

	double area() const {
		return length * width;
	}

	double perimeter() const {
		return 2 * (length + width);
	}
};

int main() {
	Rectangle r(5.0, 3.0);

	cout << "Площадь: " << r.area() << endl;
	cout << "Периметр: " << r.perimeter() << endl;

	return 0;
}


#include <iostream>
using namespace std;

class Counter {
private:
	int count;

public:
	Counter() : count(0) {}

	void increment() {
		count++;
	}
	int getCount() const {
		return count;
	}
};

int main() {
	Counter c;

	c.increment();
	c.increment();
	c.increment();

	cout << "Значение счетчика: " << c.getCount() << endl;

	return 0;
}


#include <iostream>
using namespace std;

class Vehicle {
public:
	virtual ~Vehicle() {}
	virtual void fuelEfficiency() const {
		cout << "Общая эффективность топлива транспортного средства." << endl;
	}
};

class Car : public Vehicle {
public:
	void fuelEfficiency() const override {
		cout << "Car: расход топлива 15 км/л." << endl;
	}
};

class Truck : public Vehicle {
public:
	void fuelEfficiency() const override {
		cout << "Truck: расход топлива 8 км/л." << endl;
	}
};

int main() {
	Vehicle* vehicles[2];

	vehicles[0] = new Car();
	vehicles[1] = new Truck();

	for (int i = 0; i < 2; i++) {
		vehicles[i]->fuelEfficiency();
	}

	for (int i = 0; i < 2; i++) {
		delete vehicles[i];
	}

	return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
	string title;
	string author;

public:
	Book(const string& t, const string& a) : title(t), author(a) {}

	void print() const {
		cout << "Книга: " << title << ", автор: " << author << endl;
	}
};

class Library {
private:
	vector<Book> books;

public:
	void addBook(const Book& b) {
		books.push_back(b);
	}

	void printBooks() const {
		for (const auto& book : books) {
			book.print();
		}
	}
};

int main() {
	Library lib;

	Book b1("Война и мир", "Лев Толстой");
	Book b2("Мастер и Маргарита", "Михаил Булгаков");
	Book b3("1984", "Джордж Оруэлл");

	lib.addBook(b1);
	lib.addBook(b2);
	lib.addBook(b3);

	lib.printBooks();

	return 0;
}
