#include <stdio.h>
#include <stdlib.h>

int main()
{
 int allumettes[4] = {1,3,5,7};
 int joueur = 1;
 int input = 0;
 int TotalAll = 16;
 int NbCoups = 0;
 int CoupsFaits[3] = {0,0,0};

 int IsMoveDOne(int tab[3],int move);
 int Reset(int tab[3]);

 do{
    NbCoups = 3;
    do{
        printf("Joueur %d , entrez le nombre d'allumettes a enlever. Il y a actuellement %d , %d , %d, %d allumettes.\n",joueur,allumettes[0],allumettes[1],allumettes[2],allumettes[3]);
        do{
            scanf("%d",&input);
            input--;
        }while ((input<0 && input>4) && (allumettes[input] <= 0) && (IsMoveDOne(CoupsFaits,input)));

        CoupsFaits[3-NbCoups] = input;

        if ((input == -1) && (NbCoups < 3)) NbCoups = 0;
        if (input != -1) {
                allumettes[input]--;
                TotalAll--;
                NbCoups--;
        }
    }while (NbCoups > 0);

    Reset(CoupsFaits);
    if (joueur == 1) joueur = 2;
    else joueur = 1;

 }while (TotalAll > 0);
 printf("Joueur %d a gagne!",joueur);
}

int IsMoveDOne(int tab[3],int move){
    int bool = 0;
    int i = 0;

    for(i=0;i<3;i++){

        if (tab[i] = move) bool = 1;

    }

    return bool;
}

int Reset(int tab[3]){
    int i = 0;

    for(i=0;i<3;i++){

        tab[i] = 0;

    }
}

