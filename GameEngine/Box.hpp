//
//  Box.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-14.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
#include "StaticSprite.hpp"

class Box : public StaticSprite{
public:
    
    Box(int life, int xpos, int ypos);
    ~Box();
    void blastBox();
    
    void drawSprite(SDL_Renderer *renderer) const override;
    void updateSprite() override;
    
private:
    
    
};

#endif /* Box_hpp */
