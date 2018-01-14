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
#include <SDL2_ttf/SDL_ttf.h>

using namespace std;

Game::Game(){
    
}

Game::~Game(){
    
}

void Game::add(Sprite* sprite){
    
    spriteList.push_back(sprite);
}

void Game::addWalls(Game *game){
    
    for(int i = 5; i <= 630; i+=40){
        add(new VerticalWall(0,i,game));
        add(new VerticalWall(805,i,game));
    }
    for(int i = 0; i <= 800; i+=15){
        add(new HorizontalWall(i,0,game));
        add(new HorizontalWall(i,645, game));
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
        
        
        if(gameOver){
            string text= "GameOver";
            lableGameOver(text);
            
            SDL_Delay(3000);
            
            isRunning=false;
        }
        
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
        

        if(TTF_Init()==0){
            cout <<"TTF_init"<< endl;
        }
        
        isRunning = true;
        
    }else{
        isRunning = false;
    }
    
    

}
void Game::addCommand(SDL_Keycode key, function<void()>func){
    commands.emplace(SDLK_x, func);

    
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
            switch(event.key.keysym.sym ){
                case SDLK_UP:
                    direction = 2;
                    player -> makeMove(direction);
                    break;
                    
                case SDLK_DOWN:
                    direction = 4;
                    player ->makeMove(direction);
                    break;
                    
                case SDLK_LEFT:
                    direction = 1;
                    player -> makeMove(direction);
                    break;
                    
                case SDLK_RIGHT:
                    direction = 3;
                    player ->makeMove(direction);
                    break;
                    
                case SDLK_SPACE:
                    break;
                    
                case SDLK_p:
                    break;
                    
                default:
                    if(commands[event.key.keysym.sym]){
                        commands[event.key.keysym.sym]();
                    }
                    break;
            }
            break;
            
        case SDL_MOUSEBUTTONDOWN:
            break;
            
        case SDL_MOUSEBUTTONUP:
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
                
                    if(sprite1 =="PointPill"){
                        removeSprite.push_back(spriteList.at(i));
                        spriteList.at(j) -> setPoints();
                        
                    }else{
                        removeSprite.push_back(spriteList.at(j));
                        spriteList.at(j) -> setPoints();
                    }
                    pointCounter();
                    
                }else if((sprite1 == "Enemy" && sprite2 == "Player") || (sprite1 == "Player" && sprite2 == "Enemy")){
                    
                    Sprite* spriteVec1 = spriteList.at(i);
                    spriteVec1 -> handleCollision();
                    
                    gameOver = true;
                    
                }else if((sprite1 == "Enemy" && sprite2 == "PointPill") || (sprite1 == "PointPill" && sprite2 == "Enemy")){
                    
                    
                }else if((sprite1 == "PointPill" && sprite2 == "VerticalWall")||(sprite1 == "VerticalWall" && sprite2 == "PointPill")||(sprite1 == "PointPill" && sprite2 == "HorizontalWall")||(sprite1 == "HorizontalWall" && sprite2 == "PointPill")){
                    
                    if(sprite1 == "PointPill"){
                        removeSprite.push_back(spriteList.at(i));
                    }else{
                        removeSprite.push_back(spriteList.at(j));
                    }
                    
                }else if((sprite1 == "Enemy" && sprite2 == "VerticalWall")||(sprite1 == "VerticalWall" && sprite2 == "Enemy")||(sprite1 == "Enemy" && sprite2 == "HorizontalWall")||(sprite1 == "HorizontalWall" && sprite2 == "Enemy")){
                    
                    if(sprite1 == "Enemy"){
                        Sprite* spriteVec1 = spriteList.at(i);
                        spriteVec1 -> handleCollision();
                        spriteVec1 -> resetCount();
                        
                    }else{
                        Sprite* spriteVec2 = spriteList.at(j);
                        spriteVec2 -> handleCollision();
                        spriteVec2 -> resetCount();
                    }
                    
                    
                }else{
                    Sprite* spriteVec1 = spriteList.at(i);
                    spriteVec1 -> handleCollision();
                
                    Sprite* spriteVec2 = spriteList.at(j);
                    spriteVec2 -> handleCollision();
                }
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
    
    SDL_RenderCopy(renderer, pointTexture, NULL, &rectPoint);
    
    
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

void Game::lableGameOver(string text){
    
    TTF_Font* font = TTF_OpenFont ("/Library/Fonts/Impact.ttf", 100);
    SDL_Color color={255,0,0};
    SDL_Surface* gameOverSurf = TTF_RenderText_Solid(font, text.c_str(), color);
    gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverSurf);
    SDL_Rect rectOver= {200,200,gameOverSurf -> w, gameOverSurf ->h };
    
    SDL_FreeSurface(gameOverSurf);
    
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, gameOverTexture, NULL, &rectOver);
    SDL_RenderPresent(renderer);
    
}

void Game::pointCounter(){
    
    Player* player =(Player*)spriteList.back();
    string text =  to_string(player -> getPoints());
    
    TTF_Font* font = TTF_OpenFont ("/Library/Fonts/Impact.ttf", 20);
    SDL_Color color={255,0,0};
    SDL_Surface* pointSurf = TTF_RenderText_Solid(font, text.c_str(), color);
    pointTexture = SDL_CreateTextureFromSurface(renderer, pointSurf);
    rectPoint= {20,650,pointSurf -> w, pointSurf ->h };
    
    SDL_FreeSurface(pointSurf);
    
}


