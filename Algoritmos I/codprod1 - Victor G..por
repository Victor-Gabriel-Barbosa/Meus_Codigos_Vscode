/*
 * 9) - Faça um programa que receba: o código de um produto, a quantidade de produtos comprados.
Calcule e mostre: 
a) Preço unitário do produto
b) Preço total comprado
c) Desconto
d) Preço final da compra (depois do desconto) */
programa
{
	
	funcao inicio()
	{real c, q, v = 0.00, s = 0.00, x = 0.00, y = 0.00
		escreva("Digite um código de produto entre 1 e 40: ")
		leia(c)
		escreva("Digite a quantidade de produtos comprados: ")
		leia(q)
		se(c >= 1 e c <= 40)
		{
		se(c >= 1 e c <= 10)
		{
		v = 10.00
		s = v * q	
		x = s
		}
		senao se(c >= 11 e c <= 20)
		{
		v = 15.00
		s = v * q	
		x = s	
		}
		senao se(c >= 21 e c <= 30)
		{
		v = 20.00
		s = v * q	
		x = s	
		}
		senao se(c >= 31 e c <= 40)
		{
		v = 30.00
		s = v * q	
		x = s	
		}
		se(s < 250)
		{
		y = 0.05
		s = -(s * y) + s
		y = y * 100	
		}
		senao se(s >= 250.00 e s <= 500.00)
		{
		y = 0.10
		s = -(s * y) + s	
		y = y * 100
		}
		senao se(s > 500.00)
		{
		y = 0.15
		s = -(s * y) + s 
		y = y * 100	
		}
		escreva("O preço unitário é: R$", v, "\n", "O preço total comprado é: R$", x, "\n", "O desconto foi de: ", y, "%", "\n", "O preço final da compra é: R$", s)
	}
	senao
		{
			escreva("ERRO! Código digitado não encontrado. Por gentileza digite um código entre 1 e 40")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 513; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */