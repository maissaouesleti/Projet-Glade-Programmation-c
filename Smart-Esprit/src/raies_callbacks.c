#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "raies_reclamation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int x1=0;
int x2=0;
char tyy[30]="hebergement";
char iddd[30];
reclamation t;
void
on_act_rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_rec;
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");
treeview1_rec=lookup_widget(afficher_rec,"treeview1_rec");
afficher_recc(treeview1_rec);
}


void
on_mod_rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");
gtk_widget_destroy(afficher_rec);
GtkWidget *modifierr_rec;

char id1[30];
char nom1[30];
char prenom1[30];
char cin1[30];
char type1[30];
char date1[30];
char service1[30];
char text[255];
int i=0;
FILE *f;

f=fopen("reclamation.txt","r");

 modifierr_rec = create_modifier_rec ();
  gtk_widget_show (modifierr_rec);

char matrice[6][30]={"Confort","Hygiène","Securité","Cafeteria","Nourriture","Encombrement"};


while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF){
 if (strcmp(iddd,id1)==0){decodage(text);

	while(i<6 && strcmp(matrice[i],service1)!=0)
	{
	i++;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifierr_rec,"comboboxentry2_rec")),i);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifierr_rec,"nom_rec1")),nom1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifierr_rec,"prenom_rec1")),prenom1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifierr_rec,"cin_rec1")),cin1);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifierr_rec,"text_rec1")),text);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifierr_rec,"comboboxentry2_rec")),service1);




    

}}
}


void
on_rechch_rec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_rec;
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");

treeview1_rec=lookup_widget(afficher_rec,"treeview1_rec");
cherch = lookup_widget (button ,"entre_rech_rec");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_recc(treeview1_rec,ch);
}


void
on_ajj_rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");
gtk_widget_destroy(afficher_rec);
GtkWidget *ajouter_rec;
ajouter_rec = create_ajouter_rec ();
  gtk_widget_show (ajouter_rec);
}


void
on_supp_rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");

GtkWidget *supprimer_rec;
supprimer_rec = create_supprimer_rec ();
  gtk_widget_show (supprimer_rec);
}


void
on_treeview1_rec_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* type;
	gchar* service;
	gchar* date;
	gchar* text;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id, 1, &nom,2,&prenom,3,&cin,4,&type,5,&service,6,&date,7,&text,-1);
	strcpy(iddd,id);
	
	}
}


void
on_ajout_recc_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *cin;
GtkWidget *type;

GtkWidget *service;
GtkWidget *date;
GtkWidget *text;


reclamation p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;

GtkWidget *ajouter_rec;
ajouter_rec=lookup_widget(button,"ajouter_rec");

nom = lookup_widget (button ,"nom_rec");
prenom = lookup_widget (button ,"prenom_rec");
cin = lookup_widget (button ,"cin_rec");
id = lookup_widget (button ,"id_rec");
service = lookup_widget (button ,"comboboxentry1_rec");
date = lookup_widget (button ,"calendar1_rec");
text = lookup_widget (button ,"text_rec");


GtkWidget *e_id_rec,*e_nom_rec,*e_prenom_rec,*e_cin_rec,*e_ser_rec,*e_conf_rec,*e_text_rec;



e_id_rec=lookup_widget(ajouter_rec,"e_id_rec");
e_nom_rec=lookup_widget(ajouter_rec,"e_nom_rec");
e_prenom_rec=lookup_widget(ajouter_rec,"e_prenom_rec");
e_cin_rec=lookup_widget(ajouter_rec,"e_cin_rec");
e_ser_rec=lookup_widget(ajouter_rec,"e_ser_rec");
e_conf_rec=lookup_widget(ajouter_rec,"e_conf_rec");
e_text_rec=lookup_widget(ajouter_rec,"e_text_rec");

gtk_calendar_get_date (GTK_CALENDAR(date),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;

strcpy(p.service,"");
p.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));

strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.text, gtk_entry_get_text(GTK_ENTRY(text)));
codage(p.text);


strcpy(p.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(service)));

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date_rec,y);

strcpy(p.type,tyy);


if (id_uniq(p.id)==1)
{o=1;
gtk_widget_show(e_id_rec);
}
else 
{o=0;
gtk_widget_hide(e_id_rec);
}
if (strcmp(p.nom,"")==0)
{o=1;
gtk_widget_show(e_nom_rec);
}
else 
{o=0;
gtk_widget_hide(e_nom_rec);
}

if (strcmp(p.prenom,"")==0)
{o=1;
gtk_widget_show(e_prenom_rec);
}
else 
{o=0;
gtk_widget_hide(e_prenom_rec);
}

if (strcmp(p.cin,"")==0)
{o=1;
gtk_widget_show(e_cin_rec);
}
else 
{o=0;
gtk_widget_hide(e_cin_rec);
}

if (strcmp(p.service,"")==0)
{o=1;
gtk_widget_show(e_ser_rec);
}
else 
{o=0;
gtk_widget_hide(e_ser_rec);
}

if (x1==0)
{o=1;
gtk_widget_show(e_conf_rec);
}
else 
{o=0;
gtk_widget_hide(e_conf_rec);
}

if (strcmp(p.text,"")==0)
{o=1;
gtk_widget_show(e_text_rec);
}
else 
{o=0;
gtk_widget_hide(e_text_rec);
}

 if(o==0 && x1==1){
ajouter_recc(p);



gtk_widget_destroy(ajouter_rec);
GtkWidget *afficher_rec;
afficher_rec = create_afficher_rec ();
  gtk_widget_show (afficher_rec);

x1=0;

}
}


void
on_modif_recc_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *cin;
GtkWidget *type;

GtkWidget *service;
GtkWidget *date;
GtkWidget *text;


reclamation p;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;

GtkWidget *ajouter_rec;
ajouter_rec=lookup_widget(button,"modifier_rec");

nom = lookup_widget (button ,"nom_rec1");
prenom = lookup_widget (button ,"prenom_rec1");
cin = lookup_widget (button ,"cin_rec1");
id = lookup_widget (button ,"id_rec1");
service = lookup_widget (button ,"comboboxentry2_rec");
date = lookup_widget (button ,"calendar2_rec");
text = lookup_widget (button ,"text_rec1");


GtkWidget *e_id_rec,*e_nom_rec,*e_prenom_rec,*e_cin_rec,*e_ser_rec,*e_conf_rec,*e_text_rec;



//e_id_rec=lookup_widget(ajouter_rec,"e_id_rec");
e_nom_rec=lookup_widget(ajouter_rec,"e_nom_rec1");
e_prenom_rec=lookup_widget(ajouter_rec,"e_prenom_rec1");
e_cin_rec=lookup_widget(ajouter_rec,"e_cin_rec1");
e_ser_rec=lookup_widget(ajouter_rec,"e_ser_1");
e_conf_rec=lookup_widget(ajouter_rec,"e_conf_1");
e_text_rec=lookup_widget(ajouter_rec,"e_text_rec1");


gtk_calendar_get_date (GTK_CALENDAR(date),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;

strcpy(p.service,"");
p.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));

strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.text, gtk_entry_get_text(GTK_ENTRY(text)));
codage(p.text);

strcpy(p.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(service)));

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,c);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,a);


strcpy(p.date_rec,y);

strcpy(p.type,tyy);

if (strcmp(p.text,"")==0)
{o=1;
gtk_widget_show(e_text_rec);
}
else 
{o=0;
gtk_widget_hide(e_text_rec);
}
if (strcmp(p.nom,"")==0)
{o=1;
gtk_widget_show(e_nom_rec);
}
else 
{o=0;
gtk_widget_hide(e_nom_rec);
}

if (strcmp(p.prenom,"")==0)
{o=1;
gtk_widget_show(e_prenom_rec);
}
else 
{o=0;
gtk_widget_hide(e_prenom_rec);
}

if (strcmp(p.cin,"")==0)
{o=1;
gtk_widget_show(e_cin_rec);
}
else 
{o=0;
gtk_widget_hide(e_cin_rec);
}

if (strcmp(p.service,"")==0)
{o=1;
gtk_widget_show(e_ser_rec);
}
else 
{o=0;
gtk_widget_hide(e_ser_rec);
}

if (x2==0)
{o=1;
gtk_widget_show(e_conf_rec);
}
else 
{o=0;
gtk_widget_hide(e_conf_rec);
}



 if(o==0 && x2==1){
modifier_recc(iddd,p);



gtk_widget_destroy(ajouter_rec);
GtkWidget *afficher_rec;
afficher_rec = create_afficher_rec ();
  gtk_widget_show (afficher_rec);



}
}


void
on_annn_mod_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_rec;
modifier_rec=lookup_widget(button,"modifier_rec");
gtk_widget_destroy(modifier_rec);
GtkWidget *afficher_rec;
afficher_rec = create_afficher_rec ();
  gtk_widget_show (afficher_rec);
}


void
on_ann_supp_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_rec;
supprimer_rec=lookup_widget(button,"supprimer_rec");
gtk_widget_destroy(supprimer_rec);
GtkWidget *afficher_rec;

  gtk_widget_show (afficher_rec);
}


void
on_con_supp_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_recc(iddd);
GtkWidget *supprimer_rec;
supprimer_rec=lookup_widget(button,"supprimer_rec");
gtk_widget_destroy(supprimer_rec);
GtkWidget *afficher_rec;

  gtk_widget_show (afficher_rec);
}


void
on_radiobutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"restauration");
}


void
on_radiobutton1_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"hebergement");
}


void
on_checkbutton1_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x1=1;
else x1=0;
}


void
on_checkbutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x2=1;
else x2=0;
}


void
on_annn_aj_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_re;
ajouter_re=lookup_widget(button,"ajouter_rec");
gtk_widget_destroy(ajouter_re);
GtkWidget *afficher_rec;
afficher_rec = create_afficher_rec ();
  gtk_widget_show (afficher_rec);
}


void
on_stat_recc_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char nbrr[30];
char typee[30];
char perr[30];

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
GtkWidget *nbr_rec_plus;
nbr_rec_plus=lookup_widget(button,"nbr_rec_plus");
GtkWidget *type_rec_plus;
type_rec_plus=lookup_widget(button,"type_rec_plus");
GtkWidget *pr_rec_plus;
pr_rec_plus=lookup_widget(button,"pr_rec_plus");
f=fopen("reclamation.txt","r");
int plus=0;
int somm=0;
int heb=0;
int res=0;
float perc=0;
while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF){
somm=somm+1;
if(strcmp(type1,"hebergement")==0){
heb=heb+1;
}
if(strcmp(type1,"restauration")==0){
res=res+1;
}}fclose(f);

if(heb>res){
plus=heb;
strcpy(typee,"hebergement");
float ii =heb;
float jj =somm;
perc=((ii/jj)*100);
}
else{
plus=res;
strcpy(typee,"restauration");
float ii =res;
float jj =somm;
perc=((ii/jj)*100);
}

sprintf(nbrr,"%d",plus);
sprintf(perr,"%f",perc);




gtk_label_set_text(GTK_LABEL(nbr_rec_plus),nbrr);
gtk_label_set_text(GTK_LABEL(type_rec_plus),typee);
gtk_label_set_text(GTK_LABEL(pr_rec_plus),perr);


}

/*
void
on_inscripp_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
window1=lookup_widget(button,"auth_rec");
gtk_widget_destroy(window1);
GtkWidget *inscri_rec;
inscri_rec = create_inscri_rec ();
  gtk_widget_show (inscri_rec);
}
*/
/*
void
on_auth_rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *erreur_pass;

erreur_pass = lookup_widget(button,"label56");

GtkWidget *username, *password, *windowAcceuil_hsm;
char user[20];
char passw[20];
int trouve;
username = lookup_widget (button, "auth_nom_rec");
password = lookup_widget (button, "auth_pass_rec");
strcpy(user ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(passw ,gtk_entry_get_text ( GTK_ENTRY(password)));
trouve=verif_pass(user,passw);
if (trouve==1)
{

GtkWidget *window1;
window1=lookup_widget(button,"auth_rec");
gtk_widget_destroy(window1);
GtkWidget *acuille_rec;
acuille_rec = create_acceuille_rec ();
  gtk_widget_show (acuille_rec);
}
else if (trouve==-1){gtk_widget_show (erreur_pass);}
}
*/

void
on_inscri_rec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login, *pw;
char login1[40];
char passw[40];
login = lookup_widget(button,"insc_nom_rec");
pw = lookup_widget(button,"insc_pass_rec");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
f=fopen("utilisateur.txt","a+");
if (f != NULL)
{
fprintf(f,"%s %s \n",login1,passw);

}
fclose(f);
GtkWidget *inscri_rec;
inscri_rec=lookup_widget(button,"inscri_rec");
gtk_widget_destroy(inscri_rec);

}


void
on_ann_inrec_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscri_rec;
inscri_rec=lookup_widget(button,"inscri_rec");
gtk_widget_destroy(inscri_rec);

}




void
on_go_aff1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuille_rec;
acceuille_rec=lookup_widget(button,"acceuille_rec");
gtk_widget_destroy(acceuille_rec);
GtkWidget *afficher_rec;
afficher_rec = create_afficher_rec ();
  gtk_widget_show (afficher_rec);
}


void
on_serv_pluss1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuille_rec;
acceuille_rec=lookup_widget(button,"acceuille_rec");
gtk_widget_destroy(acceuille_rec);
GtkWidget *tache2;
tache2 = create_tache2 ();
  gtk_widget_show (tache2);
}





void
on_serrplusrecl1_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char nbrr[30];
char typee[30];
char perr[30];

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
GtkWidget *nbr_rec_plus;
nbr_rec_plus=lookup_widget(button,"nbr_rec_plus1");
GtkWidget *type_rec_plus;
type_rec_plus=lookup_widget(button,"type_rec_plus1");
GtkWidget *pr_rec_plus;
pr_rec_plus=lookup_widget(button,"per_rec_plus1");
f=fopen("reclamation.txt","r");
int plus=0;
int somm=0;
int heb=0;
int res=0;
float perc=0;
while(fscanf(f, "%s %s %s %s %s %s %s %s\n",id1,nom1,prenom1,cin1,type1,service1,date1,text)!=EOF){
somm=somm+1;
if(strcmp(type1,"hebergement")==0){
heb=heb+1;
}
if(strcmp(type1,"restauration")==0){
res=res+1;
}}fclose(f);

if(heb>res){
plus=heb;
strcpy(typee,"hebergement");
float ii =heb;
float jj =somm;
perc=((ii/jj)*100);
}
else{
plus=res;
strcpy(typee,"restauration");
float ii =res;
float jj =somm;
perc=((ii/jj)*100);
}

sprintf(nbrr,"%d",plus);
sprintf(perr,"%f",perc);




gtk_label_set_text(GTK_LABEL(nbr_rec_plus),nbrr);
gtk_label_set_text(GTK_LABEL(type_rec_plus),typee);
gtk_label_set_text(GTK_LABEL(pr_rec_plus),perr);
}


void
on_deccc2_rec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
tache2=lookup_widget(button,"tache2");
gtk_widget_destroy(tache2);

}


void
on_home2_rec_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
tache2=lookup_widget(button,"tache2");
gtk_widget_destroy(tache2);
GtkWidget *acceuille_rec;
 acceuille_rec= create_acceuille_rec ();
  gtk_widget_show (acceuille_rec);
}

