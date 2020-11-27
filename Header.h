/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определение абстрактного класса Combat_Vehicle, а также его дочерних классов.
*/
#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

/*!
\brief Абстрактный класс Combat_Vehicle

Имеет следующие параметры функций:
\param projectile_ammount количество снарядов
\param  reload_speed скорость перезарядки
\param fixed_speed установленную скорость
\param speed изначальную скорость
*/

class Combat_Vehicle {
public:
	int projectile_ammount = 0;
	/// <summary>
	/// Функция shoot() описывает действия стрельбы, перезарядки конкретного объекта.
	/// </summary>
	void virtual shoot() = 0;
	/// <summary>
	/// Функция bf() хранит в себе цикл передвижения объекта.
	/// </summary>
	void virtual bf() = 0;
protected:
	/// <summary>
	/// Функция move() отвечает за действия во время поездки, их описание.
	/// </summary>
	void virtual move() = 0;
	/// <summary>
	/// Функция activation() описывает условия запуска двигателя/снятия с якоря/включение закрылок и других опций, нужных для движения.
	/// </summary>
	void virtual activation() = 0;
	int reload_speed = 0;
	int fixed_speed = 0;
	int speed = 0;
};

/*!
\brief Подкласс Missile_Launcher

\param slot количество слотов для снарядов projectile_ammount
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
	/// Буловая переменная, которая отвечает за состояние работы мотора.
	/// </returns>
	bool engine = false;
	/// <summary>
	/// Функция aiming() описывает наводку на цель.
	/// </summary>
	void aiming();
protected:
	void activation();
	void move();
};

/*!
\brief Подкласс Aircraft

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
	/// Функция flaps() описывает закрылки, если указанная скорость ниже соответстующий, скорость рекурсивно набирается до нужной, после чего выпускаются закрылки.
	/// </summary>
	void flaps();
	/// <summary>
	/// Функция chassis() описывает выпуск/поднятие шасси самолета при взлете и посадке.
	/// </summary>
	void chassis();
	bool engine = false;
	/// <summary>
	/// Переменная, отвечающая за состояние шасси в данный момент.
	/// </summary>
	bool chasis = true;
protected:
	void activation();
	void move();
};

/*!
\brief Подкласс Fighter

 Данный класс - результат множественного наследования от класса Combat_Vehicle и Aircraft.

*/

class Fighter : protected virtual Aircraft, public virtual Combat_Vehicle
{
public:
	Fighter(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
	/// <summary>
	/// Функция bomb() описывает вычисление зоны поражения в зависимости от размера снаряда в тротиловом эквиваленте.
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
\brief Подкласс Ship

*/

class Ship : public virtual Combat_Vehicle
{
public:
	Ship(int projectile_ammount, int reload_speed, int fixed_speed);
	void shoot();
	void bf();
	/// <summary>
	/// Функция echo() описывает использование определение действующей глубины с помощью эхолокатора.
	/// </summary>
	void echo();
private:
	/// <summary>
	/// Функция use_anchor() отвечает за состояние якоря.
	/// </summary>
	void use_anchor();
	/// <summary>
	/// Буловая переменная, отвечающая за состояние якоря.
	/// </summary>
	bool anchor = true;
	bool engine = false;
protected:
	void move();
	void activation();
};

/*!
\brief Подкласс Tank

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
