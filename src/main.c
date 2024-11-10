#include "./../include/Headers.h"



int main(){
    char cExp[100];
    int iDeb=0;
    int iFin=0;
    Cellule *pArbre;
    iFin=Lire_exp(cExp);
    pArbre=Cree_Arbre(cExp,iDeb,iFin);
    Afficher_Arbre(pArbre,0);
    printf("\n");
    for(int i=0;i<iFin;i++){
        printf("%c",cExp[i]);
    }
    printf("\n");
    printf("Le resultat est : %f\n",Calculer_Arbre(pArbre));
    return 0;
}