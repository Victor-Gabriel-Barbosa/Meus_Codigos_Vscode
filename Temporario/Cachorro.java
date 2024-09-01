public class Cachorro {
   public String nome;
   public void latir() {
      System.out.printf("%s: Au au!\n", nome);
   }
   public static void main(String[] var0) {
      Cachorro c1 = new Cachorro();
      Cachorro c2 = new Cachorro();
      c1.nome = "Marlon";
      c2.nome = "Hex";
      c1.latir();
      c2.latir();
   }
}