public class Pessoas {
  private String nome, sobrenome;
  public void setNome(String nome, String sobrenome) {
    this.nome = nome;
    this.sobrenome = sobrenome;
  }
  public String getNome() {
    return nome + " " + sobrenome;
  }
  public static void main(String[] args) {
    Pessoas p1 = new Pessoas();
    if (args.length > 1 && args[0].length() > 0 && args[1].length() > 0) {
      p1.setNome(args[0], args[1]);
      System.out.println(p1.getNome());
    }
    System.out.println("FIM");
  }
} 