import java.awt.Color;
import java.awtimport java.awt.Color;


public class EnhancedCitySimulation {
    private static final int GRID_SIZE = 20;
    private static final int CELL_SIZE = 30;
    private CellType[][] grid;


    public EnhancedCitySimulation() {
        grid = new CellType[GRID_SIZE][GRID_SIZE];
        // Initializing grid with empty cells
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = CellType.EMPTY;
            }
        }
    }

    public void update() {
        // For updating simulation state if needed
    }

    public void draw(Graphics g) {
        // Drawing the grid
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                switch (grid[i][j]) {
                    case EMPTY:
                        g.setColor(Color.LIGHT_GRAY);
                        break;
                    case HOUSE:
                        g.setColor(Color.BLUE);
                        break;
                    case FACTORY:
                        g.setColor(Color.RED);
                        break;        

                }
                g.fillRect(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                g.setColor(Color.BLACK);
                g.drawRect(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE);
            }
        }
    }

    public void placeBuilding(int x, int y, CellType type) {
        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
            grid[x][y] = type;
        }
    }

    public enum CellType {
        EMPTY, HOUSE, FACTORY
    }
}

