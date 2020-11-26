#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

//Абстрактный класс оружия

class Combat_Vehicle {
public:
	int projectile_ammount = 0;
	void virtual shoot() = 0;
	void virtual bf() = 0;
protected:
	void virtual move() = 0;
	void virtual activation() = 0;
	int reload_speed = 0;
	int fixed_speed = 0;
	int speed = 0;
};

class Missile_Launcher : public virtual Combat_Vehicle
{

};

class Aircraft : public virtual Combat_Vehicle
{
};

class Fighter : protected virtual Aircraft, public virtual Combat_Vehicle
{

};

class Ship : public virtual Combat_Vehicle
{
public:
	Ship(int projectile_ammount, int reload_speed);
	void shoot();
};

class Tank : public virtual Combat_Vehicle
{
public:
	Tank(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
private:
	bool engine = false;
protected:
	void activation();
	void move();
};

class Armored_Vehicle : public virtual Combat_Vehicle
{
public:
	Armored_Vehicle(int projectile_ammount, int reload_speed);
};

