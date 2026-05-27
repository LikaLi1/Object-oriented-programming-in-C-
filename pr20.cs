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


#include <iostream>
#include <string>
using namespace std;

class UserProfile
{
private:
	string login;
	string email;
	string phone;
	string city;
	int age;
	string role;
	bool isVerified;

public:
	UserProfile(string l, string  e, string p, string c, int a, string r, bool i) : login(l), email(e), phone(p), city(c), age(a), role(r), isVerified(i) {}

	void show()
	{
		cout << "Login: " << login << endl;
		cout << "Email: " << email << endl;
		cout << "Phone: " << phone << endl;
		cout << "City: " << city << endl;
		cout << "Age: " << age << endl;
		cout << "Role: " << role << endl;
		cout << "Is verified: " << isVerified << endl;
	}
};

class UserProfileBuilder
{
private:
	string login = "";
	string email = "";
	string phone = "";
	string city = "";
	int age = 0;
	string role = "user";
	bool isVerified = false;

public:
	UserProfileBuilder& setLogin(string l)
	{
		login = l;
		return *this;
	}

	UserProfileBuilder& setEmail(string e)
	{
		email = e;
		return *this;
	}

	UserProfileBuilder& setPhone(string p)
	{
		phone = p;
		return *this;
	}

	UserProfileBuilder& setCity(string c)
	{
		city = c;
		return *this;
	}

	UserProfileBuilder& setAge(int a)
	{
		age = a;
		return *this;
	}

	UserProfileBuilder& setRole(bool r)
	{
		role = r;
		return *this;
	}

	UserProfileBuilder& enableIsVerified(bool i)
	{
		isVerified = i;
		return *this;
	}

	UserProfileBuilder& verify()
	{
		if (login.empty())
		{
			cout << "Login is Null" << endl;
		}
		if (login.size() < 8)
		{
			cout << "Login < 8 sym" << endl;
		}
		return *this;
	}

	UserProfile build()
	{
		char sym = '@';

		if (email.find(sym) != string::npos) {
			return UserProfile(login, email, phone, city, age, role, isVerified);
		}
		else {
			std::cout << "Sym '@' not founded" << std::endl;
		}
	}
};

int main()
{
	UserProfile userProfile = UserProfileBuilder()
		.setLogin("Game_1257")
		.setEmail("mail@")
		.setPhone("+79865421599")
		.setCity("Moscow")
		.setAge(15)
		.setRole("")
		.enableIsVerified(true)
		.verify()
		.build();

	userProfile.show();

	return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class GameLevel
{
private:
	string title;
	int hard;
	vector<string> listE;
	vector<string> listI;
	bool boss;
	string weatherAffect;

public:
	GameLevel(string t, int  h, vector<string> e, vector<string> i, bool b, string w) : title(t), hard(h), listE(e), listI(i), boss(b), weatherAffect(w) {}

	void show()
	{
		cout << "Title: " << title << endl;
		cout << "Hard: " << hard << endl;
		cout << "Enemy: ";
		for (string listEnemy : listE)
			cout << listEnemy << endl;
		cout << "Item: ";
		for (string listItem : listI)
			cout << listItem << endl;
		cout << "Boss: " << boss << endl;
		cout << "Weather affect: " << weatherAffect << endl;
	}
};

class GameLevelBuilder
{
private:
	string title = "";
	int hard = 0;
	vector<string> listE;
	vector<string> listI;
	bool boss = false;
	string weatherAffect = "";

public:
	GameLevelBuilder& setTitle(string t)
	{
		title = t;
		return *this;
	}

	GameLevelBuilder& setHard(int h)
	{
		hard = h;
		return *this;
	}

	GameLevelBuilder& addEnemy(string listEnemy)
	{
		listE.push_back(listEnemy);
		return *this;
	}

	GameLevelBuilder& addItem(string listItem)
	{
		listI.push_back(listItem);
		return *this;
	}

	GameLevelBuilder& enableBoss(int b)
	{
		boss = b;
		return *this;
	}

	GameLevelBuilder& setWeatherAffect(bool w)
	{
		weatherAffect = w;
		return *this;
	}

	GameLevel build()
	{
		if (title.empty())
		{
			cout << "Title is Null" << endl;
		}
		else
		{
			return GameLevel(title, hard, listE, listI, boss, weatherAffect);
		}
	}
};

int main()
{
	GameLevel gameLevel = GameLevelBuilder()
		.setTitle("King")
		.setHard(5)
		.addEnemy("Robot")
		.addEnemy("Mouse")
		.addItem("Knife")
		.addItem("Flower")
		.enableBoss(true)
		.setWeatherAffect("Rain")
		.build();

	gameLevel.show();

	return 0;
}


#include <iostream>
using namespace std;

class Notification
{
private:
	string recipient;
	string heading;
	string text;
	string sendingChannel;
	int priority;
	string confirmation;

public:
	Notification(string r, string  h, string t, string s, int p, string c) : recipient(r), heading(h), text(t), sendingChannel(s), priority(p), confirmation(c) {}

	void show()
	{
		cout << "Recipient: " << recipient << endl;
		cout << "Heading: " << heading << endl;
		cout << "Text: " << text << endl;
		cout << "SendingChannel: " << sendingChannel << endl;
		cout << "Priority: " << priority << endl;
		cout << "Confirmation: " << confirmation << endl;
	}
};

class NotificationBuilder
{
private:
	string recipient = "";
	string heading = "";
	string text = "";
	string sendingChannel = "";
	int priority = 0;
	string confirmation = "";

public:
	NotificationBuilder& setRecipient(string r)
	{
		recipient = r;
		return *this;
	}

	NotificationBuilder& setHeading(string h)
	{
		heading = h;
		return *this;
	}

	NotificationBuilder& setText(string t)
	{
		text = t;
		return *this;
	}

	NotificationBuilder& setSendingChannel(string s)
	{
		sendingChannel = s;
		return *this;
	}

	NotificationBuilder& setPriority(int p)
	{
		priority = p;
		return *this;
	}

	NotificationBuilder& setConfirmation(string c)
	{
		confirmation = c;
		return *this;
	}

	Notification build()
	{
		if (recipient.empty())
		{
			throw runtime_error("Recipient is Null");
		}
		if (text.empty())
		{
			throw runtime_error("Text is Null");
		}
		return Notification(recipient, heading, text, sendingChannel, priority, confirmation);
	}
};

class SendingChannelDirector
{
public:
	Notification notificationEmail()
	{
		return NotificationBuilder()
			.setRecipient("user@example.com")
			.setHeading("Welcome!")
			.setText("Thank you for registering. Please confirm your email.")
			.setSendingChannel("email")
			.setPriority(1)
			.setConfirmation("confirmation_link")
			.build();
	}

	Notification notificationSms()
	{
		return NotificationBuilder()
			.setRecipient("+71231231213")
			.setHeading("Reg")
			.setText("Your code: 12345")
			.setSendingChannel("sms")
			.setPriority(2)
			.setConfirmation("12345")
			.build();
	}

	Notification notificationPush()
	{
		return NotificationBuilder()
			.setRecipient("device_token_ABCDEF123456")
			.setHeading("Notification")
			.setText("You received a new push!")
			.setSendingChannel("push")
			.setPriority(3)
			.setConfirmation("")
			.build();
	}
};

int main()
{
	SendingChannelDirector sendingChannelDirector;

	Notification notificationEmail = sendingChannelDirector.notificationEmail();
	Notification notificationSms = sendingChannelDirector.notificationSms();
	Notification notificationPush = sendingChannelDirector.notificationPush();

	cout << "Email: " << endl;
	notificationEmail.show();

	cout << endl;

	cout << "SMS: " << endl;
	notificationSms.show();

	cout << endl;

	cout << "Push: " << endl;
	notificationPush.show();

	return 0;
}


#include <iostream>
using namespace std;

class Order
{
private:
	string firstName;
	string lastName;
	int age;

public:
	Order(string f, string l, int a) : firstName(f), lastName(l), age(a) {}

	void show() const
	{
		cout << "First name: " << firstName << endl;
		cout << "Last name: " << lastName << endl;
		cout << "Age: " << age << endl;
	}
};

class OrderBuilder
{
private:
	string firstName = "";
	string lastName = "";
	int age = 0;

public:
	OrderBuilder& setFirstName(const string& f)
	{
		firstName = f;
		return *this;
	}

	OrderBuilder& setLastName(const string& l)
	{
		lastName = l;
		return *this;
	}

	OrderBuilder& setAge(int a)
	{
		age = a;
		return *this;
	}

	Order build()
	{
		return Order(firstName, lastName, age);
	}
};

class PaymentService {
public:
	void startPaymentService(const Order& order)
	{
		cout << "Payment Service\n";
		order.show();
	}
};

class DeliveryService {
public:
	void startDeliveryService(const Order& order)
	{
		cout << "Delivery Service\n";
		order.show();
	}
};

class NotificationService {
public:
	void startNotificationService(const Order& order)
	{
		cout << "Notification Service\n";
		order.show();
	}
};

class OrderFacade
{
	PaymentService pay;
	DeliveryService delivery;
	NotificationService notification;

public:
	void startOrderFacade(const Order& order)
	{
		pay.startPaymentService(order);
		delivery.startDeliveryService(order);
		notification.startNotificationService(order);
	}

};

int main()
{
	OrderBuilder orderBuilder;
	Order order = orderBuilder
		.setFirstName("Kate")
		.setLastName("Nik")
		.setAge(24)
		.build();

	OrderFacade orderFacade;
	orderFacade.startOrderFacade(order);

	return 0;
}


#include <iostream>
using namespace std;

class Order
{
private:
	string firstName;
	string lastName;
	int age;

public:
	Order(string f, string l, int a) : firstName(f), lastName(l), age(a) {}

	void show() const
	{
		cout << "First name: " << firstName << endl;
		cout << "Last name: " << lastName << endl;
		cout << "Age: " << age << endl;
	}
};

class OrderBuilder
{
private:
	string firstName = "";
	string lastName = "";
	int age = 0;

public:
	OrderBuilder& setFirstName(const string& f)
	{
		firstName = f;
		return *this;
	}

	OrderBuilder& setLastName(const string& l)
	{
		lastName = l;
		return *this;
	}

	OrderBuilder& setAge(int a)
	{
		age = a;
		return *this;
	}

	Order build()
	{
		return Order(firstName, lastName, age);
	}
};

class DiscountStrategy 
{
public:
	virtual void discount() = 0;
	virtual ~DiscountStrategy() {}
};

class NoDiscount : public DiscountStrategy
{
public:
	void discount() override
	{
		cout << "NoDiscount\n";
	}
};

class PercentDiscount : public DiscountStrategy
{
public:
	void discount() override
	{
		cout << "PercentDiscount\n";
	}
};

class FixedDiscount : public DiscountStrategy
{
public:
	void discount() override
	{
		cout << "FixedDiscount\n";
	}
};

int main()
{
	OrderBuilder orderBuilder;
	Order order = orderBuilder
		.setFirstName("Kate")
		.setLastName("Nik")
		.setAge(24)
		.build();

	return 0;
}


// Вопросы
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

class DiscountStrategy;

class Order {
private:
    string firstName;
    string lastName;
    int age;
    double baseAmount;
    double finalAmount;
    double sym;
    const DiscountStrategy* discountStrategy;

public:
    Order(string f, string l, int a, double am, double s, const DiscountStrategy* strategy) : firstName(f), lastName(l), age(a), baseAmount(am), sym(s), discountStrategy(strategy), finalAmount(0) {}

    void applyDiscount() {
        if (discountStrategy != nullptr) {
            finalAmount = discountStrategy->calculate(*this);
        }
        else {
            finalAmount = baseAmount;
        }
    }

    double getBaseAmount() const { return baseAmount; }
    double getSym() const { return sym; }

    void show() const {
        cout << "First name: " << firstName << " Last name: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Base amount: $" << baseAmount << endl;
        cout << "Final amount: $" << finalAmount << endl;
    }
};

class DiscountStrategy {
public:
    virtual ~DiscountStrategy() {}
    virtual double calculate(const Order& order) const = 0;
};

class NoDiscount : public DiscountStrategy {
public:
    double calculate(const Order& order) const override {
        return order.getBaseAmount();
    }
};

class PercentDiscount : public DiscountStrategy {
public:
    double calculate(const Order& order) const override {
        double percent = order.getSym();
        double discountValue = order.getBaseAmount() * (percent / 100.0);
        return max(0.0, order.getBaseAmount() - discountValue);
    }
};

class FixedDiscount : public DiscountStrategy {
public:
    double calculate(const Order& order) const override {
        double discountValue = order.getSym();
        return max(0.0, order.getBaseAmount() - discountValue);
    }
};

class OrderBuilder {
private:
    string firstName = "";
    string lastName = "";
    int age = 0;
    double amount = 0.0;
    double sym = 0.0;
    const DiscountStrategy* discountStrategy = &NoDiscount();

public:
    OrderBuilder& setFirstName(const string& f) {
        firstName = f;
        return *this;
    }

    OrderBuilder& setLastName(const string& l) {
        lastName = l;
        return *this;
    }

    OrderBuilder& setAge(int a) {
        age = a;
        return *this;
    }

    OrderBuilder& setBaseAmount(double amount) {
        this->amount = amount;
        return *this;
    }

    OrderBuilder& setSym(double s) {
        sym = s;
        return *this;
    }

    OrderBuilder& withDiscountStrategy(const DiscountStrategy* strategy) {
        discountStrategy = strategy;
        return *this;
    }

    Order build() {
        Order order(firstName, lastName, age, amount, sym, discountStrategy);
        order.applyDiscount();
        return order;
    }
};

int main()
{
    OrderBuilder builder;

    Order order1 = builder
        .setFirstName("Kate")
        .setLastName("Nik")
        .setAge(24)
        .setBaseAmount(1000.0)
        .setSym(0)
        .withDiscountStrategy(new NoDiscount())
        .build();
    order1.show();

    Order order2 = builder
        .setFirstName("Ivan")
        .setLastName("Ivanov")
        .setAge(45)
        .setBaseAmount(5000.0)
        .setSym(15)
        .withDiscountStrategy(new PercentDiscount())
        .build();
    order2.show();

    Order order3 = builder
        .setFirstName("Maria")
        .setLastName("Sidorova")
        .setAge(38)
        .setBaseAmount(2500.0)
        .setSym(200)
        .withDiscountStrategy(new FixedDiscount())
        .build();
    order3.show();

    return 0;
}


#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

class Prototype
{
public:
    virtual Prototype* clone() = 0;
    virtual void show() const = 0;
    virtual ~Prototype() {}
};

class Character : public Prototype {
private:
    string name;
    int hp;
    int damage;
    string weapons;

public:
    Character(string n, int h, int d, string w) : name(n), hp(h), damage(d), weapons(w) {}

    Prototype* clone() override
    {
        return new Character(*this);
    }

    void show() const {
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl;
        cout << "Weapons: " << weapons << endl;
    }
};

class CharacterBuilder {
private:
    string name = "";
    int hp = 0;
    int damage= 0;
    string weapons = "";

public:
    CharacterBuilder& setName(string n) {
        name = n;
        return *this;
    }

    CharacterBuilder& setHP(int h) {
        hp = h > 0 ? h : 0;
        return *this;
    }

    CharacterBuilder& setDamage(int d) {
        damage = d > 0 ? d : 0;
        return *this;
    }

    CharacterBuilder& setWeapons(string w) {
        weapons = w;
        return *this;
    }

    Character build() {
        return Character (name, hp, damage, weapons);
    }
};

int main()
{
    Character character = CharacterBuilder()
        .setName("Kate")
        .setHP(100)
        .setDamage(20)
        .setWeapons("Knife")
        .build();

    Character* character1 = dynamic_cast<Character*>(character.clone());
    character1->show();

    cout << endl;

    Character* character2 = dynamic_cast<Character*>(character.clone());
    character2->show();

    return 0;
}
