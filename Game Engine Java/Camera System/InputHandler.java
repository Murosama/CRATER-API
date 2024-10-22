package Camera System;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class InputHandler extends KeyAdapter {
    private Camera camera;
    private final float speed = 5f;  // Camera movement speed

    public InputHandler(Camera camera) {
        this.camera = camera;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_W:
            case KeyEvent.VK_UP:
                camera.move(0, -speed);  // Move camera up
                break;
            case KeyEvent.VK_S:
            case KeyEvent.VK_DOWN:
                camera.move(0, speed);  // Move camera down
                break;
            case KeyEvent.VK_A:
            case KeyEvent.VK_LEFT:
                camera.move(-speed, 0);  // Move camera left
                break;
            case KeyEvent.VK_D:
            case KeyEvent.VK_RIGHT:
                camera.move(speed, 0);  // Move camera right
                break;
        }
    }
}
