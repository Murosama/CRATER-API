package Creating-a-City-Building-game.;

public class CityPanel {
    setPreferredSize(new Dimension(800, 600));
        setBackground(Color.WHITE);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        drawCity(g);
    }

    private void drawCity(Graphics g) {
        // Example: Draw a simple building
        g.setColor(Color.GRAY);
        g.fillRect(100, 100, 100, 200);
        g.setColor(Color.BLACK);
        g.drawRect(100, 100, 100, 200);
        
        // Example: Draw a simple road
        g.setColor(Color.BLACK);
        g.fillRect(0, 300, 800, 50);
    }
}
