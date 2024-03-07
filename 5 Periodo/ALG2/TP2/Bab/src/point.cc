#include "point.hpp"
#include <cmath>

Point::Point() {

}

double Point::DistanceTo(Point other) {
	double xDiff = this->x - other.GetX();
	double yDiff = this->y - other.GetY();
	return sqrt(xDiff * xDiff + yDiff * yDiff);
}

double Point::GetX() {
	return this->x;
}

void Point::SetX(double x) {
	this->x = x;
}

double Point::GetY() {
	return this->y;
}

void Point::SetY(double y) {
	this->y = y;
}
