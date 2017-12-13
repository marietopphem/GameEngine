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

int Enemy::randomization(){
    int x, y;
    x = 4;
    y = 1;
    
    int randomizieded = (rand() % static_cast<int>(x - y + 1));
    
    cout << randomizieded << endl;
    return randomizieded;
    
}

void Enemy::move(){
    
    int direction = randomization();
    
    if (direction == 1){
        // goLeft();
        
    } else if (direction == 2){
        // goUp();
        
    } else if (direction == 3){
        // goRight();
        
    } else {
        // goDown();
    }
    
}
