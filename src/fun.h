#ifndef FUN
#define FUN

#include <complex>
#include <SFML/Graphics.hpp>

int maxIter{100};

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
#endif
