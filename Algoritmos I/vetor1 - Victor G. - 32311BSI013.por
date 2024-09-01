/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta em sala:
 * 1) Faça um programa que faça as operações de soma, subtração, multiplicação e divisão, pedindo a quantidade de números operados e a
 * operação desejada, usando vetor;
 * 2} Faça um programa que receba números do usuário e verifique qual o maior e o menor deles e mostre o maior e o menor deles ao 
 * usuário, usando vetor;
 * 3} Faça um program que receba uma quantidade qualquer de números e verifique quais deles são pares e quais são ímpares e mostre
 * ao usuário quais deles são pares e quais são ímpares, usando vetor.*/
programa
{
	
	funcao inicio()
	{inteiro vet[10], s = 0, n, m = 0, x = 0, y, w, z = 0, maior = 0, menor = 0, g, get[10], p, h, pet[10], j
	caracter op
	/*Laço condicional que irá pedir uma operação e se o usuário digitar uma operação diferente das previstas irá aparecer uma
	mensagem de erro e pedir novamente a operação desejada:*/
	faca
	{
	escreva("Digite a operação:", "\n", "Soma: '+'", "\n", "Subtração: '-'", "\n", "Multiplicação: '*'", "\n", "Divisão: '/'", "\n")
	leia(op)
		se(op != '+' e op != '-' e op != '*' e op != '/')
		{
		escreva("Erro! A operação digitada está incorreta", "\n")
		}
	}enquanto(op != '+' e op != '-' e op != '*' e op != '/')

	/*Laço condicional que irá pedir a quantidade de números a serem operados e caso o usuário digite um número negativo
	irá aparecer uma mensagem de erro e pedir novamente a quantidade esperada de números que serão operados:*/
	faca
	{
	escreva("Digite a quantidade de números a serem operados (Obs.: O número digitado tem que ser postivo e inteiro): ")
	leia(n) 
		se(n < 0)
		{
		escreva("Erro! O número digitado é negativo", "\n")
		}
	}enquanto(n < 0)
	
	/*Variáveis que armazenam quantos números serão utilizados no vetor:*/
	y = n
	w = n
	g = n
	h = n
	j = n
	
	se(op == '+') /*Condicional que irá realizar a operação de soma:*/
	{
		enquanto(n > 0) /*Condicional que irá repetir o laço até alcançar a quantidade de números a serem operados que foram
		mencionados pelo usuário*/
		{
			
			faca /*Laço condicional que irá pedir um número e caso o usuário digite um número negativo irá aparecer 
			uma mensagem de erro e pedir novamente um outro número:*/
			{
			escreva("Digite um número (Obs.: O número digitado não pode ser negativo e tem que ser inteiro: ")
			leia(vet[n])
			z = vet[n]
			se(z < 0)
			{
			escreva("Erro! O número digitado é negativo", "\n")
			}
			}enquanto(z < 0)
		s = vet[n] + s /*Acumulador da soma, que será utilizado como numerador para fazer a média aritmética*/
		n-- /*Acumulador do enquanto*/
		x++ /*Acumulador que será utilizado como denominador para fazer a média aritmética*/
		}
	m = s / x /*Operador da média aritmética*/
	escreva("O resultado da soma é: ", s, "\n")
	escreva("A média aritmética é: ", m)
	}
	senao se(op == '-') /*Condicional que irá realizar a operação de subtração:*/
	{
		enquanto(n > 0) /*Condicional que irá repetir o laço até alcançar a quantidade de números a serem operados que foram 
		mencionados pelo usuário*/
		{
			faca /*Laço condicional que irá pedir um número e caso o usuário digite um número negativo irá aparecer 
			uma mensagem de erro e pedir novamente um outro número:*/
			{
			escreva("Digite um número: ")
			leia(vet[n])
			z = vet[n]
				se(z < 0)
				{
				escreva("Erro! O número digitado é negativo", "\n")
				}
			}enquanto(z < 0)
		s = vet[n] - s  /*Acumulador da subtração*/ 
		n--
	}
	escreva("O resultado é: ", s)
	}
	senao se(op == '*') /*Condicional que irá realizar a operação de multiplicação:*/
	{
		enquanto(n > 0) /*Condicional que irá repetir o laço até alcançar a quantidade de números a serem operados que foram 
		mencionados pelo usuário*/
		{
			faca /*Laço condicional que irá pedir um número e caso o usuário digite um número negativo irá aparecer 
			uma mensagem de erro e pedir novamente um outro número:*/
			{
			escreva("Digite um número (Obs.: O número digitado não pode ser negativo e tem que ser inteiro: ")
			leia(vet[n])
			z = vet[n]
			se(z < 0)
			{
			escreva("Erro! O número digitado é negativo", "\n")
			}
			}enquanto(z < 0) 
		se(s == 0) /*Condicional que verifica se o acumulador da multiplicação é 0 */
		{
		s = vet[n] /*Acumulador da multiplicação caso ainda seja 0*/
		}
			senao /*Se o acumulador da multiplicação não é 0*/
			{
			s = vet[n] * s /*Acumulador da multiplicação*/
			}
			n-- /*Acumulador do enquanto*/
	}
	escreva("O resultado é: ", s)
	}
	senao se(op == '/') /*Condicional que irá realizar a operação de divisão:*/
	{
	enquanto(n > 0)
	{
		faca /*Laço condicional que irá pedir um número e caso o usuário digite um número negativo irá aparecer 
		uma mensagem de erro e pedir novamente um outro número:*/
		{
		escreva("Digite um número (Obs.: O número digitado não pode ser negativo, nem igual a 0 e tem que ser inteiro: ")
		leia(vet[n])
		z = vet[n]
			se(z < 0)
			{
			escreva("Erro! O número digitado é negativo")
			}
		}enquanto(z < 0)
	se(s == 0) /*Condicional que verifica se o acumulador da divisão é 0*/
	{
	s = vet[n]
	}
		senao /*Condicional que verifica se o acumulador da divisão não é 0*/
		{
		s = vet[n] / s
		}
		n-- /*Acumulador do enquanto*/
	}
	escreva("O resultado é: ", s)
	}
	enquanto(w > 0) /*Laço que irá armazenar um valor maior e um valor menor ao do vetor em outras variável*/
	{
	menor = vet[w] + 1
	maior = vet[w] - 1
	w-- /*Acumulador do enquanto*/
	}
	faca /*Laço que irá verificar e armazenar o menor e maior número digitado pelo usuário*/
	{
		se(vet[y] < menor) /*Condicional que verifica e armazena o menor número*/
		{
		menor = vet[y] 
		}
			se(vet[y] > maior) /*Condicional que verifica e armazena o maior número*/
			{
			maior = vet[y] 
			}
	y-- /*Acumulador do faca enquanto*/
	}enquanto(y > 0)
	escreva("\n", "O menor número é: ", menor)
	escreva("\n", "O maior número é: ", maior, "\n")
	enquanto(h > 0) /*Laço que irá verificar e armazenar os números pares e ímpares em vetores*/
	{
		p = vet[h] /*Variável que armazena o valor do vetor*/
		se(p % 2 == 0) /*Condicional que verifica se o número é par*/
		{
		get[h] = p
		}
		senao /*Condicional que verifica se o número é impar*/
		{
		pet[h] = p
		}
	h--
	}
	enquanto(j > 0) /*Laço que irá mostrar os números pares e ímpares*/
	{
		se(get[j] != 0 e pet[j] != 0)
		{
		escreva("O número: ", get[j], " é par", "\n", "O número: ", pet[j], " é impar", "\n")
		}
	j-- /*Acumulador do enquanto*/
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 908; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */