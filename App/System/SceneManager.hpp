#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
    Scene() {}
    virtual bool onUpdate(sf::RenderWindow& window) { return false; }
    virtual void onStart() {}
    virtual void onExit() {}
};

class SceneManager
{
private:
    Scene* currentScene;
public:
    SceneManager(){}
    void loadScene(Scene* scene , sf::RenderWindow& window);
    
};