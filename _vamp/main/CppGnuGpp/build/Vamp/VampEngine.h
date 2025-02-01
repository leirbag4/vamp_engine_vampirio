#ifndef VAMP_ENGINE_H
#define VAMP_ENGINE_H

#include <iostream>
#include "VampWindow.h"
#include "GFX.h"
#include "Key.h"
#include "Keyboard.h"
#include <functional>

using namespace std;

class VampEngine
{
    public:
        std::function<void(float deltaTime)> OnUpdate;
        std::function<void()> OnPaint;
        void Init();
        void Stop();
        void Run();
        VampWindow* GetWindow();
        
    private:
        VampWindow* window;
        bool running = true;
};

#endif