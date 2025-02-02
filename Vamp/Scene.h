#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object2D.h"



class Scene 
{
	
    public:
        void AddChild(Object2D* child);
        void RemoveChild(Object2D* child);
        int GetIndex(Object2D* child);
        void SetIndex(Object2D* child, int newIndex);
        void Update();
        void Paint();

    private:
        std::vector<Object2D*> children;
    
};

#endif
