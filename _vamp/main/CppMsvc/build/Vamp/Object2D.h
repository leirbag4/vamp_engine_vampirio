#ifndef OBJECT_2D
#define OBJECT_2D

//#include "Scene.h"

// Forward declaration for circular dependency
class Scene;

class Object2D
{

    public:
        virtual void Update() = 0;
        virtual void Paint() =  0;
        virtual int GetIndex() =  0;
        Scene* parentScene;
};

#endif