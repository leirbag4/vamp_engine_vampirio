#ifndef VAMP_ENGINE_H
#define VAMP_ENGINE_H

#include <iostream>
#include "VampWindow.h"
#include "GFX.h"
#include "Key.h"
#include "Keyboard.h"
#include "Scene.h"
#include "XConsole.h"
#include <functional>

using namespace std;

class VampEngine
{
    public:
        function<void()> OnInit;
        function<void(float deltaTime)> OnUpdate;
        function<void()> OnPaint;
        void Init();
        void Stop();
        void Run();
        VampWindow* GetWindow();
        Scene* GetScene();
        void SetScene(Scene* scene);
        void AddChild(Object2D* child);
        void RemoveChild(Object2D* child);
        int GetIndex(Object2D* child);
        void SetIndex(Object2D* child, int newIndex);
    
    private:
        VampWindow* window;
        Scene* scene;
        bool running = true;
        void Update(float deltaTime);
        void Paint();
};

#endif