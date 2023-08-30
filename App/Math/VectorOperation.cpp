#include "VectorOperation.hpp"

#include <cmath>

sf::Vector2f Normalize(sf::Vector2f vector)
{
    return vector / sqrt(vector.x * vector.x + vector.y * vector.y);
}
sf::Vector2i Normalize(sf::Vector2i vector)
{
    return vector / (int)sqrt(vector.x * vector.x + vector.y * vector.y);
}
sf::Vector2u Normalize(sf::Vector2u vector)
{
    return vector / (unsigned)sqrt(vector.x * vector.x + vector.y * vector.y);
}
float Magnitude(sf::Vector2f vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}
float Magnitude(sf::Vector2i vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}
float Magnitude(sf::Vector2u vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}
float MagnitudeSquared(sf::Vector2f vector)
{
    return vector.x * vector.x + vector.y * vector.y;
}
float MagnitudeSquared(sf::Vector2i vector)
{
    return vector.x * vector.x + vector.y * vector.y;
}
float MagnitudeSquared(sf::Vector2u vector)
{
    return vector.x * vector.x + vector.y * vector.y;
}