#include <iostream>
using namespace std;

class ContextStrategy
{
public:
    virtual void pay() = 0;
    virtual ~ContextStrategy() {}
};

class CardPayment : public ContextStrategy
{
public:
    void pay() override
    {
        cout << "Pay by card\n";
    }
};

class CashPayment : public ContextStrategy
{
public:
    void pay() override
    {
        cout << "Pay by cash\n";
    }
};

class Payment
{
private:
    ContextStrategy* strategy = nullptr;

public:
    void setStrategy(ContextStrategy* s)
    {
        strategy = s;
    }

    void execute()
    {
        if (strategy)
            strategy->pay();
    }
};

int main()
{
    Payment p;

    CardPayment card;
    CashPayment cash;

    p.setStrategy(&card);
    p.execute();

    p.setStrategy(&cash);
    p.execute();
}


#include <iostream>
using namespace std;

class Payment
{
public:
    void pay(int type)
    {
        if (type == 1)
            cout << "Card\n";
        else if (type == 2)
            cout << "Cash\n";
        else if (type == 3)
            cout << "Crypto\n";
    }
};


#include <iostream>
#include <vector>
using namespace std;

class SortStrategy
{
public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~SortStrategy() {}
};

class BubbleSort : public SortStrategy
{
public:
    void sort(vector<int>& arr) override
    {
        for (size_t i = 0; i < arr.size(); i++)
            for (size_t j = 0; j < arr.size() - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }
};

class ReverseSort : public SortStrategy
{
public:
    void sort(vector<int>& arr) override
    {
        sort(arr.begin(), arr.end(), greater<int>());
    }
};

class Sorter
{
    SortStrategy* strategy;

public:
    void setStrategy(SortStrategy* s)
    {
        strategy = s;
    }

    void execute(vector<int>& arr)
    {
        strategy->sort(arr);
    }
};

int main()
{
    vector<int> arr = { 5, 2, 9, 1, 5, 6 };

    BubbleSort bubbleSort;
    ReverseSort reverseSort;

    Sorter sorter;

    sorter.setStrategy(&bubbleSort);
    sorter.execute(arr);

    cout << "Bubble Sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    sorter.setStrategy(&reverseSort);
    sorter.execute(arr);

    cout << "Reverse Sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}


#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual void pay() = 0;
    virtual ~PaymentStrategy() {}
};

class CardPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Pay by card\n";
    }
};

class CashPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Pay by cash\n";
    }
};

class CryptoPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Pay by crypto\n";
    }
};

class DiscountStrategy
{
public:
    virtual double applyDiscount(double amount) = 0;
    virtual ~DiscountStrategy() {}
};

class PercentageDiscount : public DiscountStrategy
{
private:
    double percent;
public:
    PercentageDiscount(double p) : percent(p) {}

    double applyDiscount(double amount) override
    {
        return amount * (1 - percent / 100.0);
    }
};

class FixedDiscount : public DiscountStrategy
{
private:
    double discountAmount;
public:
    FixedDiscount(double amount) : discountAmount(amount) {}

    double applyDiscount(double amount) override
    {
        double newAmount = amount - discountAmount;
        return (newAmount < 0) ? 0 : newAmount;
    }
};

class Payment
{
private:
    PaymentStrategy* strategy = nullptr;
    DiscountStrategy* discount = nullptr;

public:
    void setStrategy(PaymentStrategy* s)
    {
        strategy = s;
    }

    void setDiscountStrategy(DiscountStrategy* d)
    {
        discount = d;
    }

    void execute(double amount)
    {
        if (!strategy)
        {
            cout << "Payment strategy is not set!\n";
            return;
        }

        double finalAmount = amount;

        if (discount)
        {
            finalAmount = discount->applyDiscount(amount);
            cout << "Amount after discount: " << finalAmount << endl;
        }

        cout << "Processing payment of " << finalAmount << " units...\n";
        strategy->pay();
        cout << "Payment completed.\n\n";
    }
};

int main()
{
    Payment p;

    CardPayment card;
    CashPayment cash;
    CryptoPayment crypto;

    p.setStrategy(&card);

    PercentageDiscount discountPercent(10);
    FixedDiscount discountFixed(2);

    cout << "Оплата картой, скидка 10%:\n";
    p.setDiscountStrategy(&discountPercent);
    p.execute(100);

    cout << "Оплата наличными, фиксированная скидка 2:\n";
    p.setStrategy(&cash);
    p.setDiscountStrategy(&discountFixed);
    p.execute(100);

    cout << "Оплата криптовалютой, без скидки:\n";
    p.setStrategy(&crypto);
    p.setDiscountStrategy(nullptr);
    p.execute(100);

    return 0;
}


#include <iostream>
using namespace std;

class Behavior
{
public:
    virtual void act() = 0;
};

class Aggressive : public Behavior
{
public:
    void act() override
    {
        cout << "Attack player\n";
    }
};

class Defensive : public Behavior
{
public:
    void act() override
    {
        cout << "Defend\n";
    }
};

class NPC
{
    Behavior* behavior;

public:
    void setBehavior(Behavior* b)
    {
        behavior = b;
    }

    void update()
    {
        behavior->act();
    }
};


#include <iostream>
using namespace std;
#include <memory>

class Context
{
public:
    virtual void pay() = 0;
    virtual ~Context() {}
};

class TextContext : public Context
{
public:
    void pay() override
    {
        cout << "Pay for text\n";
    }
};

class BookContext : public Context
{
public:
    void pay() override
    {
        cout << "Pay for book\n";
    }
};

class ContextStrategy {
    unique_ptr<Context> starategy;

public:
    void setStrategy(unique_ptr<Context> s)
    {
        starategy = move(s);
    }
    void execute() {
        starategy->pay();
    }
};

int main()
{
    ContextStrategy c;

    c.setStrategy(make_unique<TextContext>());
    c.execute();

    c.setStrategy(make_unique<BookContext>());
    c.execute();
}
