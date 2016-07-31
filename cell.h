#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

#ifndef CELL_H
#define CELL_H

class cell
{
    protected:
        RectangleShape rect;
        Vector2f position;
        Vector2f size;
        int alive;
    public:
        cell(Color cellColor, int x, int y, int w, int h);
        void showCell(RenderWindow& Window);
        int mouseOver(RenderWindow& Window);
        void toggleAlive(void);
        int getAlive(void);
        void live(void);
        void die(void);
};

#endif
