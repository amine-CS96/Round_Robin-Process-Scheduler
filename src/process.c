
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/process.h"

myfile initialise_file(myfile F,int taille){

F.taille=taille ;
return F ;
}
int estTermine(myfile *F ,node *debut ){
    int cmt =0 ,cmp=0;
    node *tmp =debut ;
while(cmp!=F->taille){
        cmp++ ;
    if(tmp->data.tmps_rest==0)
        cmt++ ;
        else
            break ;

    tmp=tmp->next ;
}
return cmt==F->taille;

}
int estVide(myfile F ){
return (F.tete==NULL && F.que==NULL ) ;
}
int estPleinne (myfile F,int cmp){
return F.taille==cmp ;
}
/*int seul_Element(myfile F){
return F.que==F.tete && (F.tete!=NULL && F.que!=NULL ) ;
}*/
void emfiler(myfile *F,node **debut , process prc){

node * cel ;

cel=(node *)malloc(sizeof(node));
if (cel==NULL){
    perror("ERRUR d'allocation ");
    exit(0) ;
}
cel->data=prc ;
cel->next=cel->prev=NULL ;

if(*debut==NULL){
 cel->next=cel->prev=cel ;
 *debut= cel;
  F->que =*debut ;
  F->tete=*debut;
}
else{


cel->prev=F->que ;
cel->next=*debut ;
F->que->next=cel;
(*debut)->prev=cel ;
F->que=cel ;
}
}


void defiler(myfile **F ,int quantum ,node * debut){
     printf("\n\n{...}--> Execution du processus de 'PID=%d' pendant %d unites de temps :",(*F)->tete->data.id,quantum) ;
     if((*F)->tete->data.tmps_rest<quantum)
        (*F)->tete->data.tmps_rest-= (*F)->tete->data.tmps_rest;
      else
     (*F)->tete->data.tmps_rest -=quantum;

      printf("--(T_Arrivee : %d )--",(*F)->tete->data.tmps_arrive);
     printf("--(T_Restant : %d )--\n",(*F)->tete->data.tmps_rest);

        (*F)->tete=(*F)->tete->next ;
   }

   void Afficher_File(node  *debut,int cmp){
       int cmt =0 ;
       node * tmp =debut ;
        printf("\n \n -------------------------------< Etat de la file d'attente :>---------------------------\n") ;
  while (cmt!=cmp) {
    cmt++ ;

     printf("====> Processus de PID = ( %d ) \n",tmp->data.id);
     printf("---> Position : ( %p ) \n",tmp);
     printf("---> Temps d'Arrivee :( %d ) \n",tmp->data.tmps_arrive);
     printf("---> Temps Restant : ( %d ) \n\n",tmp->data.tmps_rest);


     tmp=tmp->next ;
  }
  printf("\n--------------------------------------------<...>------------------------------------------\n\n");
   }

 void Execut_process(myfile*F,node * debut ,int quantum){

           if(!estTermine(F,debut)){
               if(F->tete->data.tmps_rest==0){
           F->tete=F->tete->next;
           Execut_process(F,debut,quantum);
               }
               else {

            defiler(&F,quantum,debut);
             printf("\n") ;
         }
          }
          else{
            printf("\n \n (-_-) --> Tous les processus sont termines , c-a-d : la file d'attente devient vide . \n") ;
          }
 }

node * Gestion_Temps (myfile*F,node* debut,int quantum,int cmt,int cmp){

if(!estTermine(F,debut)){
printf("\n \n (^-^) : On gere  le passage du temps en continuant a executer les processus \n restants dans la file d'attente, a partir de l'etat actuel de la file d'attente,\n et jusqu'a ce qu'elle soit vide.\n\n");
if(cmt!=0)
printf("\n !! Atention : %d des Tours sont fait deja a l'option '2' . \n\n",cmt) ;
else {
 printf("\n \n(^_^)--->Les processus sont geres selon l'algorithme d'ordonnancement 'round-robin' . ") ;
            printf("\n\n ---> Veuillez saisir un quantum de temps ( unites de temps) :");
            scanf("%d",&quantum);
            }
}
         while(!estTermine(F,debut)){
              if(F->tete->data.tmps_rest==0){
                 F->tete=F->tete->next;
                    continue ;
                   }
         printf("\n\n    \t \t \t------------< Tour  : %d >------------\n",++cmt);
        defiler(&F,quantum,debut);
        Afficher_File(debut,cmp) ;
         sleep(1) ;
         printf("\n") ;
      }
      if(estTermine(F,debut))
    printf("\n \n (-_-) --> Tous les processus sont termines , c-a-d : la file d'attente devient vide . \n") ;

      return debut ;
      }

node * peek_queue(myfile F){
return F.que ;
}
node * peek_tete(myfile F){
return F.tete ;
}
