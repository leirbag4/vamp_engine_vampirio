#ifndef XCONSOLE_H
#define XCONSOLE_H

#include <iostream>
#include <string>
#include <vector>
#include "GFX.h"
#include "Font.h"

class XConsole 
{
    public:

        static int x;
        static int y;
        static int width;
        static int height;
        static unsigned int fontColor;
        static Font* font;

        static bool IsActive();
        static void SetActive(bool active);
        static void SetFont(Font* font);
        static void CreateFont(const char* fontPath, int size);
        static void Print(const std::string& str);
        static void Println(const std::string& str);
        static void PrintWarning(const std::string& str);
        static void PrintError(const std::string& str);
        static void PrintOk(const std::string& str);
        static void Clear();
        static std::vector<std::string> GetBuffer();
        static void Paint();

    
        

    private:
        static const int _bufferSize;

        static bool _active;
        static std::vector<std::string> buffer;
        static int fontHeight;
        
};

#endif