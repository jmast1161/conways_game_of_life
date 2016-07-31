#pragma once
#define windowWidth 1024
#define windowHeight 768
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "gameObject.h"
#include "cell.h"
#include "board.h"
using namespace std;
using namespace sf;

class Game
{
    public:
        static void Start(void);
};
