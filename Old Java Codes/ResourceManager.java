public class ResourceManager {
    private int money;
    private int materials;

    public ResourceManager() {
        this.money = 1000;
        this.materials = 500;
    }

    public void update() {
        // Update resources based on buildings
        money += 10;  // Example of a basic resource increase
    }

    public int getMoney() {
        return money;
    }

    public int getMaterials() {
        return materials;
    }

    public void spendMoney(int amount) {
        if (money >= amount) {
            money -= amount;
        }
    }

    public void useMaterials(int amount) {
        if (materials >= amount) {
            materials -= amount;
        }
    }
