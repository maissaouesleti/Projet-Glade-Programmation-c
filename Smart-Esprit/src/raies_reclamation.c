#include<stdio.h>
#include"raies_reclamation.h"
#include<string.h>
#include<gtk/gtk.h>

enum{
ID,
NOM,
PRENOM,
CIN,
TYPE,
SERVICE,
DATE,
TEXT,
COLUMNS
};





/* Fonction Ajouter */
void ajouter_recc(reclamation p)

{

FILE *f;
f=fopen("reclamation.txt","a+");
if (f!=NULL)
{
fprintf(f, "%d %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.cin,p.type,p.service,p.date_rec,p.text);

fclose(f);
}}




void afficher_recc(GtkWidget *liste )

{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("service",renderer,"text",SERVICE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date reclamation",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("reclamation",renderer,"text",TEXT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("util.txt","r");

char id1[30];
char nom1[30];
char prenom1[30];
char cin1[30];
char type1[30];
char date1[30];
char service1[30];
char text[255];


{
f=fopen("reclamation.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF)
	{ decodage(text);
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id1,NOM,nom1,PRENOM,prenom1,CIN,cin1,TYPE,type1,SERVICE,service1,DATE,date1,TEXT,text,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void rechercher_recc(GtkWidget *liste,char ch[30] )
{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("service",renderer,"text",SERVICE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date reclamation",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("reclamation",renderer,"text",TEXT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("util.txt","r");

char id1[30];
char nom1[30];
char prenom1[30];
char cin1[30];
char type1[30];
char date1[30];
char service1[30];
char text[255];


{
f=fopen("reclamation.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF)
	{ if((strcmp(ch,nom1)==0) || (strcmp(ch,prenom1)==0) || (strcmp(ch,type1)==0) || (strcmp(ch,id1)==0)){ decodage(text);
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id1,NOM,nom1,PRENOM,prenom1,CIN,cin1,TYPE,type1,SERVICE,service1,DATE,date1,TEXT,text,-1);
	}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



void supprimer_recc (char id[]){

char id1[30];
char nom1[30];
char prenom1[30];
char cin1[30];
char type1[30];
char date1[30];
char service1[30];
char text[255];

FILE*f=NULL;
FILE*f1=NULL;

f=fopen("reclamation.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF){
if(strcmp(id,id1)!=0){
    fprintf(f1, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text);
}}
fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("ancien.txt","reclamation.txt");
printf("suppeimer avec succes\n");
}


void modifier_recc(char id[],reclamation r){
char id1[30];
char nom1[30];
char prenom1[30];
char cin1[30];
char type1[30];
char date1[30];
char service1[30];
char text[255];
FILE*f=NULL;
FILE*f1=NULL;

f=fopen("reclamation.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF){
if(strcmp(id,id1)==0){
fprintf(f1, "%s %s %s %s %s %s %s %s\n",id1,r.nom,r.prenom,r.cin,type1,r.service,r.date_rec,r.text);
}
else
{
fprintf(f1, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text);
}

}
fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("ancien.txt","reclamation.txt");
printf("modifier avec succes \n");
}



int verifier_cin (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)!=8 )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}



 
int id_uniq (int id){

int id1;
char nom1[30];
char prenom1[30];
char cin1[30];
char type1[30];
char date1[30];
char service1[30];
char text[255];
int x=0;
FILE*f=NULL;


f=fopen("reclamation.txt","r");


while(fscanf(f, "%d %s %s %s %s %s %s %s\n",&id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF){
if(id==id1){
x=1;
}}
fclose(f);
return x;

}




int verif_pass(char log[], char pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if (f!=NULL){
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{if( (strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0)){
trouve=1;}
}
fclose(f);
}
return trouve;
}


void codage (char ch[]){
int i ;
for (i=0;i<strlen(ch);i++)
{ if (ch[i]==' '){ch[i]='_'; }

}}
void decodage (char ch[]){
int i ;
for (i=0;i<strlen(ch);i++)
{ if (ch[i]=='_'){ch[i]=' '; }

}}

