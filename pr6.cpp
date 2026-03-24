#include <iostream>
using namespace std;

class Author
{
public:
	string firstname;

	Author(string firstname)
	{
		this->firstname = firstname;
	}
};

class Book
{
private:
	Author* author;
public:
	Book(Author* a)
	{
		author = a;
	}
	void show() {
		cout << "Author: " << author->firstname << endl;
	}
};

int main()
{
	Author a("Gagarin");
	Book b(&a);
	b.show();
}


#include <iostream>
using namespace std;

class Furniture
{
public:
	void image() 
	{
		cout << "He has furniture\n";
	}
};

class Room
{
private:
	Furniture furniture;
public:
	void imageRoom() 
	{
		furniture.image();
	}
};

int main()
{
	Room r;
	r.imageRoom();
}


#include <iostream>
using namespace std;

class Account
{
public:
	void registration()
	{
		cout << "Login to your account\n";
	}
};

class User
{
private:
	Account account;
public:
	void registrationUser()
	{
		account.registration();
	}
};

int main()
{
	User u;
	u.registrationUser();
}


#include <iostream>
using namespace std;

class Teacher
{
public:
	string firstname;

	Teacher(string firstname)
	{
		this->firstname = firstname;
	}
};

class School
{
private:
	Teacher* teacher;
public:
	School(Teacher* t)
	{
		teacher = t;
	}
	void show() {
		cout << "Teacher: " << teacher->firstname << endl;
	}
};

int main()
{
	Teacher t("Ben");
	School s(&t);
	s.show();
}


#include <iostream>
using namespace std;

class Wheel
{
public:
	void change()
	{
		cout << "The wheels change\n";
	}
};

class Car
{
private:
	Wheel wheel;
public:
	void changeCar()
	{
		wheel.change();
	}
};

int main()
{
	Car c;
	c.changeCar();
}


#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
	string name;

	Employee(const string& name) : name(name) {}

	void show() const {
		cout << "Employee: " << name << endl;
	}
};

class Company {
private:
	vector<Employee*> employees;
public:
	void addEmployee(Employee* emp) {
		employees.push_back(emp);
	}

	void showEmployees() const {
		cout << "Сотрудники компании:" << endl;
		for (auto emp : employees)
			emp->show();
	}

	~Company() {
		for (auto emp : employees)
			delete emp;
	}
};

int main() {
	Company myCompany;

	myCompany.addEmployee(new Employee("Иван Иванов"));
	myCompany.addEmployee(new Employee("Петр Петров"));

	myCompany.showEmployees();

	return 0;
}


#include <iostream>
using namespace std;

class Keybord
{
public:
	void buttons()
	{
		cout << "The keyboard has buttons\n";
	}
};

class Laptop
{
private:
	Keybord keybord;
public:
	void manyButtons()
	{
		keybord.buttons();
	}
};

int main()
{
	Laptop l;
	l.manyButtons();
}


#include <iostream>
using namespace std;

class Student
{
public:
	string firstname;

	Student(string firstname)
	{
		this->firstname = firstname;
	}
};

class Course
{
private:
	Student* student;
public:
	Course(Student* s)
	{
		student = s;
	}
	void show() {
		cout << "Student: " << student->firstname << endl;
	}
};

int main()
{
	Student s("Lika");
	Course c(&s);
	c.show();
}


#include <iostream>
using namespace std;

class Door
{
public:
	void space()
	{
		cout << "Luminal space\n";
	}
};

class House
{
private:
	Door door;
public:
	void manySpaces()
	{
		door.space();
	}
};

int main()
{
	House h;
	h.manySpaces();
}


#include <iostream>
using namespace std;

class Track
{
public:
	int num;

	Track(int num)
	{
		this->num = num;
	}
};

class Player
{
private:
	Track* track;
public:
	Player(Track* t)
	{
		track = t;
	}
	void show() {
		cout << "Track: " << track->num << endl;
	}
};

int main()
{
	Track t(200);
	Player p(&t);
	p.show();
}


#include <iostream>
using namespace std;

class Customer
{
public:
	string firstname;

	Customer(string firstname)
	{
		this->firstname = firstname;
	}
};

class Order
{
private:
	Customer* customer;
public:
	Order(Customer* c)
	{
		customer = c;
	}
	void show() {
		cout << "Customer: " << customer->firstname << endl;
	}
};

int main()
{
	Customer c("Lika");
	Order o(&c);
	o.show();
}


#include <iostream>
using namespace std;

class Battery
{
public:
	void capacity()
	{
		cout << "Capacity\n";
	}
};

class Smartphone
{
private:
	Battery battery;
public:
	void manycapacity()
	{
		battery.capacity();
	}
};

int main()
{
	Smartphone s;
	s.manycapacity();
}


#include <iostream>
using namespace std;

class Book
{
public:
	string name;

	Book(string name)
	{
		this->name = name;
	}
};

class Library
{
private:
	Book* book;
public:
	Library(Book* c)
	{
		book = c;
	}
	void show() {
		cout << "Book: " << book->name << endl;
	}
};

int main()
{
	Book b("Lika");
	Library l(&b);
	l.show();
}


#include <iostream>
using namespace std;

class Level
{
public:
	void show()
	{
		cout << "Lev\n";
	}
};

class Game
{
private:
	Level level;
public:
	void manycapacity()
	{
		level.show();
	}
};

int main()
{
	Game g;
	g.manycapacity();
}


#include <iostream>
using namespace std;

class Database
{
public:
	string name;

	Database(string name)
	{
		this->name = name;
	}
};

class Server
{
private:
	Database* database;
public:
	Server(Database* d)
	{
		database = d;
	}
	void show() {
		cout << "Database: " << database->name << endl;
	}
};

int main()
{
	Database d("Lika");
	Server s(&d);
	s.show();
}
