public class Main_p1 {
  public static void main(String[] args) {
    Notas notas = new Notas("João", new double[]{8.5, 9.0, 7.5, 8.7});
    System.out.println("Aluno: " + notas.getAluno());
    System.out.println("Média: " + notas.getMedia());
    System.out.println("Nota Maior: " + notas.getNotaMaior());
    System.out.println("Nota Menor: " + notas.getNotaMenor());
    
    notas.setNotas(new double[]{8.5, 9.0, 7.5, 8.7, 9.5});
    System.out.println("Média Atualizada: " + notas.getMedia());

    notas.setAluno("Maria");
    System.out.println("Aluno Atualizado: " + notas.getAluno());
    notas.getNotas()[3] = 6.0;
    System.out.println("Nota Atualizada na posição 3: " + notas.getNotas()[3]);
    notas.getNotas()[4] = 10.0;
    System.out.println("Nota Atualizada na posição 4: " + notas.getNotas()[4]);
  }
}