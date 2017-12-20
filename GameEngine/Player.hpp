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
#include "Game.hpp"

class Player : public DynamicSprite{
    
public:
    void makeMove(int direction);
    void shoot(); // or drop();
    
    Player(int life, int xpos, int ypos, Game *game);
    ~Player();
    
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;

    
private:
    
    
};

#endif /* Player_hpp */
