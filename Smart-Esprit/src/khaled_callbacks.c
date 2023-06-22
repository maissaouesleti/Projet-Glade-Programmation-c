#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "khaled_user.h"
/////////////////////////////////////////KHALED////////////////////////////////////
user p;
char cinident[50];
int sexe,sexem,x;
void
on_gb_auth_insc_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{

}






void
on_gb_treeview_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *nom;
gchar *prenom;
gchar *sexe;
gint *age;
gint *num;
gchar *email;
gchar *cin;
gchar *poste;

GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&age,4,&sexe,5,&num,6,&email,7,&poste,-1);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(cinident,cin);
strcpy(p.cin,cin);
strcpy(p.sexe,sexe);
strcpy(p.email,email);
strcpy(p.poste,poste);
p.age=age;
p.num=num;
//supp(p);
//gbafficher(treeview);
}
}



void
on_gb_aff_modif_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_modif, *window_destroy;
window_destroy=lookup_widget(objet,"gb_aff");
gtk_widget_destroy(window_destroy);
windowgb_modif=create_gb_modifier();
gtk_widget_show (windowgb_modif);





}


void
on_gb_aff_supp_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar *cin;
        
       /* p=lookup_widget(objet,"gb_treeview");
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,2,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView*/

GtkWidget *windowgb_show;
windowgb_show=create_gb_confirmer_supp();
gtk_widget_show (windowgb_show);

}



void
on_gb_aff_rech_btn_clicked             (GtkWidget      *objet,
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
entry=lookup_widget(objet,"gb_aff_rech_entry");
//labelid=lookup_widget(gestion,"label47");
p1=lookup_widget(objet,"gb_treeview");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entry)));
nb=chercher_user(p1,"user.txt",cin);
}


void
on_gb_aff_add_btn_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *windowgb_add, *window_destroy;
GtkWidget *fail,*succ;

window_destroy=lookup_widget(objet,"gb_aff");
gtk_widget_destroy(window_destroy);
windowgb_add=create_gb_add();
gtk_widget_show (windowgb_add);
fail=lookup_widget(objet,"label_fail");
succ=lookup_widget(objet,"label_succ");
gtk_widget_hide(fail);
gtk_widget_hide(succ);
}


void
on_gb_add_retour_btn_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_aff, *window_destroy;
GtkWidget *treeview1;
window_destroy=lookup_widget(objet,"gb_add");
gtk_widget_destroy(window_destroy);
windowgb_aff=create_gb_aff();
gtk_widget_show (windowgb_aff);


treeview1=lookup_widget(windowgb_aff,"gb_treeview");
gbafficher(treeview1);
}


void
on_gb_add_add_btn_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
user c;
int a;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
GtkWidget *fenetre_ajout;
GtkWidget *fail,*succ;
fail=lookup_widget(objet,"label_fail");
succ=lookup_widget(objet,"label_succ");



fenetre_ajout=lookup_widget(objet,"gb_add");
input1=lookup_widget(objet,"gb_add_name");
input2=lookup_widget(objet,"gb_add_prename");
input3=lookup_widget(objet,"gb_add_cin");
input4=lookup_widget(objet,"gb_add_num");
input5=lookup_widget(objet,"gb_add_email");

input6=lookup_widget(objet,"gb_add_combo_poste");
input7=lookup_widget(objet,"gb_add_spin_age");
input8=lookup_widget(objet,"gb_add_homme");
input9=lookup_widget(objet,"gb_add_femme");

if(sexe==1)
{
//gtk_toggle_button_set_active(GTK_RADIO_BUTTON(input8),TRUE);
strcpy(c.sexe,"Homme");
}
else
{
//gtk_toggle_button_set_active(GTK_RADIO_BUTTON(input9),TRUE);
strcpy(c.sexe,"Femme");
}

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
c.num=atoi(gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
c.age=a;
if(x==1)
{
if(strcmp(c.nom,"")!=0&&strcmp(c.prenom,"")!=0&&strcmp(c.cin,"")!=0&&strcmp(c.sexe,"")!=0&& (c.age>=18) && (c.num!=0) && strcmp(c.email,"")!=0&&strcmp(c.poste,"")!=0)
{gtk_widget_show(succ);
gtk_widget_hide(fail);
add_user(c);
}
else {
gtk_widget_show(fail);
gtk_widget_hide(succ);}
}
}


void
on_gb_modif_annuler_btn_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_aff, *window_destroy;
GtkWidget *treeview1;
window_destroy=lookup_widget(objet,"gb_modifier");
gtk_widget_destroy(window_destroy);
windowgb_aff=create_gb_aff();
gtk_widget_show (windowgb_aff);

treeview1=lookup_widget(windowgb_aff,"gb_treeview");
gbafficher(treeview1);
}


void
on_gb_modif_modif_btn_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *cin,*nom,*prenom,*age,*sexe1,*sexe2,*poste,*email,*numero,*rech;
GtkWidget *fail,*succ;
user p;
char reche[200];
fail=lookup_widget(objet,"label_mod_fail");
succ=lookup_widget(objet,"label_mod_succ");
rech=lookup_widget(objet,"gb_modif_chercher");
strcpy(reche,gtk_entry_get_text(GTK_ENTRY(rech)));
cin=lookup_widget(objet,"gb_modif_cin");
nom=lookup_widget(objet,"gb_modif_nom");
prenom=lookup_widget(objet,"gb_modif_prenom");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

age=lookup_widget(objet,"gb_modif_spin_age");
p.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));

sexe1=lookup_widget(objet,"gb_modif_homme");
sexe2=lookup_widget(objet,"gb_modif_femme");
if(sexem==1)
{
strcpy(p.sexe,"Homme");
}
else
{
strcpy(p.sexe,"Femme");
}
poste=lookup_widget(objet,"gb_modif_combo_poste");
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));

email=lookup_widget(objet,"gb_modif_email");
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email)));

numero=lookup_widget(objet,"gb_modif_num");
p.num=atoi(gtk_entry_get_text(GTK_ENTRY(numero)));


if(strcmp(p.nom,"")!=0&&strcmp(p.prenom,"")!=0&&strcmp(p.cin,"")!=0&&strcmp(p.sexe,"")!=0&& (p.age>=18) && (p.num!=0) && strcmp(p.email,"")!=0&&strcmp(p.poste,"")!=0)
{gtk_widget_show(succ);
gtk_widget_hide(fail);
supp_cin(reche);
add_user(p);
}
else {
gtk_widget_show(fail);
gtk_widget_hide(succ);}


/*gtk_widget_show (message);
gtk_label_set_text(GTK_LABEL(message),"la modification est validée");*/
}



void
on_gb_modif_chercher_btn_clicked        (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *cin,*nom,*prenom,*age,*genre,*email,*numero,*rech,*poste,*se1,*se2,*message;
user c;
user p;
char nmch[30];
char reche[200];
int i=0;
char matrice[6][30]={"Administrateur","Technicien","Nutritionniste","Agent_de_foyer","Agent_de_restaurant","Etudiant"};
cin=lookup_widget(objet,"gb_modif_cin");
nom=lookup_widget(objet,"gb_modif_nom");
prenom=lookup_widget(objet,"gb_modif_prenom");
email=lookup_widget(objet,"gb_modif_email");
numero=lookup_widget(objet,"gb_modif_num");

age=lookup_widget(objet,"gb_modif_spin_age");

se1=lookup_widget(objet,"gb_modif_homme");
se2=lookup_widget(objet,"gb_modif_femme");

poste=lookup_widget(objet,"gb_modif_combo_poste");

rech=lookup_widget(objet,"gb_modif_chercher");


strcpy(reche,gtk_entry_get_text(GTK_ENTRY(rech)));
//printf("hello world");
FILE *f=NULL;
int v=1;
f=fopen("user.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %s %s \n",c.nom,c.prenom,c.cin,c.sexe,&c.age,&c.num,c.email,c.poste)!=EOF)
        {
	if( strcmp(reche,c.cin)==0){
			gtk_widget_hide (message);
			v=0;
			strcpy(p.cin,c.cin);
			strcpy(p.nom,c.nom);
			strcpy(p.prenom,c.prenom);
			strcpy(p.email,c.email);
			p.num=c.num;
			p.age=c.age;
			strcpy(p.poste,c.poste);
			strcpy(p.sexe,c.sexe);
			
			
			
	}
	else 
		{gtk_widget_show (message);
		gtk_label_set_text(GTK_LABEL(message),"ce cin n'existe pas");
		gtk_entry_set_text (cin,"");
		gtk_entry_set_text (nom,"");
		gtk_entry_set_text (prenom,"");
		gtk_entry_set_text (numero,"");
		gtk_entry_set_text (age,"");
		gtk_entry_set_text (sexe,"");
		gtk_entry_set_text (email,"");
		gtk_entry_set_text (poste,"");

}
}
if(v==0)
{
	gtk_entry_set_text (cin,p.cin);
	gtk_entry_set_text (nom,p.nom);
	gtk_entry_set_text (prenom,p.prenom);
	if(strcmp(p.sexe,"Homme")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (se1),TRUE);
	}
	else if(strcmp(p.sexe,"Femme")==0) {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (se2),TRUE);
	}
	i=0;
	while(i<6 && strcmp(matrice[i],p.poste)!=0)
	{
	i++;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(poste),i);
	
	gtk_spin_button_set_value(age,p.age);
	sprintf(nmch,"%d",p.num);
	gtk_entry_set_text(numero,nmch);
	gtk_entry_set_text (email,p.email);
	gtk_widget_hide (message);
}
}


void
on_gb_aff_users_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
GtkWidget *treeview1;
window_destroy=lookup_widget(objet,"gb_welcome");
gtk_widget_destroy(window_destroy);
windowgb_show=create_gb_aff();
gtk_widget_show (windowgb_show);

treeview1=lookup_widget(windowgb_show,"gb_treeview");
gbafficher(treeview1);
}


void
on_gb_inscrit_admin_incrit_btn_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gb_inscrit_admin_retour_btn_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gb_confirmer_check_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=1;
else x=0;}


void
on_gb_add_homme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexe=1;
}


void
on_gb_add_femme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexe=2;
}


void
on_gb_accualiser_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"gb_aff");
fenetre_afficher=create_gb_aff();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"gb_treeview");
gbafficher(treeview1);
}


void
on_gb_modif_homme_activate             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexem=1;
}


void
on_gb_modif_femme_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexem=2;
}


void
on_gb_treefumee_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_gb_treemvt_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_gb_refresh_mvt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"gb_liste");
fenetre_afficher=create_gb_liste();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"gb_treemvt");
afficher_mvt(treeview1);

}


void
on_gb_refresh_fumee_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet,"gb_liste");
fenetre_afficher=create_gb_liste();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"gb_treefumee");
afficher_fume(treeview1);//yaciiiiiiiiiiine
}



void
on_gb_confirmer_supp_btn_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_destroy;
/*GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
       // GtkWidget* p;
       // GtkWidget *label;
        //gchar *cin;
	//p=lookup_widget(objet,"gb_treeview");
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,2,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView*/

 	supp(p);
window_destroy=lookup_widget(objet,"gb_confirmer_supp");
gtk_widget_destroy(window_destroy);
	//gbafficher(p);

}

void
on_gb_cancel_supp_btn_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(objet,"gb_confirmer_supp");
gtk_widget_destroy(window_destroy);

}


void
on_gb_liste_alarmes_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;

window_destroy=lookup_widget(objet,"gb_aff");
gtk_widget_destroy(window_destroy);
windowgb_show=create_gb_liste();
gtk_widget_show (windowgb_show);
}


void
on_gb_back_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(objet,"gb_liste");
gtk_widget_destroy(window_destroy);
windowgb_show=create_gb_aff();
gtk_widget_show (windowgb_show);

}


void
on_gb_alarmes_enter                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
GtkWidget *treeview1;
GtkWidget *treeview2;
window_destroy=lookup_widget(objet,"gb_welcome");
gtk_widget_destroy(window_destroy);
windowgb_show=create_gb_liste();
gtk_widget_show (windowgb_show);


treeview1=lookup_widget(windowgb_show,"gb_treefumee");
afficher_fume(treeview1);

treeview2=lookup_widget(windowgb_show,"gb_treemvt");
afficher_mvt(treeview2);
}


void
on_gb_wlc_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_show=create_gb_welcome();
gtk_widget_show (windowgb_show);
}


void
on_gb_wlc_nutritionniste_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_show=create_affichage();
gtk_widget_show (windowgb_show);
}


void
on_gb_wlc_technicien_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_show=create_Home();
gtk_widget_show (windowgb_show);
}


void
on_gb_wlc_agentf_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_show=create_FS_wlc_foyer();
gtk_widget_show (windowgb_show);
}


void
on_gb_wlc_agentr_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_show=create_MG_wlc_stock();
gtk_widget_show (windowgb_show);
}


void
on_gb_wlc_etudiant_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgb_show, *window_destroy;
window_destroy=lookup_widget(button,"gb_welcome_all");
gtk_widget_destroy(window_destroy);
windowgb_show=create_acceuille_rec ();
gtk_widget_show (windowgb_show);
}

gboolean
on_gb_modifier_focus_in_event          (GtkWidget       *objet,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget *cin,*nom,*prenom,*age,*genre,*email,*numero,*rech,*poste,*se1,*se2,*message;
user c;
user p;
char nmch[30];
char reche[200];
int i=0;
char matrice[6][30]={"Administrateur","Technicien","Nutritionniste","Agent_de_foyer","Agent_de_restaurant","Etudiant"};
cin=lookup_widget(objet,"gb_modif_cin");
nom=lookup_widget(objet,"gb_modif_nom");
prenom=lookup_widget(objet,"gb_modif_prenom");
email=lookup_widget(objet,"gb_modif_email");
numero=lookup_widget(objet,"gb_modif_num");

age=lookup_widget(objet,"gb_modif_spin_age");

se1=lookup_widget(objet,"gb_modif_homme");
se2=lookup_widget(objet,"gb_modif_femme");

poste=lookup_widget(objet,"gb_modif_combo_poste");

rech=lookup_widget(objet,"gb_modif_chercher");


strcpy(reche,cinident);
//printf("hello world");
FILE *f=NULL;
int v=1;
f=fopen("user.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %s %s \n",c.nom,c.prenom,c.cin,c.sexe,&c.age,&c.num,c.email,c.poste)!=EOF)
        {
	if( strcmp(reche,c.cin)==0){
			gtk_widget_hide (message);
			v=0;
			strcpy(p.cin,c.cin);
			strcpy(p.nom,c.nom);
			strcpy(p.prenom,c.prenom);
			strcpy(p.email,c.email);
			p.num=c.num;
			p.age=c.age;
			strcpy(p.poste,c.poste);
			strcpy(p.sexe,c.sexe);
			
			
			
	}
	else 
		{gtk_widget_show (message);
		gtk_label_set_text(GTK_LABEL(message),"ce cin n'existe pas");
		gtk_entry_set_text (cin,"");
		gtk_entry_set_text (nom,"");
		gtk_entry_set_text (prenom,"");
		gtk_entry_set_text (numero,"");
		gtk_entry_set_text (age,"");
		gtk_entry_set_text (sexe,"");
		gtk_entry_set_text (email,"");
		gtk_entry_set_text (poste,"");

}
}
if(v==0)
{
	gtk_entry_set_text (cin,p.cin);
	gtk_entry_set_text (nom,p.nom);
	gtk_entry_set_text (prenom,p.prenom);
	if(strcmp(p.sexe,"Homme")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (se1),TRUE);
	}
	else if(strcmp(p.sexe,"Femme")==0) {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (se2),TRUE);
	}
	i=0;
	while(i<6 && strcmp(matrice[i],p.poste)!=0)
	{
	i++;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(poste),i);
	
	gtk_spin_button_set_value(age,p.age);
	sprintf(nmch,"%d",p.num);
	gtk_entry_set_text(numero,nmch);
	gtk_entry_set_text (email,p.email);
	gtk_widget_hide (message);
}

  return FALSE;
}


