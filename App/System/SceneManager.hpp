#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
    Scene() {}
    virtual bool onUpdate(sf::RenderWindow& window, sf::Time dt) { return false; }
    virtual void onStart(sf::RenderWindow& window) {}
    virtual void onExit(sf::RenderWindow& window) {}
};

class SceneManager
{
private:
public:
    SceneManager(){}
    void loadScene(Scene* scene , sf::RenderWindow& window);
    
};