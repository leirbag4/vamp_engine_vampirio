#include "VampWindow.h"

void VampWindow::Init()
{
	_closeNeeded = false;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Can't init video: " << SDL_GetError() << endl;
    }

    window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);// | SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr)
    {
        cout << "Can't create window: " << SDL_GetError() << endl;
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (renderer == nullptr)
    {
        cout << "Can't create renderer: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
    // Initilizes SDL_image for use with png files.
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialized! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
    }
    
    // Initializes True type fonts
    if (TTF_Init() == -1) 
    {
        cout << "TTF_Init could not be initialized! TTF_Init Error: " << TTF_GetError() << endl;
        SDL_Quit();
    }
    

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, 0xFF);
    SDL_RenderDrawPoint(renderer, 100, 100);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 50;
    rect.h = 80;
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);


    //
    // Setup
    //
    GFX::renderer = renderer;
    
    //SDL_Delay(2000);
	
}

void VampWindow::PollEvents()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {

        int mouseX, mouseY;
        bool mouseEventTriggered = false;
        bool mouseLeft;
        bool mouseRight;

        switch (e.type)
        {
            case SDL_KEYDOWN:
                //KeyDown((Key)((int)e.key.keysym.sym));
                Keyboard::SetKeyDown((Key)((int)e.key.keysym.sym));
                break;

            case SDL_KEYUP:
                //KeyUp((Key)((int)e.key.keysym.sym));
                Keyboard::SetKeyUp((Key)((int)e.key.keysym.sym));
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&mouseX, &mouseY);
                mouseLeft  |= e.button.button == SDL_BUTTON_LEFT;
                mouseRight |= e.button.button == SDL_BUTTON_RIGHT;
                Mouse::SetValues(mouseX, mouseY, mouseLeft, mouseRight);
                //MouseDown(mouseX, mouseY, mouseLeft, mouseRight);
                //mouseEventTriggered = true;
                break;

            case SDL_MOUSEBUTTONUP:
                SDL_GetMouseState(&mouseX, &mouseY);
                mouseLeft  &= !(e.button.button == SDL_BUTTON_LEFT);
                mouseRight &= !(e.button.button == SDL_BUTTON_RIGHT);
                Mouse::SetValues(mouseX, mouseY, mouseLeft, mouseRight);
                //MouseUp(mouseX, mouseY, mouseLeft, mouseRight);
                //mouseEventTriggered = true;
                break;

            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&mouseX, &mouseY);
                Mouse::x = mouseX;
                Mouse::y = mouseY;
                //MouseMove(mouseX, mouseY, mouseLeft, mouseRight);
                break;
        	
            case SDL_QUIT:
                _closeNeeded = true;
                break;
        }
    }
}


void VampWindow::Clear()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void VampWindow::BeginRender()
{
    this->Clear();
}

void VampWindow::SwapBuffer()
{
    SDL_RenderPresent(renderer);
}

bool VampWindow::CloseNeeded()
{
    return _closeNeeded;
}

SDL_Renderer* VampWindow::GetRenderer()
{
    return renderer;
}

void VampWindow::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




