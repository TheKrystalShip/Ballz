#pragma once

#include "BallController.h"
#include "BallRenderer.h"
#include "Grid.h"

#include <Toaster/Camera2D.h>
#include <Toaster/GLSLProgram.h>
#include <Toaster/InputManager.h>
#include <Toaster/SpriteBatch.h>
#include <Toaster/SpriteFont.h>
#include <Toaster/Timing.h>
#include <Toaster/Window.h>

#include <memory>

// TODO:
// Visualize momentum with color
// Visualize velocity with color
// Visualize position with color

namespace Ballz
{
    enum class GameState
    {
        RUNNING,
        EXIT
    };

    const int CELL_SIZE = 12;

    class BallGame
    {
    public:
        ~BallGame();
        void run();

    private:
        void init();
        void initRenderers();
        void initBalls();
        void update(float deltaTime);
        void draw();
        void drawHud();
        void processInput();

        int m_screenWidth = 0;
        int m_screenHeight = 0;

        std::vector<Ball> m_balls;    ///< All the balls
        std::unique_ptr<Grid> m_grid; ///< Grid for spatial partitioning for collision

        int m_currentRenderer = 0;
        std::vector<std::unique_ptr<BallRenderer>> m_ballRenderers;

        BallController m_ballController; ///< Controls balls

        Toaster::Window m_window;                          ///< The main window
        Toaster::SpriteBatch m_spriteBatch;                ///< Renders all the balls
        std::unique_ptr<Toaster::SpriteFont> m_spriteFont; ///< For font rendering
        Toaster::Camera2D m_camera;                        ///< Renders the scene
        Toaster::InputManager m_inputManager;              ///< Handles input
        Toaster::GLSLProgram m_textureProgram;             ///< Shader for textures]

        Toaster::FpsLimiter m_fpsLimiter; ///< Limits and calculates fps
        float m_fps = 0.0f;

        GameState m_gameState = GameState::RUNNING; ///< The state of the game
    };

}
