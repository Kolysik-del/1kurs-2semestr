#include "CRTriangle.h"
#define _USE_MATH_DEFINES
#include <math.h>

void RTriangle::checkTriangle(const double leg1, const double leg2)
{
	if (leg1 <= 0 || leg2 <= 0)
	{
		cerr << "Заданы неправильные значения!" << endl;
		exit(1);
	}
}

RTriangle::RTriangle()
{
	leg1 = 3;
	leg2 = 4;
}

RTriangle::RTriangle(const double leg1, const double leg2)
{
	this->leg1 = leg1;
	this->leg2 = leg2;
	checkTriangle(leg1, leg2);
}

double RTriangle::RadiusCircle() const
{
	return sqrt(pow(leg1, 2) + pow(leg2, 2)) / 2.0;
}

double RTriangle::AreaCircle() const
{
	return pow(RadiusCircle(), 2) * M_PI;
}
