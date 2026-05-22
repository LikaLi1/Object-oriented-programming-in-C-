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
	string listOrder;
	string divilery;
	int qr_code;
	string gift;
	string commentOrder;

public:
	Order(string n, string l, string d, int q, string g, string c) : name(n), listOrder(l), divilery(d), qr_code(q), gift(g), commentOrder(c) {}


};
