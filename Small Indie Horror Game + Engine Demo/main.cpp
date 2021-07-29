// Small Indie Horror Game + Engine Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "source/Game/Game.h"

#ifdef DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#endif // DEBUG

int main()
{
#ifdef DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // DEBUG

    std::cout << "Hello World!\n";
    
    Game game;
    game.Initialize();
    double deltaTime = 0.f;
    while (!game.window_should_close())
    {
        double start_clock = glfwGetTime();
        
        game.Update(deltaTime);
        game.Render();

        double finish_clock = glfwGetTime();
        deltaTime = finish_clock - start_clock;
    }

    return 0;
}
