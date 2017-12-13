//
//  DynamicSprite.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef DynamicSprite_hpp
#define DynamicSprite_hpp

#include <iostream>
#include "Sprite.hpp"

class DynamicSprite {//}: public Sprite{
    
public:
    DynamicSprite();
    ~DynamicSprite();
    void goRight(int x);
    void goLeft(int x);
    void goDown(int y);
    void goUp(int y);
    
    
    
    
private:
    
    
    
};

#endif /* DynamicSprite_hpp */
