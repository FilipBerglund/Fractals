#ifndef FUNCC
#define FUNCC

#include <complex>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fun.h"

int maxIter = 300;

/*
 * With complex numbers.
 */
int iterations(std::complex<double> c)
{
  std::complex<double> z(0,0);
  int iter{0};
  std::complex<double> zPrev;
  std::complex<double> zPrevPrev;
  while (iter < maxIter && std::abs(z) < 2)
  {
    iter++;
    if ( iter % 2 == 0) {
      zPrevPrev = zPrev;
    }
    zPrev = z;
    z = z*z+c;
    if (z == zPrev) {
      iter=maxIter;
    }
    if (z == zPrevPrev) {
      iter=maxIter;
    }
  }
  if (iter == maxIter) return(0);
  return(iter);
}

sf::Color fun(std::complex<double> c)
{
  int iter = iterations(c);
  return(sf::Color(iter*10, iter*10, 0));
}

/*
 * Without complex numbers.
 */
int iterations(double cx, double cy)
{
    double x{0};
    double y{0};
    double x2{0};
    double y2{0};
    double w{0};
    int iter{0};
    while (iter < maxIter && x2 + y2 < 4)
    {
        iter++;
        x = x2 - y2 + cx;
        y = w - x2 - y2 + cy;
        x2 = x * x;
        y2 = y * y;
        w = (x + y) * (x + y);
    }
    if (iter == maxIter) return(0);
    return(iter);
}

sf::Color iterToColor(int iter) {
    return(sf::Color(iter*10, iter*10, 0));
}

sf::Color fun(double cx, double cy)
{
  int iter = iterations(cx, cy);
  return iterToColor(iter);
}
#endif
