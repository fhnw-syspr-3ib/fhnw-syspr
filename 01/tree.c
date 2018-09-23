#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *label;
    struct node *left;
    struct node *right;
} Node;

int main() {	
	Node *ll = malloc(sizeof(Node));
    ll->label = "I am left left";
    ll->left = NULL;
    ll->right = NULL;

	Node *lr = malloc(sizeof(Node));
    lr->label = "I am left right";
    lr->left = NULL;
    lr->right = NULL;

    Node *l = malloc(sizeof(Node));
    l->label = "I am left";
    l->left = ll;
    l->right = lr;

    Node *r = malloc(sizeof(Node));
    r->label = "I am right";
    r->left = NULL;
    r->right = NULL;

    Node *root = malloc(sizeof(Node));
    root->label = "I am root";
    root->left = l;
    root->right = r;
	
    free(n00);
    free(n01);
    free(n02);
    free(n0);
    free(n1);
    free(root);

    return 0;
}