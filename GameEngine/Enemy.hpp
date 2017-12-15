//
//  Enemy.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "DynamicSprite.hpp"

class Enemy : public DynamicSprite{
public:
    Enemy(SDL_Renderer* ren, int life, int xpos, int ypos);
    
    int randomization();
    void move();
    
    
    
};

#endif /* Enemy_hpp */
