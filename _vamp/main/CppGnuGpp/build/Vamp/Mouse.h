#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
	public:
		static int x;
		static int y;
		static bool leftClick;
		static bool rightClick;
		static void SetValues(int x, int y, bool leftClick, bool rightClick);
};

#endif