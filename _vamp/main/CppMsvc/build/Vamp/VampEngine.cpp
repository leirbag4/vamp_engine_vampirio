#include "VampEngine.h"
#include "XTimer.h"
#include <thread>

void VampEngine::Init()
{
	window = new VampWindow();
	window->Init();
	scene = new Scene(); // creates default scene
    cout << "init engine [ok]" << endl;
    
    if(OnInit)
        OnInit();
}

void VampEngine::Stop()
{
    running = false;
    cout << "stop engine [ok]" << endl;
}

void VampEngine::Run()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS; // 1000ms / 30 FPS = 33.33ms por frame

    long long lastTime = XTimer::GetMillis(); // Initial time

    while (running)
    {
        long long frameStart = XTimer::GetMillis(); // Start measuring frame time

        window->PollEvents();

        if (window->CloseNeeded())
            running = false;

        // Calc deltaTime in seconds
        long long currentTime = XTimer::GetMillis();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        //cout << "d: " << deltaTime << endl;

        //
        // UPDATE
        //
        Update(deltaTime);

        //
        // PAINT
        //
        Paint();
        

        // Frame Lock: ensures that each frame lasts at least `frameDelay` milliseconds
        long long frameTime = XTimer::GetMillis() - frameStart;

        if (frameTime < frameDelay)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay - frameTime));
        }
    }

    window->Destroy();
}

VampWindow* VampEngine::GetWindow()
{
    return window;
}

Scene* VampEngine::GetScene()
{
    return scene;
}

void VampEngine::SetScene(Scene* scene)
{
    this->scene = scene;
}

void VampEngine::AddChild(Object2D* child)
{
    scene->AddChild(child);
}

void VampEngine::RemoveChild(Object2D* child)
{
    scene->RemoveChild(child);
}

int VampEngine::GetIndex(Object2D* child)
{
    return scene->GetIndex(child);
}

void VampEngine::SetIndex(Object2D* child, int newIndex)
{
    scene->SetIndex(child, newIndex);
}

void VampEngine::Update(float deltaTime)
{
	XConsole::Clear();
	
	scene->Update();
	
    if (OnUpdate)
        OnUpdate(deltaTime);
}

void VampEngine::Paint()
{
    window->BeginRender();

    scene->Paint();
    
    if (OnPaint)
        OnPaint();
        
    XConsole::Paint();
        
    window->SwapBuffer();
}

