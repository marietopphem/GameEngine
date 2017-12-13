//
//  Sprite.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-01.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <iostream>


using namespace std;

class Sprite{
public:
    ~Sprite();
    void checkLife();
    
protected:
    Sprite();
    
    
private:
    string name;
    int life;
    
    
};

#endif /* Sprite_hpp */

