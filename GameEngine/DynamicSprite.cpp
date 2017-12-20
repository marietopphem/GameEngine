//
//  DynamicSprite.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "DynamicSprite.hpp"
#include "Tile.hpp"


Tile *tile = nullptr;

DynamicSprite::DynamicSprite( int life, int xpos, int ypos) : Sprite( life, xpos, ypos){
    
}

DynamicSprite::~DynamicSprite(){
    
}

void DynamicSprite::goLeft(int x){
    if(x == 0){
        
        //no move
    }else{
        // check if Tile is occupied
        if (isTileOccupied()) {
            // no move
        } else{
            x--;
            cout << "Went Left" << endl;
        }
    }
}


void DynamicSprite::goRight(int x){
    
    if(x /* == widht*/){
        //no move
    }else{
        if (isTileOccupied()) {
        // no move
            
        } else{
        // check if Tile is occupied
        x++;
        }
    }
}

void DynamicSprite::goUp(int y){
    if(y == 0){
        //no move
    }else{
        if (isTileOccupied()) {
            // no move
        } else{
        // check if Tile is occupied
            y--;
        }
    }
}

void DynamicSprite::goDown(int y){
    if(y /* == height*/){
        //no move
    }else{
        if (isTileOccupied()) {
            // no move
        } else{
        // check if Tile is occupied
            y++;
        }
    }
}

bool DynamicSprite::isTileOccupied(){
    
    return 0;
    
}


