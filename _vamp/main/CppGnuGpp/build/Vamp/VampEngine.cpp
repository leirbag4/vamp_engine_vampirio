#include "VampEngine.h"

void VampEngine::Init()
{
	window = new VampWindow();
	window->Init();
    cout << "init engine [ok]" << endl;
}

void VampEngine::Stop()
{
    cout << "stop engine [ok]" << endl;
}

void VampEngine::Run()
{
	int x = 0;
	
    while(running)
    {
        window->PollEvents();
        
        if(window->CloseNeeded())
        {
            running = false;
        }
        
        // Callback Event
        if (OnUpdate)
            OnUpdate();
        
        window->BeginRender();
        
        if(Keyboard::IsDown(Key::LEFT))
            x--;
        else if(Keyboard::IsDown(Key::RIGHT))
            x++;
        
        GFX::FillRect(0xFF00FFFF, x, 20, 100, 100);
        
        if (OnPaint)
            OnPaint();
        
        window->SwapBuffer();
        
    }
    
    window->Destroy();
}

VampWindow* VampEngine::GetWindow()
{
    return window;
}
