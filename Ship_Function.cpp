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



Ship::Ship(int projectile_ammount, int reload_speed)
{
	this->projectile_ammount = projectile_ammount;
	this->reload_speed = reload_speed;
}