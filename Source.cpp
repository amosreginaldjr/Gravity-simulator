#include<iostream>
#include<SFML/Graphics.hpp>
#include"GravitySource.h"
#include"Particle.h"
using namespace std;

sf::Color map_val_to_color(float value);
int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Gravity Tester");
    window.setFramerateLimit(60);

    vector<GravitySource> sources;
    sources.push_back(GravitySource(600, 500, 7000)); //(500 , 500 , 7000) default
    sources.push_back(GravitySource(1200, 500, 7000));//(1200 , 500 , 7000) default
    sources.push_back(GravitySource(900, 100, 7000)); //new

    int red_particles = 500;
    int green_particles = 500;
    int blue_particles = 500;
    int magenta_particles = 500;
    int yellow_particles = 500;
    vector<Particle> v_red_particles;
    vector<Particle> v_green_particles;
    vector<Particle> v_blue_particles;
    vector<Particle> v_magenta_particles;
    vector<Particle> v_yellow_particles;

    vector<Particle> v_all_particles; //used to put all color particles together

    //red particles:
    for (int i = 0; i < red_particles; i++)
    {
        v_red_particles.push_back(Particle(900, 327, 4, 0.2 + (0.1 / red_particles) * i)); //default

        //change colors
        float val = (float)i / (float)red_particles;
        sf::Color col = sf::Color::Red;
        v_red_particles[i].set_color(col);
    }
    //green particles :
    for (int i = 0; i < green_particles; i++)
    {
        v_green_particles.push_back(Particle(610, 710, 4, 0.2 + (0.1 / green_particles) * i));

        //change colors
        float val = (float)i / (float)green_particles;
        sf::Color col = sf::Color::Green;
        v_green_particles[i].set_color(sf::Color::Green);
    }
    //blue particles :
    for (int i = 0; i < blue_particles; i++)
    {
        v_blue_particles.push_back(Particle(620, 720, 4, 0.2 + (0.1 / blue_particles) * i));
        //v_blue_particles.push_back(Particle(620, 720, 4, 0.2 + (0.1 / blue_particles) * i)); 
        /*best rotating effect^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

        //change colors
        float val = (float)i / (float)green_particles;
        sf::Color col = sf::Color::Blue;
        v_blue_particles[i].set_color(sf::Color::Blue);
    }
    //pink particles :
    for (int i = 0; i < magenta_particles; i++)
    {
        v_magenta_particles.push_back(Particle(630, 730, 4, 0.2 + (0.1 / magenta_particles) * i));

        //change colors
        float val = (float)i / (float)green_particles;
        sf::Color col = sf::Color::Magenta;
        v_magenta_particles[i].set_color(sf::Color::Magenta);
    }
    //orange particles :
    for (int i = 0; i < yellow_particles; i++)
    {
        v_yellow_particles.push_back(Particle(630, 730, 4, 0.2 + (0.1 / yellow_particles) * i));

        //change colors
        float val = (float)i / (float)yellow_particles;
        sf::Color col = sf::Color::Yellow;
        v_magenta_particles[i].set_color(sf::Color::Magenta);
    }



    //load red and green and blue into one array
    v_all_particles.reserve(v_red_particles.size() + v_green_particles.size()
        + v_blue_particles.size() + v_magenta_particles.size() + v_yellow_particles.size());
    v_all_particles.insert(v_all_particles.end(), v_red_particles.begin(), v_red_particles.end());
    //v_all_particles.insert(v_all_particles.end(), v_green_particles.begin(), v_green_particles.end());
    //v_all_particles.insert(v_all_particles.end(), v_blue_particles.begin(), v_blue_particles.end());
    //v_all_particles.insert(v_all_particles.end(), v_magenta_particles.begin(), v_magenta_particles.end());
    v_all_particles.insert(v_all_particles.end(), v_yellow_particles.begin(), v_yellow_particles.end());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }


        window.clear();
        for (int i = 0; i < sources.size(); i++)
        {
            for (int j = 0; j < v_all_particles.size(); j++)
            {
                v_all_particles[j].update_physics(sources[i]);
            }
        }
        for (int i = 0; i < sources.size(); i++)
        {
            sources[i].render(window);
            for (int j = 0; j < v_all_particles.size(); j++)
            {
                v_all_particles[j].render(window);
            }
        }
        window.display();
    }


    return 0;
}