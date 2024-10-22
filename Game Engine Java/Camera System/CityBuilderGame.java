package Camera System;

public class CityBuilderGame {
    private GameEngine engine;
    private RenderingEngine renderingEngine;
    private ResourceManager resourceManager;
    private Camera camera;
    private InputHandler inputHandler;

    public CityBuilderGame() {
        int worldWidth = 1600;  // Example world dimensions
        int worldHeight = 1200;
        int screenWidth = 800;
        int screenHeight = 600;

        camera = new Camera(0, 0, worldWidth, worldHeight, screenWidth, screenHeight);
        renderingEngine = new RenderingEngine(camera);
        resourceManager = new ResourceManager();
        inputHandler = new InputHandler(camera);
    }

    public void start() {
        // Register input handler
        renderingEngine.addKeyListener(inputHandler);
        engine.start();

        while (true) {
            resourceManager.update();
            renderingEngine.renderScene();
        }
    }

    public static void main(String[] args) {
        CityBuilderGame game = new CityBuilderGame();
        game.start();
    }
}
