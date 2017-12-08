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
    
protected:
    Sprite();
    ~Sprite();
    void goForward();
    void goBackward();
    void jump();
    void crawl();
    
private:
    int life;
    string name;
    
    
};

#endif /* Sprite_hpp */

