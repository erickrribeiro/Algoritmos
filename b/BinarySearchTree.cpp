// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int key;
    struct node *left, *right;
};
  
/*
    Função utilizada pra criar um nó.
*/
struct node *newNode(int item)
{
    struct node *temp =  (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
/*
    Exibe a arvore In-ordem.
*/
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
  
/* 
    Função utilizada para inserir um novo Nó na arvore.
 */
struct node* insert(struct node* node, int key)
{
    /*Se a árvore está limpa, então o primeiro elemento é a raiz.*/
    if (node == NULL) return newNode(key);
 
    /* Por outro lado, percorre as subarvore da esquerda ou da diretia.*/
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}


/*
    Função para pesquisa um dada chave na árvore.
*/
struct node* search(struct node* root, int key)
{
    /*Caso Base: verifica se não o nó é nulo, ou se o Nó possue a chave procurada.*/
    if (root == NULL || root->key == key)
       return root;
    
    /*Se a chave do Nó é menor que procurada, então caminhar para a subarvore a direita.*/
    if (root->key < key)
       return search(root->right, key);
 
    /*Senão caminhar para a subarvore a esquerda.*/
    return search(root->left, key);
}

/* Dado uma arvore não vazia, retorna o menor favor dela, ou seja o Nó mais a esquerda.*/
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    /* Case base: raiz nula retorna ela mesma.*/
    if (root == NULL) return root;
 
    /*Se a chave a ser deletada for menor que a raiz, então percorrer a subarvore a esquerda*/
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    /*Se a chave a ser deletada for maior que a raiz, então percorrer a subarvore a direita.*/
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    /*Se a chave a ser deletada for igual a rauz, então recoce o Nó.*/
    else
    {
        /*Caso o Nó tenha apenas um filho.*/
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        /*Caso no Nó tenha dois filhos: pegar o menor valor da subarvore a direita.*/
        struct node* temp = minValueNode(root->right);
 
        /*Copia o valor do menor Nó para o Nó atual.*/
        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}



int main()
{
    /* Cria a seguinte árvore de busca binária.
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
    */

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // Exibe a árvore.
    inorder(root);

    struct node *result = search(root, 20);

    if (result == NULL){
        printf("A chave nao foi encontrada.\n");
    }else{
        printf("A chave %d foi encontrada.\n", result->key);
    }

    printf("Exibe a arvore In-ordem \n");
    inorder(root);
 
    printf("\nDeleta a chave 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDeleta a chave 30\n");
    root = deleteNode(root, 30);
    printf("Exibe a arvore In-ordem \n");
    inorder(root);
 
    printf("\nDeleta a chave 50\n");
    root = deleteNode(root, 50);
    printf("Exibe a arvore In-ordem \n");
    inorder(root);
 

  
    return 0;
}