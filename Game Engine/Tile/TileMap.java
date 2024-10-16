public class TileMap {
    private Tile[][] tiles;
    private int rows, cols;
    private int tileWidth, tileHeight;

    public TileMap(int rows, int cols, int tileWidth, int tileHeight) {
        this.rows = rows;
        this.cols = cols;
        this.tileWidth = tileWidth;
        this.tileHeight = tileHeight;

        tiles = new Tile[rows][cols];
        generateMap();
    }

    // Generates the grid and assigns a default color to each tile (e.g., grass)
    private void generateMap() {
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                tiles[y][x] = new Tile(x * tileWidth, y * tileHeight, tileWidth, tileHeight, Color.GREEN);
            }
        }
    }

    // Renders the entire tile map
    public void render(Graphics g) {
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                tiles[y][x].render(g);
            }
        }
    }

    // Returns the tile at a specific position
    public Tile getTileAt(int row, int col) {
        return tiles[row][col];
    }

    // Checks if a specific tile is occupied
    public boolean isTileOccupied(int row, int col) {
        return tiles[row][col].isOccupied();
    }

    // Set a tile as occupied
    public void occupyTile(int row, int col) {
        tiles[row][col].setOccupied(true);
    }
}