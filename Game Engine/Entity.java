public abstract class Entity {
    protected int x, y;

    public Entity(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public abstract void update();

    public abstract void render(Graphics g);
}

public class Building extends Entity {
    private String type;

    public Building(int x, int y, String type) {
        super(x, y);
        this.type = type;
    }

    @Override
    public void update() {
        // Update building state (e.g., resource production)
    }

    @Override
    public void render(Graphics g) {
        // Render the building on the map
        g.setColor(Color.GRAY);
        g.fillRect(x, y, 50, 50);
    }
}