package Testes_VS_CODE.Jogador;

public class MainPlayer {
    public static void main(String[] args) {
        Player player1 = new Player("Mares", 10, 100);
        System.out.println("Nome: " + player1.getNome());
        System.out.println("Ataque: " + player1.getAtaque());
        System.out.println("Vida: " + player1.getVida());    
        player1.atacar(player1);
        System.out.println("Vida após ataque: " + player1.getVida());
        player1.receberDano(20);
        System.out.println("Vida após receber dano: " + player1.getVida());
    }     
}
