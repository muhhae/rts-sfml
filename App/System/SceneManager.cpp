#include "SceneManager.hpp"

void SceneManager::loadScene(Scene* scene , sf::RenderWindow& window)
{
    currentScene = scene;
    currentScene->onStart();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        if(!currentScene->onUpdate(window)) break;
    }
    currentScene->onExit();
    delete scene;
}