//
// Created by Toranj on 6/24/2026.
//

#ifndef BRAVEHEARTS_GAME_H
#define BRAVEHEARTS_GAME_H


#include <SDL.h>
#include <iostream>

class Game
{
public:
    bool Initialize();
    void Run();
    void Shutdown();

private:
    void ProcessInput();
    void Update(float deltaTime);
    void Render();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool running = false;
};

#endif //BRAVEHEARTS_GAME_H
