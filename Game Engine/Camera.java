public class Camera {
    private float xOffset, yOffset;
    private int worldWidth, worldHeight;
    private int screenWidth, screenHeight;

    public Camera(float xOffset, float yOffset, int worldWidth, int worldHeight, int screenWidth, int screenHeight) {
        this.xOffset = xOffset;
        this.yOffset = yOffset;
        this.worldWidth = worldWidth;
        this.worldHeight = worldHeight;
        this.screenWidth = screenWidth;
        this.screenHeight = screenHeight;
    }

    public void move(float xAmt, float yAmt) {
        xOffset += xAmt;
        yOffset += yAmt;
        clampCamera();
    }

    // Ensures the camera doesn't go out of the game world bounds
    private void clampCamera() {
        if (xOffset < 0) xOffset = 0;
        if (yOffset < 0) yOffset = 0;
        if (xOffset > worldWidth - screenWidth) xOffset = worldWidth - screenWidth;
        if (yOffset > worldHeight - screenHeight) yOffset = worldHeight - screenHeight;
    }

    // Getters for camera offsets
    public float getxOffset() {
        return xOffset;
    }

    public float getyOffset() {
        return yOffset;
    }

    public void setxOffset(float xOffset) {
        this.xOffset = xOffset;
    }

    public void setyOffset(float yOffset) {
        this.yOffset = yOffset;
    }
}
