//
//  Player.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "DynamicSprite.hpp"

class Player : public DynamicSprite{
    
public:
    void makeMove(int direction);
    void shoot(); // or drop();
    
    Player(SDL_Renderer* ren, int life, int xpos, int ypos);
    ~Player();
};

#endif /* Player_hpp */
