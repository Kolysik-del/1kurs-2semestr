#include "CRTriangle.h"

/**
* @brief Считывает значение введённое с клавиатуры
* @return Значение введённое с клавиатуры, если оно считано правильно
*/
const double GetSide(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	cout << "Введите первый катет: ";
	const double side1 = GetSide();

	cout << "Введите второй катет: ";
	const double side2 = GetSide();

	RTriangle A(side1, side2);

	cout << "Радиус описанной окружности: " << A.RadiusCircle() <<
		endl << "Площадь описанной окружности: " << A.AreaCircle() <<
		endl;

	return 0;
}

const double GetSide(void)
{
	double number = 0;
	cin >> number;
	if (cin.fail())
	{
		cout << "Ошибка ввода!";
		exit(1);
	}
	return number;
}
