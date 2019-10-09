#ifndef ARBRES_H
#define ARBRES_H
#include <stdlib.h>

typedef struct _tree{
    int val;
    struct _tree *fg;
    struct _tree *fd;
} *tree;

/* constructeur d'arbre vide */
tree create_empty_tree();

/* constructeur d'arbre non vide de racine R, 
   fils gauche G et fils droit D */
tree create_tree(tree g, tree d, int r);

/* désalloue l'arbre t */
void destroy_tree(tree *t);

/* teste si l'arbre est vide */
int is_empty(tree t);

int tree_hight(tree t);

int leaf_nbr(tree t);

int node_nbr(tree t);

tree mirror_tree(tree t);

int is_degenerate(tree t);

int is_complete(tree t);

void inorder_print(tree t); /* identation */

#endif  