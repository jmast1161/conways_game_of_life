#include "cell.h"

cell::cell(Color cellColor, int x, int y, int w, int h)
{
    alive = 0;
    position = Vector2f(x, y);
    size = Vector2f(w, h);
    rect.setPosition(position);
    rect.setSize(size);
    rect.setFillColor(cellColor);
    rect.setOutlineColor(Color::Black);
    rect.setOutlineThickness(2.0f);
}

void cell::showCell(RenderWindow& Window)
{
    Window.draw(rect);
}

int cell::mouseOver(RenderWindow& Window)
{
    Vector2i mousePos = Mouse::getPosition(Window);
    Vector2f cellPos = rect.getPosition();
    
    if(mousePos.x > cellPos.x &&
       mousePos.y > cellPos.y &&
       mousePos.x - rect.getSize().x < cellPos.x &&
       mousePos.y - rect.getSize().y < cellPos.y)
    {
        if(alive)
        {
            rect.setFillColor(Color::White);
        }
        else
        {
            rect.setFillColor(Color::Black);
        }
        return 1;
    }
    else
    {
        if(alive)
        {
            rect.setFillColor(Color::Black);
        }
        else
        {
            rect.setFillColor(Color::White);
        }
    }
    return 0;
}

void cell::toggleAlive(void)
{
    if(alive)
    {
        alive = 0;
        rect.setFillColor(Color::White);
    }
    else
    {
        alive = 1;
        rect.setFillColor(Color::Black);
    }
}

int cell::getAlive(void)
{
    return alive;
}

void cell::live(void)
{
    alive = 1;
    rect.setFillColor(Color::Black);
}

void cell::die(void)
{
    alive = 0;
    rect.setFillColor(Color::White);
}
