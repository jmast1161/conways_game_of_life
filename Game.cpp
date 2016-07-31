#include "Game.h"

void Game::Start(void)
{
    VideoMode VMode(windowWidth, windowHeight, 32);
    RenderWindow Window(VMode, "Blank");
    Window.setFramerateLimit(60);
    Window.setPosition(Vector2i(300,40));

    gameObject background("Images/skyBackground.jpg", 0, 0);

    board gameBoard;

    Event event;
    while (Window.isOpen())
    {
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    Window.close();
                    break;
                case Event::KeyPressed:
                    if(event.key.code == Keyboard::Escape)
                        Window.close();
                    if(event.key.code == Keyboard::Space)
                    {
                        gameBoard.beginLife();
                    }
                    break;
                default:
                    break;
            }
        }

        gameBoard.updateBoardPieces(Window);

        background.showGameObject(Window);
        gameBoard.showBoard(Window);

        Window.display();
    }
}
