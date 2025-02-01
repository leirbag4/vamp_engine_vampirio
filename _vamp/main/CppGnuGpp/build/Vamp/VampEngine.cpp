#include "VampEngine.h"
#include "XTimer.h"
#include <thread>

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
    const int FPS = 60;
    const int frameDelay = 1000 / FPS; // 1000ms / 30 FPS = 33.33ms por frame

    long long lastTime = XTimer::GetMillis(); // Tiempo inicial

    while (running)
    {
        long long frameStart = XTimer::GetMillis(); // Comienza a medir el tiempo del frame

        window->PollEvents();

        if (window->CloseNeeded())
            running = false;

        // Calcula deltaTime en segundos
        long long currentTime = XTimer::GetMillis();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        //cout << "d: " << deltaTime << endl;

        // Llama a OnUpdate con deltaTime
        if (OnUpdate)
            OnUpdate(deltaTime);

        window->BeginRender();

        if (OnPaint)
            OnPaint();

        window->SwapBuffer();

        // Frame Lock: Asegura que cada frame dure al menos `frameDelay` milisegundos
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
