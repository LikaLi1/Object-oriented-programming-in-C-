//#include <iostream>
//using namespace std;
//
//class Train
//{
//public:
//    void tutu() {
//        cout << "Train tutu\n";
//    }
//};
//
//class Farm {
//public:
//    void chicken()
//    {
//        cout << "Chiken coco\n";
//    }
//};
//
//class Facade
//{
//    Train train;
//    Farm farm;
//
//public:
//    void startList()
//    {
//        train.tutu();
//        farm.chicken();
//    }
//
//    void shutdown()
//    {
//        cout << "Nado\n";
//    }
//};
//
//int main()
//{
//    Facade facade;
//    facade.startList();
//    facade.startList();
//    facade.shutdown();
//}


//#include <iostream>
//using namespace std;
//
//class Train
//{
//public:
//    void tutu() {
//        cout << "Train tutu\n";
//    }
//};
//
//class Farm {
//public:
//    void chicken()
//    {
//        cout << "Chiken coco\n";
//    }
//};
//
//int main()
//{
//    Train train;
//    Farm farm;
//
//    train.tutu();
//    farm.chicken();
//}


//#include <iostream>
//using namespace std;
//
//class CPU
//{
//public:
//	void startCPU()
//	{
//		cout << "CPU start\n";
//	}
//};
//
//class Memory
//{
//public:
//	void startMemory()
//	{
//		cout << "Memory start\n";
//	}
//};
//
//class Disk
//{
//public:
//	void startDisk()
//	{
//		cout << "Disk start\n";
//	}
//};
//
//class ComputerFacade
//{
//	CPU cpu;
//	Memory memory;
//	Disk disk;
//
//public:
//	void startComputer()
//	{
//		cpu.startCPU();
//		memory.startMemory();
//		disk.startDisk();
//	}
//};
//
//int main()
//{
//	ComputerFacade computer;
//	computer.startComputer();
//}


//#include <iostream>
//using namespace std;
//
//class Graphics
//{
//public:
//	void startGraphics()
//	{
//		cout << "Graphics start\n";
//	}
//};
//
//class Sound
//{
//public:
//	void startSound()
//	{
//		cout << "Sound start\n";
//	}
//};
//
//class Physics
//{
//public:
//	void startPhysics()
//	{
//		cout << "Physics start\n";
//	}
//};
//
//class GameFacade
//{
//	Graphics graphics;
//	Sound sound;
//	Physics physics;
//
//public:
//	void startGame()
//	{
//		graphics.startGraphics();
//		sound.startSound();
//		physics.startPhysics();
//	}
//};
//
//int main()
//{
//	GameFacade game;
//	game.startGame();
//}


//#include <iostream>
//using namespace std;
//
//class Validator
//{
//public:
//	void startValidator()
//	{
//		cout << "Validator start\n";
//	}
//};
//
//class Database
//{
//public:
//	void startDatabase()
//	{
//		cout << "Database start\n";
//	}
//};
//
//class EmailService
//{
//public:
//	void startEmailService()
//	{
//		cout << "EmailService start\n";
//	}
//};
//
//class UserService
//{
//	Validator validator;
//	Database data;
//	EmailService email;
//
//public:
//	void startUserService()
//	{
//		validator.startValidator();
//		data.startDatabase();
//		email.startEmailService();
//	}
//};
//
//int main()
//{
//	UserService user;
//	user.startUserService();
//}


//#include <iostream>
//using namespace std;
//
//class TV
//{
//public:
//	void startTV()
//	{
//		cout << "TV start\n";
//	}
//};
//
//class AudioSystem
//{
//public:
//	void startAudioSystem()
//	{
//		cout << "Audio system start\n";
//	}
//};
//
//class DVD
//{
//public:
//	void startDVD()
//	{
//		cout << "DVD start\n";
//	}
//};
//
//class HomeTheaterFacade
//{
//	TV tv;
//	AudioSystem audio;
//	DVD dvd;
//
//public:
//	void startHomeTheaterFacade()
//	{
//		tv.startTV();
//		audio.startAudioSystem();
//		dvd.startDVD();
//	}
//
//	void start()
//	{
//		cout << "Start\n";
//	}
//
//	void init()
//	{
//		cout << "Init\n";
//	}
//
//	void fullStart()
//	{
//		cout << "FullStart\n";
//	}
//};
//
//int main()
//{
//	HomeTheaterFacade home;
//	home.startHomeTheaterFacade();
//	home.start();
//	home.init();
//	home.fullStart();
//}


#include <iostream>
using namespace std;

class Card
{
public:
	void startCard()
	{
		cout << "Card\n";
	}
};

class QRCode
{
public:
	void startQrCode()
	{
		cout << "Qr-Code\n";
	}
};

class PaymentFacade
{
	Card card;
	QRCode qr;

public:
	void start()
	{
		card.startCard();
		qr.startQrCode();
	}

	void pay()
	{
		cout << "Choose system\n";
		cout << "Process payment\n";
	}
};

int main()
{
	PaymentFacade pay;
	pay.start();
	pay.pay();
}


#include <iostream>
#include <vector>
using namespace std;

class Command 
{
public:
	virtual void execute() = 0;
	virtual ~Command() {}
};

class Card
{
public:
	void startCard()
	{
		cout << "Card\n";
	}
};

class StartCardCommand : public Command
{
private:
	Card* card;

public:
	StartCardCommand(Card* c) : card(c) {}

	void execute() override
	{
		card->startCard();
	}
};

class QRCode
{
public:
	void startQrCode()
	{
		cout << "Qr-Code\n";
	}
};

class StartQrCodeCommand : public Command
{
private:
	QRCode* qrcode;

public:
	StartQrCodeCommand(QRCode* q) : qrcode(q) {}

	void execute() override
	{
		qrcode->startQrCode();
	}
};

class PaymentFacade
{
	vector<Command*> commands;

public:
	void addCommand(Command* cmd)
	{
		commands.push_back(cmd);
	}

	void start()
	{
		for (auto cmd : commands)
		{
			cmd->execute();
		}
	}

	void pay()
	{
		cout << "Choose system\n";
		cout << "Process payment\n";
	}
};

int main()
{
	Card plastic;
	QRCode wifi;

	StartCardCommand ppay(&plastic);
	StartQrCodeCommand wpay(&wifi);

	PaymentFacade pay;
	pay.addCommand(&ppay);
	pay.addCommand(&wpay);

	pay.start();
	pay.pay();
}
