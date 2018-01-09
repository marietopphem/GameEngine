//
//  DynamicSprite.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "DynamicSprite.hpp"
#include "Game.hpp"

using namespace std;

DynamicSprite::DynamicSprite( int life, int xpos, int ypos, vector<SDL_Texture*> images) : Sprite( xpos, ypos), images(images){
    
}

DynamicSprite::~DynamicSprite(){
    
}

void DynamicSprite::goLeft(int x){
    xpos-=5;
    rect.x = xpos;
}

void DynamicSprite::goRight(int x){
    xpos+=5;
    rect.x = xpos;
}

void DynamicSprite::goUp(int y){
    ypos-=5;
    rect.y = ypos;
}

void DynamicSprite::goDown(int y){
    ypos+=5;
    rect.y = ypos;
}

int DynamicSprite::getLife(){
    return life;
}

void DynamicSprite::checkLife(){
    if(life == 0){
        // if (enemy){disapear} else{Game Over} Använd funktionen remove() som finns i klassen Game
    } else{
        //Contiune Game
    }
}

