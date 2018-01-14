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
#include "Sprite.hpp"
#include <vector>
#include <map>
#include <functional>
#include <SDL2_ttf/SDL_ttf.h>


using namespace std;

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
    }
    void add(Sprite* sprite);
    void addWalls(Game *game);
    
    void remove(); // ta bort sprite
    void tick(); // vad har en sprite gjort under den senaste loopen? Ska kanske ligga i Sprite-klassen
    bool collision(Sprite* a, Sprite* b);
    void addCommand(SDL_Keycode key, function<void()> func);
    
    SDL_Renderer *getRenderer();
    
    void pointCounter();
    
    void lableGameOver(string text);
    
private:
    vector<Sprite*> removeSprite;
    int count = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    vector<Sprite*> spriteList;
    
    bool gameOver = false;
    std::map<SDL_Keycode, std::function<void()>> commands;

    SDL_Texture* gameOverTexture;
    SDL_Texture* pointTexture;
    SDL_Rect rectPoint;
    
   
    
    
};


#endif /* Game_hpp */
