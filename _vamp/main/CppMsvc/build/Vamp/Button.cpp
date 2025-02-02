#include "Button.h"


Button::Button(const char* fontPath, int fontSize)
{
    font = new Font(fontPath, fontSize);
    fontWidth =  1;
    fontHeight = 1;
}

void Button::SetPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Button::SetText(const char* str)
{
	text = str;
    Size size = GFX::GetFontSize(text, font);
    fontWidth = size.width;
    fontHeight = size.height;
}

void Button::SetSize(int width, int height)
{
    this->width =   width;
    this->height =  height;
}

int Button::GetIndex()
{
    return parentScene->GetIndex(this);
}

bool Button::IsInside()
{
    if( (Mouse::x >= x) && (Mouse::x <= (x + width)) &&
        (Mouse::y >= y) && (Mouse::y <= (y + height))  )
        return true;
    else
        return false;
}

bool Button::IsDown()
{
    return (state == STATE_DOWN);
}

void Button::Update()
{
    bool inside = IsInside();
    
    if(state == STATE_DOWN)
    {
        if(Mouse::leftClick)
            return;
    }

    // If the user releases the button inside the area, it gets activated
    if (state == STATE_DOWN && !Mouse::leftClick)
    {
        if (inside)
        {
            //cout << "Button pressed!" << endl;
        }
        state = STATE_UP;  // Reset state when released
        return;
    }

    // If the mouse is inside the button and there is no click, change to OVER
    if (inside)
    {
        if (Mouse::leftClick)
        {
            if (state == STATE_OVER)  // Allow changing to DOWN only if it was in OVER
            {
            	//cout << "down" << endl;
                if(OnPressed)
                    OnPressed();
                    
                state = STATE_DOWN;
            }
        }
        else
        {
            state = STATE_OVER;  // Hover over the button
        }
    }
    else
    {
        state = STATE_UP;  // Mouse outside the button
    }
}


void Button::Paint()
{
	unsigned int backColor;
	unsigned int borderColor;
	
	int fontX = x + (width >> 1) - (fontWidth >> 1);
	int fontY = y + (height >> 1) - (fontHeight >> 1);
	
	if(state == STATE_UP)
	{
        backColor =     upColor;
        borderColor =   borderUpColor;
	}
	else if(state == STATE_OVER)
	{
        backColor =     upColor;
        borderColor =   borderOverColor;
	}
	else if(state == STATE_DOWN)
	{
        backColor =     downColor;
        borderColor =   borderDownColor;
	}
	
	GFX::FillRect(backColor, x, y, width, height);
	GFX::DrawRect(borderColor, 1, x, y, width, height);
    GFX::DrawString(text, font, textColor, fontX, fontY);
}



