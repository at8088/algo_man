#include "algo_man.h"
#include <time.h>

int main(){
    srand(time(NULL));
    int p;
    int t[20];
    for (int i = 0; i < 20; i++)
    {
        t[i]=rand()%100;
    }
    affiche(t,20);
    /* segmentation(t,20,&p);
    printf(" %d\n",p); */
    tri_rapide(t,20);
    affiche(t,20);
    return 0;
}
