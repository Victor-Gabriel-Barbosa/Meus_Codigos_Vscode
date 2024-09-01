class ElectricGuitar {
    private String brand;
    private int numOfPickups;
    private boolean rockStarUsesIt;

    String getBrand() {
        return brand;
    }

    void setBrand(String brand) {
        this.brand = brand;
    }

    int getNumOfPickups() {
        return numOfPickups;
    }

    void setNumOfPickups(int numOfPickups) {
        this.numOfPickups = numOfPickups;
    }

    boolean isRockStarUsesIt() {
        return rockStarUsesIt;
    }
    
    void setRockStarUsesIt(boolean rockStarUsesIt) {
        this.rockStarUsesIt = rockStarUsesIt;
    }
}