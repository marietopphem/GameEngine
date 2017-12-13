//
//  Game.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-11-30.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <iostream>

class Game{
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void run();
    void handleEvent();
    void update();
    void render();
    void clean();
    
    bool running(){
        return isRunning;
    };
    
    void add(); // lägg till ny sprite
    void remove(); // ta bort sprite
    void tick(); // vad har en sprite gjort under den senaste loopen? Ska kanske ligga i Sprite-klassen
    
private:
    int count = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    
};


#endif /* Game_hpp */
