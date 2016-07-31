#include "board.h"

board::board(void)
{
    for(int i = 0; i <rowSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            board::cellArr[j][i] = new cell(Color::White, i*30 + horOffset, j*30 +vertOffset, 30, 30);
        }
    }
    boardState = setCells;
    once = 1;
    count = 0;
    clock.restart();
};

void board::showBoard(RenderWindow& Window)
{
    for(int i = 0; i < rowSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            cellArr[i][j]->showCell(Window);
            aliveCheckArr[i][j] = 0;
        }
    }
}

void board::updateBoardPieces(RenderWindow& Window)
{
    switch(boardState)
    {
        case(setCells):
            for(int i = 0; i < rowSize; ++i)
            {
                for(int j = 0; j < colSize; ++j)
                {
                    if(cellArr[i][j]->mouseOver(Window))
                    {
                        if(Mouse::isButtonPressed(Mouse::Left))
                        {
                            if(once)
                            {
                                cellArr[i][j]->toggleAlive();
                                once = 0;
                            }
                        }
                        if(!Mouse::isButtonPressed(Mouse::Left))
                        {
                            once = 1;
                        }
                    }
                }
            }
            break;
        case(run):
            if(clock.getElapsedTime().asSeconds() > 1.0f)
            {
                for(int i = 0; i < rowSize; ++i)
                {
                    for(int j = 0; j < colSize; ++j)
                    {
                        count = 0;
                        if(i > 0 && j > 0 && i < 24 && j < 24)
                        {
                            if(cellArr[i-1][j]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i+1][j]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i][j-1]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i][j+1]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i-1][j-1]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i-1][j+1]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i+1][j-1]->getAlive())
                            {
                                ++count;
                            }
                            if(cellArr[i+1][j+1]->getAlive())
                            {
                                ++count;
                            }
                        }
                        if(cellArr[i][j]->getAlive())
                        {
                            if(count < 2 || count > 3)
                            {
                                aliveCheckArr[i][j] = 0;
                            }
                            else
                            {
                                aliveCheckArr[i][j] = 1;
                            }
                        }
                        else
                        {
                            if(count == 3)
                            {
                                aliveCheckArr[i][j] = 1;
                            }
                        }
                    }
                }

                for(int i = 0; i < rowSize; ++i)
                {
                    for(int j = 0; j < colSize; ++j)
                    {
                        if(aliveCheckArr[i][j])
                        {
                            cellArr[i][j]->live();
                        }
                        else
                        {
                            cellArr[i][j]->die();
                        }
                    }
                }
                clock.restart();
            }
            break;
    }
}

void board::beginLife()
{
    boardState = run;
}

board::~board(void)
{
    for(int i = 0; i < rowSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            delete cellArr[i][j];
        }
    }
}
