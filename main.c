#include "algo_man.h"
#include <time.h>
#define TAILLE 5
int main(){
    srand(time(NULL));
    int p;
    int t[TAILLE] ;
    int a[TAILLE] ;
    int f[2*TAILLE] ;
    for (int i = 0; i < TAILLE; i++){
        t[i]=fibo(i);
        a[i] = 2*i;
    }

    affiche(t,TAILLE);
    puts("");
    affiche(a,TAILLE);
    puts("");
    /* segmentation(t,TAILLE,&p);
    printf(" %d\n",p); */
    fusion(t,a,TAILLE,t,TAILLE);
    affiche(f,2*TAILLE);
   
    
    return 0;
}
