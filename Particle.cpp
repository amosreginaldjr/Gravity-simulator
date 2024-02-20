#include"Particle.h"

Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y)
{
    pos.x = pos_x;
    pos.y = pos_y;

    vel.x = vel_x;
    vel.y = vel_y;

    s.setPosition(pos);
    s.setFillColor(sf::Color::White);
    s.setRadius(6);
    s.setPointCount(10); //was 25

    //s.setOutlineThickness(2);
    //s.setOutlineColor(sf::Color::Yellow);
}

Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y, int radius)
{
    pos.x = pos_x;
    pos.y = pos_y;

    vel.x = vel_x;
    vel.y = vel_y;

    s.setPosition(pos);
    s.setFillColor(sf::Color::White);
    s.setRadius(radius);
    s.setPointCount(1000); //was 25

    //s.setOutlineThickness(2);
    //s.setOutlineColor(sf::Color::Yellow);
}

void Particle::render(sf::RenderWindow& wind)
{
    s.setPosition(pos);
    wind.draw(s);
}

void Particle::update_physics(GravitySource& s)
{
    float distance_x = s.get_pos().x - pos.x;
    float distance_y = s.get_pos().y - pos.y;

    float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

    float inverse_distance = 1.f / distance;

    float normalized_x = inverse_distance * distance_x;
    float normalized_y = inverse_distance * distance_y;

    float inverse_square_dropoff = inverse_distance * inverse_distance;

    float acceleration_x = normalized_x * s.get_strength() * inverse_square_dropoff;
    float acceleration_y = normalized_y * s.get_strength() * inverse_square_dropoff;

    vel.x += acceleration_x;
    vel.y += acceleration_y;

    pos.x += vel.x;
    pos.y += vel.y;
}

void Particle::set_color(sf::Color col)
{
    s.setFillColor(col);
}