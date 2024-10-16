public class Tile {
    private int x, y;
    private int width, height;
    private boolean occupied;
    private Color color;  // To represent different types of terrain

    public Tile(int x, int y, int width, int height, Color color) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.color = color;
        this.occupied = false;
    }

    public void render(Graphics g) {
        g.setColor(color);
        g.fillRect(x, y, width, height);

        if (occupied) {
            g.setColor(Color.RED); // Overlay color to show it's occupied
            g.drawRect(x, y, width, height);
        }
    }

    public boolean isOccupied() {
        return occupied;
    }

    public void setOccupied(boolean occupied) {
        this.occupied = occupied;
    }
}