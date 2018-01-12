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
#include <string>
#include <SDL2/SDL.h>

class Enemy : public DynamicSprite{
public:
    Enemy(int life, int xpos, int ypos, vector<SDL_Texture*> images, Game *game);
    ~Enemy();
    
    int randomization();
    void move();
    void handleCollision() override;
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;
    
    void setPoints() override{}
    int getPoints() override{return 0;}
    
    std::string getType() override;
    
private:
    int count = 0;
    int countDirection = 0;
    int direction;
    
};

#endif /* Enemy_hpp */
