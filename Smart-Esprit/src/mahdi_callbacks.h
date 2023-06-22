#include <gtk/gtk.h>


void
on_MGButtonAdd_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonModify_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonEditm_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonAjout_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_MGRadioemablenon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioemableoui_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioAjoutm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioSuppm_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioEmbaleNonm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGRadioEmbaleOuim_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGWindowEdit_activate_focus         (GtkWindow       *window,
                                        gpointer         user_data);

void
on_MGButtonDelete_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonAfficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

gboolean
on_MGWindowEdit_focus                  (GtkWidget       *widget,
                                        GtkDirectionType  direction,
                                        gpointer         user_data);

void
on_MGWindowEdit_set_focus              (GtkWindow       *window,
                                        GtkWidget       *widget,
                                        gpointer         user_data);

gboolean
on_MGWindowEdit_focus_in_event         (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGWindowEdit_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_MGTreeView_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MGButtonRefresh_clicked             (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_MGTreeView_focus_in_event           (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGButtonSearch_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGEntrySearch_changed               (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_MGCheckBoxStock_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MGCheckBoxRepture_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_MGWindowStock_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_MGWindowAjout_destroy_event         (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_MGWindowAjout_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_MGWindowError_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_MGTreeView_select_cursor_parent     (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_MGButtonAlt_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonSendMail_clicked            (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_WindowMailing_focus_in_event        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_MGButtonOuiarticle_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_MGButtonNonArticle_clicked          (GtkButton       *button,
                                        gpointer         user_data);
