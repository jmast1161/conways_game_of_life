#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#define rowSize     25
#define colSize     25
#define horOffset   128
#define vertOffset  9

class board
{
    private:
        cell* cellArr[rowSize][colSize];
        enum {setCells, run} boardState;
        int once, count;
        int aliveCheckArr[rowSize][colSize];
        Clock clock;
    public:
        board(void);
        void showBoard(RenderWindow& Window);
        void updateBoardPieces(RenderWindow& Window);
        void beginLife(void);
        ~board(void);
};

#endif
