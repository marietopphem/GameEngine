//
//  DynamicSprite.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "DynamicSprite.hpp"



DynamicSprite::DynamicSprite(){
    
}

DynamicSprite::~DynamicSprite(){
    
}

void DynamicSprite::goLeft(int x){
    if(x == 0){
        //no move
    }else{
        // check if Tile is occupied
        x--;
    }
}


void DynamicSprite::goRight(int x){
    
    if(x /* == widht*/){
        //no move
    }else{
        // check if Tile is occupied
        x++;
    }
}

void DynamicSprite::goUp(int y){
    if(y == 0){
        //no move
    }else{
        // check if Tile is occupied
        y--;
    }
}

void DynamicSprite::goDown(int y){
    if(y /* == height*/){
        //no move
    }else{
        // check if Tile is occupied
        y++;
    }
}


