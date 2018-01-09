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
#include <string>



using namespace std;

void Player::makeMove(int inputDirection){
    cout << "Let's make a move" << endl;
    direction = inputDirection;
    
    if (direction == 1){
        goLeft(xpos);
    } else if (direction == 2){
        goUp(ypos);
    } else if (direction == 3){
        goRight(xpos);
    } else {
        goDown(ypos);
    }
}

void Player::shoot(){
    cout << "Let's shoot!! or Let's drop the bomb!!" << endl;
}

Player::Player(int life, int xpos, int ypos, vector<SDL_Texture*>images, Game *game): DynamicSprite( life, xpos, ypos, images){
    
    SDL_Surface* pacman = IMG_Load("/Users/marietopphem/Desktop/PacmanRight.png");
    rect = {xpos,ypos,pacman -> w, pacman ->h };
    Uint32 white = SDL_MapRGB(pacman->format, 255, 255, 255);
    SDL_SetColorKey(pacman, true, white);
    SDL_Texture* pacmanTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacman);
    SDL_FreeSurface(pacman);
    
    texture = pacmanTx;
}

void Player::drawSprite(SDL_Renderer *renderer) const{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Player::updateSprite(){
    
    tick++;
    if (direction == 1){
        if(tick<10){
            texture = images.at(1);
        }else if(tick<20){
            texture = images.at(0);
        }else{
            tick=0;
        }
    } else if (direction == 2){
        if(tick<10){
            texture = images.at(2);
        }else if(tick<20){
            texture = images.at(0);
        }else{
            tick=0;
        }
    } else if (direction == 4){
        if(tick<10){
            texture = images.at(4);
        }else if(tick<20){
            texture = images.at(0);
        }else{
            tick=0;
        }
    } else {
        if(tick<10){
            texture = images.at(3);
        }else if(tick<20){
            texture = images.at(0);
        }else{
            tick=0;
        }
    }
}

void Player::handleCollision() {
    if (direction == 1){
        goRight(xpos);
    } else if (direction == 2){
        goDown(ypos);
    } else if (direction == 3){
        goLeft(xpos);
    } else {
        goUp(ypos);
    }
}

std::string Player::getType(){
    return "Player";
}
