#include "algo_man.h"
int main(){
    int t[100];
    for (int i = 0; i < 100; i++)
    {
        t[i]=100-i;
    }
    
    //int l[9];
    //copie(l,t,9);
    affiche(t,100);
    puts(" ");
    tri_fusion(t,100);
    affiche(t,100);
    return 0;
}
