//
//  Game.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-11-30.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

Game::Game(){
    
}

Game::~Game(){
    
}

void Game::run(){
    
    
    for(int countdown = 10; countdown>=0; countdown--){
        // "game starts in" count--; //count down from 10
        if(countdown == 0){
            cout << "GO" << endl;
        }
        else{
            cout << "Game starts in " << countdown << endl;
            
        }
    }
    
    
    while(running()){
        handleEvent();
        update();
        render();
    }
    
    clean();
}

void Game::init(const char *title, int xpos, int ypos,int width, int height, bool fullscreen){
    
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout << "Subsystem initilized" << endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, false);
        
        if(window){
            cout << "Window created!" << endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        isRunning = true;
    }else{
        isRunning = false;
    }
    
}

void Game::handleEvent(){
    
    Player *player = nullptr;
    
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        case SDL_KEYDOWN:
            int direction;
            cout << "Key pushed" << endl;
            switch( event.key.keysym.sym )
        {
            case SDLK_UP:
                
                direction = 2;
                player -> makeMove(direction);
                
                cout << "upkey" << endl;
                //jump
                //gCurrentSurface = gKeyPressSurfaces[ SDL_KEY_PRESS_SURFACE_UP ];
                break;
                
            case SDLK_DOWN:
                
                direction = 4;
                player ->makeMove(direction);
                
                cout << "downkey" << endl;
                //crawl
                //gCurrentSurface = gKeyPressSurfaces[ SDL_KEY_PRESS_SURFACE_DOWN ];
                break;
                
            case SDLK_LEFT:
                
                direction = 1;
                player -> makeMove(direction);
                
                cout << "leftkey" << endl;
                //goLeft
                //gCurrentSurface = gKeyPressSurfaces[ SDL_KEY_PRESS_SURFACE_LEFT ];
                break;
                
            case SDLK_RIGHT:
                
                direction = 3;
                player ->makeMove(direction);
                
                cout << "rightkey" << endl;
                //goRight
                //gCurrentSurface = gKeyPressSurfaces[ SDL_KEY_PRESS_SURFACE_RIGHT ];
                break;
              
            case SDLK_SPACE:
                cout << "Space pressed" << endl;
                player -> shoot();
                
                break;
                
            case SDLK_p:
                cout << "p button pressed"<< endl;
                
                //paus game
                break;
                
            default:
                //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                break;
        }
            
            break;
            
            
        case SDL_MOUSEBUTTONDOWN:
            cout << "mouseclicked down" << endl;
            //shoot
            break;
            
        case SDL_MOUSEBUTTONUP:
            cout << "mouseclicked up" << endl;
            //choose, start game
            break;
            
        default:
            break;
    }
    
}

void Game::update(){
    count++;
    //cout << count << endl;
}

void Game::render(){
    
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned!" << endl;
}




