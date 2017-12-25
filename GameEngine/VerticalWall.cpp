//
//  Box.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-14.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "VerticalWall.hpp"
#include "StaticSprite.hpp"
#include "Game.hpp"
#include <SDL2/SDL.h>

VerticalWall::VerticalWall(int xpos, int ypos, Game *game) : StaticSprite( xpos, ypos){
    
    SDL_Surface *wall = SDL_LoadBMP("/Users/marietopphem/Desktop/PacmanWall.bmp");
    rect = {xpos, ypos, wall -> w, wall->h};
    SDL_Texture *wallTx = SDL_CreateTextureFromSurface(game -> getRenderer(), wall);
    SDL_FreeSurface(wall);
    
    texture = wallTx;
}

void VerticalWall::blastBox(){
    
}

void VerticalWall::drawSprite(SDL_Renderer *renderer) const{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
}


void VerticalWall::updateSprite(){
    
    
}
