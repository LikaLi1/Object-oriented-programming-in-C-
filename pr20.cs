#include <iostream>
using namespace std;

class Character
{
private:
   string name;
   string characterClass;
   int hp;
   int damage;
   int aqility;
   int iq;
   string weapon;
   string armor;

public:
   Character(string n, string c, int h, int d, int aq, int i, string w, string ar) : name(n), characterClass(c), hp(h), damage(d), aqility(aq), iq(i), weapon(w), armor(ar) {}

   void show()
   {
       cout << "Name: " << name << endl;
       cout << "Character class: " << characterClass << endl;
       cout << "HP: " << hp << endl;
       cout << "Damage: " << damage << endl;
       cout << "Aqility: " << aqility << endl;
       cout << "IQ: " << iq << endl;
       cout << "Weapon: " << weapon << endl;
       cout << "Armor: " << armor << endl;
   }
};

class CharacterBuilder
{
   private:
   string name = "Nike";
   string characterClass = "Mage";
   int hp = 5000;
   int damage = 42;
   int aqility = 8;
   int iq = 600;
   string weapon = "Fire and Ice";
   string armor = "None";

public:
   CharacterBuilder& setName(string n)
   {
       name = n; 
       return *this;
   }
   CharacterBuilder& setCharacterClass(string c)
   {
       characterClass = c;
       return *this;
   }
   CharacterBuilder& setHP(int h)
   {
       hp = h;
       return *this;
   }
   CharacterBuilder& setDamage(int d)
   {
       damage = d;
       return *this;
   }
   CharacterBuilder& setAqility(int aq)
   {
       aqility = aq;
       return *this;
   }
   CharacterBuilder& setIQ(int i)
   {
       iq = i;
       return *this;
   }
   CharacterBuilder& setWeapon(string w)
   {
       weapon = w;
       return *this;
   }
   CharacterBuilder& setArmor(string ar)
   {
       armor = ar;
       return *this;
   }

   Character buield()
   {
       if(name != "" || hp != 0)
       {
           return Character(name, characterClass, hp, damage, aqility, iq, weapon, armor);
       }
       else if (name == "")
       {
           cout << "Name NULL" << endl;
       }
       else if (hp == 0)
       {
           cout << "HP NULL" << endl;
       }
   }
};

int main()
{
   Character NPC = CharacterBuilder()
       .setName("Kate")
       .setCharacterClass("Hill")
       .setHP(600)
       .setDamage(25)
       .setAqility(348)
       .setIQ(9)
       .setWeapon("Sword")
       .setArmor("None")
       .buield();

   NPC.show();

   return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Order
{
private:
	string name;
	vector<string> listOrder;
	bool divilery;
	string qr_code;
	bool gift;
	string commentOrder;

public:
	Order(string n, vector<string> l, bool d, string q, bool g, string c) : name(n), listOrder(l), divilery(d), qr_code(q), gift(g), commentOrder(c) {}

	void show()
	{
		cout << "name: " << name << endl;
		cout << "List Order: ";
		for (string listsOrder : listOrder)
		cout << listsOrder << endl;
		cout << "Divilery: " << (divilery ? "yes" : "no") << endl;
		cout << "QR Code: " << (qr_code.empty() ? "none" : qr_code) << endl;
		cout << "Gift: " << (gift ? "yes" : "no") << endl;
		cout << "Comment Order: " << commentOrder << endl;
	}
};

class OrderBuilder
{
private:
	string name = "";
	vector<string> listOrder;
	bool divilery = false;
	string qr_code = "";
	bool gift = false;
	string commentOrder = "";

public:
	OrderBuilder& setName(string n)
	{
		name = n;
		return *this;
	}

	OrderBuilder& addProduct(string listsOrder)
	{
		listOrder.push_back(listsOrder);
		return *this;
	}

	OrderBuilder& setDivilery()
	{
		divilery = false;
		return *this;
	}

	OrderBuilder& setQr_code(string q)
	{
		qr_code = q;
		return *this;
	}

	OrderBuilder& setGift()
	{
		gift = true;
		return *this;
	}

	OrderBuilder& setCommentOrder(string c)
	{
		commentOrder = c;
		return *this;
	}

	Order build()
	{
		return Order(name, listOrder, divilery, qr_code, gift, commentOrder);
	}
};

int main()
{
	Order order = OrderBuilder()
		.setName("Lora")
		.addProduct("Telephone")
		.addProduct("Camera")
		.setDivilery()
		.setQr_code("5876_K")
		.setGift()
		.setCommentOrder("Good shop")
		.build();

	order.show();

	return 0;
}


