//
//  PointPill.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2018-01-08.
//  Copyright © 2018 Marie Topphem. All rights reserved.
//

#ifndef PointPill_hpp
#define PointPill_hpp

#include <stdio.h>
#include <string>
#include "StaticSprite.hpp"
#include "Game.hpp"

class PointPill : public StaticSprite{
public:
    PointPill(int xpos, int ypos, Game* game);
    ~PointPill();
    
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;
    void handleCollision() override;
    void setPoints() override{}
    int getPoints() override{return 0;}
    
    std::string getType() override;

private:
    

};

#endif /* PointPill_hpp */
