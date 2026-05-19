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


#include <iostream>
#include <map>
using namespace std;

class Enemy
{
private:
	string name;
	int level;

public:
	Enemy(string n, int l) : name(n), level(l) {}

	Enemy* clone()
	{
		return new Enemy(*this);
	}

	void printInfo() const
	{
		cout << "Enemy: " << name << ", Level: " << level << endl;
	}
};

class EnemyFactory
{
private:
	map<string, Enemy*> prototypes;

public:
	void addPrototype(string key, Enemy* prototype)
	{
		prototypes[key] = prototype;
	}

	Enemy* create(string key) {
		return prototypes[key]->clone();
	}
};

int main()
{
	EnemyFactory factory;

	factory.addPrototype("zombie", new Enemy("Zombie", 1));
	factory.addPrototype("skeleton", new Enemy("Skeleton", 2));
	factory.addPrototype("mage", new Enemy("Mage", 5));

	Enemy* e1 = factory.create("zombie");
	Enemy* e2 = factory.create("skeleton");
	Enemy* e3 = factory.create("mage");

	e1->printInfo();
	e2->printInfo();
	e3->printInfo();

	delete e1;
	delete e2;
	delete e3;

	return 0;
}


#include <iostream>
#include <map>
using namespace std;

class Prototype
{
public:
	virtual Prototype* clone() const = 0;
	virtual ~Prototype() {}
};

class Enemy : public Prototype
{
private:
	string name;
	int level;

public:
	Enemy(const string& n, int l) : name(n), level(l) {}

	Prototype* clone() const override
	{
		return new Enemy(*this);
	}

	void printInfo() const
	{
		cout << "Enemy: " << name << ", Level: " << level << endl;
	}
};

class EnemyFactory
{
private:
	map<string, Prototype*> prototypes;

public:
	void addPrototype(const string& key, Prototype* prototype)
	{
		prototypes[key] = prototype;
	}

	Enemy* create(const string& key) 
	{
		auto it = prototypes.find(key);
		if (it != prototypes.end());
		{
			return dynamic_cast<Enemy*>(it->second->clone());
		}
		return nullptr;
	}
};

int main()
{
	EnemyFactory factory;

	factory.addPrototype("zombie", new Enemy("Zombie", 1));
	factory.addPrototype("skeleton", new Enemy("Skeleton", 2));
	factory.addPrototype("mage", new Enemy("Mage", 5));

	Enemy* e1 = factory.create("zombie");
	Enemy* e2 = factory.create("skeleton");
	Enemy* e3 = factory.create("mage");

	e1->printInfo();
	e2->printInfo();
	e3->printInfo();

	delete e1;
	delete e2;
	delete e3;

	return 0;
}


#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

class Spawner
{
public:
	virtual ~Spawner() = default;

	virtual unique_ptr< Spawner> clone() const = 0;
	virtual void info() const = 0;
};

class SpawnerA : public Spawner {
public:
	unique_ptr< Spawner> clone() const override {
		return make_unique<SpawnerA>(*this);
	}
	void info() const override {
		cout << "First Spawner" << endl;
	}
};

class SpawnerB : public Spawner {
public:
	unique_ptr< Spawner> clone() const override {
		return make_unique<SpawnerB>(*this);
	}
	void info() const override {
		cout << "Second Spawner" << endl;
	}
};

int main()
{
	vector<unique_ptr<Spawner>> clones;

	unique_ptr<Spawner> prototype = make_unique< SpawnerA>();
	auto interval = chrono::milliseconds(500);
	auto start_time = chrono::steady_clock::now();

	while (clones.size() < 5) {
		auto current_time = chrono::steady_clock::now();
		auto elapsed = chrono::duration_cast<chrono::milliseconds>(current_time - start_time);
		

		if (elapsed >= interval)
		{
			clones.push_back(prototype->clone());

			cout << "Clones: " << clones.size() << endl;
			clones.back()->info();

			start_time = current_time;
		}

		this_thread::sleep_for(chrono::milliseconds(50));
	}
}


#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Spell {
public:
    virtual ~Spell() = default;
    virtual unique_ptr<Spell> clone() const = 0;
    virtual void cast() const = 0;
};

class Fireball : public Spell {
public:
    unique_ptr<Spell> clone() const override {
        return make_unique<Fireball>(*this);
    }
    void cast() const override {
        cout << "Casting Fireball!" << endl;
    }
};

class IceBlast : public Spell {
public:
    unique_ptr<Spell> clone() const override {
        return make_unique<IceBlast>(*this);
    }
    void cast() const override {
        cout << "Casting IceBlast!" << endl;
    }
};

class PoisonCloud : public Spell {
public:
    unique_ptr<Spell> clone() const override {
        return make_unique<PoisonCloud>(*this);
    }
    void cast() const override {
        cout << "Casting PoisonCloud!" << endl;
    }
};

int main() {
    vector<unique_ptr<Spell>> spellPrototypes;
    spellPrototypes.push_back(make_unique<Fireball>());
    spellPrototypes.push_back(make_unique<IceBlast>());
    spellPrototypes.push_back(make_unique<PoisonCloud>());

    vector<unique_ptr<Spell>> spells;
    for (const auto& proto : spellPrototypes) {
        auto spell = proto->clone();
        spell->cast();
        spells.push_back(move(spell));
    }

    return 0;
}


#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual unique_ptr<Weapon> clone() const = 0;
    virtual void info() const = 0;
};

class BasicWeapon : public Weapon {
public:
    unique_ptr<Weapon> clone() const override {
        return make_unique<BasicWeapon>(*this);
    }
    void info() const override {
        cout << "Basic Weapon" << endl;
    }
};

class WeaponDecorator : public Weapon {
protected:
    unique_ptr<Weapon> weapon;
public:
    WeaponDecorator(unique_ptr<Weapon> w) : weapon(move(w)) {}
    virtual ~WeaponDecorator() = default;
};

class FireDecorator : public WeaponDecorator {
public:
    FireDecorator(unique_ptr<Weapon> w) : WeaponDecorator(move(w)) {}
    unique_ptr<Weapon> clone() const override {
        return make_unique<FireDecorator>(weapon->clone());
    }
    void info() const override {
        weapon->info();
        cout << " + Fire effect" << endl;
    }
};

class IceDecorator : public WeaponDecorator {
public:
    IceDecorator(unique_ptr<Weapon> w) : WeaponDecorator(move(w)) {}
    unique_ptr<Weapon> clone() const override {
        return make_unique<IceDecorator>(weapon->clone());
    }
    void info() const override {
        weapon->info();
        cout << " + Ice effect" << endl;
    }
};

class PoisonDecorator : public WeaponDecorator {
public:
    PoisonDecorator(unique_ptr<Weapon> w) : WeaponDecorator(move(w)) {}
    unique_ptr<Weapon> clone() const override {
        return make_unique<PoisonDecorator>(weapon->clone());
    }
    void info() const override {
        weapon->info();
        cout << " + Poison effect" << endl;
    }
};

int main() {
    auto weapon = make_unique<BasicWeapon>();
    auto decoratedWeapon = make_unique<FireDecorator>(make_unique<IceDecorator>(move(weapon)));

    auto cloneWeapon = decoratedWeapon->clone();

    cout << "Original weapon:" << endl;
    decoratedWeapon->info();

    cout << "Cloned weapon:" << endl;
    cloneWeapon->info();

    return 0;
}


#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Character {
public:
    string name;
    int level;
    Character(const string& n, int l) : name(n), level(l) {}
    shared_ptr<Character> clone() const {
        return make_shared<Character>(*this);
    }
    void info() const {
        cout << "Character: " << name << ", Level: " << level << endl;
    }
};

class CloneCharacterCommand {
private:
    shared_ptr<Character> character;

public:
    CloneCharacterCommand(shared_ptr<Character> c) : character(c) {}
    shared_ptr<Character> execute() {
        return character->clone();
    }
};

int main() {
    auto hero = make_shared<Character>("Hero", 10);
    hero->info();

    CloneCharacterCommand cmd(hero);
    auto clone_hero = cmd.execute();
    clone_hero->info();

    return 0;
}


#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Enemy {
public:
    string name;
    int power;
    Enemy(const string& n, int p) : name(n), power(p) {}
    shared_ptr<Enemy> clone() const {
        return make_shared<Enemy>(*this);
    }
    void info() const {
        cout << "Enemy: " << name << ", Power: " << power << endl;
    }
};

class GameFacade {
private:
    vector<shared_ptr<Enemy>> enemyPrototypes;

public:
    void createEnemies() {
        enemyPrototypes.push_back(make_shared<Enemy>("Goblin", 5));
        enemyPrototypes.push_back(make_shared<Enemy>("Orc", 10));
        enemyPrototypes.push_back(make_shared<Enemy>("Dragon", 50));
    }

    shared_ptr<Enemy> cloneEnemy(const string& name) {
        for (auto& proto : enemyPrototypes) {
            if (proto->name == name)
                return proto->clone();
        }
        return nullptr;
    }

    void startLevel() {
        cout << "Starting level with enemies:" << endl;
        auto enemy1 = cloneEnemy("Goblin");
        auto enemy2 = cloneEnemy("Dragon");
        enemy1->info();
        enemy2->info();
    }
};

int main() {
    GameFacade game;
    game.createEnemies();
    game.startLevel();
    return 0;
}


class Weapon {
public:
    virtual ~Weapon() = default;
    virtual unique_ptr<Weapon> clone() const = 0;
    virtual void info() const = 0;
};

class BasicWeapon : public Weapon {
public:
    unique_ptr<Weapon> clone() const override {
        return make_unique<BasicWeapon>(*this);
    }
    void info() const override {
        cout << "Basic Weapon" << endl;
    }
};
