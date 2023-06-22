#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "safa_fonction.h"
#include "maysa_fonction.h"




int retourdash=0; //0 if return to auth and 1 if to dash

void
on_FS_foyer_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *show, *des;
des=lookup_widget(button,"FS_wlc_foyer");
gtk_widget_destroy(des);
show=create_safaflissespacefoyer();
gtk_widget_show (show);
}


void
on_FS_foyer_logout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
if(!retourdash){
GtkWidget *windowgb_welcome, *window_destroy;
window_destroy=lookup_widget(button,"FS_wlc_foyer");
gtk_widget_destroy(window_destroy);
windowgb_welcome=create_gb_auth();
gtk_widget_show (windowgb_welcome);
retourdash = 0; 
}else{
GtkWidget *windowgb_welcome, *window_destroy;
window_destroy=lookup_widget(button,"FS_wlc_foyer");
gtk_widget_destroy(window_destroy);
windowgb_welcome=create_gb_welcome_all();
gtk_widget_show (windowgb_welcome);
retourdash = 1; 
}
}


void
on_MG_stock_logout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
if(!retourdash){
GtkWidget *windowgb_welcome, *window_destroy;
window_destroy=lookup_widget(button,"MG_wlc_stock");
gtk_widget_destroy(window_destroy);
windowgb_welcome=create_gb_auth();
gtk_widget_show (windowgb_welcome);
retourdash = 0; 
}else{
GtkWidget *windowgb_welcome, *window_destroy;
window_destroy=lookup_widget(button,"MG_wlc_stock");
gtk_widget_destroy(window_destroy);
windowgb_welcome=create_gb_welcome_all();
gtk_widget_show (windowgb_welcome);
retourdash = 1; 
}
}


void
on_MG_Dashboard_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Dash,*safa;
Dash = create_dashboard();//(GTK_WIDGET(button),"dashboard");

gtk_widget_show(Dash);
GtkWidget *tree;
char text[150];
char nbetud[3];
etudiant etud;

tree =  lookup_widget(Dash,"dash_tree_stock");

safa = lookup_widget(Dash,"dash_nbr_elev1er");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 1ere:   ");
sprintf(nbetud,"%d",nombreetud(etud,"1"));
strcat(text,nbetud);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev2eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 2eme:   ");
sprintf(nbetud,"%d",nombreetud(etud,"2"));
strcat(text,nbetud);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev3eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 3eme:   ");
sprintf(nbetud,"%d",nombreetud(etud,"3"));
strcat(text,nbetud);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev4eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 4eme:   ");
sprintf(nbetud,"%d",nombreetud(etud,"4"));
strcat(text,nbetud);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev5eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 5eme:   ");
sprintf(nbetud,"%d",nombreetud(etud,"5"));
strcat(text,nbetud);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

//////
mgafficherstock(tree,"reptureplease");
/////
FILE *f=NULL;
f=fopen("reclamation.txt","r");
int plus=0;
int somm=0;
int heb=0;
int res=0;
float perc=0;
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
sprintf(perr,"%.2f",perc);



safa = lookup_widget(Dash,"dash_rec_plus");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le type de service le plus reclame est   :  ");
//sprintf(nbetud,"%d",p);
strcat(text,typee);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nb_rec");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Avec un nombre des reclamation =   ");
//sprintf(nbetud,"%d",nombreetud(etud,"5"));
strcat(text,nbrr);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_pr_rec");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Et un pourcentage =   ");
//printf(nbetud,"%d",nombreetud(etud,"5"));
strcat(text,perr);
strcat(text,"%</b></span>");
gtk_label_set_markup(safa,text);


dechet min;
dechet dech;
dechet dechs[88];
float tabdech[88];
int i=0;
int r; 
//FILE *f=NULL;
f=fopen("dechets.txt","r");
if(f == NULL)
{
strcpy(nbetud,"null");
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
char test[50];
r = 0;//min.repas;
//strcpy(test,"5");
sprintf(test,"%d",min.repas);
//strcpy(nbetud,"null");
if (strcmp(test,"1")==0)
strcpy(test,"EST CELUI DU PETIT DEJEUNER");
if (strcmp(test,"2")==0)
strcpy(test,"EST CELUI DU REPAS MIDI");
if (strcmp(test,"3")==0)
strcpy(test,"EST CELUI DU REPAS DU DINER");

safa = lookup_widget(Dash,"dash_mm");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le meilleur men de la semaine:   ");
//sprintf(nbetud,"%d",nombreetud(etud,"5"));

strcat(text,test);
strcat(text,"</b></span>");
gtk_label_set_markup(safa,text);


GtkWidget *treeview1;
GtkWidget *treeview2;


treeview1=lookup_widget(Dash,"dash_tree_mvt");
afficher_fume(treeview1);

treeview2=lookup_widget(Dash,"dash_tree_fume");
afficher_mvt(treeview2);


GtkWidget *treedef;

treedef=lookup_widget(Dash,"dash_tree_captdef");
afficherdef(treedef);
}


void
on_MG_gestion_stock_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *show, *des;
des=lookup_widget(button,"MG_wlc_stock");
gtk_widget_destroy(des);
show=create_MGWindowStock ();
gtk_widget_show (show);
}


void
on_SF_dashboard_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FS_retour_wlc_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *show, *des;
des=lookup_widget(button,"safaflissespacefoyer");
gtk_widget_destroy(des);
show=create_gb_auth ();
gtk_widget_show (show);
retourdash = 0;
}else{
GtkWidget *show, *des;
des=lookup_widget(button,"safaflissespacefoyer");
gtk_widget_destroy(des);
show=create_gb_welcome_all ();
gtk_widget_show (show);
retourdash = 1;

}
}


void
on_MG_retour_to_wlc_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *show, *des;
des=lookup_widget(button,"MGWindowStock");
gtk_widget_destroy(des);
show=create_gb_auth();
gtk_widget_show (show);
retourdash = 0;
}else{
GtkWidget *show, *des;
des=lookup_widget(button,"MGWindowStock");
gtk_widget_destroy(des);
show=create_gb_welcome_all();
gtk_widget_show (show);
retourdash = 1;
}
}




void
on_gb_aff_tache2_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
GtkWidget *treeview1;
GtkWidget *treeview2;
window_destroy=lookup_widget(objet,"gb_aff");
gtk_widget_destroy(window_destroy);
windowgb_show=create_gb_liste();
gtk_widget_show (windowgb_show);


treeview1=lookup_widget(windowgb_show,"gb_treefumee");
afficher_fume(treeview1);

treeview2=lookup_widget(windowgb_show,"gb_treemvt");
afficher_mvt(treeview2);
}


void
on_rmaff_captdef_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *des;
des=lookup_widget(button,"acceuil");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_liste_des_capteurs ();
gtk_widget_show (aff);
}





void
on_radiobutton3_suc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton4_sal_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}



void
on_wlc_all_admin_dash_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
retourdash = 1;
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
/*windowgb_show=create_dashboard ();
gtk_widget_show (windowgb_show);*/

GtkWidget *Dash,*safa;
Dash = create_dashboard();//(GTK_WIDGET(button),"dashboard");

gtk_widget_show(Dash);
GtkWidget *tree;
char text[150];
char nbetud[3];
etudiant etud;

tree =  lookup_widget(Dash,"dash_tree_stock");

safa = lookup_widget(Dash,"dash_nbr_elev1er");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 1ere:   </b></span>");
sprintf(nbetud,"%d",nombreetud(etud,"1"));
strcat(text,nbetud);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev2eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 2eme:   </b></span>");
sprintf(nbetud,"%d",nombreetud(etud,"2"));
strcat(text,nbetud);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev3eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 3eme:   </b></span>");
sprintf(nbetud,"%d",nombreetud(etud,"3"));
strcat(text,nbetud);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev4eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 4eme:   </b></span>");
sprintf(nbetud,"%d",nombreetud(etud,"4"));
strcat(text,nbetud);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nbr_elev5eme");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le nombre de etudiant de 5eme:   </b></span>");
sprintf(nbetud,"%d",nombreetud(etud,"5"));
strcat(text,nbetud);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

//////
mgafficherstock(tree,"reptureplease");
/////
FILE *f=NULL;
f=fopen("reclamation.txt","r");
int plus=0;
int somm=0;
int heb=0;
int res=0;
float perc=0;
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
sprintf(perr,"%.2f",perc);



safa = lookup_widget(Dash,"dash_rec_plus");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le type de service le plus reclame est   :  </b></span>");
//sprintf(nbetud,"%d",p);
strcat(text,typee);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_nb_rec");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Avec un nombre des reclamation =   </b></span>");
//sprintf(nbetud,"%d",nombreetud(etud,"5"));
strcat(text,nbrr);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);

safa = lookup_widget(Dash,"dash_pr_rec");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Et un pourcentage =   </b></span>");
//printf(nbetud,"%d",nombreetud(etud,"5"));
strcat(text,perr);
//strcat(text,"%</span>");
gtk_label_set_markup(safa,text);


dechet min;
dechet dech;
dechet dechs[88];
float tabdech[88];
int i=0;
int r; 
//FILE *f=NULL;
f=fopen("dechets.txt","r");
if(f == NULL)
{
strcpy(nbetud,"null");
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
char test[50];
r = 0;//min.repas;
//strcpy(test,"5");
sprintf(test,"%d",min.repas);
//strcpy(nbetud,"null");
if (strcmp(test,"1")==0)
strcpy(test,"EST CELUI DU PETIT DEJEUNER");
if (strcmp(test,"2")==0)
strcpy(test,"EST CELUI DU REPAS MIDI");
if (strcmp(test,"3")==0)
strcpy(test,"EST CELUI DU REPAS DU DINER");

safa = lookup_widget(Dash,"dash_mm");
strcpy(text,"<span color=\"black\" font-size=\"13500\"><b>Le meilleur men de la semaine:  </b></span> ");
//sprintf(nbetud,"%d",nombreetud(etud,"5"));

strcat(text,test);
//strcat(text,"</span>");
gtk_label_set_markup(safa,text);


GtkWidget *treeview1;
GtkWidget *treeview2;


treeview1=lookup_widget(Dash,"dash_tree_mvt");
afficher_fume(treeview1);

treeview2=lookup_widget(Dash,"dash_tree_fume");
afficher_mvt(treeview2);


GtkWidget *treedef;

treedef=lookup_widget(Dash,"dash_tree_captdef");
afficherdef(treedef);
}


void
on_gb_goauth_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_auth();
gtk_widget_show (windowgb_auth);
retourdash = 0;
}


void
on_out_dashboard_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"dashboard");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_auth();
gtk_widget_show (windowgb_auth);
retourdash = 0;
}else{
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"dashboard");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_welcome_all();
gtk_widget_show (windowgb_auth);
retourdash = 1;

}
}


void
on_gb_quitter_btn_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(objet,"gb_welcome");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_auth();
gtk_widget_show (windowgb_auth);
retourdash = 0;
}else{
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(objet,"gb_welcome");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_welcome_all();
gtk_widget_show (windowgb_auth);
retourdash = 1;

}
}



void
on_gb_auth_connecter_btn_clicked        (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *windowwlc;
GtkWidget *window_destroy;
GtkWidget *label_err;
char user[20];
char passw[20];
int trouve;
label_err=lookup_widget(objet,"label_auth_err");

gtk_widget_hide(label_err);
username = lookup_widget (objet, "gb_auth_cin");
password = lookup_widget (objet, "gb_auth_mdp");
strcpy(user ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(passw ,gtk_entry_get_text ( GTK_ENTRY(password)));
trouve=gbverif(user,passw);
if (trouve==1)
{
if(strcmp(passw,"khaled")==0)
{

windowwlc=create_gb_welcome ();
gtk_widget_show (windowwlc);
}
else if(strcmp(passw,"mahdi")==0)
{
windowwlc=create_MG_wlc_stock();
gtk_widget_show (windowwlc);}

else if(strcmp(passw,"safa")==0)
{
windowwlc=create_FS_wlc_foyer ();
gtk_widget_show (windowwlc);}

else if(strcmp(passw,"raies")==0)
{
windowwlc=create_acceuille_rec ();
gtk_widget_show (windowwlc);}

else if(strcmp(passw,"rania")==0)
{
windowwlc=create_Home();
gtk_widget_show (windowwlc);}

else if(strcmp(passw,"maysa")==0)
{
windowwlc=create_mo_wlc();
gtk_widget_show (windowwlc);}

else if(strcmp(passw,"admin")==0)
{
windowwlc=create_gb_welcome_all ();
gtk_widget_show (windowwlc);
retourdash = 1;
}


window_destroy=lookup_widget(objet,"gb_auth");
gtk_widget_destroy(window_destroy);
}
else 
printf("\n NOT FOUND");
gtk_widget_show(label_err);

}


void
on_gb_aff_retour_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
if(!retourdash){
GtkWidget *windowgb_welcome, *window_destroy;
window_destroy=lookup_widget(objet,"gb_aff");
gtk_widget_destroy(window_destroy);
windowgb_welcome=create_gb_auth();
gtk_widget_show (windowgb_welcome);
retourdash = 0; 
}else{
GtkWidget *windowgb_welcome, *window_destroy;
window_destroy=lookup_widget(objet,"gb_aff");
gtk_widget_destroy(window_destroy);
windowgb_welcome=create_gb_welcome_all();
gtk_widget_show (windowgb_welcome);
retourdash = 1; 
}
}


void
on_buttonhome_exit_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *des;
des=lookup_widget(objet,"Home");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_gb_auth ();
  gtk_widget_show (aff);
retourdash = 0;
}else{
GtkWidget *des;
des=lookup_widget(objet,"Home");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_gb_welcome_all ();
  gtk_widget_show (aff);
retourdash = 1;

}
}


void
on_rmaffquit_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *des;
des=lookup_widget(button,"acceuil");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_gb_auth ();
  gtk_widget_show (aff);
retourdash = 0;
}else{
GtkWidget *des;
des=lookup_widget(button,"acceuil");
gtk_widget_destroy(des);
GtkWidget *aff;
aff= create_gb_welcome_all ();
  gtk_widget_show (aff);
retourdash = 1;

}
}


void
on_decc_rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{if (!retourdash){
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");
gtk_widget_destroy(afficher_rec);
GtkWidget *aff;
aff= create_gb_auth ();
  gtk_widget_show (aff);
retourdash = 0;
}else{
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"afficher_rec");
gtk_widget_destroy(afficher_rec);
GtkWidget *aff;
aff= create_gb_welcome_all ();
  gtk_widget_show (aff);
retourdash = 1;
}
}

void
on_ret_acui1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{if (!retourdash){
GtkWidget *acceuille_rec;
acceuille_rec=lookup_widget(button,"acceuille_rec");
gtk_widget_destroy(acceuille_rec);
GtkWidget *aff;
aff= create_gb_auth ();
  gtk_widget_show (aff);
retourdash = 0;
}else{
GtkWidget *afficher_rec;
afficher_rec=lookup_widget(button,"acceuille_rec");
gtk_widget_destroy(afficher_rec);
GtkWidget *aff;
aff= create_gb_welcome_all ();
  gtk_widget_show (aff);
retourdash = 1;
}

}





void
on_buton_clicked                       (GtkButton       *button,
                                        gpointer         user_data)

{
if (!retourdash){
GtkWidget *window_m, *window_affichage;
window_affichage=lookup_widget(button,"affichage");
gtk_widget_destroy(window_affichage);
window_m=create_gb_auth();
gtk_widget_show(window_m);
retourdash = 0;
}else{
GtkWidget *window_m, *window_affichage;
window_affichage=lookup_widget(button,"affichage");
gtk_widget_destroy(window_affichage);
window_m=create_gb_welcome_all();
gtk_widget_show(window_m);
retourdash = 1;

}
}


void
on_retmaysa_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *window_m, *window_affichage;
window_affichage=lookup_widget(button,"Menu");
gtk_widget_destroy(window_affichage);
window_m=create_gb_auth();
gtk_widget_show(window_m);
retourdash = 0;
}else{
GtkWidget *window_m, *window_affichage;
window_affichage=lookup_widget(button,"Menu");
gtk_widget_destroy(window_affichage);
window_m=create_gb_welcome_all();
gtk_widget_show(window_m);
retourdash = 1;

}
}


void
on_go_to_esp_nut_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
GtkWidget *treeview1;
window_destroy=lookup_widget(button,"mo_wlc");
gtk_widget_destroy(window_destroy);
windowgb_show=create_affichage();
gtk_widget_show (windowgb_show);

/*treeview1=lookup_widget(windowgb_show,"treeview1");
afficherMenus(treeview1);*/
}


void
on_supp_menu_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu , *window_supprimer;
menu=lookup_widget(button,"Menu");
window_supprimer=create_supprimer ();
gtk_widget_show(window_supprimer);
gtk_widget_destroy(menu);
}


void
on_add_menu_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu , *window_ajouter;
menu=lookup_widget(button,"Menu");
window_ajouter=create_ajout();
gtk_widget_show(window_ajouter);
gtk_widget_destroy(menu);
}


void
on_best_menu_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char r [30];
GtkWidget  *menu,*output2,*menu1;
menu=lookup_widget(button,"Menu");
gtk_widget_destroy(menu);
menu1=create_window_mm();
gtk_widget_show(menu1);
}


void
on_quit_menu_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"affichage");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_auth();
gtk_widget_show (windowgb_auth);
retourdash = 0;
}else{
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"affichage");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_welcome_all();
gtk_widget_show (windowgb_auth);
retourdash = 1;
}
}


void
on_refresh_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree;

tree =  lookup_widget(GTK_WIDGET(button),"treeview1");

afficherMenus(tree);

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
if (!retourdash){
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"mo_wlc");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_auth();
gtk_widget_show (windowgb_auth);
retourdash = 0;
}else{
GtkWidget *windowgb_auth, *window_destroy;
window_destroy=lookup_widget(button,"mo_wlc");
gtk_widget_destroy(window_destroy);
windowgb_auth=create_gb_welcome_all();
gtk_widget_show (windowgb_auth);
retourdash = 1;

}
}

/*
void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelcin;
GtkWidget *nbResultat;
GtkWidget *message;
char cin[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(button,"chercher_menu");
//labelid=lookup_widget(gestion,"label47");
p1=lookup_widget(button,"treeview1");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entry)));
nb=chercher_menu(p1,"menu.txt",cin);
}*/


void
on_button6_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelcin;
GtkWidget *nbResultat;
GtkWidget *message;
char cin[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(button,"chercher_menu");
//labelid=lookup_widget(gestion,"label47");
p1=lookup_widget(button,"treeview1");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entry)));
nb=chercher_menu(p1,"menu.txt",cin);
}


void
on_ajout_menu_retour_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"ajout");
gtk_widget_destroy(window_destroy);
}




