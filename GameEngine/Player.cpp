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
#include <SDL2_image/SDL_image.h>



using namespace std;

void Player::makeMove(int direction){
    cout << "Let's make a move" << endl;
    
    
    
    if (direction == 1){
        
        
        goLeft(xpos);
        cout << "Left move" << endl;
        
    } else if (direction == 2){
        
        
        goUp(ypos);
        cout << "Up move" << endl;
        
    } else if (direction == 3){
        
    
        goRight(xpos);
        cout << "Right move" << endl;
        
    } else {
        
        
        goDown(ypos);
        cout << "Down move" << endl;
    }
    
}

void Player::shoot(){
    cout << "Let's shoot!! or Let's drop the bomb!!" << endl;
    
}

Player::Player(int life, int xpos, int ypos, Game *game): DynamicSprite( life, xpos, ypos){
    
    SDL_Surface* pacman = IMG_Load("/Users/marietopphem/Desktop/pacman.jpeg");
    rect = {0,0,pacman -> w, pacman ->h };
    Uint32 white = SDL_MapRGB(pacman->format, 255, 255, 255);
    SDL_SetColorKey(pacman, true, white);
    SDL_Texture* pacmanTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacman);
    SDL_FreeSurface(pacman);
    
    texture = pacmanTx;
    
    //cout << pacman -> h << "  " << pacman -> w << endl;
    
}



void Player::drawSprite(SDL_Renderer *renderer) const{
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
    //cout << "draw Sprite"<< endl;
    
}

void Player::updateSprite(){
    
    
    
}





