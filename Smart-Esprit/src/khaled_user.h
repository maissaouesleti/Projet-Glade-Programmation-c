#include <gtk/gtk.h>

typedef struct
{
	char nom[20];
	char prenom[20];
	char cin[20];
	char sexe[20];
	int age;
	int num;
	char email[50];
	char poste[50];
}user;

typedef struct
{
	int j;
	int h;
	int cap;
	int val;
}alarme;

void add_user(user c);
void gbafficher(GtkWidget *liste);
void supp(user c);
void supp_cin( char cin[]);
int chercher_user(GtkWidget* treeview1,char*l,char*type);
void afficher_mvt(GtkWidget *liste);
void afficher_fume(GtkWidget *liste);

//////
int gbverif(char log[],char pw[]);

