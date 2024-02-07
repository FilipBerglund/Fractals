#ifndef FUNH
#define FUNH

#include <complex>
#include <SFML/Graphics.hpp>

extern int maxIter;
int iterations(std::complex<double> c);

sf::Color fun(std::complex<double> c);

int iterations(double cx, double cy);

sf::Color fun(double cx, double cy);

sf::Color iterToColor(int iter);
#endif
