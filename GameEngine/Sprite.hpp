//
//  Sprite.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-01.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <SDL2/SDL.h>
#include <iostream>



class Sprite{
public:
    ~Sprite();
    
    virtual void drawSprite(SDL_Renderer *renderer) const = 0;
    virtual void updateSprite() = 0;
    virtual void handleCollision() = 0;
    virtual void setPoints() = 0;
    
    SDL_Rect *getRect();
    int getXPos();
    int getYPos();

    virtual int getPoints() = 0;
    
    virtual std::string getType(){return type;}
    virtual void resetCount() =0;
    
protected:
    Sprite( int xpos, int ypos);
    SDL_Texture *texture;
    int xpos;
    int ypos;
    SDL_Rect rect;

private:
    std::string type;
    
};

#endif /* Sprite_hpp */

