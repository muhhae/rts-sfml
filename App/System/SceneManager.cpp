#include "SceneManager.hpp"

void SceneManager::loadScene(Scene* scene , sf::RenderWindow& window)
{
    sf::Clock clock;
    sf::Time dt;
    
    scene->onStart(window);
    while (window.isOpen())
    {
        dt = clock.restart();
        if(!scene->onUpdate(window, dt)) break;
    }
    scene ->onExit(window);
    delete scene;
}