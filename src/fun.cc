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

/*
 * Iterations to color.
 */
sf::Color iterToColor(int iter) {
    const double S{1};
    const double L{0.5};
    double H = double(iter)/double(maxIter)*12;

    double C = (1 - std::abs(2*L - 1))*S;
    double X = C*(1 - std::abs(std::fmod(H, 2) - 1));
    double m = L - C/2;

    C *= 255;
    X *= 255;
    m *= 255;

    if (H < 1) {
        return(sf::Color(C + m, X + m, m));
    } else if (H < 2) {
        return(sf::Color(X + m, C + m, m));
    } else if (H < 3) {
        return(sf::Color(m, C + m, X + m));
    } else if (H < 4) {
        return(sf::Color(m, X + m, C + m));
    } else if (H < 5) {
        return(sf::Color(X + m, m, C + m));
    } else { //if (H < 6) {
        return(sf::Color(C + m, m, X + m));
    }
}

sf::Color fun(double cx, double cy)
{
  int iter = iterations(cx, cy);
  return iterToColor(iter);
}
#endif
