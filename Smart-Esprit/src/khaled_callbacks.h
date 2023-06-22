#include <gtk/gtk.h>


void
on_gb_auth_insc_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_gb_auth_connecter_btn_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_gb_quitter_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_treeview_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gb_aff_retour_btn_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_modif_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_supp_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_rech_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_add_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_add_retour_btn_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_add_add_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_modif_annuler_btn_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_modif_modif_btn_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_modif_chercher_btn_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_users_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_inscrit_admin_incrit_btn_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_inscrit_admin_retour_btn_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_confirmer_check_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_add_homme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_add_femme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_accualiser_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_modif_homme_activate             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_modif_femme_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_treefumee_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gb_treemvt_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gb_refresh_mvt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_gb_refresh_fumee_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_confirmer_supp_btn_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_gb_cancel_supp_btn_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_liste_alarmes_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_back_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_gb_alarmes_enter                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_wlc_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_wlc_nutritionniste_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_wlc_technicien_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_wlc_agentf_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_wlc_agentr_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_wlc_etudiant_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonAdd_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonLogout_clicked              (GtkButton       *button,
                                        gpointer         user_data);
