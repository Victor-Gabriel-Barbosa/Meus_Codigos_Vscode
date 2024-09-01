#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* novo_no(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao final da lista
void append(struct Node** head, int data) {
    struct Node* newNode = novo_no(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Aponta para si mesmo
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head; // Faz o novo nó apontar para o head
    }
}

// Função para exibir a lista
void display(struct Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(circular)\n");
}

// Função para deletar um nó com um valor específico
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *current = *head, *prev = NULL;

    // Se o nó a ser deletado é o head
    if (current->data == key) {
        while (current->next != *head) {
            current = current->next;
        }
        if (current == *head) { // Se há apenas um nó
            free(*head);
            *head = NULL;
        } else {
            current->next = (*head)->next;
            free(*head);
            *head = current->next;
        }
        return;
    }

    // Procura o nó a ser deletado
    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }

    // Se o nó não foi encontrado
    if (current->data != key) {
        printf("Nó com valor %d não encontrado.\n", key);
        return;
    }

    // Desconecta o nó
    prev->next = current->next;
    free(current);
}

// Função para buscar um nó com um valor específico
int search(struct Node* head, int key) {
    if (head == NULL) return 0;
    struct Node* current = head;
    do {
        if (current->data == key) {
            return 1; // Encontrado
        }
        current = current->next;
    } while (current != head);
    return 0; // Não encontrado
}

// Função principal para testar a lista encadeada circular
int main() {
    struct Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    display(head); // Saída: 1 -> 2 -> 3 -> (circular)

    printf("Buscando 2: %s\n", search(head, 2) ? "Encontrado" : "Não encontrado"); // Saída: Encontrado
    printf("Buscando 4: %s\n", search(head, 4) ? "Encontrado" : "Não encontrado"); // Saída: Não encontrado
    printf("Buscando 5: %s\n", search(head, 5) ? "Encontrado" : "Não encontrado"); // Saída: Não encontrado

    deleteNode(&head, 2);
    display(head); // Saída: 1 -> 3 -> (circular)
    printf("Teste: %s\n", search(head, 2) ? "Encontrado" : "Não encontrado"); // Saída: Não encontrado

    return 0; 
}