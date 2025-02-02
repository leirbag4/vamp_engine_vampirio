#include "Font.h"

Font::Font(const char* fontPath, int fontSize)
{
    _font = TTF_OpenFont(fontPath, fontSize);
    if (!_font) 
    {
        cout << "Can't load font at: " << fontPath << TTF_GetError() << endl;
        loaded = false;
    }
    else
        loaded = true;
}

TTF_Font* Font::GetInternalFont()
{
    return _font;
}

int Font::GetFontHeight()
{
    return TTF_FontHeight(_font);
}

bool Font::IsLoaded()
{
    return loaded;
}

