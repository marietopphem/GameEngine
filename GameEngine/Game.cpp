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
#include "Enemy.hpp"
#include "VerticalWall.hpp"
#include "HorizontalWall.hpp"

using namespace std;

Game::Game(){
    
}

Game::~Game(){
    
}



void Game::add(Sprite* sprite){
    
    spriteList.push_back(sprite);
    
    
}

void Game::addWalls(Game *game){
    
    for(int i = 0; i <= 640; i+=20){
        add(new VerticalWall(0,i,game));
        add(new VerticalWall(795,i,game));
    }
    for(int i = 5; i <= 795; i+=20){
        add(new HorizontalWall(i,0,game));
        add(new HorizontalWall(i,635, game));
    }
}



void Game::run(){
    
    const int FPS = 60;
    
    const int frameDelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;
    
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
        
        frameStart = SDL_GetTicks();
        
        handleEvent();
        update();
        render();
        
        
        frameTime = SDL_GetTicks()-frameStart;
        
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
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
       
        if(renderer){
            cout << "Renderer created" << endl;
        }
        
        isRunning = true;
        
        
    }else{
        isRunning = false;
    }
    
}



void Game::handleEvent(){
    
    Player *player = (Player*)spriteList.back();
    
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
                
                break;
        }
            
            break;
            
            
        case SDL_MOUSEBUTTONDOWN:
            cout << "mouseclicked down" << endl;
            //shoot
            break;
            
        case SDL_MOUSEBUTTONUP:
            cout << "mouseclicked up" << endl;
            
            break;
            
        default:
            break;
    }
    
}

void Game::update(){
    
   Enemy *enemy = (Enemy*)spriteList.front();;
    count++;
    if(count % 10 == 0){
        enemy -> move();
    }
    for(auto& sprite: spriteList){
        sprite -> updateSprite();
    }
}



void Game::render(){
    
    SDL_RenderClear(renderer);
    // Skriv vad som ska ritas ut
    
    for(auto const& sprite: spriteList){
        sprite -> drawSprite(renderer);
    }
    
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned!" << endl;
}

SDL_Renderer* Game::getRenderer(){
    return renderer;
    
}




