#ifndef FONCTIONS_H
#define FoNCTIONS_H


typedef struct cel{
    float iVal; // la valeur de la cellule (c'est un feuille)
    char cOp; // l'opération par defaut est '@'(c'est un feuille) sinon c'est un Noeud
    struct cel *filsG;
    struct cel *filsD;
}Cellule;

/**
 * @brief Allouer l'espace pour une cellule
 * @return la cellule
 */
Cellule* Cree_Cellule();

/**
    @brief convertir la chaine de caractere en nombre reel
    @param cExp[] la chaine de caractere
    @param Ind l'indice de la chaine
    @return le nombre reel
*/
float Convert_String_Reel(char cExp[],int Ind);



/**
    @brief lire une expression arithmetique 
    @param cExp[] la chaine de caractere 
    @return la taille de la chaine
*/
int Lire_exp(char cExp[]);


/**
 * @brief Creer une arbre a partir d'une expression arithmetique
 * @param cExp[] la chaine de caractere
 * @param iDeb l'indice de debut
 * @param iFin l'indice de fin
 * @return l'arbre
 */
Cellule* Cree_Arbre(char cExp[],int iDeb,int iFin);


/**
 * @brief Afficher l'arbre
 * @param pRacine la racine de l'arbre
 */
void Afficher_Arbre(Cellule *pRacine, int niveau);

float Calculer_Arbre(Cellule *pRacine);



#endif 

