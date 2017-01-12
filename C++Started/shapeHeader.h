#include <math.h>
namespace shape {
	namespace shape1
	{
		const double pi = 3.14159265358;
		struct circle
		{
			double r;
		};
		struct square
		{
			double a;
		};
		struct rectangle
		{
			double a,b;
		};
		struct triangle
		{
			double a,b,c,alpha,beta,gamma;
		};

		double perimeter_of_circle(double r)
		{
			return 2*pi*r;
		}
		double area_of_circle(double r)
		{
			return pi*r*r;
		}
		double perimeter_of_square(double a)
		{
			return 4*a;
		}
		double area_of_square(double a)
		{
			return a*a;
		}
		double perimeter_of_rectangle(double a, double b)
		{
			return 2*a+2*b;
		}
		double area_of_rectangle(double a, double b)
		{
			return a*b;
		}
		double area_of_triangle(double a, double b, double gamma)
		{
			return sin(gamma/180*pi)*a*b/2;
		}
	}
}