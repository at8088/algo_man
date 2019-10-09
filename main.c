#include "arbres.h"
#include <stdio.h>

int main(){
    tree t = create_tree(NULL,NULL,5);
    t->fg = create_tree(NULL,NULL,9);
    t->fd = create_tree(NULL,NULL,6);
    /* t->fg->fg = create_tree(NULL,NULL,3);
    t->fg->fd = create_tree(NULL,NULL,8); */
    t->fd->fg = create_tree(NULL,NULL,55);
    t->fd->fd = create_tree(NULL,NULL,40);


    tree a = create_tree(NULL,NULL,0);
    a->fd = create_tree(NULL,NULL,1);
    a->fd->fd = create_tree(NULL,NULL,5);
    int h = is_complete(t);
    printf("%d\n",h);
    destroy_tree(&t);
    return 0;
}
