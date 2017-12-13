//
//  Map.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-08.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "Map.hpp"


Map::Map(vector <vector <Tile> > matrix){
    
    for ( int i = 0 ; i < widht ; i++ )
        matrix[i].resize(height);
}
