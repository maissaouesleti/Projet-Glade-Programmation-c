#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "maysa_fonction.h"
#include <string.h>

int motype = 1; // 0 if sucre et 1 if sale
int motypemodif ;
char moidentmodif[20];
int moflag = 0;
int tm[6]={0,0,0,0,0,0};




void
on_button1_mm_clicked                  (GtkButton       *button,
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
on_button5_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu , *window_supprimer;
menu=lookup_widget(button,"Menu");
window_supprimer=create_supprimer ();
gtk_widget_show(window_supprimer);
gtk_widget_destroy(menu);
}


void
on_button2_aj_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *menu , *window_ajouter;
menu=lookup_widget(button,"Menu");
window_ajouter=create_ajout();
gtk_widget_show(window_ajouter);
gtk_widget_destroy(menu);


}


void
on_button4_aff_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu , *window_affichage;
menu=lookup_widget(button,"Menu");
window_affichage=create_affichage();
gtk_widget_show(window_affichage);
gtk_widget_destroy(menu);
}


void
on_button3_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu , *modifier;
menu=lookup_widget(button,"Modifier");
modifier=create_Modifier();
gtk_widget_show(modifier);
gtk_widget_destroy(menu);
}


void
on_radiobutton2_sal_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		motype=1;
	}

}



void
on_checkbutton1_pd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tm[0]=1;}
}


void
on_checkbutton2_rm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tm[1]=1;}
}


void
on_checkbutton3_d_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tm[2]=1;}
}
void
on_checkbutton4_pd_toggled              (GtkToggleButton *togglebutton,
                                           gpointer         user_data)
{  

if(gtk_toggle_button_get_active(togglebutton))
{tm[3]=1;}
}


                                     
void
on_checkbutton5_rm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tm[4]=1;}
}
void
on_checkbutton6_d_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tm[5]=1;}
}


void
on_radiobutton1_suc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		motype=0;
	}
}



void
on_button1m_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ident,*jour,*mois,*annee,*prix;
char fich[20]="menu.txt";
momenu menu;

ident = lookup_widget(button,"entry3_id");
jour = lookup_widget(GTK_WIDGET(button),"jour");
mois = lookup_widget(GTK_WIDGET(button),"mois");
annee = lookup_widget(GTK_WIDGET(button),"annee");
prix = lookup_widget(GTK_WIDGET(button),"combobox1");

strcpy(menu.iden,gtk_entry_get_text(GTK_ENTRY(ident)));
menu.modate.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
menu.modate.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
menu.modate.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(menu.prix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(prix)));

if (motype){
strcpy(menu.type,"sale");
}else{
strcpy(menu.type,"sucre");
}
if (tm[0]==1)
{strcpy(menu.jr.petitdej,"petit-dejeuner");}
else
{strcpy(menu.jr.petitdej,"non");}
if(tm[1]==1)
{strcpy(menu.jr.repas_midi,"Repas-midi");}
else
{strcpy(menu.jr.repas_midi,"non");}
if(tm[2]==1)
{strcpy(menu.jr.diner,"Diner");}
else
{strcpy(menu.jr.diner,"non");}

moajouter(fich,menu);
GtkWidget *affichage,*ajout;
affichage = create_affichage();
ajout = lookup_widget(GTK_WIDGET(button),"ajout");
gtk_widget_destroy(ajout);
//gtk_widget_show(affichage);

}
void
on_button10_rech_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *window_affichage;
GtkWidget *ide;
GtkWidget *outputt;
char ident[5];
momenu menu;
int v;
ide=lookup_widget(button,"entry6");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(ide)));
v=rech(ident);
if(v==1)
{
window_affichage=create_affichage();
gtk_widget_show (window_affichage);
}
else
{
gtk_label_set_text(GTK_LABEL(outputt),"identifiant introuvable");
}*/
}

void
on_button9_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *ident,*jour,*mois,*annee,*prix,*togglebuttonsucre,*togglebuttonsale;
char fich[20]="menu.txt";
momenu menu;

ident = lookup_widget(button,"entry6");
jour = lookup_widget(GTK_WIDGET(button),"sp_jour");
mois = lookup_widget(GTK_WIDGET(button),"sp_mois");
annee = lookup_widget(GTK_WIDGET(button),"sp_annee");
prix = lookup_widget(GTK_WIDGET(button),"comboboxentry1");
togglebuttonsale = lookup_widget(GTK_WIDGET(button),"radiobutton4_sal");
togglebuttonsucre = lookup_widget(GTK_WIDGET(button),"radiobutton3_suc");

strcpy(menu.iden,gtk_entry_get_text(GTK_ENTRY(ident)));
menu.modate.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
menu.modate.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
menu.modate.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(menu.prix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(prix)));

if (motypemodif){
strcpy(menu.type,"sale");
}else{
strcpy(menu.type,"sucre");
}

momodifier(fich,menu);


}


void
on_button11_supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ident;
char fich[20]="menu.txt";
char iden[20];
momenu menu;

ident = lookup_widget(GTK_WIDGET(button),"entry9");
strcpy(iden,gtk_entry_get_text(GTK_ENTRY(ident)));

mosupprimer(fich,iden);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter  iter;
gchar *type;
gchar *id;
gchar *nom;
gchar *unite;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0 , &id ,-1);
strcpy(moidentmodif,id);

}
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *tree;

tree =  lookup_widget(GTK_WIDGET(button),"treeview1");

afficherMenus(tree);

}


gboolean
on_Modifier_focus_in_event             (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
if (!moflag){

GtkWidget *ident,*jour,*mois,*annee,*prix,*togglebuttonsucre,*togglebuttonsale,*b1,*b2,*b3;
char fich[20]="menu.txt";
momenu menu;

ident = lookup_widget(GTK_WIDGET(widget),"entry6");
jour = lookup_widget(GTK_WIDGET(widget),"sp_jour");
mois = lookup_widget(GTK_WIDGET(widget),"sp_mois");
annee = lookup_widget(GTK_WIDGET(widget),"sp_annee");
prix = lookup_widget(GTK_WIDGET(widget),"comboboxentry1");
togglebuttonsale = lookup_widget(GTK_WIDGET(widget),"radiobutton4_sal");
togglebuttonsucre = lookup_widget(GTK_WIDGET(widget),"radiobutton3_suc");
b1 = lookup_widget(GTK_WIDGET(widget),"checkbutton4_pd");
b2 = lookup_widget(GTK_WIDGET(widget),"checkbutton5_rm");
b3 = lookup_widget(GTK_WIDGET(widget),"checkbutton6_d");

menu = moremplirmodif(fich ,moidentmodif );

gtk_entry_set_text(GTK_ENTRY(ident),menu.iden);
gtk_spin_button_set_value(jour,menu.modate.jour);
gtk_spin_button_set_value(mois,menu.modate.mois);
gtk_spin_button_set_value(annee,menu.modate.annee);
if (strcmp(menu.prix,"1DT")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(prix), 0);
}
if (strcmp(menu.prix,"2DT")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(prix), 1);
}
if (strcmp(menu.prix,"3DT")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(prix), 2);
}
if (strcmp(menu.prix,"4DT")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(prix), 3);
}
if (strcmp(menu.prix,"5DT")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(prix), 4);
}
if (strcmp(menu.type,"sale")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebuttonsale),TRUE);
motypemodif = 1;
}else
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebuttonsucre),TRUE);
motypemodif = 0;
}
if (tm[0]==1)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(b1),TRUE);}
if(tm[1]==1)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(b2),TRUE);}
if(tm[2]==1)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(b3),TRUE);}

//strcpy(moidentmodif,"");

moflag = 1;
}
  return FALSE;
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_m, *window_supp;
window_supp=lookup_widget(button,"supprimer");
gtk_widget_destroy(window_supp);
//window_m=create_affichage();
//gtk_widget_show(window_m);
}


void
on_button4_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu, *mm;
mm = lookup_widget(button,"window_mm");
gtk_widget_destroy(mm);
menu = create_affichage();
//gtk_widget_show(menu);
}


void
on_button5_calcul_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{int r=1;
GtkWidget *output2;
output2 = lookup_widget(button,"output2");
r = meilleurmenu();
if (r==1)
gtk_label_set_text(GTK_LABEL(output2),"EST CELUI DU PETIT DEJEUNER");
else if (r==2)
gtk_label_set_text(GTK_LABEL(output2),"EST CELUI DU REPAS MIDI");
else if (r==3)
gtk_label_set_text(GTK_LABEL(output2),"EST CELUI DU REPAS DU DINER");
}



void
on_mod_menu_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu , *modifier;
menu=lookup_widget(button,"Modifier");
modifier=create_Modifier();
gtk_widget_show(modifier);
gtk_widget_destroy(menu);
moflag=0;
}


