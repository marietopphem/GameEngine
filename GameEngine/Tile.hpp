//
//  Tile.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-08.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "Sprite.hpp"

class Tile{
public:
    Tile();
    ~Tile();

private:
    
    bool occupied;
    
    //Sprite &objectOnMap; // om något existerar på Tilen så är den True;
};




#endif /* Tile_hpp */
