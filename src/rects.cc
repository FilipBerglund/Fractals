#ifndef RECTSCC
#define RECTSCC

#include <bits/stdc++.h>
#include <complex>
#include <algorithm>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "fun.h"

void createItMap(double xPos, double yPos, double scale, double sizex, double sizey,
    std::map<std::pair<double, double>, int> &itMap) {
    for (double x = 0; x < sizex; x++)
    {
        for (double y = 0; y < sizey; y++)
        {
            double xd{x};
            double yd{y};
            xd = 4 * xd / sizex - 2;
            yd = 4 * yd / sizey - 2;
            xd = xd/scale + xPos;
            yd = yd/scale + yPos;
            int iter = iterations(xd, yd);
            itMap[ { x, y } ] = iter;
        }
    }
}


void colorGraph(sf::Image &graph, double xPos, double yPos, double scale, double sizex, double sizey) {
    for (double x = 0; x < sizex; x++)
    {
        for (double y = 0; y < sizey; y++)
        {
            double xd{x};
            double yd{y};
            xd = 4 * xd / sizex - 2;
            yd = 4 * yd / sizey - 2;
            xd = xd/scale + xPos;
            yd = yd/scale + yPos;
            graph.setPixel(x, y, fun(xd, yd));
        }
    }
}


#endif


  //std::vector<unsigned int> X(size.x);
  //std::iota(X.begin(), X.end(), 0);
  //std::vector<unsigned int> Y(size.y);
  //std::iota(Y.begin(), Y.end(), 0);

  //std::for_each(
  //    //std::execution::par_unseq,
  //    std::execution::par,
  //    X.begin(),
  //    X.end(),
  //    [this, size, Y, &graph](unsigned int x)
  //    {
  //    std::for_each(
  //        //std::execution::par_unseq,
  //        std::execution::par,
  //        Y.begin(),
  //        Y.end(),
  //        [this, x, size, &graph](unsigned int y)
  //        {
  //        double xd{x};
  //        double yd{y};
  //        xd = 4 * xd / size.x - 2;
  //        yd = 4 * yd / size.y - 2;

  //        xd = xd/scale + xPos;
  //        yd = yd/scale + yPos;

  //        //std::complex<double> c(xd,yd);
  //        //graph.setPixel(x, y, fun(c));
  //        graph.setPixel(x, y, fun(xd, yd));

  //        });
  //    });



  //for (double x = 0; x < size.x; x++)
  //{
  //    for (double y = 0; y < size.y; y++)
  //    {
  //        double xd{x};
  //        double yd{y};
  //        xd = 4 * xd / size.x - 2;
  //        yd = 4 * yd / size.y - 2;

  //        xd = xd/scale + xPos;
  //        yd = yd/scale + yPos;

  //        std::complex<double> c(xd,yd);
  //        graph.setPixel(x, y, fun(c));
  //    }
  //}

