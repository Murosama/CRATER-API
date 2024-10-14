import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class EnhancedCityPanel extends JPanel {
    private CitySimulation simulation;

    public EnhancedCityPanel(CitySimulation simulation) {
        this.simulation = simulation;
        Timer timer = new Timer(1000 / 60, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                simulation.update();
                repaint();
            }
        });
        timer.start();

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int x = e.getX() / CitySimulation.CELL_SIZE;
                int y = e.getY() / CitySimulation.CELL_SIZE;
                simulation.placeBuilding(x, y, CitySimulation.CellType.HOUSE); // Example: placing a house
            }
        });
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        simulation.draw(g);
    }
}
