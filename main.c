#include "algo_man.h"
#include <time.h>
#define TAILLE 150
int main(){
    srand(time(NULL));
    int t[TAILLE];
    for (int i = 0; i < TAILLE; i++){
        
        t[i]=rand()%50;
    }
    affiche(t,TAILLE);
    puts("");
    tri_rapide(t,TAILLE);
    affiche(t,TAILLE );
    return 0;
}
