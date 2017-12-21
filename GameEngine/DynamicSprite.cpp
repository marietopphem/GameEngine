//
//  DynamicSprite.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "DynamicSprite.hpp"

using namespace std;


DynamicSprite::DynamicSprite( int life, int xpos, int ypos) : Sprite( life, xpos, ypos){
    
}

DynamicSprite::~DynamicSprite(){
    
}

void DynamicSprite::goLeft(int x){
    if(x == 0){
        
        //no move
    }else{
        // check if Tile is occupied
        // collision , is it a wall or a enemy?
        if (isTileOccupied()) {
            // no move
        } else{
            
            cout << "Went Left" << endl;
        }
    }
    xpos--;
    rect.x = xpos;
    
}


void DynamicSprite::goRight(int x){
    
    if(x /* == widht*/){
        //no move
    }else{
        if (isTileOccupied()) {
        // no move
            
        } else{
        // check if Tile is occupied
        
        }
    }
    
    xpos++;
    rect.x = xpos;
    
    
}

void DynamicSprite::goUp(int y){
    if(y == 0){
        //no move
    }else{
        if (isTileOccupied()) {
            // no move
        } else{
        // check if Tile is occupied
        }
    }
    ypos--;
    rect.y = ypos;

}

void DynamicSprite::goDown(int y){
    if(y /* == height*/){
        //no move
    }else{
        if (isTileOccupied()) {
            // no move
        } else{
        // check if Tile is occupied
            
        }
    }
    ypos++;
    rect.y = ypos;

}

bool DynamicSprite::isTileOccupied(){
    
    return 0;
    
}


