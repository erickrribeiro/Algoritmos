/*A estrutura de dados Pilha implementada em linguagem C.
Baseado a aula: https://youtu.be/QcOepttae38?si=MvEIrhLHUye1LAly*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;    
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void create(Stack *pStack) {
    pStack->top = NULL;
}

void push(Stack *pStack, int value) {
    /*Insere um novo elemento no inicio da Pilha.*/
    Node *aux;
    aux = (Node*) malloc(sizeof(Node));
    aux->value = value;
    aux->next = pStack->top;
    pStack->top = aux; 
}

void show(Stack *pStack) {
    Node *aux;
    aux = pStack->top;
    while (aux != NULL) {
        printf("[%d]->", aux->value);
        aux = aux->next;        
    }
    printf("NULL\n");
}

int pop(Stack *pStack) {
    Node *aux, *tmp;
    int response;
    if (pStack->top == NULL) {
        printf("Stack is empty!\n");
        exit(1);        
    } 
    
    tmp = pStack->top;
    response = tmp->value;
    pStack->top = tmp->next;
    free(tmp);

    return response;
}

int main() {
    Stack s1;
    create(&s1);
    push(&s1, 12);
    push(&s1, 2);
    push(&s1, 9);
    push(&s1, 95);
    push(&s1, 94);
    show(&s1);
        
    printf("pop() = %d\n", pop(&s1));
    show(&s1);

    printf("pop() = %d\n", pop(&s1));
    show(&s1);

    printf("pop() = %d\n", pop(&s1));
    show(&s1);

    printf("pop() = %d\n", pop(&s1));
    show(&s1);

    push(&s1, 94);
    show(&s1);

    printf("pop() = %d\n", pop(&s1));
    show(&s1);

    printf("pop() = %d\n", pop(&s1));
    show(&s1);

    printf("pop() = %d\n", pop(&s1));
    show(&s1);
}
