programa
{
	
	funcao inicio()
	{inteiro num[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, lug[12] = {10, 8, 7, 14, 20, 8, 7, 13, 0, 9, 7, 14}, i, n, n1 = 0
	cadeia ori[12] = {"Brasil", "Canadá", "EUA", "China", "Japão", "Alemanha", "França", "Itália", "Portugal", "Caribe", "Rússia", "Egito"},
	des[12] = {"Egito", "Rússia", "Caribe", "Portugal", "Itália", "França", "Alemanha", "Japão", "China", "EUA", "Canadá", "Brasil"}
	caracter x = 'y'
	faca{
	para(i = 0; i < 12; i++){
	escreva(i+1, "° voo:\n", "N°: ", num[i], "\nLugares vagos: ", lug[i], "\nLocal de origem: ", ori[i], "\nDestino: ", des[i], "\n\n")
	}
	escreva("Digite qual o número do voo (Entre ", num[0], " e ", num[11], "): ")
	leia(n)
		se(n > 0 e n <= 12)
		{
			para(i = 0; i < 12; i++){
				se(n == num[i]){
					escreva("N°: ", num[i], "\nLugares vagos: ", lug[i], "\nLocal de origem: ", ori[i], "\nDestino: ", des[i], "\n\n")
					escreva("Para fazer a reserva digite 1 | Para voltar ao menu digite qualquer outro número: ")
					leia(n1)
						se(n1 != 1){
						escreva("Para sair do programa tecle 'x' | Para continuar tecle qualquer outra tecla: ")
						leia(x)
						}
							se(n1 == 1){
								se(lug[i] == 0){
								escreva("Infelizmente o voo não tem lugares vagos! Tente novamente em outro momento\n")
								n1--
								}	
									senao{
									escreva("O voo com origem do(a): ", ori[i], "\nCom destino a: ", des[i], "\nFoi reservado. Tenha uma boa viagem!")
									}
						}
				}
			}
		}
			senao{
			escreva("Número de voo não encontrado! Digite uma valor entre 0 e 12\n")
			}
	}enquanto (n1 != 1 e x != 'x')
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1195; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */