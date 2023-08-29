#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
    Scene(std::string name) : name(name) {}
    virtual void onUpdate(sf::RenderWindow& window, sf::Time dt) {}
    virtual void onStart(sf::RenderWindow& window) {}
    virtual void onExit(sf::RenderWindow& window) {}
    std::string name;
};

class SceneManager
{
private:
    SceneManager(){}
public:
    static void loadScene(Scene* scene, sf::RenderWindow& window);
    static void changeScene(std::string scene) { currentScene = scene; }
    static SceneManager* instance;
    static std::string currentScene;
};

