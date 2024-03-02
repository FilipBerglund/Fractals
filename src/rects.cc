#ifndef RECTSCC
#define RECTSCC

#include <bits/stdc++.h>
#include <complex>
#include <algorithm>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "fun.h"
#include "main.h"

double screenToGraphX(double x) {
    x = 4 * x / size.x - 2;
    return x/scale + xPos;
}
double screenToGraphY(double y) {
    y = 4 * y / size.y - 2;
    return y/scale + yPos;
}
double screenToGraphX(int x) {
    return screenToGraphX(double(x));
}
double screenToGraphY(int y) {
    return screenToGraphY(double(y));
}

int mp[1001][1001]{0};
int mapp(double x, double y) {
    return mapp(int(x), int(y));
}
int mapp(int x, int y) {
    int i{-1};
    i = mp[x][y];
    if (i == 0) {
        i = iterations(screenToGraphX(x), screenToGraphY(y));
        mp[x][y] = i;
    }
    return i;
}


void rect(sf::Image &graph, sf::Vector2i p0, sf::Vector2i p1) {
    bool black{true};
    for (int x = p0.x; x < p1.x; x++) {
        int f = mapp(x, p1.y);
        int s = mapp(x, p0.y);
        if (s != 0 or f != 0) {
            black = false;
            graph.setPixel(x, p1.y, iterToColor(f));
            graph.setPixel(x, p0.y, iterToColor(s));
        }
    }
    for (int y = p0.y; y < p1.y; y++) {
        int f = mapp(p0.x, y);
        int s = mapp(p1.x, y);
        if (s != 0 or f != 0) {
            black = false;
            graph.setPixel(p0.x, y, iterToColor(f));
            graph.setPixel(p1.x, y, iterToColor(s));
        }
    }
    if (!black) {
        sf::Vector2i p00{p0};
        sf::Vector2i p01{p1};
        sf::Vector2i p10{p0};
        sf::Vector2i p11{p1};
        int dx = p1.x - p0.x;
        int dy = p1.y - p0.y;
        if (dx < 2 and dy < 2) return;
        if (dx > dy) {
            p00.x += floor(dx/2);
            p11.x = p00.x;
        } else {
            p00.y += floor(dy/2);
            p11.y = p00.y;
        }
        rect(graph, p00, p01);
        rect(graph, p10, p11);
    }

}


void colorGraph(sf::Image &graph) {
    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            mp[x][y] = 0;
        }
    }
    sf::Vector2i sizeShort{size.x-1, size.y-1};
    rect(graph, sf::Vector2i(0, 0), sizeShort);
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
