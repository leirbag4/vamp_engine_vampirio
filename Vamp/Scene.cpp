#include "Scene.h"
#include <algorithm>

void Scene::AddChild(Object2D* child) 
{
    if (child) 
    {
    	child->parentScene = this;
        children.push_back(child);
    }
}

void Scene::RemoveChild(Object2D* child) 
{
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

int Scene::GetIndex(Object2D* child) 
{
    auto it = std::find(children.begin(), children.end(), child);
    
    if (it != children.end())
    {
        return std::distance(children.begin(), it);
    }
    
    return -1; // Returns -1 if the object is not in the list
}

void Scene::SetIndex(Object2D* child, int newIndex) 
{
    int currentIndex = GetIndex(child);
    
    if (currentIndex == -1 || newIndex < 0 || newIndex >= children.size()) 
    {
        return; // Avoid moving if index does not exist or is invalid
    }

    children.erase(children.begin() + currentIndex); // Removes the object from its current position
    children.insert(children.begin() + newIndex, child); // Insert it into the new position
}

void Scene::Update() 
{
    for (auto child : children) 
    {
        child->Update();
    }
}

void Scene::Paint() 
{
    for (auto child : children) 
    {
        child->Paint();
    }
}
