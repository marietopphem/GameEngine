//
//  HorizontalWall.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-23.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "HorizontalWall.hpp"
#include "StaticSprite.hpp"
#include "Game.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <SDL2_image/SDL_image.h>

HorizontalWall::HorizontalWall(int xpos, int ypos, Game *game) : StaticSprite( xpos, ypos){
    
    SDL_Surface *box = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/PacmanHorizontalWall.png");
    rect = {xpos, ypos, box -> w, box->h};
    SDL_Texture *boxTx = SDL_CreateTextureFromSurface(game -> getRenderer(), box);
    SDL_FreeSurface(box);
    
    texture = boxTx;
}

void HorizontalWall::drawSprite(SDL_Renderer *renderer) const{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void HorizontalWall::updateSprite(){
    
}

void HorizontalWall::handleCollision() {
    
}

std::string HorizontalWall::getType(){return "HorizontalWall";}
