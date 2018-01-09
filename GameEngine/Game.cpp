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
#include <string>

using namespace std;

Game::Game(){
    
}

Game::~Game(){
    
}

void Game::add(Sprite* sprite){
    
    spriteList.push_back(sprite);
}

void Game::addWalls(Game *game){
    
    for(int i = 0; i <= 640; i+=24){
        add(new VerticalWall(0,i,game));
        add(new VerticalWall(795,i,game));
    }
    for(int i = 6; i <= 794; i+=24){
        add(new HorizontalWall(i,0,game));
        add(new HorizontalWall(i,635, game));
    }
}

void Game::run(){
    
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    
    while(running()){
        
        frameStart = SDL_GetTicks();
        
        handleEvent();
        update();
        render();
        
        for(Sprite* remove: removeSprite){
            for(auto iterator = spriteList.begin();iterator!=spriteList.end();){
                if(remove == *iterator){
                    iterator = spriteList.erase(iterator);
                }else{
                    iterator++;
                }
            }
        }
        
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
    
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
            
        case SDL_KEYDOWN:
            int direction;
            cout << "Key pushed" << endl;
            switch(event.key.keysym.sym ){
                case SDLK_UP:
                    direction = 2;
                    player -> makeMove(direction);
                    cout << "upkey" << endl;
                    break;
                    
                case SDLK_DOWN:
                    direction = 4;
                    player ->makeMove(direction);
                    cout << "downkey" << endl;
                    break;
                    
                case SDLK_LEFT:
                    direction = 1;
                    player -> makeMove(direction);
                    cout << "leftkey" << endl;
                    break;
                    
                case SDLK_RIGHT:
                    direction = 3;
                    player ->makeMove(direction);
                    cout << "rightkey" << endl;
                    break;
                    
                case SDLK_SPACE:
                    cout << "Space pressed" << endl;
                    player -> shoot();
                    break;
                    
                case SDLK_p:
                    cout << "p button pressed"<< endl;
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
    
    for(auto& sprite: spriteList){
        sprite -> updateSprite();
    }
    
    for(unsigned i = 0; i < spriteList.size()-1; i++){
        for(unsigned j = i+1; j < spriteList.size(); j++){
            if (collision(spriteList.at(i), spriteList.at(j)) == true){
                
                
                string sprite1 = spriteList.at(i)->getType();
                string sprite2 = spriteList.at(j)->getType();
                
                if((sprite1 == "PointPill" || sprite2 == "PointPill") && (sprite1 == "Player" || sprite2 == "Player")){
                    
                    // pointPill disappear
                    if(sprite1 =="PointPill"){
                        removeSprite.push_back(spriteList.at(i));
                        spriteList.at(j) -> setPoints();
                    
                    }else{
                        removeSprite.push_back(spriteList.at(j));
                        spriteList.at(j) -> setPoints();
                    }
                }else if((sprite1 == "Enemy" && sprite2 == "Player") || (sprite1 == "Player" && sprite2 == "Enemy")){
                    
                    Sprite* spriteVec1 = spriteList.at(i);
                    spriteVec1 -> handleCollision();
                    
                    Sprite* spriteVec2 = spriteList.at(j);
                    spriteVec2 -> handleCollision();
                    
                    cout << "GAME OVER" << endl;
                    
                    isRunning = false;
                    
                }else{
                    Sprite* spriteVec1 = spriteList.at(i);
                    spriteVec1 -> handleCollision();
                
                    Sprite* spriteVec2 = spriteList.at(j);
                    spriteVec2 -> handleCollision();
                }
                cout << sprite1 << " har kolliderat med " << sprite2 <<endl;
            }
        }
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

bool Game::collision(Sprite* a, Sprite* b){
    
    int xposA = a -> getRect() -> x;
    int yposA = a -> getRect() -> y;
    int widthA = a -> getRect() -> w+xposA;
    int heightA = a -> getRect() -> h+yposA;
    
    int xposB = b -> getRect() -> x;
    int yposB = b -> getRect() -> y;
    int widthB = b -> getRect() -> w+xposB;
    int heightB = b -> getRect() -> h+yposB;
    
    if(heightA <= yposB){
        return false ;
    }
    if(yposA >= heightB){
        return false;
    }
    if(widthA <= xposB){
        return false;
    }
    if(xposA >= widthB){
        return false;
    }else{
        return true;
    }
}

