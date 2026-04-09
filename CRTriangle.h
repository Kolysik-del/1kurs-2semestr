#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
* @brief класс прямоугольного треугольника
*/

class RTriangle
{
private:

	/**
	* @param leg1 - первый катет
	*/
	double leg1;

	/**
	* @param leg_two - второй катет
	*/
	double leg2;

	/**
	* @brief Функция проверки задания треугольника
	* @param leg1 - первый катет
	* @param leg2 - второй катет
	*/
	void checkTriangle(const double leg1, const double leg2);

public:

	/**
	* @brief Конструктор по-умолчанию, задаёт стороны как 3 и 4
	*/
	RTriangle();

	/**
	* @brief Конструктор, задаёт стороны как значения, которые передал пользователь
	* @param leg1 - первый катет
	* @param leg2 - второй катет
	*/
	RTriangle(const double leg1, const double leg2);

	/**
	* @brief Рассчитывает радиус описанной окружности
	* @return Радиус описанной окружности
	*/
	double RadiusCircle() const;

	/**
	* @brief Рассчитывает площадь описанной окружности
	* @return Площадь описанной окружности
	*/
	double AreaCircle() const;
};
