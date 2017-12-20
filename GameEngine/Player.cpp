//
//  Player.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-09.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"



using namespace std;

void Player::makeMove(int direction){
    cout << "Let's make a move" << endl;
    
    
    
    if (direction == 1){
        
        // /Users/marietopphem/Desktop/GubbeLeft.bmp
        
        // goLeft();
        cout << "Left move" << endl;
        
    } else if (direction == 2){
        
        // /Users/marietopphem/Desktop/GubbeBack.bmp
        
        // goUp();
        cout << "Up move" << endl;
        
    } else if (direction == 3){
        
        // /Users/marietopphem/Desktop/GubbeRight.bmp
        
        // goRight();
        cout << "Right move" << endl;
        
    } else {
        
        // /Users/marietopphem/Desktop/GubbeFront.bmp
        
        // goDown();
        cout << "Down move" << endl;
    }
    
}

void Player::shoot(){
    cout << "Let's shoot!! or Let's drop the bomb!!" << endl;
    
}

Player::Player(int life, int xpos, int ypos, Game *game): DynamicSprite( life, xpos, ypos){
    
    SDL_Surface* gubbe = SDL_LoadBMP("/Users/marietopphem/Desktop/gubbefront.bmp");
    
    SDL_Texture* gubbeTx = SDL_CreateTextureFromSurface(game -> getRenderer(), gubbe);
    SDL_FreeSurface(gubbe);
    
    texture = gubbeTx;
    
}



void Player::drawSprite(SDL_Renderer *renderer) const{
    
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    
    cout << "draw Sprite"<< endl;
    
}

void Player::updateSprite(){
    
}





