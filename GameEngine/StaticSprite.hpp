//
//  StaticSprite.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef StaticSprite_hpp
#define StaticSprite_hpp

#include <stdio.h>
#include "Sprite.hpp"

class StaticSprite :public Sprite {
    
public:
    
    StaticSprite(int life, int xpos, int ypos);
    ~StaticSprite();
    
    
private:
    
    
};

#endif /* StaticSprite_hpp */
