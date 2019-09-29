#ifndef ALGO_MAN_H
#define ALGO_MAN_H


#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <string.h>
void echange(int *x, int *y);
void traitement_seq();
void affiche(int t[],int n);
bool suite_est_croiss(int a, int b, int c, int d, int e, int f );
long fibo(unsigned int n);
int puissance(int x, int p);
int eval_poly(int x , unsigned n);
bool rech_dicho(int t[],int n,int val);
void fusion (int f[],int t1[] , unsigned int size1 , int t2[] , unsigned int size2) ;
void swap(int t[] , int i1 , int i2);
void segmentation(int t[] , unsigned int size ,unsigned int * indice_pivot);
bool est_permut(int p[], int size , int N);


/***********Listes***************/

typedef struct cell_t {
    int val;
    struct cell_t* suiv;
}*liste;




void affiche_liste(liste l);
void insere_tete(int v, liste*l);
void insere_queue(int v,liste *l);
int recherche(int v ,liste l); /*renvoie la position de v dans la liste et -1 s'il n'y est pas */
void supprimer(int v, liste*l);
void inverser(liste *l);
int taille(liste l);
void vider_liste(liste* l);

/*******pile*****/
typedef struct _stack {
    unsigned  taille_max;
    liste l_val;
} *stack;
stack  create_empty_stack(unsigned size);
void destroy_stack(stack  s);
void push(stack  const s, int v);
void affiche_stack(stack s);
int pop(stack const s );
bool is_empty(stack  const s);
bool is_full(stack const s);
void empty_stack(stack s);
/******les tris********* */
int max_tab(int t[],unsigned int n);
void tri_max(int t[], unsigned int size);

void tri_fusion(int t[], unsigned int size);
void tri_insertion(int t[], unsigned int size);
void copie(int dest[],int src[],int size);


void tri_rapide(int t[],unsigned int size);




#endif