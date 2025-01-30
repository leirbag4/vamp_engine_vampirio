#include "Mouse.h"

int Mouse::x = -1;
int Mouse::y = -1;
bool Mouse::leftClick = false;
bool Mouse::rightClick = false;

void Mouse::SetValues(int x, int y, bool leftClick, bool rightClick)
{
    Mouse::x = x;
    Mouse::y = y;
    Mouse::leftClick =  leftClick;
    Mouse::rightClick = rightClick;
}
