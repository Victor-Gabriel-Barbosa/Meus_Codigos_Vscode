import java.util.Scanner;

public class LimparTela {
  public static void limpar(String mensagem) {
    // Exibe a mensagem e espera o usuário apertar Enter
    System.out.print(mensagem);
    Scanner scanner = new Scanner(System.in);
    scanner.nextLine();
    
    // ANSI escape code para limpar a tela
    System.out.print("\033[H\033[2J");
    System.out.flush();
  }
}
