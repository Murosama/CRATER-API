public class GameEngine implements Runnable {
    private boolean running;
    private Thread gameThread;

    private final int FPS = 60;
    private final double timePerTick = 1_000_000_000.0 / FPS;

    public GameEngine() {
        running = false;
    }

    public synchronized void start() {
        if (running) return;
        running = true;
        gameThread = new Thread(this);
        gameThread.start();
    }

    public synchronized void stop() {
        if (!running) return;
        running = false;
        try {
            gameThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        long lastTime = System.nanoTime();
        double delta = 0;

        while (running) {
            long now = System.nanoTime();
            delta += (now - lastTime) / timePerTick;
            lastTime = now;

            if (delta >= 1) {
                update();
                render();
                delta--;
            }
        }

        stop();
    }

    private void update() {
        // Update game logic, physics, etc.
    }

    private void render() {
        // Render game objects
    }
}
