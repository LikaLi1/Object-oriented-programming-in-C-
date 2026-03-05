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
			cout << "Машина заведена" << endl;
		}
		else {
			cout << "Машина не заведена" << endl;
		}
	}

	void getSpeed() 
	{
		return speed;
	}
};

int main() {
	Car c1;

	c1.setSpeed(50);
	c1.getSpeed();
	cout << "Машина со скорость: " << c1.getSpeed << endl;

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


class Shape {
private:
	string type;

public:
	Shape(string t)
	{
		type = t;
	}

	void area(int t)
	{
		if (t > 0) 
		{
			cout << "Фигура существует" << endl;
		}
	}

	void displayInfo() 
	{
		cout << "Area: " << area << endl;
	}
};

class Rectangle : public Shape
{
private:
	int size;

public:
	Rectangle(int s) : Shape(t)
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
