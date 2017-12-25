//
//  Enemy.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <iostream>
#include "DynamicSprite.hpp"
#include "Game.hpp"

class Enemy : public DynamicSprite{
public:
    Enemy( int life, int xpos, int ypos, Game *game);
    
    int randomization();
    void move();
    
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;
    
    
private:
    
};

#endif /* Enemy_hpp */
