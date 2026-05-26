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


#include <iostream>
#include <string>
#include <map>
using namespace std;

class HttpRequest
{
private:
	string methodRequest;
	string url;
	map<string, string> header;
	int setting;
	string bodyRequest;

public:
	HttpRequest(string m, string u, map<string, string> h, int s, string b) : methodRequest(m), url(u), header(h), setting(s), bodyRequest(b) {}

	void show()
	{
		cout << "Method request: " << methodRequest << endl;
		cout << "URL: " << url << endl;
		cout << "Header: ";
		for (auto headers : header)
		{
			cout << headers.first << ": " << headers.second << endl;
		}
		cout << "Setting: " << setting << endl;
		if (!bodyRequest.empty())
		{
			cout << "Body: " << bodyRequest << endl;
		}
	}
};

class HttpRequestBuilder
{
private:
	string methodRequest = "";
	string url = "";
	map<string, string> header;
	int setting = 5452;
	string bodyRequest = "";

public:
	HttpRequestBuilder& setMethodRequest(string m)
	{
		methodRequest = m;
		return *this;
	}

	HttpRequestBuilder& setURL(string u)
	{
		url = u;
		return *this;
	}

	HttpRequestBuilder& addHeader(string key, string value)
	{
		header[key] = value;
		return *this;
	}

	HttpRequestBuilder& setSetting(int s)
	{
		setting = s;
		return *this;
	}

	HttpRequestBuilder& setBodyRequest(string b)
	{
		bodyRequest = b;
		return *this;
	}

	HttpRequest build()
	{
		return HttpRequest(methodRequest, url, header, setting, bodyRequest);
	}
};

int main()
{
	HttpRequest httpRequest = HttpRequestBuilder()
		.setMethodRequest("Method")
		.setURL("/github/user")
		.addHeader("Text", "TXT")
		.setSetting(5486)
		.setBodyRequest("Object")
		.build();

	httpRequest.show();

	return 0;
}


#include <iostream>
#include <stdexcept>
using namespace std;

class DatabaseConfig
{
private:
	string host;
	int port;
	string login;
	string password;
	string databaseName;
	bool useSSL;
	string timeout;

public:
	DatabaseConfig(string h, int p, string l, string pa, string d, bool u, string t) : host(h), port(p), login(l), password(pa), databaseName(d), useSSL(u), timeout(t) {}

	void show()
	{
		cout << "Host: " << host << endl;
		cout << "Port: " << port << endl;
		cout << "Login: " << login << endl;
		if (!password.empty())
		{
			cout << "Password: " << password << endl;
		}
		else
		{
			cout << "Password is Null" << endl;
		}
		cout << "Database name: " << databaseName << endl;
		cout << "Use SSL: " << (useSSL ? "yes" : "no") << endl;
		cout << "Timeout: " << timeout << endl;
	}
};

class DatabaseConfigBuilder
{
private:
	string host = "";
	int port = 0;
	string login = "";
	string password = "";
	string databaseName = "";
	bool useSSL = false;
	string timeout = "";

public:
	DatabaseConfigBuilder& setHost(string h)
	{
		host = h;
		return *this;
	}

	DatabaseConfigBuilder& setPort(int p)
	{
		if (p < 0 || p > 65535)
		{
			throw std::invalid_argument("Invalid port number!");
		}
		port = p;
		return *this;
	}

	DatabaseConfigBuilder& setLogin(string l)
	{
		login = l;
		return *this;
	}

	DatabaseConfigBuilder& setPassword(string pa)
	{
		password = pa;
		return *this;
	}

	DatabaseConfigBuilder& setDatabaseName(string d)
	{
		databaseName = d;
		return *this;
	}

	DatabaseConfigBuilder& enableSSL()
	{
		useSSL = true;
		return *this;
	}

	DatabaseConfigBuilder& setTimeout(string t)
	{
		timeout = t;
		return *this;
	}

	DatabaseConfig build()
	{
		return DatabaseConfig(host, port, login, password, databaseName, useSSL, timeout);
	}
};

int main()
{
	try{
	DatabaseConfig databaseConfig = DatabaseConfigBuilder()
		.setHost("Host")
		.setPort(523)
		.setLogin("Admin")
		.setPassword("")
		.setDatabaseName("K")
		.enableSSL()
		.setTimeout("21.06.25")
		.build();

	databaseConfig.show();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}

	return 0;
}


#include <iostream>
using namespace std;

class Query
{
private:
	string sql;

public:
	Query(string s) : sql(s) {}

	void show()
	{
		cout << "SQL: " << sql << endl;
	}
};

class QueryBuilder
{
private:
	string selectText = "";
	string fromText = "";
	string whereText = "";
	string orderByText = "";
	string limitText = "";

public:
	QueryBuilder& select(string file)
	{
		selectText = "SELECT " + file;
		return *this;
	}

	QueryBuilder& from(string table)
	{
		fromText = "FROM " + table;
		return *this;
	}

	QueryBuilder& where(string condition)
	{
		whereText = "WHERE " + condition;
		return *this;
	}

	QueryBuilder& orderBy(string files)
	{
		orderByText = "ORDER BY " + files;
		return *this;
	}

	QueryBuilder& limit(string number)
	{
		limitText = "LIMIT " + number;
		return *this;
	}

	Query build()
	{
		if (selectText == "" || fromText == "")
		{
			cout << "Error" << endl;
		}
		string sql = selectText + " " + fromText;

		if (!whereText.empty())
		{
			sql += " " + whereText;
		}
		if (!orderByText.empty())
		{
			sql += " " + orderByText;
		}
		if (!limitText.empty())
		{
			sql += " " + limitText;
		}

		sql += ";";

		return Query(sql);
	}
};

int main()
{
	try
	{
		Query query = QueryBuilder()
			.select("name, age")
			.from("Users")
			.where("age > 18")
			.orderBy("name")
			.limit("10")
			.build();

		query.show();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}


#include <iostream>
using namespace std;

class Computer
{
private:
	string CPU;
	string GPU;
	int RAM;
	int SSD;
	bool HDD;
	bool Wi_Fi;
	bool waterCooling;

public:
	Computer(string c, string  g, int r, int s, bool h, bool wi, bool wa) : CPU(c), GPU(g), RAM(r), SSD(s), HDD(h), Wi_Fi(wi), waterCooling(wa) {}

	void show()
	{
		cout << "CPU: " << CPU << endl;
		cout << "GPU: " << GPU << endl;
		cout << "RAM: " << RAM << endl;
		cout << "SSD: " << SSD << endl;
		cout << "HDD: " << HDD << endl;
		cout << "Wi_Fi: " << Wi_Fi << endl;
		cout << "waterCooling: " << waterCooling << endl;
	}
};

class ComputerBuilder
{
private:
	string CPU = "";
	string GPU = "";
	int RAM = 0;
	int SSD = 0;
	bool HDD = false;
	bool Wi_Fi = false;
	bool waterCooling = false;

public:
	ComputerBuilder& setCPU(string c)
	{
		CPU = c;
		return *this;
	}

	ComputerBuilder& setGPU(string g)
	{
		GPU = g;
		return *this;
	}

	ComputerBuilder& setRAM(int r)
	{
		RAM = r;
		return *this;
	}

	ComputerBuilder& setSSD(int s)
	{
		SSD = s;
		return *this;
	}

	ComputerBuilder& setHDD(bool h)
	{
		HDD = h;
		return *this;
	}

	ComputerBuilder& setWi_Fi(bool wi)
	{
		Wi_Fi = wi;
		return *this;
	}

	ComputerBuilder& setWaterCooling(bool wa)
	{
		waterCooling = wa;
		return *this;
	}

	Computer  build()
	{
		return Computer(CPU, GPU, RAM, SSD, HDD, Wi_Fi, waterCooling);
	}
};

class ComputerDirector
{
public:
	Computer computerOfficePC()
	{
		return ComputerBuilder()
			.setCPU("Apple M4")
			.setGPU("Integrated")
			.setRAM(16)
			.setSSD(180)
			.setHDD(1)
			.setWi_Fi(true)
			.setWaterCooling(false)
			.build();
	}

	Computer computerGamingPC()
	{
		return ComputerBuilder()
			.setCPU("AMD Ryzen 7 9800X3D")
			.setGPU("NVIDIA GeForce RTX 3080")
			.setRAM(32)
			.setSSD(1000)
			.setHDD(2)
			.setWi_Fi(true)
			.setWaterCooling(true)
			.build();
	}

	Computer computerServer()
	{
		return ComputerBuilder()
			.setCPU("Intel Xeon Silver 4214")
			.setGPU("None")
			.setRAM(64)
			.setSSD(2000)
			.setHDD(8)
			.setWi_Fi(false)
			.setWaterCooling(true)
			.build();
	}
};

int main()
{
	ComputerDirector computerDirector;

	Computer officePC = computerDirector.computerOfficePC();
	Computer gamingPC = computerDirector.computerGamingPC();
	Computer server = computerDirector.computerServer();

	cout << "Office PC: " << endl;
	officePC.show();

	cout << " " << endl;

	cout << "Gaming PC: " << endl;
	gamingPC.show();

	cout << " " << endl;

	cout << "Server: " << endl;
	server.show();

	return 0;
}
