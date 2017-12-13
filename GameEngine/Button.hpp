//
//  Button.hpp
//  GameEngine
//
//  Created by Marie Topphem on 2017-12-08.
//  Copyright © 2017 Marie Topphem. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <string>
#include <SDL2/SDL.h>



class Button{
public:
    ~Button();

    
    void mouseDown();
    void mouseUp(const SDL_Event& eve);
    void drawButton();
    
    virtual void perform(Button* source) {}
    
protected:
    Button(int x, int y, int w, int h, std::string txt);
    
private:
    
    bool isDown = false;
    
};

#endif /* Button_hpp */
