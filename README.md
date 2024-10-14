# CRATER API
 Java Source Codes for my game


#CityBuilder Game Engine

CityBuilder Game Engine is a custom-built Java-based game engine designed for creating 2D city-building simulation games. This engine provides essential components like rendering, entity management, resource management, and input handling to help developers like us to create interactive and dynamic city-building games with ease.


Features:

Entity Management: Create and manage buildings, roads, and other city elements through an easy-to-use Entity system.


Rendering Engine: Efficient rendering pipeline using Java AWT for smooth drawing of game objects and UI.


Resource Management: Handle in-game resources like money, materials, and population growth.


Collision Detection: Integrated basic collision detection for managing building placement.


Input Handling: Mouse input handling for interacting with the game (e.g., placing buildings)
.

Modular Design: Extensible and scalable to support additional features like traffic simulation, AI for citizens, and procedural map generation.
Getting Started


These instructions will get your game engine up and running on your local machine for development and testing purposes.


Installation:

Clone the repository:

git clone https://github.com/Murosama/CRATER-API
cd CityBuilder-GameEngine


Build the project: Ensure that your IDE is using the correct JDK version and compile the project using the IDE's build tools.


Running the Game:
After successful setup, run the CityBuilderGame class to start the game engine.



entities: Contains the base Entity class and its concrete implementations like Building.
engine: Contains the core game loop, rendering engine, and engine initialization.
input: Handles player input via mouse.
resources: Contains resource management logic such as money, materials, etc.

Usage:

Creating New Entities:

To add new types of buildings or other city elements, extend the Entity class. For example, you can create a Road class by following the pattern used in the Building class:
public class Road extends Entity {
    public Road(int x, int y) {
        super(x, y);
    }

    @Override
    public void update() {
        // Road-specific update logic
    }

    @Override
    public void render(Graphics g) {
        // Road-specific render logic
        g.setColor(Color.DARK_GRAY);
        g.fillRect(x, y, 100, 20); // Example dimensions
    }

Resource Management:


The ResourceManager handles the in-game economy, such as money and materials. You can modify this class to include additional resources (e.g., food, water, energy).

public class ResourceManager {
    private int population;

    public ResourceManager() {
        this.population = 50;
    }

    public void increasePopulation(int amount) {
        this.population += amount;
    }

    public int getPopulation() {
        return population;
    }


Rendering:

The RenderingEngine uses a buffer strategy for efficient drawing and can be extended to include layers, such as roads, terrain, and UI.

Contributing:

I welcome you for contributions to improve the engine! Feel free to fork the repository and submit pull requests with new features, optimizations, or bug fixes.

License:

This project is not licensed yet, but will be. Feel free to use it until that day.

