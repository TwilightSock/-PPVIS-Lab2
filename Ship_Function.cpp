/*!
\file
\brief Файл, в котором хранятся методы класса Ship


*/

#include "Header.h"

using namespace std;

void Ship::shoot()
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

void Ship::move()
{
	use_anchor();
	while (speed < fixed_speed)
	{
		speed += (rand() % 10 + 1);
		cout << "Current Speed is " << speed << "...\t";
		Sleep(500);
	}
	while (speed > 0)
	{
		cout << "Current Speed is " << speed << "...\t";
		speed -= (rand() % 10 + 1);
		Sleep(500);
	}
	use_anchor();
}

void Ship::echo()
{
	cout << "Sonar calculates the depth...\t";
	Sleep(2000);
	cout << "The depth is " << rand() % 5000 + 300 << " metres...\t";
}

void Ship::activation()
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

void Ship::use_anchor()
{
	if (anchor)
	{
		anchor = false;
		cout << "You retracting anchor...\t";
	}
	else
	{
		anchor = true;
		cout << "You pulling up anchor...\t";
	}
}

void Ship::bf()
{
	if (!engine)
	{
		activation();
	}
	move();
	activation();
}

Ship::Ship(int projectile_ammount, int reload_speed, int fixed_speed)
{
	this->projectile_ammount = projectile_ammount;
	this->reload_speed = reload_speed;
	this->fixed_speed = fixed_speed;
}