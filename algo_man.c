#include "algo_man.h"


void echange(int *x, int *y){
    int a;
    a=*x;
    *x=*y;
    *y=a;
    return;
}
void traitement_seq(){
   char courant;
    int len=0;
    puts("entrer un char");
    scanf("%c",&courant);
    while(courant !='#'){
        len++;
        scanf("%c",&courant);
    }
    printf("la taille est : %d\n",len);
}
void affiche(int t[],int n){
    if(n==0) return;
    for (int i = 0; i < n; i++)
    {
        printf("%d ,",t[i]);
    }
    puts("**fin**");
}
bool suite_est_croiss(int a, int b, int c, int d, int e, int f ){
    return (a < b) && (b < c) && (c < d) && (d < e )&& (e < f);
}
long fibo(unsigned int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}
int puissance(int x, int p){
    int s = 1;
    for(int i = 0 ; i<p ; i++){s*=x;}
    return s;
}

int eval_poly(int x , unsigned n){
    int p=0;
    int a;
    for(unsigned i =0 ; i <= n ; i++){
        puts("entrer la valeur du coef ai");
        scanf("%d",&a);
        p+=a*puissance(x,i);
    }
    return p;
}
bool rech_dicho(int t[],int n,int val){
    if (n==0)
    {
        return false;
    }

    int m = n/2;
    if (t[m]==val){
        return true;
    }
    if (t[m] < val){
        return rech_dicho(t+m+1,m,val);
    }else{
         return rech_dicho(t,m,val);
    }
}
void fusion (int f[],int t1[] , unsigned int size1 , int t2[] , unsigned int size2) {
    unsigned int it1=0,it2=0,i=0;
    if (size1==0)  f=t2;
    if (size2==0)  f=t1;

    while (it1 < size1 || it2 < size2){
        if( (t1[it1] < t2[it2] || it2 == size2 ) && it1 < size1){
            f[i]=t1[it1];
            i++;
            it1++;
        }
        if( (t2[it2] <= t1[it1] || it1 == size1) && it2 < size2) {
            f[i]=t2[it2];
            i++;
            it2++;
        }
    }
}
void swap(int t[] , int i1 , int i2){
    int tmp = t[i1];
    t[i1]=t[i2];
    t[i2]=tmp;
    return ;
}


void segmentation(int t[] , unsigned int size ,unsigned int * indice_pivot){
   if(size ==1) {*indice_pivot=0;return;} 
   swap(t,0,size-1);
   int j = 0;
   for(unsigned int i=0 ; i<=size-2 ; i++){
        if(t[i] <= t[size-1]){
            swap(t,i,j);
            j++;
        }
    }
    swap(t,j,size-1);
    *indice_pivot = j;
}



bool est_permut(int p[], int size , int N){
  bool dejavu[size];
  for(unsigned int i = 0;i<size;i++) dejavu[i]=false;
  for (unsigned int j=0; j < size; j++) {
    if (!(p[j]<=N && p[j] >=0) || dejavu[j]) {
      return false;
    }else dejavu[j]=true;
  }
  return true;
}

/******************** */
void affiche_liste(liste l){
    printf("Liste =");
    liste p = NULL;
    for(p=l;p!=NULL;p=p->suiv){
        printf(" %d,",p->val);
    }
    puts("");
}
void insere_tete(int val,liste*l){
    liste p = (liste)malloc(sizeof(*p));
    p->val=val;
    p->suiv=*l;
    *l=p;
}
void insere_queue(int v,liste *l){
    if((*l)==NULL) {
        insere_tete(v,l);
        return;
    }
    liste q =NULL;
    liste p = (liste)malloc(sizeof(*p));
    p->val=v;
    p->suiv = NULL;
    for(q=*l;q->suiv!=NULL;q=q->suiv){;}
    q->suiv = p;
}
int recherche(int v ,liste l){
    liste p = NULL;
    int i=0;
    for(p=l;p!=NULL;p=p->suiv){
        if(p->val==v){
            return i;
        }
        i++;
    }
    return -1;
}

/*supprime la 1ere occurence de v */
 /*pas optimale */
void supprimer(int v, liste*l){
    if (*l==NULL) return;
    if((*l)->suiv == NULL){
        if((*l)->val == v){
           (*l)=NULL;
           return;
        }
    }
    if((*l)->val == v){         // si l'élément à supprimer est le 1er
        liste f = *l;
        *l=(*l)->suiv;
        free(f);
        return;
    }else{
        liste p=NULL;
        for(p=*l;p->suiv!=NULL;p=p->suiv){
            if(p->suiv->val==v){
                liste q = p->suiv;
                p->suiv = p->suiv->suiv;
                free(q);
                break;
            }
        }
        if(p->val==v){
            liste m=NULL;
            for(m=*l;m->suiv!=p;m=m->suiv){;}
            m->suiv=NULL;
            free(p);
        }
    }
}
void supprimer_tete(liste *l){
    if(*l!=NULL && taille(*l) >1 ){
        liste p = *l;
        *l=(*l)->suiv;
        free(p);
    }else{
        *l = NULL;
    }

}
int taille(liste l){
    if( l== NULL) return 0;
    int n = 0;
    liste p = NULL;
    for(p=l;p!=NULL;p=p->suiv){
        n++;
    }
    return n;
}
void inverser(liste *l){
    int n = taille(*l);
    if(n>1){
        liste p=*l,q=NULL,r=NULL,s=NULL;
        q=(*l)->suiv;
        (*l)->suiv = NULL;
        while(q!=NULL){
            r=q->suiv;
            s=q;
            q->suiv = p;
            q=r;
            p=s;
        }
        *l=p;
    }
}
void vider_liste(liste* l){
    int n = taille(*l);
    if(n!=0){

        for(int i=1 ;i<=n;i++){
            supprimer_tete(&(*l));
        }
    }
}



/**************************/
stack  create_empty_stack(unsigned size){
    stack s = (stack)malloc(sizeof(*s));
    s->taille_max = size;
    s->l_val=NULL;
    return s;
}
void destroy_stack(stack  s){
    free(s);
}

void push(stack  const s, int v){
    if(!is_full(s)){
        insere_tete(v,&(s->l_val));
    }
    else{
        printf("Pile pleine.Impossible d'empiler %d\n",v);

        return;
    }
}
void affiche_stack(stack s){
    printf("taille max = %d\n",s->taille_max);
    printf("Pile = ");
    liste p = NULL;
    for(p=s->l_val;p!=NULL;p=p->suiv){
        printf(" %d,",p->val);
    }
    puts("");
}
int pop(stack const s ){
    if(s!=NULL && s->l_val != NULL ){
        int valeur = s->l_val->val;
        supprimer_tete(&(s->l_val));
        return valeur;
    }
    else{
        puts("Pile vide, la fonction renvoie -1  ");
        return -1;
    }
}
bool is_empty(stack  const s){
    return (s==NULL || s->l_val == NULL);
}
bool is_full(stack const s){
    return (taille(s->l_val) == s->taille_max);
}
void empty_stack(stack s){
    if(!is_empty(s)){
        vider_liste(&(s->l_val));return;
    }
    else return;
}


/************les tris ****************/

int max_tab(int t[],unsigned int n){
    int max =0;
    for(int i=0;i<n;i++){
        if(t[max]<t[i]){
            max = i;
        }
    }
    return max;
}


void tri_max(int t[], unsigned int size){
    int mx=0;
    for(int i=size; i!=0;i--){
        mx=max_tab(t,i);
        if(mx!=i) swap(t,i-1,mx);
    }
}

void tri_insertion(int t[], unsigned int size){
    int mem,i,j;
    for(i=1;i<size;i++){
        mem=t[i];
        j=i;
        while(j>0 && t[j-1]>mem){
            t[j]=t[j-1];
            j--;
        }
        t[j]=mem;
    }
}
void tri_fusion(int *t, unsigned int size){
    if(size <=1) return;
    int *fus = (int*)calloc(size,sizeof(int));
    int mid = size/2;
    tri_fusion(t,mid);
    tri_fusion(t+mid,size-mid);
    fusion(fus,t,mid,t+mid,size-mid);
    copie(t,fus,size);  
    free(fus);         
}

void copie(int dest[],int src[],int size){
    memmove(dest,src,size * 4);
}

/*marche pas*/
void tri_rapide(int t[],unsigned int size){      
    if (size <= 1) return;
    unsigned int pivot;
    segmentation(t,size,&pivot);
    if ((signed)pivot-1 > 0){
        tri_rapide(t,pivot);
    }if (pivot < size-1){
        tri_rapide(t+pivot+1,size-pivot-1);
    }
}
