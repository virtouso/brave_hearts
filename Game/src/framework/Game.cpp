//
// Created by Toranj on 6/24/2026.
//

#include "Game.h"
bool Game::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        "Brave Hearts",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    running = true;
    return true;
}

void Game::Run()
{
    constexpr float TargetFPS = 60.0f;
    constexpr float TargetFrameTime = 1.0f / TargetFPS;

    Uint64 previousCounter = SDL_GetPerformanceCounter();

    while (running)
    {
        Uint64 currentCounter = SDL_GetPerformanceCounter();

        float deltaTime =
            static_cast<float>(currentCounter - previousCounter) /
            static_cast<float>(SDL_GetPerformanceFrequency());

        previousCounter = currentCounter;

        ProcessInput();
        Update(deltaTime);
        Render();

        Uint64 frameEnd = SDL_GetPerformanceCounter();

        float frameTime =
            static_cast<float>(frameEnd - currentCounter) /
            static_cast<float>(SDL_GetPerformanceFrequency());

        if (frameTime < TargetFrameTime)
        {
            Uint32 delayMs =
                static_cast<Uint32>((TargetFrameTime - frameTime) * 1000.0f);

            SDL_Delay(delayMs);
        }
    }
}

void Game::ProcessInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

void Game::Update(float deltaTime)
{
    // Game logic here
   // std::cout << "ddddd" << std::endl;
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    
    // Present to screen
    SDL_RenderPresent(renderer);
}

void Game::Shutdown()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
}
