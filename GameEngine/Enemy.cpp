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

using namespace std;


Enemy::Enemy( int life, int xpos, int ypos, vector<SDL_Texture*> images, Game *game) : DynamicSprite(life, xpos, ypos, images){
    
    SDL_Surface* enemy = IMG_Load("/Users/marietopphem/Desktop/PacmanGhostGreenBlue.png");
    rect = {xpos,ypos,enemy -> w/10, enemy ->h/10 };
    Uint32 white = SDL_MapRGB(enemy->format, 255, 255, 255);
    SDL_SetColorKey(enemy, true, white);
    SDL_Texture* enemyTx = SDL_CreateTextureFromSurface(game -> getRenderer(), enemy);
    SDL_FreeSurface(enemy);
    
    texture = enemyTx;
}

int Enemy::randomization(){
    
    int randomizieded = (rand() % 4);
    
    cout << randomizieded << endl;
    return randomizieded;
}

void Enemy::move(){
    direction = randomization();
    cout << "EmenyMove" << endl;
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
    if(count % 10 == 0){
        move();
    }
}

void Enemy::handleCollision() {
    if (direction == 1){
        goRight(xpos);
    } else if (direction == 2){
        goDown(ypos);
    } else if (direction == 3){
        goLeft(xpos);
    } else {
        goUp(ypos);
    }
}

std::string Enemy::getType(){return "Enemy";}
