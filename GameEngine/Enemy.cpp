//
//  Enemy.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "Enemy.hpp"
#include <cstdlib>
#include <iostream>
#include "DynamicSprite.hpp"
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include "Player.hpp"


using namespace std;


Enemy::Enemy( int life, int xpos, int ypos, vector<SDL_Texture*> images, Game *game) : DynamicSprite(life, xpos, ypos, images){
    
    SDL_Surface* enemy = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/PacmanGhostGreenBlue.png");
    rect = {xpos,ypos,enemy -> w/20, enemy ->h/20 };
    Uint32 white = SDL_MapRGB(enemy->format, 255, 255, 255);
    SDL_SetColorKey(enemy, true, white);
    SDL_Texture* enemyTx = SDL_CreateTextureFromSurface(game -> getRenderer(), enemy);
    SDL_FreeSurface(enemy);
    
    texture = enemyTx;

}

int Enemy::randomization(){
    
    int randomizieded = (rand() % 4);
    return randomizieded;
    
}

void Enemy::move(){
    
    if(count % 35 == 0){
      direction = randomization();
    }
    
    if (direction == 0){
        goLeft(xpos);
    } else if (direction == 1){
         goUp(ypos);
    } else if (direction == 2){
         goRight(xpos);
    } else {
         goDown(ypos);
    }
}

void Enemy::drawSprite(SDL_Renderer *renderer) const{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Enemy::updateSprite(){
    
    count++;
    if(count % 2 == 0){
        move();
    }
}

void Enemy::handleCollision() {
    if (direction == 0){
        goRight(xpos);
    } else if (direction == 1){
        goDown(ypos);
    } else if (direction == 2){
        goLeft(xpos);
    } else {
        goUp(ypos);
    }
}

std::string Enemy::getType(){return "Enemy";}
