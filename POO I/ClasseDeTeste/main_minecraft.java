import java.util.Scanner;

public class main_minecraft {
  public static void main(String[] args) {
    // Criando um objeto da classe bloco
    Scanner scanner = new Scanner(System.in);
    Bloco[] blocos = new Bloco[5];
    blocos[0] = new Bloco(1, "Ar", false);
    blocos[1] = new Bloco(2, "Terra", true);
    blocos[2] = new Bloco(3, "Agua", false);
    blocos[3] = new Bloco(4, "Neve", true);
    blocos[4] = new Bloco(5, "Pedra", true);
    boolean loop = true;
    int idAlterar = -1;
    String caixa_opcoes = "";
    for (int i = 0; i < blocos.length; i++) {
      caixa_opcoes += ((blocos[i].isSolido() == true) ? "[Solido]" : "[Vazio]") + " " + blocos[i].getNome() + " " + blocos[i].getID() + "\n";
    }
    while (loop) {
      System.out.println("--------------------------------");
      System.out.print(caixa_opcoes);
      System.out.println("--------------------------------");
      System.out.print("Digite o ID do bloco para alterar seu nome: ");
      idAlterar = scanner.nextInt();
      for (int i = 0; i < blocos.length; i++) {
        if (blocos[i].getID() == idAlterar) {
          loop = false;
          break;
        }
      }
      if (loop) {
        System.out.println("ID invalido!");
      }
    }

    for (int i = 0; i < blocos.length; i++) {
      if (blocos[i].getID() == idAlterar) {
        System.out.print("Digite o novo nome do bloco: ");
      String nomeAlterar = scanner.next();
        blocos[i].setNome(nomeAlterar);
        break;
      }
    }
    
    for (int i = 0; i < blocos.length; i++) {
System.out.println(((blocos[i].isSolido() == true) ? "[Solido]" : "[Vazio]") + " " + blocos[i].getNome() + " " + blocos[i].getID());
    }
    
    scanner.close();
  }
}
