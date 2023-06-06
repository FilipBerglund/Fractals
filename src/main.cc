#ifndef MAINCC
#define MAINCC
#include <SFML/Graphics.hpp>
#include "main.h"
#include <execution>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "fun.h"
#include <complex>
#include "timer.h"
#include <vector>
//#include "tbb/blocked_range.h"
//#include "tbb/parallel_for.h"
//#include "tbb/task_scheduler_init.h"

Main::Main():
  width{},
  height{},
  window{},
  //mouse{},
  keyboard{},
  fps_clock{},
  fps{},
  target{},
  event{}
  //menu_music{}
{
  load_window_settings();
  //menu_music.openFromFile("res/menu_music.oog");
  //menu_music.play();
  //menu_music.setLoop(true);
  xPos = 0;
  yPos = 0;
  scale = 1;
}

void Main::run()
{
    draw();
    while (window.isOpen())
    {
        fps_clock.restart();
        bool invalid{false};
        while (window.pollEvent(event))
        {
          invalid = false;
          if (event.type == sf::Event::Closed)
          {
            window.close();
          }
          if (keyboard.isKeyPressed(sf::Keyboard::J))
          {
            yPos += 0.1/scale;
            invalid = true;
          }
          if (keyboard.isKeyPressed(sf::Keyboard::K))
          {
            yPos -= 0.1/scale;
            invalid = true;
          }
          if (keyboard.isKeyPressed(sf::Keyboard::L))
          {
            xPos += 0.1/scale;
            invalid = true;
          }
          if (keyboard.isKeyPressed(sf::Keyboard::H))
          {
            xPos -= 0.1/scale;
            invalid = true;
          }
          if (keyboard.isKeyPressed(sf::Keyboard::F))
          {
            scale *= 1.1;
            invalid = true;
          }
          if (keyboard.isKeyPressed(sf::Keyboard::D))
          {
            scale *= 0.9;
            invalid = true;
          }

        }
        if (invalid)
        {
          window.clear();
          draw();
          window.display();
        }
        sf::sleep (target - fps_clock.getElapsedTime());
    }
}

void Main::update()
{

}

void Main::draw()
{
  window.clear();

  sf::Vector2u size(width, height);
  sf::Image graph;
  graph.create(size.x, size.y, sf::Color(255, 255, 255));
  // y = 2x

  Timer t;
  std::vector<unsigned int> X(size.x);
  std::iota(X.begin(), X.end(), 0);
  std::vector<unsigned int> Y(size.y);
  std::iota(Y.begin(), Y.end(), 0);

  std::for_each(
      std::execution::par,
      X.begin(),
      X.end(),
      [this, size, Y, &graph](unsigned int x)
      {
      std::for_each(
          std::execution::par,
          Y.begin(),
          Y.end(),
          [this, x, size, &graph](unsigned int y)
          {
          double xd{x};
          double yd{y};
          xd = 4 * xd / size.x - 2;
          yd = 4 * yd / size.y - 2;

          xd = xd/scale + xPos;
          yd = yd/scale + yPos;

          std::complex<double> c(xd,yd);
          graph.setPixel(x, y, fun(c));

          });
      });


//  for (unsigned int x = 0; x < size.x; x++)
//  {
//    for (unsigned int y = 0; y < size.y; y++)
//    {
//      double xd{x};
//      double yd{y};
//      xd = 4 * xd / size.x - 2;
//      yd = 4 * yd / size.y - 2;
//
//      xd = xd/scale + xPos;
//      yd = yd/scale + yPos;
//
//      std::complex<double> c(xd,yd);
//      graph.setPixel(x, y, fun(c));
//    }
//  }
  std::cout << t.elapsed() << std::endl;
  //std::cout << i << std::endl;

  sf::Texture texture;
  texture.loadFromImage(graph);
  sf::Sprite sprite;
  sprite.setTexture(texture, true);
  //graph.saveToFile("img.png");

  window.draw(sprite);
  window.display();
}

void Main::load_window_settings()
{
    std::ifstream settings;
    settings.open("res/window_settings.txt");
    settings >> width;
    settings >> height;
    window.create(sf::VideoMode{width, height}, "Playing with Fire");

    settings >> fps;
    target = sf::Time{sf::milliseconds(1000 / fps)};
    settings.close();
}






#endif
