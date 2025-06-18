#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/process.h"
int main()
{
myfile F;
F.tete=F.que=NULL;
node * ls=NULL;
int cmp=0,cmt=0,cmu=0,taille ,quantum ;
process prc ;
int v ,x ;
int cmpt  ;


    while (1) {
            if(x!=2){
    printf("\n------------------------------ MENU :--------------------------------------------------------\n");
    printf("1. Ajouter un processus a la file d'attente .\n");
    printf("2. Executer un processus pendant un quantum de temps.\n");
    printf("3. Afficher l'etat actuel de la file d'attente .\n");
    printf("4. Gerer le passage du temps .\n");
    printf("5. Quitter .\n \n --------------------------------------------------------------------------------------------");
            }

    printf("\n  --->Entrez votre choix a partir de menu  : ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                if(cmp==0){
               printf("\n\n ---> Veuillez saisir la taille maximal de la file :");
                scanf("%d",&taille);
               F=initialise_file(F,taille);
                 }
        if(!estPleinne(F,cmp)){
               printf("\n{^_^} --> Ajouter un nouveau processus a la file :\n");
        cmp++;
    printf(" \n ==> Processus %d : \n",cmp);
     printf(" \n   ->  Identifiant (!unique!):") ;
     scanf("%d",&prc.id);
      if(F.que!=NULL){
  cmu =0 ;
  while(cmu!=cmp){
    if(prc.id == F.que->data.id){
      printf(" \n !!(Saisir un identifiant unique ) -> Identifiant (unique) :") ;
    scanf("%d",&prc.id);
    cmu =0 ;
    continue ;
    }
    F.que=F.que->prev ;
    cmu++ ;
   }
 F.que=ls->prev ;
      }

      printf(" \n   ->   Temps D'arrivee :") ;
    scanf("%d",&prc.tmps_arrive);
    if(F.que!=NULL){
    while(prc.tmps_arrive <= F.que->data.tmps_arrive){
      printf(" \n !!(Saisir un temps d'arrivee superieur aux precedents processuss) -> Temps D'arrivee :") ;
    scanf("%d",&prc.tmps_arrive);
    }
    }
      printf(" \n   ->   Duree d'execution :") ;
    scanf("%d",&prc.tmps_rest);
    emfiler(&F,&ls,prc) ;

        }

    else
    printf(" \n\n -->Choix invalide : (-_-) !! La File  est Pleinne !!\n\n ") ;

                break;

            case 2:

              if (estVide(F)){
                 printf("\n\n  !!ERREUR : la File est vide (-_-)\n\n ");
                continue ;
              }
                   if(cmpt==0){
            printf("\n \n(^_^)--->Les processus sont geres selon l'algorithme d'ordonnancement 'round-robin' . ") ;
            printf("\n\n ---> Veuillez saisir un quantum de temps,que tous les processuss sont executee pendant ce quantum ( unites de temps) :");
            scanf("%d",&quantum);
                   }

        Execut_process(&F,ls,quantum);
         cmpt++ ;

                break;
            case 3:
                  if (estVide(F )){
                 printf(" \n\n !!ERREUR : la File est vide (-_-)\n\n ");
                 continue ;
              }
              Afficher_File(ls,cmp) ;
                break;
            case 4 :
                if (estVide(F )){
                 printf(" \n\n !!ERREUR : la File est vide (-_-)\n\n ");
                 continue ;
              }
               ls=Gestion_Temps(&F,ls,quantum,cmpt,cmp) ;

                break;
            case 5:
                 printf("\n\n--------------------------<...AU REVOIR (^_^)...>------------------------------\n");
                return 0;
            default:
                printf("\n\n(-_-)-->!! Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }

    return 0;
}
