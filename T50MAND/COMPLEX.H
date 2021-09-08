#include <glut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>


typedef struct
{
	double Re, Im;

}CMPL;







  CMPL cmpl(double a, double b)
  { 
	  CMPL c;
	  c.Re = a;
	  c.Im = b;
	  return c;
  }
  
  CMPL Sum(cmpl a, cmpl b)
  {
	  return cmpl(a.Re + b.Re, a.Im + b.Im);
  }
  double Sqrt (cmpl a)
  {
    return sqrt(a.x * a.x + a.y * a.y);
  }        
  complex Mul (cmpl a, cmpl b)
  {
    return complex(a.x * b.x - a.y * b.y, a.x * b.y + b.x *a.y);// x = Re y = Im
  }
  int Iter(void)
  {
    int n = 0;
    complex z(x, y);
    complex z0 = z;
    while(!z < 2 && n < 255)
    {
      z = z * z + z0;
      n++;
    }
    return n;
  }
  int Iter1(double SuncTime)
  {
    int n = 0;
    complex z(x, y);
    complex z0 = z;
    while(!z < 2 && n < 255)
    {
      z = z * z + complex(0.36 + sin(SuncTime) * 0.01, 0.35 + sin(SuncTime) * 0.02)/*complex(0.37, 0.34)*/;
      n++;
    }
    return n;
  }
