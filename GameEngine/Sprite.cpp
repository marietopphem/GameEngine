//
//  Sprite.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-01.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "Sprite.hpp"
#include "Game.hpp"
#include <SDL2/SDL.h>

using namespace std;

Sprite::Sprite( int xpos, int ypos):xpos(xpos),ypos(ypos) {
    
}

Sprite::~Sprite(){
    
}

SDL_Rect* Sprite::getRect(){
    
    return &rect;
}

int Sprite::getXPos(){
    return xpos;
}

int Sprite::getYPos(){
    return ypos;
}



