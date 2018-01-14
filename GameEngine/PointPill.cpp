//
//  PointPill.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2018-01-08.
//  Copyright © 2018 Marie Topphem. All rights reserved.
//

#include "PointPill.hpp"
#include "StaticSprite.hpp"
#include "Game.hpp"
#include <SDL2/SDL.h>
#include <string>

PointPill::PointPill(int xpos, int ypos, Game *game) : StaticSprite( xpos, ypos){
    
    SDL_Surface *box = SDL_LoadBMP("/Users/marietopphem/Desktop/PacmanPointPill.bmp");
    rect = {xpos, ypos, box -> w, box->h};
    SDL_Texture *boxTx = SDL_CreateTextureFromSurface(game -> getRenderer(), box);
    SDL_FreeSurface(box);
    
    texture = boxTx;
}

void PointPill::drawSprite(SDL_Renderer *renderer) const{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
}

void PointPill::updateSprite(){
    
}

void PointPill::handleCollision() {
    
}

std::string PointPill::getType(){return "PointPill";}


