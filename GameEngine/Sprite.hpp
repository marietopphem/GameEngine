//
//  Sprite.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-01.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include "Tile.hpp"


using namespace std;

class Sprite{
public:
    ~Sprite();
    void checkLife();
    
protected:
    Sprite(SDL_Renderer* ren, int life, int xpos, int ypos);
    
    
private:
    
    SDL_Renderer* ren;
    int life;
    int xpos;
    int ypos;
    
    
};

#endif /* Sprite_hpp */

