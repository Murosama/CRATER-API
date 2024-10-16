import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class InputHandler extends MouseAdapter {
    private TileMap tileMap;

    public InputHandler(TileMap tileMap) {
        this.tileMap = tileMap;
    }

    @Override
    public void mousePressed(MouseEvent e) {
        int mouseX = e.getX();
        int mouseY = e.getY();

        int row = mouseY / tileMap.getTileAt(0, 0).getHeight();
        int col = mouseX / tileMap.getTileAt(0, 0).getWidth();

        // Check if the tile is not already occupied
        if (!tileMap.isTileOccupied(row, col)) {
            tileMap.occupyTile(row, col);
            System.out.println("Placed building at tile (" + row + ", " + col + ")");
        }
    }
}