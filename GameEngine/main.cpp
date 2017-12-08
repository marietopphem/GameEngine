//
//  main.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-11-10.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>


using namespace std;

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    
    game = new Game();
    
    game -> init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);
    
    
    
    
    game -> run();
    
    delete game;
    
    return 0;
}
