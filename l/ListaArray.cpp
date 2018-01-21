#include <stdio.h>
#define MAX_TAM 100
#define BEGIN 0

typedef struct item{
	int value;
}Item;

typedef struct list{
	Item item[MAX_TAM];
	int begin;
	int end;
}List;

void init(List *l){
	(*l).begin = BEGIN;
	(*l).end   = (*l).begin;
}

bool empty(List *l){
	return (*l).begin == (*l).end;
}

void insert(int position, Item *i, List *l){
	int aux;
	if((*l).end + 1 > MAX_TAM){
		printf("Lista está cheia\n");
	}else{
		printf("Insert element at the position %d", position);
		aux = (*l).end;
		
		while(aux >= position){
			(*l).item[aux + 1] = (*l).item[aux];
			aux -= 1;
		}
		
		(*l).item[position] = (*i);
		(*l).end += 1;
	}
}

void push_back(Item *i, List *l){
	if((*l).end > MAX_TAM){
		printf("Lista está cheia\n");
	}else{
		printf("Insert element at the end [Item:%d]\n", (*i).value);
		int key = (*l).end;
		(*l).item[key] = *i;
		(*l).end += 1;
	}
}

void remove_element(int position, List *l){
	int aux;
	if(empty(l) || position > (*l).end){
		printf("Erro: Posicao nao existe!\n");
	}else{
		Item i = (*l).item[position];
		printf("Remove element in position %d [Item: %d]\n", position, i.value);
		(*l).end -= 1;

		aux = position;
		while(aux < (*l).end){
			(*l).item[aux] = (*l).item[aux + 1];
			aux += 1;
		}
	}
}

void show(List *l){
	int aux;

	aux = (*l).begin;
	while(aux < (*l).end){
		printf("[Item: %d]\n", (*l).item[aux].value);
		aux += 1;
	}
}
int main(){
	List l; 
	Item x1;
	x1.value = 2;

	Item x2;
	x2.value = 3;

	Item x3;
	x3.value = 4;

	Item x4;
	x4.value = 1;
	init(&l);
	printf("[empty]: %d\n", empty(&l));
	
	push_back(&x1, &l);
	push_back(&x2, &l);
	push_back(&x3, &l);

	insert(0, &x4, &l);

	printf("\n[empty]: %d\n", empty(&l));
	show(&l);
	
	//remove_element(0, &l);
	//show(&l);
}