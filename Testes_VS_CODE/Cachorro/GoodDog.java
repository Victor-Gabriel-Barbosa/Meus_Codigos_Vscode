class GoodDog {
  private String name;
  private int size;

  GoodDog(String name, int size) {
    this.name = name;
    this.size = size;
  }

  public int getSize() {
    return size;
  }

  public void setSize(int size) {
    if (size < 0 || size > 10) {
      System.out.println("Tamanho inválido!");
      return;
    }
    this.size = size;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    if (name == null) {
      System.out.println("Nome inválido!");
      return;
    }
    this.name = name;
  }

  void bark() {
    System.out.println(name + " says Woof!");
    if (size > 5) {
      System.out.println("The dog is big.");
    } else {
      System.out.println("The dog is small.");
    }
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null || getClass() != obj.getClass()) {
      return false;
    }
    GoodDog other = (GoodDog) obj;
    return name.equals(other.name) && size == other.size;
  }
}
