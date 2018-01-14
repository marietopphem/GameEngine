//
//  HorizontalWall.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-23.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef HorizontalWall_hpp
#define HorizontalWall_hpp

#include <stdio.h>

#include <stdio.h>
#include "StaticSprite.hpp"
#include "Game.hpp"
#include <string>

class HorizontalWall : public StaticSprite{
public:
    
    HorizontalWall(int xpos, int ypos, Game *game);
    ~HorizontalWall();
    
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;
    void handleCollision() override;
    void setPoints() override{}
    int getPoints() override{return 0;}
    void resetCount()override {}
    std::string getType() override;
    
private:
    
    
};

#endif /* HorizontalWall_hpp */
