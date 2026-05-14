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
