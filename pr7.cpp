#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;

public:
    Book(const string& t, const string& a) {
        setTitle(t);
        setAuthor(a);
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    void setTitle(const string& t) {
        if (t.empty()) {
            cout << "Название не может быть пустым." << endl;
        }
        else {
            title = t;
        }
    }

    void setAuthor(const string& a) {
        if (a.empty()) {
            cout << "Автор не может быть пустым." << endl;
        }
        else {
            author = a;
        }
    }

    void Proverka(const string& t, const string& a) {
        if (t.empty() || a.empty()) {
            cout << "Not NULL" << endl;
        }
        else {
            title = t;
            author = a;
        }
    }
};

int main()
{
    Book b("King", "Top");
    cout << "Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;

    b.setTitle("");
    b.setAuthor("");

    b.setTitle("Full Gays");
    b.setAuthor("Misha");

    cout << "New title: " << b.getTitle() << endl;
    cout << "New author: " << b.getAuthor() << endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Counter
{
private:
    int value;

public:
    Counter() : value(0) {}

    void increment() { if (value < 100) value++; }

    void decrement() { if (value > 0) value--; }

    void setValue(int v) 
    {
        if (v >= 0 && v <= 100) value = v;
    }

    int getValue() const 
    {
        return value;
    }
};

int main()
{
    Counter c;
    c.increment();
    c.decrement();
    c.setValue(200);
    cout << "Counter: " << c.getValue() << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    vector<int> grades;

public:
    Student(string n) { name = n; }

    void addGrade(int g)
    {
        if(g >= 0 && g <= 100)
            grades.push_back(g);
        else
            cout << "Invalid grade!\n";
    }

    double getAverage()
    {
        if(grades.empty()) return 0;
        double sum = 0;
        for(int g : grades) sum += g;
        return sum / grades.size();
    }

    void show()
    {
        cout << "Student: " << name << ", Average: " << getAverage() << endl;
    }
};

int main()
{
    Student s("Ivan");
    s.addGrade(95);
    s.addGrade(87);
    s.addGrade(110);
    s.show();
}


#include <iostream>
#include <string>
using namespace std;

class Card
{
private:
    string number;
    double balance;

public:
    Card(string num, double bal) : number(num), balance(bal) {}

    void deposit(double amount)
    {
        if(amount > 0) balance += amount;
    }

    void withdraw(double amount)
    {
        if(amount > 0 && amount <= balance) balance -= amount;
        else cout << "Insufficient funds!\n";
    }

    void showBalance() { cout << "Card " << number << " balance: " << balance << endl; }
};

int main()
{
    Card myCard("1234-5678", 1000);
    myCard.withdraw(1200);
    myCard.deposit(500);
    myCard.showBalance();
}


#include <iostream>
using namespace std;

class Player
{
private:
    int hp;
    int level;

public:
    Player() : hp(100), level(1) {}

    void takeDamage(int dmg)
    {
        hp -= dmg;
        if(hp < 0) hp = 0;
    }

    void heal(int amount)
    {
        hp += amount;
        if(hp > 100) hp = 100;
    }

    void levelUp() { level++; }

    void showStats()
    {
        cout << "Level: " << level << ", HP: " << hp << endl;
    }
};

int main()
{
    Player p;
    p.takeDamage(150);
    p.showStats();
    p.heal(50);
    p.levelUp();
    p.showStats();
}


#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int speed;

public:
    Car(const string& b = "BMW") : model(b), speed(0) {}

    void acceleration() { if (speed < 100) speed++; }

    void braking() 
    {
        if (speed > 0) 
        {
            speed--;
        }
    }

    void show() const {
        cout << "Brand: " << model << "Speed: " << speed << endl;
    }

    void setValue(int v) 
    {
        if (v >= 0 && v <= 100) speed = v;
    }

    int getValue() const 
    {
        return speed;
    }
};

int main()
{
    Car c;
    c.acceleration();
    c.braking();
    c.show();
    c.setValue(200);
    cout << "Car: " << c.getValue() << endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string name;
    string subject;

public:
    Teacher(const string& n = "Max", const string& s = "Dog") {
        setName(n);
        setSubject(s);
    }

    void setName(const string& n) {
        if (n.empty()) {
            cout << "Not NULL" << endl;
        }
        else {
            name = n;
        }
    }

    void setSubject(const string& s) {
        subject = s;
    }

    string getName() const {
        return name;
    }

    string getSubject() const {
        return subject;
    }

    void showInfo() const {
        cout << "Teacher: " << name << " Subject: " << subject << endl;
    }
};

int main() {
    Teacher t1;
    t1.showInfo();

    t1.setName("Piter");
    t1.setSubject("Math");
    t1.showInfo();

    t1.setName("");
    t1.showInfo();

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Order {
private:
    vector<string> products;
    vector<double> prices;
    double totalSum;

public:
    Order() : totalSum(0.0) {}

    void addProduct(const string& productName, double price) {
        products.push_back(productName);
        prices.push_back(price);
    }

    void calculateSum() {
        totalSum = 0.0;
        for (double price : prices) {
            totalSum += price;
        }
    }

    void printOrder() const {
        cout << "Order:" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            cout << "- " << products[i] << ": " << prices[i] << " r" << endl;
        }
        cout << "Sum: " << totalSum << " r" << endl;
    }
};

int main() {
    Order myOrder;

    myOrder.addProduct("Bread", 50);
    myOrder.addProduct("Milk", 70);
    myOrder.addProduct("Apple", 100);

    myOrder.calculateSum();

    myOrder.printOrder();

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Card
{
private:
    string number;
    double balance;

public:
    Card(string num, double bal) : number(num), balance(bal) {}

    void deposit(double amount)
    {
        if(amount > 0) balance += amount;
    }

    void withdraw(double amount)
    {
        if(amount > 0 && amount <= balance) balance -= amount;
        else cout << "Insufficient funds!\n";
    }

    void showBalance() { cout << "Card " << number << " balance: " << balance << endl; }
};

int main()
{
    Card myCard("1234-5678", 1000);
    myCard.withdraw(1200);
    myCard.deposit(500);
    myCard.showBalance();
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(const string& n, double p) : name(n), price(p) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void showProduct() const {
        cout << "Product: " << name << " Price: " << price << " r" << endl;
    }
};

class Shop {
private:
    vector<Product> products;

public:
    void addProduct(const Product& p) {
        products.push_back(p);
    }

    void removeProduct(const string& productName) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getName() == productName) {
                products.erase(it);
                cout << "Product '" << productName << "' delete" << endl;
                return;
            }
        }
        cout << "Product '" << productName << "' not found" << endl;
    }

    void showAllProducts() const {
        if (products.empty()) {
            cout << "Shop NULL" << endl;
            return;
        }
        cout << "All products in the store:" << endl;
        for (const auto& p : products) {
            p.showProduct();
        }
    }
};

int main() {
    Shop myShop;

    myShop.addProduct(Product("Bread", 50));
    myShop.addProduct(Product("Milk", 70));
    myShop.addProduct(Product("Apple", 100));

    myShop.showAllProducts();

    myShop.removeProduct("Milk");

    myShop.showAllProducts();

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee(const string& n, double s) {
        name = n;
        setSalary(s);
    }

    void setSalary(double s) {
        if (s < 0) {
            cout << "No" << endl;
        }
        else {
            salary = s;
        }
    }

    void showInfo() const {
        cout << "Employee: " << name << " Salary: " << salary << " r" << endl;
    }

    void setName(const string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }
};

int main() {
    Employee emp("Nikita", 50000);
    emp.showInfo();

    emp.setSalary(-1000);
    emp.showInfo();

    emp.setSalary(60000);
    emp.showInfo();

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double grade;

public:
    Student(const string& n, double g) : name(n), grade(g) {}

    string getName() const {
        return name;
    }

    double getGrade() const {
        return grade;
    }
};

class Course {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void removeStudent(const string& studentName) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getName() == studentName) {
                students.erase(it);
                cout << "Student '" << studentName << "' delete" << endl;
                return;
            }
        }
        cout << "Student '" << studentName << "' not found" << endl;
    }

    void showAverageGrade() const {
        if (students.empty()) {
            cout << "No student" << endl;
            return;
        }
        double sum = 0;
        for (const auto& s : students) {
            sum += s.getGrade();
        }
        double average = sum / students.size();
        cout << "Average sum: " << average << endl;
    }

    void showAllStudents() const {
        if (students.empty()) {
            cout << "No student" << endl;
            return;
        }
        cout << "List student:" << endl;
        for (const auto& s : students) {
            cout << "- " << s.getName() << " Grade: " << s.getGrade() << endl;
        }
    }
};

int main() {
    Course mathCourse;

    mathCourse.addStudent(Student("Max", 85));
    mathCourse.addStudent(Student("Mari", 92));
    mathCourse.addStudent(Student("Vika", 78));

    mathCourse.showAllStudents();

    mathCourse.showAverageGrade();

    mathCourse.removeStudent("Vika");

    mathCourse.showAllStudents();
    mathCourse.showAverageGrade();

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class WaterMeter {
private:
    double liters;

public:
    WaterMeter() : liters(0) {}

    void addLiters(double amount) {
        if (amount < 0) {
            cout << "Cannot add negative liters" << endl;
        } else {
            liters += amount;
        }
    }

    void removeLiters(double amount) {
        if (amount < 0) {
            cout << "Cannot remove negative liters." << endl;
        } else if (amount > liters) {
            cout << "Cannot remove more liters than current total" << endl;
        } else {
            liters -= amount;
        }
    }

    void showLiters() const {
        cout << "Current water usage: " << liters << " liters" << endl;
    }
};

int main() {
    WaterMeter wm;
    wm.addLiters(50);
    wm.showLiters();
    wm.removeLiters(20);
    wm.showLiters();
    wm.removeLiters(40);
    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Library {
private:
    vector<string> books;

public:
    void addBook(const string& bookTitle) {
        books.push_back(bookTitle);
        cout << "Book \"" << bookTitle << "\" added" << endl;
    }

    void removeBook(const string& bookTitle) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (*it == bookTitle) {
                books.erase(it);
                cout << "Book \"" << bookTitle << "\" removed" << endl;
                return;
            }
        }
        cout << "Book \"" << bookTitle << "\" not found" << endl;
    }

    void showAllBooks() const {
        if (books.empty()) {
            cout << "The library is empty" << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (const auto& book : books) {
                cout << "- " << book << endl;
            }
        }
    }
};

int main() {
    Library myLibrary;
    myLibrary.addBook("The Great Gatsby");
    myLibrary.addBook("1984");
    myLibrary.showAllBooks();
    myLibrary.removeBook("1984");
    myLibrary.showAllBooks();
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class CPU {
public:
    string model;
    CPU(const string& m) : model(m) {}
    void show() const {
        cout << "CPU: " << model << endl;
    }
};

class RAM {
public:
    int sizeGB;
    RAM(int s) : sizeGB(s) {}
    void show() const {
        cout << "RAM: " << sizeGB << " GB" << endl;
    }
};

class HDD {
public:
    int capacityGB;
    HDD(int c) : capacityGB(c) {}
    void show() const {
        cout << "HDD: " << capacityGB << " GB" << endl;
    }
};

class PCSystem {
private:
    CPU cpu;
    RAM ram;
    HDD hdd;

public:
    PCSystem(const CPU& c, const RAM& r, const HDD& h) : cpu(c), ram(r), hdd(h) {}

    void start() const {
        cout << "Starting the PC..." << endl;
    }

    void showStatus() const {
        cout << "System Components Status:" << endl;
        cpu.show();
        ram.show();
        hdd.show();
    }
};

int main() {
    CPU myCPU("Intel Core i7");
    RAM myRAM(16);
    HDD myHDD(512);

    PCSystem myPC(myCPU, myRAM, myHDD);
    myPC.start();
    myPC.showStatus();

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game {
private:
    vector<string> levels;

public:
    void addLevel(const string& levelName) {
        levels.push_back(levelName);
        cout << "Level \"" << levelName << "\" added." << endl;
    }

    void removeLevel(const string& levelName) {
        for (auto it = levels.begin(); it != levels.end(); ++it) {
            if (*it == levelName) {
                levels.erase(it);
                cout << "Level \"" << levelName << "\" removed." << endl;
                return;
            }
        }
        cout << "Level \"" << levelName << "\" not found." << endl;
    }

    void showCurrentLevel() const {
        if (levels.empty()) {
            cout << "No levels available." << endl;
        } else {
            cout << "Current Level: " << levels.back() << endl;
        }
    }
};

int main() {
    Game myGame;
    myGame.addLevel("Level 1");
    myGame.addLevel("Level 2");
    myGame.showCurrentLevel();
    myGame.removeLevel("Level 1");
    myGame.showCurrentLevel();

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
public:
    string name;
    Person(const string& n) : name(n) {}
};

class Student : public Person {
public:
    Student(const string& n) : Person(n) {}
};

class Teacher : public Person {
public:
    Teacher(const string& n) : Person(n) {}
};

class University {
private:
    vector<Student> students;
    vector<Teacher> teachers;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
        cout << "Student \"" << s.name << "\" added." << endl;
    }
    void addTeacher(const Teacher& t) {
        teachers.push_back(t);
        cout << "Teacher \"" << t.name << "\" added." << endl;
    }
    void showStudents() const {
        cout << "Students:" << endl;
        for (const auto& s : students) {
            cout << "- " << s.name << endl;
        }
    }

    void showTeachers() const {
        cout << "Teachers:" << endl;
        for (const auto& t : teachers) {
            cout << "- " << t.name << endl;
        }
    }
};

int main() {
    University uni;
    uni.addStudent(Student("Alice"));
    uni.addTeacher(Teacher("Dr. Smith"));
    uni.showStudents();
    uni.showTeachers();
    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
public:
    string model;
    Car(const string& m) : model(m) {}
};

class Garage {
private:
    vector<Car> cars;

public:
    void addCar(const Car& c) {
        cars.push_back(c);
        cout << "Car \"" << c.model << "\" added." << endl;
    }
    void removeCar(const string& model) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->model == model) {
                cars.erase(it);
                cout << "Car \"" << model << "\" removed." << endl;
                return;
            }
        }
        cout << "Car \"" << model << "\" not found." << endl;
    }
    void showAllCars() const {
        if (cars.empty()) {
            cout << "No cars in the garage." << endl;
        } else {
            cout << "Cars in the garage:" << endl;
            for (const auto& c : cars) {
                cout << "- " << c.model << endl;
            }
        }
    }
};

int main() {
    Garage g;
    g.addCar(Car("Toyota"));
    g.addCar(Car("BMW"));
    g.showAllCars();
    g.removeCar("Toyota");
    g.showAllCars();
    return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
public:
    string accountNumber;
    double balance;

    BankAccount(const string& accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void showBalance() const {
        cout << "Account " << accountNumber << ": " << balance << " USD" << endl;
    }
};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void openAccount(const string& accNum, double initialBalance) {
        accounts.emplace_back(accNum, initialBalance);
        cout << "Account " << accNum << " opened with balance " << initialBalance << "." << endl;
    }
    void closeAccount(const string& accNum) {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->accountNumber == accNum) {
                accounts.erase(it);
                cout << "Account " << accNum << " closed." << endl;
                return;
            }
        }
        cout << "Account " << accNum << " not found." << endl;
    }
    void showAllBalances() const {
        if (accounts.empty()) {
            cout << "No accounts available." << endl;
        } else {
            for (const auto& acc : accounts) {
                acc.showBalance();
            }
        }
    }
};

int main() {
    Bank bank;
    bank.openAccount("123456", 1000);
    bank.openAccount("654321", 500);
    bank.showAllBalances();
    bank.closeAccount("123456");
    bank.showAllBalances();
    return 0;
}
