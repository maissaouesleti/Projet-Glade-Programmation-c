#include <gtk/gtk.h>
typedef struct
{
int j; //les jours 1 2 3 4 ...
int repas; //1pour repas du petit dej 2pour repas midi et 3 pour repas du diner
float p; //poids des déchets
}dechet;


typedef struct{

int jour;
int mois;
int annee;

}modated;

 struct journee
 {
     char petitdej[200];
     char repas_midi[200];
     char diner[200];
 };
typedef struct{

char iden[20];
char type[20];
modated modate;
char prix[5];
struct journee jr;

}momenu;

int rech( Numrech);
void moajouter(char fich[],momenu menu);
void momodifier(char fich[],momenu menu);
void afficherMenus(GtkWidget *liste);
momenu moremplirmodif(char fich[],char idi[]);
int meilleurmenu();
int chercher_menu(GtkWidget* treeview1,char*l,char*type);
