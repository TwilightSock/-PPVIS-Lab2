/*!
\file
\brief Файл, в котором хранятся методы класса Aircraft


*/

#include "Header.h"

using namespace std;

void Aircraft::shoot()
{
	for (int i = 0; i < projectile_ammount; i++)
	{
		cout << "Shot was fired - ";
		if ((rand() % 10 + 1) % 2 == 0)
		{
			cout << "Target is destroyed" << endl;
		}
		else {
			cout << "Missed the target" << endl;
		}
		for (int j = 0; j < reload_speed; j++)
		{
			cout << "Reload...\t";
			Sleep(1000);
		}
		cout << endl;
	}
}

void Aircraft::activation()
{
	if (engine)
	{
		engine = false;
		cout << "You turned off engine" << endl;
	}
	else
	{
		engine = true;
		cout << "You turned on engine" << endl;
	}
}
void Aircraft::move()
{
	chassis();
	while (speed < fixed_speed)
	{
		speed += (rand() % 10 + 1);
		cout << "Current Speed is " << speed << "...\t";
		Sleep(500);
	}
	while (speed > 40)
	{
		cout << "Current Speed is " << speed << "...\t";
		speed -= (rand() % 10 + 1);
		Sleep(500);
	}
	flaps();
	chassis();
}

void Aircraft::flaps()
{
	if (speed > 40)
	{
		cout << "You opened the flaps...\t";
		while (speed > 0)
		{
			cout << "Reducing the speed...\t";
			speed -= (rand() % 10 + 1);
			Sleep(500);
		}
	}
	else
	{
		cout << "Getting speed up...\t";
		Sleep(500);
		speed += 20;
		flaps();
	}
}

void Aircraft::chassis()
{
	if (chasis)
	{
		chasis = false;
		cout << "You retracting landing gear...\t";
	}
	else
	{
		chasis = true;
		cout << "You pulling up landing gear...\t";
	}
}

void Aircraft::bf()
{
	if (!engine)
	{
		activation();
	}
	move();
	activation();
}

Aircraft::Aircraft(int projectile_ammount, int reload_speed, int fixed_speed)
{
	this->projectile_ammount = projectile_ammount;
	this->reload_speed = reload_speed;
	this->fixed_speed = fixed_speed;
}