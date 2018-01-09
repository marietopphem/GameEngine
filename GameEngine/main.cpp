//
//  main.cpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-11-10.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "PointPill.hpp"
#include "VerticalWall.hpp"
#include "HorizontalWall.hpp"


using namespace std;

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    
    game = new Game();
    
    game -> init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, true);
    
    vector<SDL_Texture*> enemyImages;
    vector<SDL_Texture*> playerImages;
    
    SDL_Surface* pacman = IMG_Load("/Users/marietopphem/Desktop/Pacman.png");
    Uint32 white = SDL_MapRGB(pacman->format, 255, 255, 255);
    SDL_SetColorKey(pacman, true, white);
    SDL_Texture* pacmanTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacman);
    SDL_FreeSurface(pacman);
    
    playerImages.push_back(pacmanTx);
    
    SDL_Surface* pacmanLeft = IMG_Load("/Users/marietopphem/Desktop/PacmanLeft.png");
    Uint32 whiteLeft = SDL_MapRGB(pacmanLeft->format, 255, 255, 255);
    SDL_SetColorKey(pacmanLeft, true, whiteLeft);
    SDL_Texture* pacmanLeftTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanLeft);
    SDL_FreeSurface(pacmanLeft);
    
    playerImages.push_back(pacmanLeftTx);
    
    SDL_Surface* pacmanUp = IMG_Load("/Users/marietopphem/Desktop/PacmanUp.png");
    Uint32 whiteUp = SDL_MapRGB(pacmanUp->format, 255, 255, 255);
    SDL_SetColorKey(pacmanUp, true, whiteUp);
    SDL_Texture* pacmanUpTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanUp);
    SDL_FreeSurface(pacmanUp);
    
    playerImages.push_back(pacmanUpTx);
    
    SDL_Surface* pacmanRight = IMG_Load("/Users/marietopphem/Desktop/PacmanRight.png");
    Uint32 whiteRight = SDL_MapRGB(pacmanRight->format, 255, 255, 255);
    SDL_SetColorKey(pacmanRight, true, whiteRight);
    SDL_Texture* pacmanRightTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanRight);
    SDL_FreeSurface(pacmanRight);
    
    playerImages.push_back(pacmanRightTx);
    
    SDL_Surface* pacmanDown = IMG_Load("/Users/marietopphem/Desktop/PacmanDown.png");
    Uint32 whiteDown = SDL_MapRGB(pacmanDown->format, 255, 255, 255);
    SDL_SetColorKey(pacmanDown, true, whiteDown);
    SDL_Texture* pacmanDownTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanDown);
    SDL_FreeSurface(pacmanDown);
    
    playerImages.push_back(pacmanDownTx);
    
    
    
    
    game -> add(new Enemy(1, 200, 200, enemyImages, game));
    
    game -> addWalls(game);
    
    game -> add(new VerticalWall(70,70,game));
    game -> add(new HorizontalWall(79,70,game));
    game -> add(new VerticalWall(70,94,game));
    game -> add(new HorizontalWall(103,70,game));
    game -> add(new VerticalWall(70,118,game));
    game -> add(new HorizontalWall(127,70,game));
    game -> add(new VerticalWall(70,142,game));
    game -> add(new HorizontalWall(151,70,game));
    game -> add(new VerticalWall(70,166,game));
    game -> add(new HorizontalWall(175,70,game));
    game -> add(new VerticalWall(70,190,game));
    game -> add(new HorizontalWall(199,70,game));
    
    game -> add(new VerticalWall(135,79,game));

    
    
    game -> add(new PointPill(400,325,game));
    game -> add(new PointPill(425,325,game));
    game -> add(new PointPill(450,325,game));
    game -> add(new PointPill(475,325,game));
    game -> add(new PointPill(500,325,game));
    game -> add(new PointPill(525,325,game));
    game -> add(new PointPill(550,325,game));
    game -> add(new PointPill(575,325,game));
    game -> add(new PointPill(600,325,game));
    game -> add(new PointPill(625,325,game));
    
    game -> add(new Player(3, 300, 300, playerImages, game));
    
    game -> run();
    
    delete game;
    
    return 0;
}
