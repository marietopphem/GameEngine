//
//  Player.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

class Player{
    
public:
    void makeMove(int direction);
    void shoot();
    
    Player();
    ~Player();
};

#endif /* Player_hpp */
