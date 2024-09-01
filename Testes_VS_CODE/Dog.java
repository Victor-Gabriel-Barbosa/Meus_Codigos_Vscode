import java.util.Scanner;

public class Dog {
  private String name;
  private int age;

  public Dog(String name, int age) {
    this.name = name;
    this.age = age;
  }

  public void bark() {
    System.out.println(name + " barks!");
  }

  public void play() {
    System.out.println(name + " is playing!");
  }

  public void eat() {
    System.out.println(name + " is eating!");
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String dogName;
    int dogAge;
    Dog[] myDogs = new Dog[3];

    for (int i = 0; i < myDogs.length; i++) {
      System.out.println("Digite um nome para o cachorro:");
      dogName = scanner.nextLine();
      System.out.println("Digite a idade do cachorro:");
      dogAge = scanner.nextInt();
      scanner.nextLine();
      myDogs[i] = new Dog(dogName, dogAge);
    }

    myDogs[0].bark();
    myDogs[1].play();
    myDogs[2].eat();

    scanner.close();
  }
}