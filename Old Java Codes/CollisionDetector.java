public class CollisionDetector {
    public boolean isColliding(Entity entity1, Entity entity2) {
        int e1x = entity1.getX(), e1y = entity1.getY();
        int e2x = entity2.getX(), e2y = entity2.getY();
        return (e1x < e2x + 50 && e1x + 50 > e2x && e1y < e2y + 50 && e1y + 50 > e2y);
    }
}