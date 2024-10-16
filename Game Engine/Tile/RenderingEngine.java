public class RenderingEngine extends Canvas {
    private BufferStrategy bufferStrategy;
    private TileMap tileMap;

    public RenderingEngine(TileMap tileMap) {
        this.tileMap = tileMap;
        this.setSize(800, 600);
    }

    public void renderScene() {
        bufferStrategy = this.getBufferStrategy();
        if (bufferStrategy == null) {
            this.createBufferStrategy(3);
            return;
        }

        Graphics g = bufferStrategy.getDrawGraphics();

        // Render the tile map first
        tileMap.render(g);

        g.dispose();
        bufferStrategy.show();
    }
}