class Bloco {
  private int ID;
  private String nome;
  private boolean solido;


  public Bloco(int ID, String nome, boolean solido) {
    this.nome = nome;
    this.ID = ID;
    this.solido = solido;
  }

  public boolean setNome(String nome) {
    if (nome == null) return false;
    this.nome = nome;
    return true;
  }


  public boolean setID(int ID) {
    if (ID < 0) return false;
    this.ID = ID;
    return true;
  }

  public void setSolido(boolean solido) {
    this.solido = solido;
  }


  public int getID() {
    return ID;
  }

  public String getNome() {
    return nome;
  }

  public boolean isSolido() {
    return solido;
  }

  
}