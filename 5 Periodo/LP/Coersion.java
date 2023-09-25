class ThreeDPoint { int x; int y; int z; }

class DateType { int day; int month; int year; }

public class Coersion {
	public static void main(String args[]) {
		ThreeDPoint p = new ThreeDPoint();
		p.x = 7; p.y = 7; p.z = 1822;
		Object o = p;
		DateType d = (DateType)o;
		System.out.println(d.day + ", " + d.month + ", " + d.year);
	}
}