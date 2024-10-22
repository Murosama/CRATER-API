package Camera System;

public class RenderingEngine extends Canvas {
    private BufferStrategy bufferStrategy;
    private Camera camera;

    public RenderingEngine(Camera camera) {
        this.camera = camera;
        this.setSize(800, 600);  // Set window size
    }

    public void renderScene() {
        bufferStrategy = this.getBufferStrategy();
        if (bufferStrategy == null) {
            this.createBufferStrategy(3);
            return;
        }

        Graphics g = bufferStrategy.getDrawGraphics();

        // Adjust rendering by camera offset
        g.translate((int) -camera.getxOffset(), (int) -camera.getyOffset());

        // Draw background (example)
        g.setColor(Color.GREEN);
        g.fillRect(0, 0, 1600, 1200); // Example game world larger than screen

        // Draw buildings, terrain, etc.
        // g.drawImage(...);

        g.dispose();
        bufferStrategy.show();
    }
}
