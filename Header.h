/*!
\file
\brief ������������ ���� � ��������� �������

������ ���� �������� � ���� ����������� ������������ ������ Combat_Vehicle, � ����� ��� �������� �������.
*/
#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

/*!
\brief ����������� ����� Combat_Vehicle

����� ��������� ��������� �������:
\param projectile_ammount ���������� ��������
\param  reload_speed �������� �����������
\param fixed_speed ������������� ��������
\param speed ����������� ��������
*/

class Combat_Vehicle {
public:
	int projectile_ammount = 0;
	/// <summary>
	/// ������� shoot() ��������� �������� ��������, ����������� ����������� �������.
	/// </summary>
	void virtual shoot() = 0;
	/// <summary>
	/// ������� bf() ������ � ���� ���� ������������ �������.
	/// </summary>
	void virtual bf() = 0;
protected:
	/// <summary>
	/// ������� move() �������� �� �������� �� ����� �������, �� ��������.
	/// </summary>
	void virtual move() = 0;
	/// <summary>
	/// ������� activation() ��������� ������� ������� ���������/������ � �����/��������� �������� � ������ �����, ������ ��� ��������.
	/// </summary>
	void virtual activation() = 0;
	int reload_speed = 0;
	int fixed_speed = 0;
	int speed = 0;
};

/*!
\brief �������� Missile_Launcher

\param slot ���������� ������ ��� �������� projectile_ammount
*/

class Missile_Launcher : public virtual Combat_Vehicle
{
public:
	Missile_Launcher(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
private:
	int slot = 6;
	/// <returns>
	/// ������� ����������, ������� �������� �� ��������� ������ ������.
	/// </returns>
	bool engine = false;
	/// <summary>
	/// ������� aiming() ��������� ������� �� ����.
	/// </summary>
	void aiming();
protected:
	void activation();
	void move();
};

/*!
\brief �������� Aircraft

*/

class Aircraft : public virtual Combat_Vehicle
{
public:
	Aircraft()
	{}
	Aircraft(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
private:
	/// <summary>
	/// ������� flaps() ��������� ��������, ���� ��������� �������� ���� ��������������, �������� ���������� ���������� �� ������, ����� ���� ����������� ��������.
	/// </summary>
	void flaps();
	/// <summary>
	/// ������� chassis() ��������� ������/�������� ����� �������� ��� ������ � �������.
	/// </summary>
	void chassis();
	bool engine = false;
	/// <summary>
	/// ����������, ���������� �� ��������� ����� � ������ ������.
	/// </summary>
	bool chasis = true;
protected:
	void activation();
	void move();
};

/*!
\brief �������� Fighter

 ������ ����� - ��������� �������������� ������������ �� ������ Combat_Vehicle � Aircraft.

*/

class Fighter : protected virtual Aircraft, public virtual Combat_Vehicle
{
public:
	Fighter(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
	/// <summary>
	/// ������� bomb() ��������� ���������� ���� ��������� � ����������� �� ������� ������� � ���������� �����������.
	/// </summary>
	void bomb();
private:
protected:
	void flaps();
	void chassis();
	bool engine = false;
	bool chasis = true; 
	void activation();
	void move();
};

/*!
\brief �������� Ship

*/

class Ship : public virtual Combat_Vehicle
{
public:
	Ship(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
	/// <summary>
	/// ������� echo() ��������� ������������� ����������� ����������� ������� � ������� �����������.
	/// </summary>
	void echo();
private:
	/// <summary>
	/// ������� use_anchor() �������� �� ��������� �����.
	/// </summary>
	void use_anchor();
	/// <summary>
	/// ������� ����������, ���������� �� ��������� �����.
	/// </summary>
	bool anchor = true;
	bool engine = false;
protected:
	void move();
	void activation();
};

/*!
\brief �������� Tank

*/

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
