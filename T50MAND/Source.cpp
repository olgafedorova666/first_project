#include "COMPLEX.H"
#include <cmath>

CMPL cmpl(double a, double b)
{
	CMPL c;
	c.Re = a;
	c.Im = b;
	return c;
}

CMPL Sum(CMPL a, CMPL b)
{
	return cmpl(a.Re + b.Re, a.Im + b.Im);
}
double Mod(CMPL a)
{
	return sqrt(a.Re * a.Re + a.Im * a.Im);
}
CMPL Mul(CMPL a, CMPL b)
{
	return cmpl(a.Re * b.Re - a.Im * b.Im, a.Re * b.Im + b.Re *a.Im);
}
int Mandelbrot(CMPL z)
{
	int n = 0;
	CMPL z;
	CMPL z0 = z;
	while (Mod(z) < 2 && n < 255)
	{
		z = Sum (Mul(z, z), z0);
		n++;
	}
	return n;
}

int Julia(CMPL z)
{
	int n = 0;
	CMPL c = cmpl(0.35, 0.38);
	while (Mod(z) < 2 && n < 255)
	{
		z = Sum(Mul(z, z), c);
		n++;
	}
	return n;
}


void frame(void)
{
	int ws = 200;
	int hs = 220;
	CMPL z;
	//unsigned char Image[hs][ws][3];
	double x0 = -2, x1 = 2, y0 = -2, y1 = 2;

	for (int ys = 0; ys < hs; ys++)
	{
		for (int xs = 0; xs < ws; xs++)
		{

			double a = ((double)xs / ws) * (x1 - x0) + x0;
			double b = ((double)ys / hs) * (y1 - y0) + y0;
			z = cmpl(a, b);
			int n = Julia(z);
			/*Image[ys][xs][0] = n;
			Image[ys][xs][1] = n * 2;
			Image[ys][xs][2] = n * 3;*/
			PutPixel(xs, ys, n * 3, n * 30, n * 8);
		}
	}
}