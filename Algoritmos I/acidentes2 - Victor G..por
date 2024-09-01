/*Nome: Victor Gabriel Barbosa; 
 * Data: 29/08/2023
 * 
 * Descrição do problema: 
 * "Foi feita uma estatística em cinco cidades brasileiras para coletar dados sobre acidentes de trânsito.
 * Foram obtidos os seguintes dados:
 * O código da cidade;
 * O número de veículos de passeio;
 * O número de acidentes de trânsito com vítimas.
 * Deseja-se saber:
 * Qual é o maior e o menor índice de acidentes de trânsito e a que cidade pertencem;
 * Qual a média de veículos de passeios nas cinco cidades;
 * Qual a média de acidentes de trânsito nas cidades com menos de 2000 veículos de passeio."
Algorítimo que analisa os dados de veículos e acidentes de trânsito*/
programa
{
	inclua biblioteca Matematica
	funcao inicio()
	{real c1, v1, a1, c2, v2, a2, c3, v3, a3, c4, v4, a4, c5, v5, a5, s, x, m, c = 0.0, d = 0.0, h = 0.0, f = 0.0

	/*ENTRADA DOS VALORES*/
		escreva("Digite o código da cidade 1: ")
		leia(c1)
		escreva("Digite o número de veículos de passeio da cidade 1: ")
		leia(v1)
		escreva("Digite o número de acidentes de trânsito com vítimas da cidade 1: ")
		leia(a1)
		escreva("Digite o código da cidade 2: ")
		leia(c2)
		escreva("Digite o número de veículos de passeio cidade 2: ")
		leia(v2)
		escreva("Digite o número de acidentes de trânsito com vítimas da cidade 2: ")
		leia(a2)
		escreva("Digite o código da cidade 3: ")
		leia(c3)
		escreva("Digite o número de veículos de passeio da cidade 3: ")
		leia(v3)
		escreva("Digite o número de acidentes de trânsito com vítimas da cidade 3: ")
		leia(a3)
		escreva("Digite o código da cidade 4: ")
		leia(c4)
		escreva("Digite o número de veículos de passeio da cidade 4: ")
		leia(v4)
		escreva("Digite o número de acidentes de trânsito com vítimas da cidade 4: ")
		leia(a4)
		escreva("Digite o código da cidade 5: ")
		leia(c5)
		escreva("Digite o número de veículos de passeio da cidade 5: ")
		leia(v5)
		escreva("Digite o número de acidentes de trânsito com vítimas da cidade 5: ")
		leia(a5)
		
		/*ÍNDICE DE ACIDENTES:*/
		a1 = a1/v1
		a2 = a2/v2
		a3 = a3/v3
		a4 = a4/v4
		a5 = a5/v5

		/*MAIOR ÍNDICE:*/
		s = Matematica.maior_numero(a1, a2)
		s = Matematica.maior_numero(s, a3)
		s = Matematica.maior_numero(s, a4)
		s = Matematica.maior_numero(s, a5)

		/*CÓDIGO DA CIDADE:*/
		se(s == a1)
		{
		h = c1
		}
		senao se(s == a2)
		{
		h = c2
		}
		senao se(s == a3)
		{
		h = c3
		}
		senao se(s == a4)
		{
		h = c4
		}
		senao se(s == a5)
		{
		h = c5
		}

		/*MENOR ÍNDICE:*/
		x = Matematica.menor_numero(a1, a2)
		x = Matematica.menor_numero(x, a3)
		x = Matematica.menor_numero(x, a4)
		x = Matematica.menor_numero(x, a5)

		/*CÓDIGO DA CIDADE:*/
		se(x == a1)
		{
		f = c1
		}
		senao se(s == a2)
		{
		f = c2
		}
		senao se(s == a3)
		{
		f = c3
		}
		senao se(s == a4)
		{
		f = c4
		}
		senao se(s == a5)
		{
		f = c5
		}
		
		/*MÉDIA DE VEÍCULOS NAS CINCO CIDADES:*/
		m = (v1 + v2 + v3 + v4 + v5)/5

		/*RESPOSTA DA CIDADE COM O MENOR E O MAIOR ÍNDICE DE ACIDENTES E A MÉDIA DE VEÍCULOS DE PASSEIO:*/
		escreva("A cidade com o menor índice de acidentes é a cidade: ", f, " com: ", x, " acidentes", "\n", 
		"E a cidade com maior número de acidentes é a cidade: ", h, " com: ", s, " acidentes")
	     escreva("\n", "A média de veículos nas cinco cidades é: ", m)

	     /*MÉDIA DAS CIDADES COM MENOS DE 2000 ACIDENTES DE TRÃNSITO COM VÍTIMAS:*/
		se (v1 < 2000)
		{
		c = a1
		d = 1.0	
		}
		se (v2 < 2000)
		{
		c = c + a2
		d = d + 1.0
		}
		se (v3 < 2000)
		{
		c = c + a3
		d = d + 1.0
		}
		se (v4 < 2000)
		{
		c = c + a4
		d = d + 1.0
		}
		se (v5 < 2000)
		{
		c = c + a5
		d = d + 1.0
		}
		c = c/d 

		/*RESPOSTA DA MÉDIA DE VEÍCULOS NAS CIDADES COM MENOS DE 2000 VEÍCULOS DE PASSEIO:*/
		escreva("\n", "A média das cidades com menos de 2000 veículos de passeio é:", c)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 3183; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */