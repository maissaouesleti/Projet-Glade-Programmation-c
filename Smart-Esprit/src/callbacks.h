#include <gtk/gtk.h>


void
on_gb_auth_connecter_btn_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_quitter_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_users_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_alarmes_enter                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_treeview_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gb_accualiser_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_aff_rech_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_retour_btn_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_modif_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_supp_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_aff_add_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_add_retour_btn_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_confirmer_check_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_add_femme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_add_add_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_add_homme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_modif_annuler_btn_clicked        (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_modif_modif_btn_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_modif_homme_activate             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_modif_femme_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_modif_chercher_btn_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_gb_inscrit_admin_incrit_btn_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_inscrit_admin_retour_btn_clicked (GtkButton       *button,
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
on_gb_refresh_fumee_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_refresh_mvt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_back_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_confirmer_supp_btn_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gb_cancel_supp_btn_clicked          (GtkWidget       *objet,
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

gboolean
on_MGWindowStock_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGEntrySearch_changed               (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_MGTreeView_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MGButtonAdd_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonModify_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonDelete_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonAlt_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonAfficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_MGCheckBoxStock_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGCheckBoxRepture_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGButtonLogout_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGWindowAjout_destroy               (GtkObject       *object,
                                        gpointer         user_data);

gboolean
on_MGWindowAjout_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGRadioemablenon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGButtonAjout_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_MGRadioemableoui_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_MGWindowEdit_focus_in_event         (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGWindowEdit_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_MGRadioAjoutm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioEmbaleOuim_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioEmbaleNonm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGButtonEditm_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGRadioSuppm_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_MGWindowError_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_WindowMailing_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGButtonSendMail_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonOuiarticle_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonNonarticle_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSentry1chercher_changed            (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_FStreeview1liste_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_FSentry1chercher_changed            (GtkEditable     *editable,
                                        gpointer         user_data);

gboolean
on_FStreeview1liste_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_FSbutton1actualiser_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_flisssafabutton2chercher_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_flisssafabutton2statistique_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton3supprimerfoyer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1modifierfoyer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2afficherfoyer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_flisssafabutton1ajouter_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FScheckbutton1condition_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FSradiobutton1femme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FSradiobutton2homme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_flisssafabutton3ajouter_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FSradiobutton3femme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FSradiobutton4homme_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FSbutton4enregistrer_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1retourner_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton7modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton8supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2okii9_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FSbutton1ajout_ins_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2log_auth_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1oui_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2non_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton1window2oui_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_FSbutton2window2non_clicked         (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_safaflissModifier_focus_in_event    (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_safaflissModifier_destroy           (GtkObject       *object,
                                        gpointer         user_data);

gboolean
on_safaflissaffichage_focus_in_event   (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_safaflissstatistique_focus_in_event (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_safaflisssure_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_Flisssafawindow1modif_ajout_supp_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_SF_nb_etud_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FS_foyer_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_FS_foyer_logout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MG_stock_logout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MG_Dashboard_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_MG_gestion_stock_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_SF_dashboard_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_FS_retour_wlc_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MG_retour_to_wlc_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffaff_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_remaffadd_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffmod_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffsupp_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmchercher_btn_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffquit_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_remaffadd_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffmod_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffsupp_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffquit_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmchercher_btn_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaddadd_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaddretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rmcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_remaffadd_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffmod_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffsupp_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffquit_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmchercher_btn_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmaffadd_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16chercher_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_rmmodmod_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rmmodretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonhome_acceuil_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_capteur_def_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_buttonhome_exit_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_def_aff_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_button15_retour_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_rmaffaff_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_aff_tache2_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_rmaff_captdef_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajj_rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_act_rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_mod_rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat_recc_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_homme_rec_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_decc_rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_annn_aj_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajout_recc_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_modif_recc_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_annn_mod_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ann_supp_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_con_supp_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_aff1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_serv_pluss1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ret_acui1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_home2_rec_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_deccc2_rec_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_serrplusrecl1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_rec_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_rechch_rec_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_aj_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_aff_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_mm_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_pd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_rm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_d_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_suc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_sal_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_pd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_rm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6_d_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button9_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_rech_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buton_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_calcul_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_suc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_sal_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_Modifier_focus_in_event             (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_radiobutton3_suc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_sal_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1m_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_wlc_all_admin_dash_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_gb_goauth_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_out_dashboard_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retmaysa_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_to_esp_nut_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_menu_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_mod_menu_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_add_menu_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_best_menu_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_quit_menu_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_refresh_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

/*void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_button6_menu_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajout_menu_retour_clicked           (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_gb_modifier_focus_in_event          (GtkWidget       *objet,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);
