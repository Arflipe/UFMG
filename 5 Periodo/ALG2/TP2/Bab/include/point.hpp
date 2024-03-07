#ifndef POINT_HPP
#define POINT_HPP

class Point {
	private:
	double x;
	double y;

	public:
	Point();
	double DistanceTo(Point other);
	double GetX();
	void SetX(double x);
	
	double GetY();
	void SetY(double y);

};

#endif