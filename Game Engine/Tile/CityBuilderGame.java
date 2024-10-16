public class CityBuilderGame {
    private GameEngine engine;
    private RenderingEngine renderingEngine;
    private TileMap tileMap;
    private InputHandler inputHandler;

    public CityBuilderGame() {
        int rows = 20;
        int cols = 20;
        int tileWidth = 40;
        int tileHeight = 40;

        tileMap = new TileMap(rows, cols, tileWidth, tileHeight);
        renderingEngine = new RenderingEngine(null);  // No camera needed for now
        inputHandler = new InputHandler(tileMap);
    }

    public void start() {
        renderingEngine.addKeyListener(inputHandler);
        engine.start();

        while (true) {
            renderingEngine.renderScene();
        }
    }

    public static void main(String[] args) {
        CityBuilderGame game = new CityBuilderGame();
        game.start();
    }
}