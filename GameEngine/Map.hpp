//
//  Map.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-08.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include "Tile.hpp"
#include <vector>

using namespace std;
class Map{
public:
    Map(vector <vector <Tile> > matrix);
    ~Map();
    
    
private:
    
    int widht;
    int height;
    vector <vector <Tile> > matrix;

    
    
};

#endif /* Map_hpp */
