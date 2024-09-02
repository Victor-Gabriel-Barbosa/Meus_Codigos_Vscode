import java.util.Scanner;
import java.util.Arrays;

public class Main_p1 {
  public static void main(String[] args) {
    LimparTela.cls();
    Scanner scanner = new Scanner(System.in);

    Notas[] notas = new Notas[5];
    System.out.print("Digite o nome do aluno: ");
    String nomeAluno = scanner.nextLine();
    System.out.print("Digite as notas do aluno (separadas por espaço): ");
    double[] notasArray = Arrays.stream(scanner.nextLine().split(" ")).mapToDouble(Double::parseDouble).toArray();
    notas[0] = new Notas(nomeAluno, notasArray);
    scanner.close();


    System.out.println("Aluno: " + notas[0].getAluno());
    System.out.println("Média: " + notas[0].getMedia());
    System.out.println("Nota Maior: " + notas[0].getNotaMaior());
    System.out.println("Nota Menor: " + notas[0].getNotaMenor());
    
    notas[0].setNotas(new double[]{8.5, 9.0, 7.5, 8.7, 9.5});
    System.out.println("Média Atualizada: " + notas[0].getMedia());

    notas[0].setAluno("Maria");
    System.out.println("Aluno Atualizado: " + notas[0].getAluno());
    notas[0].getNotas()[3] = 6.0;
    System.out.println("Nota Atualizada na posição 3: " + notas[0].getNotas()[3]);
    notas[0].getNotas()[4] = 10.0;
    System.out.println("Nota Atualizada na posição 4: " + notas[0].getNotas()[4]);
  }
}