public class CityBuilderGame {
    private GameEngine engine;
    private RenderingEngine renderingEngine;
    private ResourceManager resourceManager;

    public CityBuilderGame() {
        engine = new GameEngine();
        renderingEngine = new RenderingEngine();
        resourceManager = new ResourceManager();
    }

    public void start() {
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

// This is for connecting everything together.
