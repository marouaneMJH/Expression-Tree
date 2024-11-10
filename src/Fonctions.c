#include "./../include/Headers.h"






float Convert_String_Reel(char cExp[],int Ind){
    // les caracter avans la vergule
    float     fNbAvanVerg=0; // le nombre avant la vergule
    float     fNbApreVerg=0; // le nombre d'apres la vergule
    
    
    
    // parcourir jusqua un caractere difirent de nombre 
    while((cExp[Ind]>='0') && (cExp[Ind] <='9')){
            fNbAvanVerg*=10;    // 12->120
            fNbAvanVerg+=(-'0'); // 120 -> 123
            Ind++;
    };
    
    // si le caractère est '.' alors on doit lire les caractères après la vergule    
    if(cExp[Ind]=='.'){
        int i=0; // une countour  pour les caractères après la vergule
        while((cExp[Ind]>='0') && (cExp[Ind] <='9')){
            fNbApreVerg*=10;                // 12->120
            fNbApreVerg+=(cExp[Ind]-'0');   // 120 -> 123
            Ind++;
        };
        fNbApreVerg=((float)fNbApreVerg/pow(10,i)); // pour avoir le nombre réel dans le cas de nombre après la vergule
    }

    fNbAvanVerg+=fNbApreVerg; // le nombre total    


    return ((float)fNbAvanVerg);
}

Cellule* Cree_Cellule(){

    // la creation d'une cellule
    Cellule *pNouv=(Cellule *)malloc(sizeof(Cellule));
    if(!pNouv){
        printf("\nErreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    // la intilisation de la cellule
    pNouv->cOp='@';
    pNouv->filsG=NULL;
    pNouv->filsD=NULL;
    return (Cellule*)(pNouv);
}
int Lire_exp(char cExp[]){
    char cTmp; // caractère temporaire
    int ind=0; // indice de la chaine
    cTmp=getchar();
    while(cTmp!='\n'){  // lire jusqu'à la fin de la ligne
        cExp[ind]=cTmp; // ajouter le caractère dans la chaine
        cTmp=getchar(); 
    }
    cExp[ind]='\0'; // fin de la chaine
    return ((int)ind); // returner la taille de la chaine
}

Cellule* Cree_Arbre(char cExp[],int iDeb,int iFin){
    Cellule *pRacine;
    
    // cherchon la derniere operateur somme au dans la chaine 
    for(int i=iFin;i>=iDeb;i--){
        if(cExp[i]=='+' || cExp[i]=='-'){
            pRacine=Cree_Cellule();
            pRacine->cOp=cExp[i];
            pRacine->filsG=Cree_Arbre(cExp,iDeb,i-1);
            pRacine->filsD=Cree_Arbre(cExp,i+1,iFin);
            return (Cellule*)(pRacine);
        }
    }

    // cherchon la derniere operateur produit ou division  au dans la chaine
    for(int i=iFin;i>=iDeb;i--){
        if(cExp[i]=='*'  || cExp[i]=='/'){
            pRacine=Cree_Cellule();
            pRacine->cOp=cExp[i];
            pRacine->filsG=Cree_Arbre(cExp,iDeb,i-1);
            pRacine->filsD=Cree_Arbre(cExp,i+1,iFin);
            return (Cellule*)(pRacine);
        }
    }
    
    // si la chaine est un nombre
    
    pRacine=Cree_Cellule();
    pRacine->cOp='@';
    pRacine->iVal=Convert_String_Reel(cExp,iDeb);
    return (Cellule*)(pRacine);
}


// l'aide de chat gpt pour la fonction afficher arbre
void Afficher_Arbre(Cellule *pRacine, int niveau) {
    if (pRacine == NULL) return;

    Afficher_Arbre(pRacine->filsD, niveau + 1);

    for (int i = 0; i < niveau; i++) {
        printf("   ");
    }

    if (pRacine->cOp == '@') {
        printf("%f\n", pRacine->iVal);
    } else {
        printf("%c\n", pRacine->cOp);
    }

    Afficher_Arbre(pRacine->filsG, niveau + 1);
}

float Calculer_Arbre(Cellule *pRacine) {
    if (pRacine == NULL) return 0;

    if (pRacine->cOp == '@') {
        return pRacine->iVal;
    }

    float valG = Calculer_Arbre(pRacine->filsG);
    float valD = Calculer_Arbre(pRacine->filsD);

    switch (pRacine->cOp) {
        case '+': return valG + valD;
        case '-': return valG - valD;
        case '*': return valG * valD;
        case '/': return valG / valD;
        default: return 0;
    }
}


// deux fonction prancipal arbresSomme et arbresProduit 
// l'arbre somme est toujour l'arbre pere
// la nouvelle arbre somme est toujour larbre pere
// la nouvelle arbre produit  est toujour larbre pere dans sous arbre produit