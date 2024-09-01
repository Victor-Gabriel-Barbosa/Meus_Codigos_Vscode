programa 
{
  funcao inicio()
  {
    inteiro idade = 0, opiniao = 0, qtd_regular = 0, total_espectadores = 15, i
    real media_idades_otimo, soma_idades_otimo = 0.0, qtd_bom = 0.0, porcentagem_bom = 0.0
    para (i = 1; i<= total_espectadores; i++) {
      escreva ("Digite a idade do espectador ", i, ": ")
      leia (idade)
      escreva ("Digite a opinião em relação ao filme (3 - Ótimo, 2 - Bom, 1 - Regular): ")
      leia (opiniao)
      se (opiniao == 3) // Calcular a média das idades das pessoas que responderam "Ótimo" (opiniao == 3)
          soma_idades_otimo += idade
      senao se (opiniao == 1)  // Contar a quantidade de pessoas que responderam "Regular" (opiniao == 1)
        qtd_regular++
      senao se (opiniao == 2) // Contar a quantidade de pessoas que responderam "Bom" (opiniao == 2)
         qtd_bom++
      senao{
        escreva ("Opinião Inválida! \n")
        pare
      }
        
    }
    // Calcular a média das idades das pessoas que responderam "Ótimo"
    media_idades_otimo = soma_idades_otimo / qtd_bom

    // Calcular a porcentagem de pessoas que responderam "Bom" entre todos os espectadores
    porcentagem_bom = (qtd_bom * 100) / total_espectadores

    // Exibir os resultados
    escreva("Média das idades das pessoas que responderam Ótimo: ", media_idades_otimo, "\n")
    escreva("Quantidade de pessoas que responderam Regular: ", qtd_regular, "\n")
    escreva("Porcentagem de pessoas que responderam Bom: ", porcentagem_bom, "\n")
  }
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 32; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */