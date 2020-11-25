#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

//Абстрактный класс оружия

class Combat_Vehicle {
public:
	int projectile_ammount = 0;
	virtual void shoot() = 0;
protected:
	int reload_speed = 0;
};

class Missile_Launcher : public virtual Combat_Vehicle
{
public: 
	Missile_Launcher(int projectile_ammount, int reload_speed);
	void shoot();
protected:
private:
	
};

class Aircraft : public virtual Combat_Vehicle
{

};

class Fighter : protected virtual Aircraft, public virtual Combat_Vehicle
{

};

class Ship : public virtual Combat_Vehicle
{

};

class Tank : public virtual Combat_Vehicle
{

};

class Armored_Vehicle : public virtual Combat_Vehicle
{

};
