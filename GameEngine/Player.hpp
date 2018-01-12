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
#include <string>
#include <SDL2/SDL.h>

class Player : public DynamicSprite{
    
public:
    
    void shoot(); // or drop(); ???
    
    Player(int life, int xpos, int ypos, vector<SDL_Texture*> images, Game *game);
    ~Player();
    
    void makeMove(int direction);
    void handleCollision() override;
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;

    void setPoints() override{
        points +=10;
        std::cout << "Poängen har ökat till " << points << std::endl;
    }
    
    int getPoints() override{
        return points;
    }
    
    std::string getType() override;
    
private:
    int direction;
    int points = 0;
    int tick = 0;
    
};

#endif /* Player_hpp */
