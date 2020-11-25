#pragma once
#include <iostream>
#include <string>

using namespace std;

//Абстрактный класс оружия

class Combat_Vehicle {
public:
	int projectile_ammount = 0;
protected:
	virtual void shoot() = 0;
};

class Missile_Launcher : public virtual Combat_Vehicle
{
public: 
	void shoot() override
	{
		cout << "Выстрел очередью";
	}
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