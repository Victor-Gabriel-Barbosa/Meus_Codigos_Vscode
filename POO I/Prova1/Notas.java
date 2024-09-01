public class Notas {
  private String aluno;
  private double[] notas;

  public Notas(String aluno, double[] notas) {
    this.aluno = aluno;
    this.notas = notas;
  }

  public double getMedia() {
    double soma = 0;
    for (double nota : notas) {
      soma += nota;
    }
    return soma / notas.length;
  }

  public double getNotaMaior() {
    double maiorNota = Double.MIN_VALUE;
    for (double nota : notas) {
      if (nota > maiorNota) {
        maiorNota = nota;
      }
    }
    return maiorNota;
  }

  public double getNotaMenor() {
    double menorNota = Double.MAX_VALUE;
    for (double nota : notas) {
      if (nota < menorNota) {
        menorNota = nota;
      }
    }
    return menorNota;
  }

  public void setAluno(String aluno) {
    this.aluno = aluno;
  }

  public void setNotas(double[] notas) {
    for (int i = 0; i < notas.length; i++) {
      if (notas[i] < 0 || notas[i] > 10) {
        System.out.println("Nota inválida na posição " + i + ". Ignorando essa nota!");
        continue;
      }
    }
    this.notas = notas;
  }

  public String getAluno() {
    if (aluno == null || aluno.isEmpty()) {
      return "Nome do aluno não informado";
    } 
    return aluno;
  }

  public double[] getNotas() {
    return notas;
  }
}
