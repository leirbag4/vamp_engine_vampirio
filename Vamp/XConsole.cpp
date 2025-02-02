#include "XConsole.h"


const int XConsole::_bufferSize = 10;

int XConsole::x = 0;
int XConsole::y = 0;
int XConsole::width = 100;
int XConsole::height = 100;
unsigned int XConsole::fontColor = 0x333333FF;
bool XConsole::_active = false;
std::vector<std::string> XConsole::buffer;
int XConsole::fontHeight = 15;
Font* XConsole::font = nullptr;

bool XConsole::IsActive()
{
    return _active;
}

void XConsole::SetActive(bool active) 
{
    _active = active;
}

void XConsole::SetFont(Font* font)
{
    XConsole::font = font;
    fontHeight = font->GetFontHeight();
}

void XConsole::CreateFont(const char* fontPath, int size)
{
    XConsole::font = new Font(fontPath, size);
    fontHeight = font->GetFontHeight();
}

void XConsole::Print(const std::string& str) 
{
    if (_active)
        buffer[buffer.size() - 1] += str;
    else
        std::cout << str;
}

void XConsole::Println(const std::string& str) 
{
    if (_active) 
    {
        buffer.push_back(str);
        if (buffer.size() > _bufferSize)
            buffer.erase(buffer.begin());
    }
    else
        std::cout << str << std::endl;
}

void XConsole::PrintWarning(const std::string& str) 
{
    std::string warningStr = "[WARN] " + str;

    if (_active) 
    {
        buffer.push_back(warningStr);
        if (buffer.size() > _bufferSize)
            buffer.erase(buffer.begin());
    }
    else 
    {
        std::cout << "\033[1;33m" << warningStr << "\033[0m" << std::endl;
    }
}

void XConsole::PrintError(const std::string& str) 
{
    std::string errorStr = "[ERROR] " + str;

    if (_active) 
    {
        buffer.push_back(errorStr);
        if (buffer.size() > _bufferSize)
            buffer.erase(buffer.begin());
    }
    else
    {
        std::cout << "\033[1;31m" << errorStr << "\033[0m" << std::endl;
    }
}

void XConsole::PrintOk(const std::string& str) 
{
    std::string okStr = "[OK] " + str;

    if (_active) 
    {
        buffer.push_back(okStr);
        if (buffer.size() > _bufferSize)
            buffer.erase(buffer.begin());
    }
    else 
    {
        std::cout << "\033[1;32m" << okStr << "\033[0m" << std::endl;
    }
}

void XConsole::Clear() 
{
	if (_active)
        buffer.clear();
}

std::vector<std::string> XConsole::GetBuffer() 
{
    return buffer;
}

void XConsole::Paint() 
{
    int startX = x;
    int startY = y;

    if(_active)
    {
    	if(font != nullptr)
        {
            for (const auto& line : buffer) 
            {
                GFX::DrawString(line.c_str(), font, XConsole::fontColor, startX, startY);
                startY += fontHeight;
            }
        }
    }
}