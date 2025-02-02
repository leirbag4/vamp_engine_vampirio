#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <functional>
#include "Object2D.h"
#include "Font.h"
#include "GFX.h"
#include "Geometry.h"
#include "Scene.h"
#include "Mouse.h"

using namespace std;

class Button : public Object2D
{

    public:
        int x = 0;
        int y = 0;
        int width = 10;
        int height = 10;
        int fontWidth = 1;
        int fontHeight = 1;
        const int STATE_UP = 0;
        const int STATE_OVER = 1;
        const int STATE_DOWN = 2;
        int state = 0;
        unsigned int upColor =          0x444444FF;
        unsigned int overColor =        0x4F4F4FFF;
        unsigned int downColor =        0x505050FF;
        unsigned int borderUpColor =    0x000000FF;
        unsigned int borderOverColor =  0xA4A4FFFF;
        unsigned int borderDownColor =  0xB3B3FFFF;
        unsigned int textColor =        0xCCCCCCFF;
        Font* font;
        
        // Events
        function<void()> OnPressed;
        
        // Methods
        Button(const char* fontPath, int fontSize);
        void SetPos(int x, int y);
        void SetText(const char* text);
        void SetSize(int width, int height);
        bool IsDown();
        int GetIndex() override;
        void Update() override;
        void Paint() override;
        
    private:
        const char* text;
        bool IsInside();

};

#endif