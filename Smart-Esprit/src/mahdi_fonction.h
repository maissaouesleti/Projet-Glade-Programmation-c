#include <gtk/gtk.h>

typedef struct Date{

int jour,mois,annee;


}Date;

typedef struct produit{

char type[30],id[30],name[30],unity[30],embale[30];
int quantity,alert;
Date date;

}produit;

const char* mgcheckstring(char stringe[]);
const char* mgdecompstring(char stringe[]);
int mgajouterstock(char fich[],produit p);
int mgmodifierstock(char fich[], produit m,int supp);
produit mgrempliredit(char fich[], char id[]);
int mgsupprimerstock(char fich[],char id[]);
produit mgrechercherstock(char fich[], char id[]);
void mgafficherstock(GtkWidget *liste,char idi[]);
//void mgafficherstock(char fich[],char id[]);
void mgrepture_stock(char fich[]);
//void mgvider(GtkWidget *liste);
/*void mgrechercher(char fich[], char id[],GtkWidget *liste);*/
void mgrepturestock(char fich[], GtkWidget *liste);
int mgchecksubstring(char str1[], char str2[]);
void mgstockenstock(char fich[], GtkWidget *liste);
int mgcheckid(char fich[], char id[]);


void send_email(char to[]);

struct upload_status {
  int lines_read;
};
void mgreptureemail(char fich[]);

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp);
