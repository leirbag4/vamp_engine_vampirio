#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <unordered_map>
#include "Key.h"

class Keyboard 
{
    public:
        static void SetKeyDown(Key key);
        static void SetKeyUp(Key key);

        static bool IsDown(Key key);

    private:
        static std::unordered_map<Key, bool> _keys_;
};

#endif