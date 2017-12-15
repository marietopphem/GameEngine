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

using namespace std;

DynamicSprite *dynSpri = nullptr;

Enemy::Enemy(SDL_Renderer* ren, int life, int xpos, int ypos) : DynamicSprite(ren, life, xpos, ypos){
    
    life = 1;
}

int Enemy::randomization(){
    
    int randomizieded = (rand() % 4);
    
    cout << randomizieded << endl;
    return randomizieded;
    
}

void Enemy::move(){
    int direction = randomization();
    cout << "EmenyMove" << endl;
    int x = 19;
    if (direction == 0){
        cout << "direction left" << endl;
        dynSpri -> goLeft(x);
    } else if (direction == 1){
        // goUp();
    } else if (direction == 2){
        // goRight();
    } else {
        // goDown();
    }
}



