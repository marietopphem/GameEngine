//
//  Sprite.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-01.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "Sprite.hpp"
#include "Game.hpp"

using namespace std;

Sprite::Sprite( int life, int xpos, int ypos) {
    
    
    
}

Sprite::~Sprite(){
    
}

int Sprite::getLife(){
    return life;
}

void Sprite::checkLife(){
    
    if(life == 0){
        // if (enemy){disapear} else{Game Over} Använd funktionen remove() som finns i klassen Game
    } else{
        //Contiune Game
    }
}
