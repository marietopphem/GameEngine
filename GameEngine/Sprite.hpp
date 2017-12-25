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


class Sprite{
public:
    ~Sprite();
    
    virtual void drawSprite(SDL_Renderer *renderer) const = 0;
    virtual void updateSprite() = 0;
    
protected:
    Sprite( int xpos, int ypos);
    SDL_Texture *texture;
    int xpos;
    int ypos;
    SDL_Rect rect;
    
    
    
private:
    
    
    
    
    
    
};

#endif /* Sprite_hpp */

