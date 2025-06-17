#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

typedef struct process {
int id ;
int tmps_arrive ;
int tmps_rest;
}process ;

typedef struct node{
struct node *next ;
struct node *prev ;
process data ;
}node;

typedef struct {
int taille ;
node * tete ;
node * que ;
}myfile ;

// Prototypes des fonctions

// Initialisation de la file
myfile initialise_file(myfile F, int taille);

// Test d'état de la file
int estTermine(myfile* F, node* debut);
int estVide(myfile F);
int estPleinne(myfile F, int cmp);
// int seul_Element(myfile F); // Commentée dans ton code

// Opérations sur la file
void emfiler(myfile* F, node** debut, process prc);
void defiler(myfile** F, int quantum, node* debut);
void Afficher_File(node* debut, int cmp);
void Execut_process(myfile* F, node* debut, int quantum);
node* Gestion_Temps(myfile* F, node* debut, int quantum, int cmt, int cmp);

// Accès aux extrémités
node* peek_queue(myfile F);
node* peek_tete(myfile F);


#endif // PROCESS_H_INCLUDED
