#include <stdio.h>
#include <stdlib.h>
void TourJoueur(int *allumettes);
void TourBot(int *allumettes);
int main()
{
 int allumettes = 21;
 int joueur = 1;
 do{
    //========================DEBUT TOUR====================
    //Tour Joueur
        if (joueur ==1) TourJoueur(&allumettes);

    //Tour Bot
        else TourBot(&allumettes);
    //======================FIN TOUR=========================

    //Changement Joueur
    if (joueur == 1) joueur = 2;
    else joueur = 1;

 }while (allumettes > 0);
 printf("Joueur %d a gagne!",joueur);

 return 0;
}

/*
BUT : Faire enlever au jouerur un nobre d'allumettes.
ENTREE : Les allumettes.
SORTIE : Les allumettes moins le nombre d'allumettes enlevées.
*/
void TourJoueur(int *allumettes){
 int input = 0;


    printf("Vous jouez. Entrez le nombre d'allumettes a enlever. Il y a actuellement %d allumettes.\n",*allumettes);
    do{
        scanf("%d",&input);
    }while ((input<1) | (input>3));  //On n'accepte que les inputs entre 1 et 3

    *allumettes = *allumettes - input;
}

/*
BUT : Le bot enleve enleve assezd'allumette pour arriver a un lultiple de 4 moins 1.
ENTREE : Les allumettes.
SORTIE : Les allumettes moins le nombre d'allumettes enlevées.
*/
void TourBot(int *allumettes){
    int input = 0;

            //On ultilise modulo moins le nombre d'allumettes que l'on soyhaite testé moins encore un. SI ça revoie 0, on enleve cc enleve ce nombre d'allumettes. Si on ne peux y arriver, on elve une allumete.
            //On ultilise modulo moins le nombre d'allumettes que l'on soyhaite testé moins encore un. SI ça revoie 0, on enleve cc enleve ce nombre d'allumettes. Si on ne peux y arriver, on elve une allumete.
            if ((*allumettes - 2)%4 == 0) input = 1;
            else if ((*allumettes - 3)%4 == 0) input = 2;
            else if ((*allumettes - 4)%4 == 0) input = 3;
            if ((*allumettes - 1)%4 == 0) input = 1;

            printf("Le bot enleve %d allumettes.\n", input);
            *allumettes = *allumettes - input;
}
