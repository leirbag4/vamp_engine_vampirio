#include "Keyboard.h"

std::unordered_map<Key, bool> Keyboard::_keys_;

void Keyboard::SetKeyDown(Key key) 
{
    _keys_[key] = true;
}

void Keyboard::SetKeyUp(Key key) 
{
    _keys_[key] = false;
}

bool Keyboard::IsDown(Key key)
{
    if (_keys_.find(key) != _keys_.end())
        return _keys_[key];
    else
        return false;
}