/*Nome: Victor Gabriel Barbosa; 
 * Data: 29/08/2023
 * Descrição do problema: 
 * "Em um campeonato de futebol existem cinco equipes de onze jogadores. 
 * Faça um programa que receba a idade, a altura e o peso de cada jogador e calcule e mostre:
 * A quantidade de jogadores com menos de 18 anos;
 * A média das idades de cada time;
 * A média das alturas dos jogadores do campeonato;
 * A porcentagem de jogadores com mais de 80 kg.
Algorítimo que faz uma análise das características de jogadores de um campeonato"*/
programa
{
	
	funcao inicio()
	{real n1, n2, n3, s = 0.0, x = 0.0, y = 0.0, a = 0.0, c = 0.0, d = 0.0
	para(inteiro z = 1; z <= 5; z++)
	{
	para(inteiro i = 1; i <= 11; i++)
	{
	     escreva("Digite a idade do jogador: ")
		leia(n1)
		escreva("Digite a altura do jogador: ")
		leia(n2)
		escreva("Digite o peso do jogador: ")
		leia(n3)
		se(n1 < 18)
		{
		/*Soma de jogadores com mais de 18 anos*/
		s = s + 1	
		}
		se(n3 > 80)
		{
		/*Soma de jogadores com mais de 80 kg*/
		c = c + 1
		}
		y = y + n1 /*Soma das idades de todos os jogadores*/
		x = x + 1 /*Soma do número de jogadores*/
		a = a + n2 /*Soma das alturas de todos os jogadores*/
	}
	     y = y/x /*Média das idades dos jogadores de cada time*/
	     escreva("A média das idades dos jogadores desse time é: ", y, "\n")
	     y = 0.0
	}
	     c = (c/55)*100 /*Porcentagem de jogadores com mais de 80 kg*/
	     a = a/x /*Média das alturas dos jogadores do campeonato*/
		escreva("A quantidade de jogadores com menos de 18 anos é: ", s, "\n")
		escreva("A média das alturas dos jogadores do campeonato é: ", a, "\n")
		escreva("A porcentagem de jogadores com mais de 80 kg em todo campeonato é: ", c, "%")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1077; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */