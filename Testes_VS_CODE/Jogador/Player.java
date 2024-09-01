package Testes_VS_CODE.Jogador;

public class Player {
    private String nome;
    private int ataque, vida;

    public Player(String nome, int ataque, int vida) {
        if (nome == null) {
            throw new IllegalArgumentException("Nome inválido! Não pode ser nulo!");
        } else {
            this.nome = nome;
        }
        if (ataque <= 0) {
            throw new IllegalArgumentException("Ataque inválido! Não pode ser zero ou negativo!");
        } else {
            this.ataque = ataque;
        }
        if (vida <= 0) {
            throw new IllegalArgumentException("Vida inválida! Não pode ser zero ou negativo!");
        } else {
            this.vida = vida;
        }      
    }

    public String getNome() {
        return nome;
    }

    public int getAtaque() {
        return ataque;
    }

    public int getVida() {
        return vida;
    }

    public void atacar(Player player) {
        if (player == null) {
            throw new IllegalArgumentException("Jogador inválido! Não pode ser nulo!");
        } else {
            player.vida -= ataque;
            System.out.printf("%s atacou %s e causou %d de dano.\n", nome, player.nome, ataque);
        }
    }

    public void receberDano(int dano) {
        if (dano <= 0) {
            throw new IllegalArgumentException("Dano inválido! Não pode ser zero ou negativo!");
        } else {
            vida -= dano;
            System.out.printf("%s recebeu %d de dano.\n", nome, dano);
            if (vida <= 0) {
                System.out.printf("%s morreu!\n", nome);
            }
        }
    }
}   
