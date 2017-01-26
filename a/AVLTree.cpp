#include<stdio.h>
#include<stdlib.h>
/*
    Estrutura da arvore AVL.
*/ 
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
 
/*
    Função utilizada para retornar o peso de um Nó da árvore.
*/
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

/*
    Função utilizada para retornar o maior de dois numeros.
*/
int max(int a, int b)
{
    return (a > b)? a : b;
}

/*
    Função responsável por alocar o Nó em memória.
*/ 
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // O novao Nó é adicionado como folha.
    return(node);
}
/*
    Função de rotação simples a direita.
*/
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    /*Atualiza os pesos.*/
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    /*Retorna a nova raiz.*/
    return x;
}
/*
    Função de Rotação simple a esquerda.
*/ 
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    /*Atualiza os pesos.*/
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    /*Retona a nova raiz.*/
    return y;
}
 
/*
    Função responsável por calcular o fator de balanceamento do nó.
*/
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/*
    Função responsável por inserir um nova Nó na Árvore, e ainda balancear caso nessário.
*/
struct Node* insert(struct Node* node, int key)
{
    /*1. Inserção normal de uma árvore de pesquisa binária.*/
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else /*Chaves identicas não são permitidas em árvores binários.*/
        return node;
 
    /* 2. Atualiza o peso do nó anterior.*/
    node->height = 1 + max(height(node->left),
                           height(node->right));
 

    /* 3. Calcula o fator de balanceamento verificando se a árvore ficou desbalanceada.*/
    int balance = getBalance(node);
 
    /*Verifica se é necessario realizar a rotação simples a direita.*/
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    /*Verifica se é necessario realizar a rotação simples a esquerda.*/
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    /*Verifica se é necessario realizar a rotação dupla a direita.*/
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    /*Verifica se é necessario realizar a rotação dupla a esquerda.*/
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    /*Retorna a raiz da árvore.*/
    return node;
}

/*
    Exibe a árvore AVL em pre-ordem.
*/
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main()
{
  struct Node *root = NULL;
 
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /*
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Representação final da Arvore AVL: \n");
  preOrder(root);
 
  return 0;
}
