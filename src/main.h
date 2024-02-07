#ifndef MAINH
#define MAINH

#include <SFML/Graphics.hpp>
#include <string>

extern sf::Vector2i size;
extern double scale;
extern double xPos;
extern double yPos;

class Main
{
public:
    Main();
    Main(const Main&) = delete;
    Main& operator=(const Main&) = delete;

    void run();

private:
    void update();
    void draw();
    //void play_music();
    void load_window_settings();
    uint width;
    uint height;
    sf::RenderWindow window;
    //sf::Mouse mouse;
    sf::Keyboard keyboard;
    sf::Clock fps_clock;
    double fps;
    sf::Time target;
    sf::Event event;
    //sf::Music menu_music;
};
#endif


