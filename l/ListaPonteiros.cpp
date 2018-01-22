#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int value;
    item *next;
}Item;

typedef struct list{
    Item *begin;
    Item *end;
    unsigned int size;
}List;

List* init(){
    List *l = (List*) malloc(sizeof(List));
    l->begin = l->end = NULL;
    l->size = 0;

    return l;
}

bool empty(List *l){
    return (*l).begin == NULL;
}

void push_back(Item *i, List *l){
    printf("Insert element at the end [Item:%d]\n", (*i).value);

    if(empty(l)){
        (*l).begin = i;
        (*l).end = (*l).begin;
    } else{
        (*l).end->next = i;
        (*l).end = i;
    }

    (*i).next = NULL;
    (*l).size += 1;
}

void push_front(Item *i, List *l){
    printf("Insert element at the front [Item:%d]\n", (*i).value);
    if(empty(l)){
        (*l).begin = i;
        (*l).end = (*l).begin;
    }else{
        i->next = (*l).begin;
        (*l).begin = i;
    }

    (*l).size += 1;
}

void insert(int position, Item *i, List *l){
    Item *aux;

    if(empty(l) || position > (*l).size){
        printf("Erro: Lista vazia ou posicao nao existe!\n");
    } else{
        printf("Insert element at the position %d [Item:%d]\n", position, (*i).value);

        if(position == 0){
            push_front(i, l);
        }else if(position == (*l).size){
            push_back(i, l);
        }else{
            position -= 1;

            aux = (*l).begin;

            while (position--){
                aux = aux->next;
            }

            i->next = aux->next;
            aux->next = i;

            (*l).size += 1;
        }
    }
}

int pop_front(List *l){

    if(empty(l)){
        printf("Erro: Lista está vazia!\n");
    }else{
        int temp = (*l).begin->value;

        (*l).begin = (*l).begin->next;
        (*l).size -= 1;
        printf("Removing element at the front.[Item:%d]\n", temp);

    }

}

int pop_back(List *l){
    Item *aux = NULL;
    if(empty(l)){
        printf("Erro: Lista está vazia!\n");
    } else{

        aux = (*l).begin;
        while ((*aux).next != (*l).end){
            aux = (*aux).next;
        }

        int temp  = (*aux).next->value;

        (*l).end    = aux;
        (*l).size  -= 1;
        (*aux).next = NULL;

        printf("Removing element at the end.[Item:%d]\n", temp);

        return temp;
    }

    return -1;
}

int remove(int position, List *l){
    Item *aux;
    if(empty(l) || position > (*l).size){
        printf("Erro: Lista vazia ou posicao nao existe!\n");
    } else{

        if(position == 0){
            pop_front(l);
        }else if(position == (*l).size){
            pop_back(l);
        }else{
            printf("Removing element at the position %d ", position );
            position -= 1;

            aux = (*l).begin;

            while (position--){
                aux = aux->next;
            }

            int temp = (*aux).next->value;
            (*aux).next = aux->next->next;

            (*l).size += 1;

            printf("[Item:%d]\n", temp);
        }
    }
}

void show(List *l){
    Item *aux;
    aux = (*l).begin;
    while(aux != NULL){
        printf("[Item:%d]\n", (*aux).value);
        aux = (*aux).next;
    }
}

int main(int argc, char const *argv[]){
    List *l;
    Item x1;
    x1.value = 3;

    Item x2;
    x2.value = 4;

    Item x3;
    x3.value = 5;

    Item x4;
    x4.value = 1;

    Item x5;
    x5.value = 2;

    l = init();
    push_back(&x1, l);
    push_back(&x2, l);
    push_back(&x3, l);
    push_front(&x4, l);
    insert(1, &x5, l);
    show(l);

    pop_back(l);
    pop_front(l);
    remove(3,l);
    show(l);

    return 0;
}