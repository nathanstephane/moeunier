#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <glm/glm.hpp>

#include <sol/config.hpp>
#include <sol/sol.hpp>
#include <cassert>

int main(int argc, char* argv[])
{
    // sol::state lua;
    // lua.open_libraries(sol::lib::base);
    

// Create a Lua state
    sol::state lua;

    // Load a Lua script
    lua.script("x = 10;");

    // Read a Lua variable
    int x = lua["x"];
    std::cout << "The value of x from Lua is: " << x << std::endl;

    // Define a C++ function and make it callable from Lua
    lua.set_function("add", [](int a, int b) {
        return a + b;
    });

    // Call the C++ function from Lua
    int result = lua.script("return add(5, 3);");
    std::cout << "The result of adding 5 and 3 in Lua is: " << result << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    glm::vec2 velocity = glm::vec2(5.0,-2.0);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}