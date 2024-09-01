public class Main {
    public static void main(String[] args) {
        ElectricGuitar guitarra = new ElectricGuitar();
        guitarra.setBrand("Gibson");
        System.out.println("Marca da guitarra: " + guitarra.getBrand());
        guitarra.setNumOfPickups(6);
        System.out.println("Número de pickups: " + guitarra.getNumOfPickups());
        guitarra.setRockStarUsesIt(true);
        System.out.println("Rock Star utiliza a guitarra: " + guitarra.isRockStarUsesIt());
    }
}
