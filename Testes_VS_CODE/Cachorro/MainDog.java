import java.util.Scanner;

public class MainDog {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    GoodDog[] dogs = new GoodDog[5]; // Assuming GoodDog has a default constructor
    GoodDog dogao = new GoodDog("Márcio", 10);
    GoodDog doginho = new GoodDog("Márcio", 10);

    if (doginho.equals(dogao) == true) {
      System.out.println("Dogs are equal");
    } else {
      System.out.println("Dogs are not equal");
    }

    for (int i = 0; i < dogs.length; i++) {
      System.out.print("Enter name for Dog " + (i + 1) + ": ");

      String name = scanner.nextLine();
      System.out.print("Enter size for Dog " + (i + 1) + ": ");
      int size = scanner.nextInt();
      dogs[i] = new GoodDog(name, size);
      System.out.println("Dog " + (i + 1) + " created successfully!");
      scanner.nextLine();
    }
    for (GoodDog dog : dogs) {
      dog.bark();
      System.out.println("Size: " + dog.getSize());
    }
    scanner.close();
  }
}