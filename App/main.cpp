#include <SFML/Graphics.hpp>

#include <iostream>

#include "UI/Button.hpp"
#include "System/SceneManager.hpp"

#include "Scene/tesScene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
    sf::View view = window.getDefaultView();
    window.setView(view);
    
    while (window.isOpen())
    {
        SceneManager sceneManager;
        sceneManager.loadScene(new tesScene() , window);
    }

    return 0;
}