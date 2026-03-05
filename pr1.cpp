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

	cout << "До изменения:" << endl;
	cout << "Student 1: " << s1.getName() << endl;
	cout << "Student 2: " << s2.getName() << endl;

	changeName(s1, "Алексей");

	cout << "После изменения:" << endl;
	cout << "Student 1: " << s1.getName() << endl;

	return 0;
}


class Animal {
private:
	string name;

public:
	Animal(string n) {
		name = n;
	}
};

class Dog {
private:
	string breed;

public:
	Dog(string b) {
		breed = b;
	}
};

