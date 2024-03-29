#include "arbres.h"

int main(){
    tree t = create_tree(NULL,NULL,7);
    t->fg = create_tree(NULL,NULL,5);
    t->fd = create_tree(NULL,NULL,10);
    t->fg->fd = create_tree(NULL,NULL,6);
    t->fg->fg = create_tree(NULL,NULL,4); 
    t->fg->fg->fg = create_tree(NULL,NULL,2); 
    t->fd->fg = create_tree(NULL,NULL,5);
    t->fd->fd = create_tree(NULL,NULL,11);
    print_search_tree(t);
    int min = min_tree(t);
    int max = max_tree(t);
    printf("min =%d\n",min);
    printf("max =%d\n",max);
    int p =is_search_tree(t,min,max);
    
    puts("");
    printf("is_search_tree = %d\n",p);
    destroy_tree(&t);
    return 0;
}
