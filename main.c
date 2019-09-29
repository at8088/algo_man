#include "algo_man.h"
int main(){
    int t[20];
    for (int i = 0; i < 20; i++)
    {
        t[i]=20-i;
    }
    
    //int l[9];
    //copie(l,t,9);
    affiche(t,20);
    puts(" ");
    tri_rapide(t,20);
    affiche(t,20);
    return 0;
}
