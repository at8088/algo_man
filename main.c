#include "algo_man.h"
#include <time.h>
#define TAILLE 50
int main(){
    srand(time(NULL));
    int p;
    int t[TAILLE];
    /* int a[TAILLE+5]; */
    /* int f[2*TAILLE+5]; */
    for (int i = 0; i < TAILLE; i++)
    {
        
        t[i]=rand()%102;
    }
    /* for (int i = TAILLE; i < TAILLE+5; i++)
    {        
        a[i] = 5*i + 1;
    } */
    affiche(t,TAILLE);
    puts("");
    /* affiche(a,TAILLE+5); */
    tri_fusion(t,TAILLE);
    /* segmentation(t,TAILLE,&p);
    printf(" %d\n",p); */
    /* fusion(f,t,TAILLE,a,TAILLE+5); */
    affiche(t,TAILLE );
    return 0;
}
