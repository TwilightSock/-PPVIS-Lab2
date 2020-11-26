#include "Header.h"

using namespace std;

void Missile_Launcher::shoot()
{
	aiming();
	bool slot_over = true;
	while (slot_over)
	{
		for (int j = 0; j < reload_speed; j++)
		{
			cout << "Reload...\t";
			Sleep(1000);
		}
		if (projectile_ammount >= slot) 
		{
			projectile_ammount = projectile_ammount - slot;
			for (int j = 1; j < slot + 1; j++)
			{
				cout << j << " Missile fired...\t";
				Sleep(200);
			}
		}
		else if (projectile_ammount < slot)
		{
			for (int j = 1; j < projectile_ammount + 1; j++)
			{
				cout << j << " Missile fired...\t";
				Sleep(200);
			}
			slot_over = false;
		}
		else
		{
			cout << "Missing missiles...\t";
			slot_over = false;
		}
	}
}

void Missile_Launcher::aiming()
{
	int n = (rand() % 10 -5);
	cout << "the Target is " << n << " degrees away" << endl;
	while (n != 0)
	{
		if (n > 0)
		{
			n--;
			cout << n << "degrees\t";
		}
		else if (n < 0)
		{
			n++;
			cout << n << "degrees\t";
		}
	}
	cout << "Dead ahead" << endl;
}




void Missile_Launcher::activation()
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
void Missile_Launcher::move()
{
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
}

void Missile_Launcher::bf()
{
	if (!engine)
	{
		activation();
	}
	move();
	activation();
}

Missile_Launcher::Missile_Launcher(int projectile_ammount, int reload_speed, int fixed_speed)
{
	this->projectile_ammount = projectile_ammount;
	this->reload_speed = reload_speed;
	this->fixed_speed = fixed_speed;
}