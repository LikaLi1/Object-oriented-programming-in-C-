#include <iostream>
using namespace std;

class Prototype
{
public:
	virtual Prototype* clone() = 0;
	virtual ~Prototype() {}
};

class Enemy : public Prototype
{
private:
	int hp;
	int damage;
	int speed;

public:
	Enemy(int h, int d, int s) : hp(h), damage(d), speed(s) {}

	Prototype* clone() override
	{
		return new Enemy(*this);
	}

	void setHp(int h) { hp = h; }
	void setDamage(int d) { damage = d; }
	void setSpeed(int s) { speed = s; }

	void show()
	{
		cout << "HP: " << hp << endl;
		cout << "Damage: " << damage << endl;
		cout << "Speed: " << speed << endl;
	}
};

int main()
{
	Enemy original(100, 20, 5);

	Enemy* copy1 = dynamic_cast<Enemy*>(original.clone());
	copy1->show();
	delete copy1;
	Enemy* copy2 = dynamic_cast<Enemy*>(original.clone());
	copy2->show();
	delete copy2;
	Enemy* copy3 = dynamic_cast<Enemy*>(original.clone());
	copy3->setHp(50);
	copy3->setDamage(8);
	copy3->setSpeed(3);
	copy3->show();
	delete copy3;
}


#include <iostream>
using namespace std;

class Enemy
{
private:
    int hp;
    int damage;
    int speed;

public:
    Enemy(int h, int d, int s) : hp(h), damage(d), speed(s) {}

    Enemy* clone() {
        return new Enemy(*this);
    }

    void setHp(int h) { hp = h; }
    void setDamage(int d) { damage = d; }
    void setSpeed(int s) { speed = s; }

    void show() const
    {
        cout << "HP: " << hp << ", Damage: " << damage << ", Speed: " << speed << endl;
    }
};

int main()
{
    Enemy original(100, 20, 5);
    Enemy* copy = original.clone();

    cout << "Оригинал: ";
    original.show();

    cout << "Клон до изменений: ";
    copy->show();

    copy->setHp(200);
    copy->setDamage(50);
    copy->setSpeed(10);

    cout << "Клон после изменений: ";
    copy->show();

    cout << "Оригинал не изменился: ";
    original.show();

    delete copy;
    return 0;
}


#include <iostream>
using namespace std;

class LegendarySword
{
private:
	int damage;
	int price;
	string title;

public:
	LegendarySword(int d, int p, string t) : damage(d), price(p), title(t) {}

	LegendarySword* clone()
	{
		return new LegendarySword(*this);
	}

	void setDamage(int d) { damage = d; }
	void setPrice(int p) { price = p; }
	void setTitle(string t) { title = t; }

	void show()
	{
		cout << "Damage: " << damage << endl;
		cout << "Price: " << price << endl;
		cout << "Title: " << title << endl;
	}
};

int main()
{
	LegendarySword original(100, 20, "Stormbreaker");

	LegendarySword* copy1 = dynamic_cast<LegendarySword*>(original.clone());
	copy1->show();
	delete copy1;
	LegendarySword* copy2 = dynamic_cast<LegendarySword*>(original.clone());
	copy2->setDamage(50);
	copy2->setPrice(8);
	copy2->setTitle("Shadowbane");
	copy2->show();
	delete copy2;
	LegendarySword* copy3 = dynamic_cast<LegendarySword*>(original.clone());
	copy3->setDamage(65);
	copy3->setPrice(48);
	copy3->setTitle("Dragon’s Claw");
	copy3->show();
	delete copy3;
	LegendarySword* copy4 = dynamic_cast<LegendarySword*>(original.clone());
	copy4->setDamage(400);
	copy4->setPrice(7);
	copy4->setTitle("Sword of Light");
	copy4->show();
	delete copy4;
	LegendarySword* copy5 = dynamic_cast<LegendarySword*>(original.clone());
	copy5->setDamage(96);
	copy5->setPrice(80);
	copy5->setTitle("Blade of Eternity");
	copy5->show();
	delete copy5;
}


#include <iostream>
using namespace std;

class NPC
{
private:
	string name;
	int level;
	string fraction;

public:
	NPC(string n, int l, string f) : name(n), level(l), fraction(f) {}

	NPC* clone()
	{
		return new NPC(*this);
	}


	void show()
	{
		cout << "Name: " << name << endl;
		cout << "Level: " << level << endl;
		cout << "Fraction: " << fraction << endl;
	}
};

int main()
{
	NPC original("Nike", 20, "Magical");

	NPC* npc1 = original.clone();
	npc1->show();
	delete npc1;

	NPC* npc2 = original.clone();
	npc2->show();
	delete npc2;

	NPC* npc3 = original.clone();
	npc3->show();
	delete npc3;

	NPC* npc4 = original.clone();
	npc4->show();
	delete npc4;
}


#include <iostream>
using namespace std;

class ShallowCopy
{
public:
	int* value;

	ShallowCopy(int v)
	{
		value = new int(v);
	}

	ShallowCopy* clone()
	{
		return new ShallowCopy(*this);
	}

	void show()
	{
		cout << *value << endl;
	}

	~ShallowCopy()
	{
		delete value;
	}
};
	
int main()
{
	ShallowCopy setting(10);

	ShallowCopy* copy = setting.clone();
	copy->show();
	delete copy;
}


#include <iostream>
using namespace std;

class DeepCopy
{
private:
	int* value;

public:
	DeepCopy(int v)
	{
		value = new int(v);
	}

	DeepCopy(const DeepCopy& other)
	{
		value = new int(*other.value);
	}

	DeepCopy* clone()
	{
		return new DeepCopy(*this);
	}

	void show()
	{
		cout << *value << endl;
	}

	~DeepCopy()
	{
		delete value;
	}
};
	
int main()
{
	DeepCopy setting(10);

	DeepCopy* copy = setting.clone();
	copy->show();
	delete copy;
}


#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Prototype
{
public:
    virtual ~Prototype() = default;
    virtual unique_ptr<Prototype> clone() const = 0;
    virtual void print() const = 0;
};

class Player : public Prototype
{
private:
    vector<string> name;
    vector<int> hp;
    vector<string> inventory;
    vector<string> weapon;

public:
    Player() = default;

    Player(const vector<string>& n, const vector<int>& h, const vector<string>& i, const vector<string>& w)
        : name(n), hp(h), inventory(i), weapon(w) {
    }

    unique_ptr<Prototype> clone() const override {
        return make_unique<Player>(*this);
    }

    void addName(const string& title) {
        name.push_back(title);
    }

    void addHP(int value) {
        hp.push_back(value);
    }

    void addInventory(const string& item) {
        inventory.push_back(item);
    }

    void addWeapon(const string& wpn) {
        weapon.push_back(wpn);
    }

    void print() const override {
        cout << "Names: ";
        for (const auto& n : name) cout << n << " ";
        cout << "\nHPs: ";
        for (const auto& h : hp) cout << h << " ";
        cout << "\nInventory: ";
        for (const auto& item : inventory) cout << item << " ";
        cout << "\nWeapons: ";
        for (const auto& w : weapon) cout << w << " ";
        cout << endl;
    }
};

int main()
{
    Player prototype({ "Player1" }, { 100 }, { "Potion" }, { "Sword" });

    auto clone1 = prototype.clone();

    Player* playerClone = static_cast<Player*>(clone1.get());

    playerClone->addName("ClonedPlayer");
    playerClone->addHP(120);
    playerClone->addInventory("Elixir");
    playerClone->addWeapon("Axe");

    playerClone->print();

    prototype.print();

    return 0;
}
