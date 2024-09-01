typedef struct lista Lista;

Lista* Cria_lista(void); /* Cria a lista */
Lista* Libera_lista(Lista* Ptl); /* Libera a lista */
Lista* Insere_elem(Lista* Ptl, int elem); /* Insere um elemento no final da lista */
Lista* Remove_elem(Lista* Ptl, int elem); /* Remove um elemento da lista */
Lista* Remove_elem_mov(Lista* Ptl, int elem); /* Remove um elemento da lista */
int Consulta_nodo(Lista* Ptl, int pos, int* info); /* Retorna o elemento da posição pos */
int Tamanho_lista(Lista* Ptl); /* Retorna o tamanho da lista */
int E_cheia(Lista* Ptl); /* Verifica se a lista está cheia */
int E_vazia(Lista* Ptl); /* Verifica se a lista está vazia */
void limpa_buffer(); /* Limpa o buffer do terminal */
int exibe_lista(); /* Exibe a lista */
int grava_lista(Lista* Ptl, char* nome_arqv); /* Grava a lista em um arquivo */
