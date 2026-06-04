#include <iostream>
using namespace std;

class Implementor
{
public:
    virtual void implementorFirst(int numfirst) = 0;
    virtual void implementorSecond(int numsecond) = 0;
    virtual ~Implementor() {}
};

class ImplementorFirst : public Implementor
{
public:
    void implementorFirst(int numfirst) override
    {
        cout << "First" << endl;
    }
    void implementorSecond(int numsecond) override
    {
        cout << "Second" << endl;
    }
};

class ImplementorSecond : public Implementor
{
    void implementorFirst(int numfirst) override
    {
        cout << "Number first: " << numfirst << endl;
    }
    void implementorSecond(int numsecond) override
    {
        cout << "Number second: " << numsecond << endl;
    }
};

class Abstraction
{
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* i) : implementor(i) {}
    virtual void print() = 0;
    virtual ~Abstraction() {}
};

class PrintFirst : public Abstraction
{
private:
    int numfirst;

public:
    PrintFirst(Implementor* i, int numf) : Abstraction(i), numfirst(numf) {}
    void print() override
    {
        implementor->implementorFirst(numfirst);
    }
};

class PrintSecond : public Abstraction
{
private:
    int numsecond;

public:
    PrintSecond(Implementor* i, int nums) : Abstraction(i), numsecond(nums) {}
    void print() override
    {
        implementor->implementorSecond(numsecond);
    }
};

int main()
{
    ImplementorFirst implementorf;
    ImplementorSecond implementors;

    PrintFirst pf1(&implementorf, 10);
    PrintFirst pf2(&implementors, 10);

    PrintSecond ps1(&implementorf, 10);
    PrintSecond ps2(&implementors, 10);

    pf1.print();
    pf2.print();
    ps1.print();
    ps2.print();

    return 0;
}
