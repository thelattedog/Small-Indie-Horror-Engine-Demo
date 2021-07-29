#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Game.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Game::Game() : m_window(nullptr)
{}

Game::~Game()
{
    glfwTerminate();
}

bool Game::Initialize()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    m_window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

    return true;
}

void Game::Input()
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}

bool Game::window_should_close()
{
    return glfwWindowShouldClose(m_window);
}

void Game::Update(double dt)
{
    Input();
    std::cout << dt << std::endl;
}
void Game::Render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // render commands

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}