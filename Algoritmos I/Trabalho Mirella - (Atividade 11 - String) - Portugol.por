programa
{
	inclua biblioteca Tipos // Inclui a biblioteca de tipos de dados
	inclua biblioteca Texto // Inclui a biblioteca de manipulação de texto

	funcao inicio()
	{
		cadeia fr1, fr2[10] // Declara duas variáveis de string, fr1 para a frase e fr2 para as palavras
		caracter pl // Declara uma variável de caractere para armazenar cada caractere da frase
		inteiro i, j, qp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, c = 1 // Declara variáveis inteiras para loops e contagem
		
		// Inicializa cada elemento de fr2 com uma string vazia 
		para(i = 0; i < 10; i++){
			fr2[i] = ""
		}

		escreva("Digite uma frase: ") // Solicita ao usuário que digite uma frase
		leia(fr1) // Lê a frase do usuário

		// Loop para percorrer cada caractere da frase
		para(i = 0; i < Texto.numero_caracteres(fr1); i++){
			pl = Texto.obter_caracter(Texto.caixa_baixa(fr1), i) // Obtém o caractere atual da frase
			se(pl != ' '){ // Se o caractere não for um espaço em branco
				fr2[c] = fr2[c] + Tipos.caracter_para_cadeia(pl) // Adiciona o caractere à palavra atual	
			}
			senao se (pl == ' '){ // Se o caractere for um espaço em branco
				c++ // Passa para a próxima palavra
			}
			
		}

		// Loop para contar a frequência de cada palavra na frase
		para(i = 1; i <= c; i++){
			para(j = 1; j <= c; j++){
				se(fr2[i] == fr2[j]){ // Se as palavras forem iguais
					qp[i]++	// Incrementa a contagem da palavra atual
				}
			}
		}

		// Loop para imprimir a frequência de cada palavra na frase
		para(i = 1; i <= c; i++){
			escreva("A quantidade de vezes que a ", i, "ª palavra: (", fr2[i], ") aparece na frase é: ", qp[i], "\n")
		}
	}
}


/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1631; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */