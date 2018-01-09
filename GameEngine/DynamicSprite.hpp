//
//  DynamicSprite.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef DynamicSprite_hpp
#define DynamicSprite_hpp

#include <iostream>
#include "Sprite.hpp"
#include "Game.hpp"
#include <SDL2/SDL.h>


class DynamicSprite : public Sprite{
    
public:
    DynamicSprite( int life, int xpos, int ypos, vector<SDL_Texture*> images);
    ~DynamicSprite();
    void goRight(int x);
    void goLeft(int x);
    void goDown(int y);
    void goUp(int y);
    
    int getLife();
    void checkLife();
    
private:
    int life;
protected:
    vector<SDL_Texture*> images;
    
};

#endif /* DynamicSprite_hpp */
