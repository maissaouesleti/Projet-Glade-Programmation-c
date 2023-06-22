#include "maysa_fonction.h"
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
int rech( int Numrech,char fich[])
{
momenu menu;
FILE *f;
f=fopen(fich,"r");
do
{
fscanf(f,"%s %s %d %d %d %s %s %s %s \n",menu.iden,menu.type,&menu.modate.jour,&menu.modate.mois,&menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner);

fflush(stdin);
if (menu.iden==Numrech)
{
fclose(f);
return 1;
}
}while(!EOF);
fclose(f);
return -1;
}



void moajouter(char fich[],momenu menu){
	
	FILE *f = NULL;
	f = fopen(fich,"a+");
	if (f!= NULL){
	fprintf(f,"%s %s %d %d %d %s %s %s %s \n",menu.iden,menu.type,menu.modate.jour,menu.modate.mois,menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner);
}
	fclose(f);
}

momenu moremplirmodif(char fich[],char idi[]){
	FILE *f=NULL;
	momenu menu;
	f = fopen(fich,"r");
	if (f!=NULL){
		while(fscanf(f,"%s %s %d %d %d %s %s %s %s\n",menu.iden,menu.type,&menu.modate.jour,&menu.modate.mois,&menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner)!=EOF){
	printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa %s",idi);
	if (strcmp(idi,menu.iden)==0){
		return menu;
			}
		}
	}
	fclose(f);
	return menu;
}


void momodifier(char fich[],momenu m){
	FILE *f=NULL;
	FILE*t = NULL;
	momenu menu;
	f = fopen(fich,"r");
	t = fopen("tmp.txt","a+");
	if (f!=NULL){
		while(fscanf(f,"%s %s %d %d %d %s %s %s %s \n",menu.iden,menu.type,&menu.modate.jour,&menu.modate.mois,&menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner)!=EOF){
	if (strcmp(m.iden,menu.iden)==0){
	fprintf(t,"%s %s %d %d %d %s %s %s %s \n",m.iden,m.type,m.modate.jour,m.modate.mois,m.modate.annee,m.prix,m.jr.petitdej,m.jr.repas_midi,m.jr.diner);
			}else{
	fprintf(t,"%s %s %d %d %d %s %s %s %s \n",menu.iden,menu.type,menu.modate.jour,menu.modate.mois,menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner);
}
		}
	}
	fclose(f);
	fclose(t);
        remove(fich);
	rename("tmp.txt",fich);
	

}

void mosupprimer(char fich[],char iden[]){
	FILE *f=NULL;
	FILE *t = NULL;
	momenu menu;
	f = fopen(fich,"r");
	t = fopen("tmp.txt","a+");
	if (f != NULL){
		while(fscanf(f,"%s %s %d %d %d %s %s %s  %s\n",menu.iden,menu.type,&menu.modate.jour,&menu.modate.mois,&menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner)!=EOF){
	if (strcmp(iden,menu.iden)==0){
			}else{
	fprintf(t,"%s %s %d %d %d %s %s %s %s\n",menu.iden,menu.type,menu.modate.jour,menu.modate.mois,menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner);
}
		}
	
	}
	fclose(f);
	fclose(t);
        remove(fich);
	rename("tmp.txt",fich);
}

enum{
IDENTIFIANT,
TYPE,
JOUR,
MOIS,
ANNEE,
PRIX,
PETIT_DEJ,
REPAS_MIDI,
DINER,
COLUMNS
};

void afficherMenus(GtkWidget *liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

momenu menu;
store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("identi",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Petit dejeuner",renderer,"text",PETIT_DEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Repas Midi",renderer,"text",REPAS_MIDI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Diner",renderer,"text",DINER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store= gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("menu.txt","r");
if(f==NULL)
{return;}
else
{f=fopen("menu.txt","a+");
while(fscanf(f,"%s %s %d %d %d %s %s %s %s \n",menu.iden,menu.type,&menu.modate.jour,&menu.modate.mois,&menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner)!=EOF)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDENTIFIANT,menu.iden,TYPE,menu.type,JOUR,menu.modate.jour,MOIS,menu.modate.mois,ANNEE,menu.modate.annee,PRIX,menu.prix,PETIT_DEJ,menu.jr.petitdej,REPAS_MIDI,menu.jr.repas_midi,DINER,menu.jr.diner-1);

//gtk_list_store_set(store,&iter,IDENTIFIANT,menu.iden,TYPE,menu.type,JOUR,menu.modate.jour,MOIS,menu.modate.mois,ANNEE,menu.modate.annee,PRIX,menu.prix,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



int meilleurmenu(){
dechet min;
dechet dech;
dechet dechs[88];
float tabdech[88];
int i=0;
int r; 
FILE *f=NULL;
f=fopen("dechets.txt","r");
if(f == NULL)
{
//printf("le fichier n'existe pas\n");
}
else
{
while(fscanf(f,"%d %d %f",&dech.j,&dech.repas,&dech.p)!=EOF) {dechs[i]=dech;i++;}
fclose(f);}
min.p=100000.0;
for(i=0;i<87;i++)
{
if(min.p>dechs[i].p) min=dechs[i];
}
return min.repas;
}



int chercher_menu(GtkWidget* treeview1,char*l,char*type)
{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
momenu menu;
int nb=0, j;


        /* Creation du modele */
        adstore = gtk_list_store_new(8,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
				     G_TYPE_INT,
				     G_TYPE_INT,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
			             G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %d %d %d %s %s %s %s \n",menu.iden,menu.type,&menu.modate.jour,&menu.modate.mois,&menu.modate.annee,menu.prix,menu.jr.petitdej,menu.jr.repas_midi,menu.jr.diner)!=EOF)
        {
if( strcmp(type,menu.iden)==0){ nb++;
GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,menu.iden,
                            1,menu.type,
                            2,menu.modate.jour,
                            3,menu.modate.mois,
                            4,menu.modate.annee,
		            5,menu.prix,
			    6,menu.jr.petitdej,
			    7,menu.jr.repas_midi,
			    8,menu.jr.diner,
                            -1);}
}
        fclose(f);

/* Creation de la 1ere colonne */
if(j==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
/* Ajouter la 2emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jour",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
/* Ajouter la 3emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mois",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
/* Ajouter la 4emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("année",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
/* Ajouter la 5emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prix",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
/* Ajouter la 6emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("petitdej",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("repas midi",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("diner",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

j++;}

  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}


