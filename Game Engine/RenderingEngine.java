import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

public class RenderingEngine extends Canvas {
    private BufferStrategy bufferStrategy;

    public RenderingEngine() {
        this.setSize(800, 600);  // Set window size
    }

    public void renderScene() {
        bufferStrategy = this.getBufferStrategy();
        if (bufferStrategy == null) {
            this.createBufferStrategy(3);
            return;
        }

        Graphics g = bufferStrategy.getDrawGraphics();

        // Draw background
        g.setColor(Color.GREEN);
        g.fillRect(0, 0, 800, 600);

        // Draw buildings, terrain, etc.
        // g.drawImage(...);

        g.dispose();
        bufferStrategy.show();
    }
}