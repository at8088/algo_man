#include "arbres.h"


int nbr_tabulation=0;

tree create_empty_tree(){
    return NULL;
}

tree create_tree(tree g ,tree d, int r){
    tree t = (tree)malloc(sizeof(t));
    t->val = r;
    t->fg=NULL;
    t->fd=NULL;
    return t;
}
void destroy_tree(tree* t){
    if(*t!=NULL){
    destroy_tree(&((*t)->fg));
    destroy_tree(&((*t)->fd));
    free(*t);
    *t = NULL;
    }    
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else return b;
}
int is_empty(tree t){ return t == NULL ;}

int tree_hight(tree t){
    
    if(is_empty(t)){
        return 0;        
    }else if (is_empty(t->fg) && is_empty(t->fd)){
        return 0;
    }
    return 1 + max(tree_hight(t->fd) , tree_hight(t->fg));

}
int leaf_nbr(tree t){
    int ln=0;
    if(is_empty(t)){
        return ln;
    }else if(is_empty(t->fd) && is_empty(t->fg)){
        ln++;
        return ln ;
    } 
    if (!is_empty(t->fg)){
        ln+=leaf_nbr(t->fg);
    }
    if (!is_empty(t->fd)){
        ln+=leaf_nbr(t->fd);
    }
    return ln;
}
int node_nbr(tree t){
    int n = 0;
    if(is_empty(t)){
        return n;
    }
    n=1;
    n += node_nbr(t->fd);
    n +=node_nbr(t->fg);  
    return n;
}

tree mirror_tree(tree t){
    if(is_empty(t)) return create_empty_tree();
    tree mt = create_tree(t->fd,t->fg,t->val);
    mt->fg = mirror_tree(t->fd);
    mt->fd = mirror_tree(t->fg);
    return mt;
}

int is_degenerate(tree t){
    if(is_empty(t)) return 1;
    if (is_empty(t->fg) || is_empty(t->fd)){
        if(!is_empty(t->fd)) return 1 && is_degenerate(t->fd);
        if(!is_empty(t->fg)) return 1 && is_degenerate(t->fg);
    }else return 0;
}

// pas optimale.
int is_complete(tree t){        
    if(is_empty(t)) return 1;
    return ( is_complete(t->fd) && is_complete(t->fg) && (node_nbr(t->fd)==node_nbr(t->fg)) );
    
}
int is_complete_v2(tree t, int size){

}

void print_tree(tree t){
    if (is_empty(t)){return;}
    char *s=calloc(nbr_tabulation,sizeof(char));
    memset(s,'_',nbr_tabulation);
    printf("%s",s);
    free(s);
    printf("%d\n",t->val);
    nbr_tabulation++;
    int mem_nbr_tab = nbr_tabulation;
    if(t->fg == NULL && t->fd !=NULL){
        char *s=calloc(nbr_tabulation,sizeof(char));
        memset(s,'_',nbr_tabulation);
        printf("%s",s);
        free(s);
        printf("*\n");
    }
    if(t->fg != NULL){
        print_tree(t->fg);
    }
    nbr_tabulation = mem_nbr_tab;
    if(t->fd != NULL){
        print_tree(t->fd);
    }
}

void print_search_tree(tree t){
    if(t != NULL){
        print_search_tree(t->fg);
        printf(" %d ",t->val);
        print_search_tree(t->fd);
    }
}

int is_present(int value , tree t){
    if(!is_empty(t)){
        if(value == t->val){
            return 1;
        }
        if(value > t->val){
            return is_present(value,t->fd);
        }else {
            return is_present(value,t->fg);
        }
    }else return 0;
}

int min_tree(tree t){
    if(!is_empty(t)){
        tree p = t;
        while(!is_empty(p->fg)){
            p=p->fg;
        }
        if (!is_empty(p)) return p->val;
    }
}

int is_search_tree(tree t){
    if(is_empty(t)){
        return 1;
    }else{
        if(is_empty(t->fg) && is_empty(t->fd)){
            return 1;
        }
        if(is_empty(t->fg)){
            return t->val < t->fd->val;
        }
        if(is_empty(t->fd)){
            return t->val > t->fg->val;
        }
        
        return ( t->val > t->fg->val && t->val < t->fd->val
                && is_search_tree(t->fd) && is_search_tree(t->fg));
    }

}


