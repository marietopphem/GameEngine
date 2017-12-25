//
//  VerticalWall.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-14.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef VerticalWall_hpp
#define VerticalWall_hpp

#include <stdio.h>
#include "StaticSprite.hpp"
#include "Game.hpp"

class VerticalWall : public StaticSprite{
public:
    
    VerticalWall(int xpos, int ypos, Game *game);
    ~VerticalWall();
    void blastBox();
    
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;
    
private:
    
    
};

#endif /* VerticalWall_hpp */
