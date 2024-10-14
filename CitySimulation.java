import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;

public class CitySimulation extends JFrame {
    
    public CitySimulation() {
        setTitle("City Simulation");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        add(new CityPanel());
        setVisible(true);
    }

    public static void main(String[] args) {
        new CitySimulation();
    }
}

class CityPanel extends JPanel {

    public CityPanel() {
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