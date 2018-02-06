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
    
    game -> init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 810, 680, true);
    
    vector<SDL_Texture*> enemyImages;
    vector<SDL_Texture*> playerImages;
    
    SDL_Surface* pacman = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/Pacman.png");
    Uint32 white = SDL_MapRGB(pacman->format, 255, 255, 255);
    SDL_SetColorKey(pacman, true, white);
    SDL_Texture* pacmanTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacman);
    SDL_FreeSurface(pacman);
    
    playerImages.push_back(pacmanTx);
    
    SDL_Surface* pacmanLeft = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/PacmanLeft.png");
    Uint32 whiteLeft = SDL_MapRGB(pacmanLeft->format, 255, 255, 255);
    SDL_SetColorKey(pacmanLeft, true, whiteLeft);
    SDL_Texture* pacmanLeftTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanLeft);
    SDL_FreeSurface(pacmanLeft);
    
    playerImages.push_back(pacmanLeftTx);
    
    SDL_Surface* pacmanUp = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/PacmanUp.png");
    Uint32 whiteUp = SDL_MapRGB(pacmanUp->format, 255, 255, 255);
    SDL_SetColorKey(pacmanUp, true, whiteUp);
    SDL_Texture* pacmanUpTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanUp);
    SDL_FreeSurface(pacmanUp);
    
    playerImages.push_back(pacmanUpTx);
    
    SDL_Surface* pacmanRight = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/PacmanRight.png");
    Uint32 whiteRight = SDL_MapRGB(pacmanRight->format, 255, 255, 255);
    SDL_SetColorKey(pacmanRight, true, whiteRight);
    SDL_Texture* pacmanRightTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanRight);
    SDL_FreeSurface(pacmanRight);
    
    playerImages.push_back(pacmanRightTx);
    
    SDL_Surface* pacmanDown = IMG_Load("/Users/marietopphem/Desktop/Data-ochSystemvetenskap år3/Prog3/C++/Inlupp/Pacman/PacmanDown.png");
    Uint32 whiteDown = SDL_MapRGB(pacmanDown->format, 255, 255, 255);
    SDL_SetColorKey(pacmanDown, true, whiteDown);
    SDL_Texture* pacmanDownTx = SDL_CreateTextureFromSurface(game -> getRenderer(), pacmanDown);
    SDL_FreeSurface(pacmanDown);
    
    playerImages.push_back(pacmanDownTx);
    
    
    
    
    game -> add(new Enemy(1, 410, 410, enemyImages, game));
    
    game -> addWalls(game);
    
    //h1
    game->add(new HorizontalWall(43,43,game));
    game->add(new HorizontalWall(123,43,game));
    game->add(new HorizontalWall(163,43,game));
    game->add(new HorizontalWall(283,43,game));
    game->add(new HorizontalWall(323,43,game));
    game->add(new HorizontalWall(363,43,game));
    game->add(new HorizontalWall(403,43,game));
    game->add(new HorizontalWall(483,43,game));
    game->add(new HorizontalWall(563,43,game));
    game->add(new HorizontalWall(603,43,game));
    game->add(new HorizontalWall(643,43,game));
    game->add(new HorizontalWall(683,43,game));
    game->add(new HorizontalWall(723,43,game));
    
    //h2
    
    game->add(new HorizontalWall(83,83,game));
    game->add(new HorizontalWall(163,83,game));
    game->add(new HorizontalWall(323,83,game));
    game->add(new HorizontalWall(403,83,game));
    game->add(new HorizontalWall(443,83,game));
    game->add(new HorizontalWall(523,83,game));
    game->add(new HorizontalWall(563,83,game));
    game->add(new HorizontalWall(603,83,game));
    game->add(new HorizontalWall(683,83,game));
    
    //h3
    
    game->add(new HorizontalWall(43,123,game));
    game->add(new HorizontalWall(123,123,game));
    game->add(new HorizontalWall(443,123,game));
    game->add(new HorizontalWall(563,123,game));
    game->add(new HorizontalWall(603,123,game));
    game->add(new HorizontalWall(643,123,game));
    
    //h4
    game->add(new HorizontalWall(43,163,game));
    game->add(new HorizontalWall(83,163,game));
    game->add(new HorizontalWall(403,163,game));
    game->add(new HorizontalWall(603,163,game));
    
    //h5
    game->add(new HorizontalWall(43,203,game));
    game->add(new HorizontalWall(163,203,game));
    game->add(new HorizontalWall(203,203,game));
    game->add(new HorizontalWall(323,203,game));
    game->add(new HorizontalWall(403,203,game));
    game->add(new HorizontalWall(443,203,game));
    game->add(new HorizontalWall(483,203,game));
    game->add(new HorizontalWall(523,203,game));
    
    //h6
    game->add(new HorizontalWall(203,243,game));
    game->add(new HorizontalWall(243,243,game));
    game->add(new HorizontalWall(283,243,game));
    game->add(new HorizontalWall(443,243,game));
    game->add(new HorizontalWall(483,243,game));
    game->add(new HorizontalWall(683,243,game));
    
    //h7
    game->add(new HorizontalWall(243,283,game));
    game->add(new HorizontalWall(403,283,game));
    game->add(new HorizontalWall(443,283,game));
    game->add(new HorizontalWall(643,283,game));


    //h8
    game->add(new HorizontalWall(363,323,game));
    game->add(new HorizontalWall(403,323,game));

    //h9
    game->add(new HorizontalWall(123,363,game));
    game->add(new HorizontalWall(323,363,game));
    game->add(new HorizontalWall(363,363,game));
    game->add(new HorizontalWall(523,363,game));
    
    //h10
    game->add(new HorizontalWall(83,403,game));
    game->add(new HorizontalWall(283,403,game));
    game->add(new HorizontalWall(323,403,game));
    game->add(new HorizontalWall(483,403,game));
    game->add(new HorizontalWall(523,403,game));
    game->add(new HorizontalWall(563,403,game));
    
    //h11
    game->add(new HorizontalWall(243,443,game));
    game->add(new HorizontalWall(283,443,game));
    game->add(new HorizontalWall(323,443,game));
    game->add(new HorizontalWall(363,443,game));
    game->add(new HorizontalWall(443,443,game));
    game->add(new HorizontalWall(523,443,game));
    game->add(new HorizontalWall(563,443,game));
    game->add(new HorizontalWall(603,443,game));

    //h12
    game->add(new HorizontalWall(163,483,game));
    game->add(new HorizontalWall(363,483,game));
    game->add(new HorizontalWall(683,483,game));
    game->add(new HorizontalWall(723,483,game));

    //h13
    game->add(new HorizontalWall(123,523,game));
    game->add(new HorizontalWall(163,523,game));
    game->add(new HorizontalWall(203,523,game));
    game->add(new HorizontalWall(323,523,game));
    game->add(new HorizontalWall(643,523,game));
    game->add(new HorizontalWall(723,523,game));

    
    //h14
    
    game->add(new HorizontalWall(83,563,game));
    game->add(new HorizontalWall(163,563,game));
    game->add(new HorizontalWall(203,563,game));
    game->add(new HorizontalWall(243,563,game));
    game->add(new HorizontalWall(323,563,game));
    game->add(new HorizontalWall(363,563,game));
    game->add(new HorizontalWall(443,563,game));
    game->add(new HorizontalWall(603,563,game));
    game->add(new HorizontalWall(683,563,game));

    
    //h15
    game->add(new HorizontalWall(43,603,game));
    game->add(new HorizontalWall(83,603,game));
    game->add(new HorizontalWall(123,603,game));
    game->add(new HorizontalWall(163,603,game));
    game->add(new HorizontalWall(203,603,game));
    game->add(new HorizontalWall(283,603,game));
    game->add(new HorizontalWall(363,603,game));
    game->add(new HorizontalWall(403,603,game));
    game->add(new HorizontalWall(443,603,game));
    game->add(new HorizontalWall(483,603,game));
    game->add(new HorizontalWall(603,603,game));
    game->add(new HorizontalWall(643,603,game));
    game->add(new HorizontalWall(723,603,game));

    //v1
    game -> add(new VerticalWall(43,43,game));
    game -> add(new VerticalWall(43,203,game));
    game -> add(new VerticalWall(43,243,game));
    game -> add(new VerticalWall(43,283,game));
    game -> add(new VerticalWall(43,363,game));
    game -> add(new VerticalWall(43,403,game));
    game -> add(new VerticalWall(43,483,game));
    game -> add(new VerticalWall(43,523,game));
    game -> add(new VerticalWall(43,563,game));
    
    //v2
    
    game -> add(new VerticalWall(83,83,game));
    game -> add(new VerticalWall(83,243,game));
    game -> add(new VerticalWall(83,283,game));
    game -> add(new VerticalWall(83,323,game));
    game -> add(new VerticalWall(83,443,game));
    game -> add(new VerticalWall(83,483,game));
    game -> add(new VerticalWall(83,523,game));

    //v3
    game -> add(new VerticalWall(123,43,game));
    game -> add(new VerticalWall(123,163,game));
    game -> add(new VerticalWall(123,203,game));
    game -> add(new VerticalWall(123,243,game));
    game -> add(new VerticalWall(123,283,game));
    game -> add(new VerticalWall(123,403,game));
    game -> add(new VerticalWall(123,443,game));
    game -> add(new VerticalWall(123,483,game));
    
    //v4
    game -> add(new VerticalWall(163,123,game));
    game -> add(new VerticalWall(163,203,game));
    game -> add(new VerticalWall(163,243,game));
    game -> add(new VerticalWall(163,283,game));
    game -> add(new VerticalWall(163,363,game));
    game -> add(new VerticalWall(163,403,game));
    game -> add(new VerticalWall(163,443,game));

    //v5
    game -> add(new VerticalWall(203,83,game));
    game -> add(new VerticalWall(203,123,game));
    game -> add(new VerticalWall(203,283,game));
    game -> add(new VerticalWall(203,323,game));
    game -> add(new VerticalWall(203,363,game));
    game -> add(new VerticalWall(203,403,game));
    
    //v6
    game -> add(new VerticalWall(243,43,game));
    game -> add(new VerticalWall(243,83,game));
    game -> add(new VerticalWall(243,163,game));
    game -> add(new VerticalWall(243,283,game));
    game -> add(new VerticalWall(243,363,game));
    game -> add(new VerticalWall(243,403,game));
    game -> add(new VerticalWall(243,483,game));

    //v7
    game -> add(new VerticalWall(283,43,game));
    game -> add(new VerticalWall(283,83,game));
    game -> add(new VerticalWall(283,123,game));
    game -> add(new VerticalWall(283,163,game));
    game -> add(new VerticalWall(283,323,game));
    game -> add(new VerticalWall(283,363,game));
    game -> add(new VerticalWall(283,483,game));
    game -> add(new VerticalWall(283,523,game));
    game -> add(new VerticalWall(283,563,game));
    
    //v8
    game -> add(new VerticalWall(323,123,game));
    game -> add(new VerticalWall(323,163,game));
    game -> add(new VerticalWall(323,243,game));
    game -> add(new VerticalWall(323,283,game));
    game -> add(new VerticalWall(323,323,game));
    game -> add(new VerticalWall(323,443,game));
    game -> add(new VerticalWall(323,483,game));
    
    //v9
    game -> add(new VerticalWall(363,83,game));
    game -> add(new VerticalWall(363,123,game));
    game -> add(new VerticalWall(363,243,game));
    game -> add(new VerticalWall(363,283,game));

    //v10
    game -> add(new VerticalWall(403,83,game));
    game -> add(new VerticalWall(403,123,game));
    game -> add(new VerticalWall(403,243,game));
    game -> add(new VerticalWall(403,363,game));
    game -> add(new VerticalWall(403,483,game));
    game -> add(new VerticalWall(403,523,game));

    
    //v11
    game -> add(new VerticalWall(443,323,game));
    game -> add(new VerticalWall(443,363,game));
    game -> add(new VerticalWall(443,443,game));
    game -> add(new VerticalWall(443,483,game));
    
    //v12
    game -> add(new VerticalWall(483,123,game));
    game -> add(new VerticalWall(483,163,game));
    game -> add(new VerticalWall(483,283,game));
    game -> add(new VerticalWall(483,323,game));
    game -> add(new VerticalWall(483,363,game));
    game -> add(new VerticalWall(483,483,game));
    game -> add(new VerticalWall(483,523,game));
    
    //v13
    game -> add(new VerticalWall(523,43,game));
    game -> add(new VerticalWall(523,83,game));
    game -> add(new VerticalWall(523,123,game));
    game -> add(new VerticalWall(523,243,game));
    game -> add(new VerticalWall(523,283,game));
    game -> add(new VerticalWall(523,443,game));
    game -> add(new VerticalWall(523,483,game));
    game -> add(new VerticalWall(523,523,game));
    game -> add(new VerticalWall(523,563,game));

    //v14
    game -> add(new VerticalWall(563,123,game));
    game -> add(new VerticalWall(563,203,game));
    game -> add(new VerticalWall(563,243,game));
    game -> add(new VerticalWall(563,323,game));
    game -> add(new VerticalWall(563,483,game));
    game -> add(new VerticalWall(563,523,game));
    game -> add(new VerticalWall(563,563,game));
    
    //v15
    game -> add(new VerticalWall(603,203,game));
    game -> add(new VerticalWall(603,243,game));
    game -> add(new VerticalWall(603,283,game));
    game -> add(new VerticalWall(603,323,game));
    game -> add(new VerticalWall(603,483,game));
    game -> add(new VerticalWall(603,523,game));

    //v16
    game -> add(new VerticalWall(643,163,game));
    game -> add(new VerticalWall(643,203,game));
    game -> add(new VerticalWall(643,243,game));
    game -> add(new VerticalWall(643,323,game));
    game -> add(new VerticalWall(643,363,game));
    game -> add(new VerticalWall(643,403,game));
    game -> add(new VerticalWall(643,483,game));
    
    //v17
    game -> add(new VerticalWall(683,123,game));
    game -> add(new VerticalWall(683,163,game));
    game -> add(new VerticalWall(683,203,game));
    game -> add(new VerticalWall(683,323,game));
    game -> add(new VerticalWall(683,363,game));
    game -> add(new VerticalWall(683,403,game));
    game -> add(new VerticalWall(683,443,game));
    game -> add(new VerticalWall(683,563,game));
    
    //v18
    game -> add(new VerticalWall(723,83,game));
    game -> add(new VerticalWall(723,123,game));
    game -> add(new VerticalWall(723,163,game));
    game -> add(new VerticalWall(723,283,game));
    game -> add(new VerticalWall(723,323,game));
    game -> add(new VerticalWall(723,363,game));
    game -> add(new VerticalWall(723,403,game));
    game -> add(new VerticalWall(723,523,game));

    //v19
    game -> add(new VerticalWall(763,43,game));
    game -> add(new VerticalWall(763,83,game));
    game -> add(new VerticalWall(763,123,game));
    game -> add(new VerticalWall(763,203,game));
    game -> add(new VerticalWall(763,243,game));
    game -> add(new VerticalWall(763,323,game));
    game -> add(new VerticalWall(763,363,game));
    game -> add(new VerticalWall(763,403,game));
    game -> add(new VerticalWall(763,563,game));


    for (int i = 22; i<795; i+=20) {
        for (int j = 22; j<630; j+=20){
         game -> add(new PointPill(i,j,game));
        }
    }
    
    game -> add(new Player(3, 12, 12, playerImages, game));
    
    game->addCommand(SDLK_x, []() { std::cout << "Klickat på X"<< endl; });
    game -> run();
    
    delete game;
    
    return 0;
}
