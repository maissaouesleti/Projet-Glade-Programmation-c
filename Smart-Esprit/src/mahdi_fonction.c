#include "mahdi_fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>


#include <curl/curl.h>

#define from "stockprojetc@gmail.com"
#define pw "Stock123!"
#define too "mahdi.ghali@esprit.tn"
//apt-get install libcurl4-openssl-dev

static const char *payload_text[] = {

  "To: " "Modurateur d'achat" "\r\n",
  "From: " "Modurateur de stock" "\r\n",
  "Cc: " "Repture de Stock" "\r\n",
  "Subject: Les produits en repture de stock\r\n",
  "\r\n",
};

char Tableau_info[50][20];
int taille_tableau_info = 0;
int j=0;
/*
struct upload_status {
  int lines_read;
};*/

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }
  char flag[50];
  if (j >= 5 && j<(taille_tableau_info+5)){
    strcpy(flag,"le produit d'id   <");
    strcat(flag,Tableau_info[j-5]);
    strcat(flag, ">   est en repture de stock.\r\n");
  payload_text[j] = flag;
  }
  payload_text[taille_tableau_info+5] = NULL;
  data = payload_text[j];
  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;
    j++;

    return len;
  }

  return 0;
}

void send_email(char to[])
{
mgreptureemail("stock.txt");
j=0;
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *recipients = NULL;
  struct upload_status upload_ctx;
  upload_ctx.lines_read = 0;

  curl = curl_easy_init();
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_USERNAME, from);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, pw);

    curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:25");

    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

    recipients = curl_slist_append(recipients, to);

    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    else


    curl_slist_free_all(recipients);

    curl_easy_cleanup(curl);
  }
}
/*
void main(){
send_email("mahdi.ghali@esprit.tn");
}*/

const char* mgcheckstring(char stringe[]){
	int n,i;
	char *string = stringe;
	n = strlen(string);
	for (i = 0 ;i<n;i++){
		if (isspace(string[i])){
			string[i] = '_';
		}
	}
	return string;
}

const char* mgdecompstring(char stringe[]){
	int n,i;
	char *string = stringe;
	n = strlen(string);
	for (i = 0 ;i<n;i++){
		if (string[i]=='_'){
			string[i] = ' ';
		}
	}
	return string;
}

void mgreptureemail(char fich[]){
	FILE *f=NULL;
	produit p;
	taille_tableau_info = 0;
	f = fopen(fich,"r");
	if (f!=NULL){
		while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){	
		if (p.quantity<= p.alert){
				strcpy(Tableau_info[taille_tableau_info],mgcheckstring(p.id));
				taille_tableau_info ++;
			
			}
		}	
	}
		strcpy(Tableau_info[taille_tableau_info],"null");

}

void mgrepturestock(char fich[], GtkWidget *liste){
	FILE *f=NULL;
	FILE *t = NULL;
	taille_tableau_info = 0;
	f = fopen(fich,"r");
	t = fopen("repture.txt","w");
	
	produit p;
	if (f!=NULL){
		while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){	
		if (t!=NULL){
		if (p.quantity<= p.alert){
				fprintf(t,"%s %s %s %d %s %d %s %d %d %d\n",p.type,mgcheckstring(p.id),mgcheckstring(p.name),p.quantity,mgcheckstring(p.unity),p.alert,p.embale,p.date.jour,p.date.mois,p.date.annee);
				strcpy(Tableau_info[taille_tableau_info],mgcheckstring(p.id));
				taille_tableau_info ++;
			}
		}
		}	
	}
		strcpy(Tableau_info[taille_tableau_info],"null");
		fclose(f);
		fclose(t);
		mgafficherstock(liste,"reptureplease");
}
void mgstockenstock(char fich[], GtkWidget *liste){
	FILE *f=NULL;
	FILE *t = NULL;
	f = fopen(fich,"r");
	t = fopen("repture.txt","w");
	
	produit p;
	if (f!=NULL){
		while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){	
		if (t!=NULL){
		if (p.quantity> p.alert){
				fprintf(t,"%s %s %s %d %s %d %s %d %d %d\n",p.type,mgcheckstring(p.id),mgcheckstring(p.name),p.quantity,mgcheckstring(p.unity),p.alert,p.embale,p.date.jour,p.date.mois,p.date.annee);

			}
		}
		}	
	}
		fclose(f);
		fclose(t);
		mgafficherstock(liste,"reptureplease");
}


int mgajouterstock(char fich[],produit p){
    FILE *f=NULL;
    f = fopen(fich,"a+");
    if ((strlen(p.id) * strlen(p.name) * strlen(p.unity) )==0){
	
	return 2;
}
    if (f!=NULL){
	
	fprintf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,mgcheckstring(p.id),mgcheckstring(p.name),p.quantity,mgcheckstring(p.unity),p.alert,p.embale,p.date.jour,p.date.mois,p.date.annee);
	fclose(f);
	return 1;
    }
    fclose(f);
return 0;
}


produit mgrempliredit(char fich[], char id[]){

 FILE *f=NULL;
    produit p;
    f = fopen(fich,"r");
    if (f!=NULL)
    {

    while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){
		if (strcmp(mgdecompstring(p.id),id)==0){
 		fclose(f);
		strcpy(p.id ,mgdecompstring(p.id));
		strcpy(p.name , mgdecompstring(p.name));
		strcpy(p.unity  , mgdecompstring(p.unity));
		return p;
		};
}
    }


 	fclose(f);
}

int mgcheckid(char fich[], char id[]){
    produit p;
    FILE *f=NULL;
    f = fopen(fich,"r");
    if (f!=NULL)
    {

    while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){
		if (strcmp(mgdecompstring(p.id),id)==0){
 		fclose(f);
		return 1;
		}
}
    }


 	fclose(f);
return 0;
}

int mgsupprimerstock(char fich[],char id[]){
FILE *f=NULL;
    FILE *t = NULL;
    produit p;
    int flag=0;
    f = fopen(fich,"r");
    t = fopen("temp.txt" , "a+");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){
            if (strcmp(mgdecompstring(p.id),id)!=0){
fprintf(t,"%s %s %s %d %s %d %s %d %d %d\n",p.type,mgcheckstring(p.id),mgcheckstring(p.name),p.quantity,mgcheckstring(p.unity),p.alert,p.embale,p.date.jour,p.date.mois,p.date.annee);
}else{
flag = 1;
}


        }}
        fclose(f);
        remove(fich);
        fclose(t);
        rename("temp.txt",fich);
	return flag;
}


int mgmodifierstock(char fich[], produit m,int supp){
    FILE *f=NULL;
    FILE *t = NULL;
    produit p;
	//int quan = 10;

    if ((strlen(m.id) * strlen(m.name) * strlen(m.unity) )==0){
	
	return 2;
}
    int flag=0;
    f = fopen(fich,"r");
    t = fopen("temp.txt" , "a+");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){
            if (strcmp(p.id,m.id)==0){
		flag = 1;
		if (supp){
		//m.quantity =m.quantity+ p.quantity;
		fprintf(t,"%s %s %s %d %s %d %s %d %d %d\n",m.type,mgcheckstring(m.id),mgcheckstring(m.name),m.quantity + p.quantity/*m.quantity*/,mgcheckstring(p.unity),m.alert,m.embale,m.date.jour,m.date.mois,m.date.annee);
		}else{
		//m.quantity =m.quantity-  p.quantity;
		fprintf(t,"%s %s %s %d %s %d %s %d %d %d\n",m.type,mgcheckstring(m.id),mgcheckstring(m.name),p.quantity - m.quantity/*m.quantity*/,mgcheckstring(p.unity),m.alert,m.embale,m.date.jour,m.date.mois,m.date.annee);
		}
            }else{
fprintf(t,"%s %s %s %d %s %d %s %d %d %d\n",p.type,mgcheckstring(p.id),mgcheckstring(p.name),p.quantity,mgcheckstring(p.unity),p.alert,p.embale,p.date.jour,p.date.mois,p.date.annee);
}


        }
        fclose(f);
        remove(fich);
        fclose(t);
        rename("temp.txt",fich);
return flag;

    }
}
int mgchecksubstring(char str1[], char str2[]){
	int n1,n2,i,flag = 0;
	n1 = strlen(str1);
	n2= strlen(str2);
	if (n1<=n2){
	for (i=0;i<n1;i++){
		if (str1[i] == str2[i]){
			flag +=1;			
}
	}
	if (flag == n1){
		return 1;
	}else{
		return 0;
	}
}else{
	return 0;
}
}

enum{
TYPE,
ID,
NOM,
QUANTITY,
UNITE,
ALERT,
EMBALE,
JOUR,
MOIS,
ANNEE,
COLUMNS
};

void mgafficherstock(GtkWidget *liste, char idi[]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;

produit p;

store = NULL;

FILE* f= NULL;
FILE *t = NULL;
store = gtk_tree_view_get_model(liste);

if (store==NULL){

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" quantite",renderer,"text",QUANTITY,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" unite",renderer,"text",UNITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" alert",renderer,"text",ALERT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" embale",renderer,"text",EMBALE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_INT, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f = fopen("stock.txt","r");
if (f==NULL){
return ;
}else{
while(fscanf(f,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){
if (strlen(idi)>0){
 if (mgchecksubstring(idi, mgdecompstring(p.id)) || mgchecksubstring(idi, mgdecompstring(p.name)) || mgchecksubstring(idi, mgdecompstring(p.type))){
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,TYPE,p.type,ID,mgdecompstring(p.id),NOM,mgdecompstring(p.name),QUANTITY,p.quantity,UNITE,mgdecompstring(p.unity),ALERT,p.alert,EMBALE,p.embale,JOUR,p.date.jour,MOIS,p.date.mois,ANNEE,p.date.annee,-1);
}
else {if (strcmp(idi,"aucun_resultat")==0){
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,TYPE,"aucun",ID,"resultat",NOM,"de_stock",QUANTITY,0,UNITE,".",ALERT,0,EMBALE,"aucun",JOUR,0,MOIS,0,ANNEE,0,-1);
break;} }
}if (strcmp(idi,"")==0){
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,TYPE,p.type,ID,mgdecompstring(p.id),NOM,mgdecompstring(p.name),QUANTITY,p.quantity,UNITE,mgdecompstring(p.unity),ALERT,p.alert,EMBALE,p.embale,JOUR,p.date.jour,MOIS,p.date.mois,ANNEE,p.date.annee,-1);
}

}

if (strcmp(idi,"reptureplease")==0){
t = fopen("repture.txt","r");
if (t != NULL){
	while(fscanf(t,"%s %s %s %d %s %d %s %d %d %d\n",p.type,p.id,p.name,&p.quantity,p.unity,&p.alert,p.embale,&p.date.jour,&p.date.mois,&p.date.annee)!=EOF){
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,TYPE,p.type,ID,mgdecompstring(p.id),NOM,mgdecompstring(p.name),QUANTITY,p.quantity,UNITE,mgdecompstring(p.unity),ALERT,p.alert,EMBALE,p.embale,JOUR,p.date.jour,MOIS,p.date.mois,ANNEE,p.date.annee,-1);
}}
fclose(t);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}}

