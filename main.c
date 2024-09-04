#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
char titre[100];
char auteur[100];
float prix;
int quantite;


} livre;
livre l[100];
int cmp = 0;

void ajouterLivre() {
    if (cmp >= 100) {
        printf("Stock plein\n");
        return;
    }

    livre livres;

    int result;
while (getchar() != '\n');


    printf("Entrer le titre du livre: ");
    fgets(livres.titre, sizeof(livres.titre), stdin);
    livres.titre[strcspn(livres.titre, "\n")] = '\0';


    printf("Entrer l'auteur du livre: ");
    fgets(livres.auteur, sizeof(livres.auteur), stdin);
    livres.auteur[strcspn(livres.auteur, "\n")] = '\0';


    printf("Entrer le prix du livre: ");
    result = scanf("%f", &livres.prix);
    if (result != 1) {
        printf("Erreur: Veuillez entrer un prix valide.\n");
        getchar();
        return;
    }


    getchar();


    printf("Entrer la quantite du livre: ");
    result = scanf("%d", &livres.quantite);
    if (result != 1) {
        printf("Erreur: Veuillez entrer une quantité valide.\n");
        getchar();
        return;
    }


    getchar();


    l[cmp] = livres;
    cmp++;
    printf("Livre ajouter avec succes !\n");
}
void afficherLivres(){
        printf("******************Affichef LIvre******************\n");
if (cmp == 0)
    printf("\nStock est vide\n");
else {
for (int i = 0;i<cmp;i++){
    printf("Livre %d: \n", i+1);
    printf("Titre du Livre: %s\n", l[i].titre);
    printf("Auteur du Livre: %s\n", l[i].auteur);
    printf("Prix du Livre: %.2f\n", l[i].prix);
    printf("Quantite du livre: %d\n", l[i].quantite);

}
}
    printf("************************************\n");

}
void modifierLivre(){
    printf("******************Modifier LIvre******************\n");
    char t[100];

int q,f=0,j;
while (getchar() != '\n');
printf("Entrer le nom du livre: ");
 fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';
    for (int i=0; i<cmp;i++){
        if (strcmp(t,l[i].titre)==0){

            j=i;
    }
    else f++;
    }
    if (f == 0){
        printf("Entrer la nouvelle quantite: ");
        scanf("%d",&q);
            l[j].quantite=q;
    printf("\nLivre Modifier avec succes!!\n");
     printf("Livre Modifier \n");
    printf("Titre du Livre: %s\n", l[j].titre);
    printf("Auteur du Livre: %s\n", l[j].auteur);
    printf("Prix du Livre: %.2f\n", l[j].prix);
    printf("Quantite du livre: %d\n", l[j].quantite);
}
else
    printf("NOT FOUND!! \n");
    printf("************************************\n");


}
void rechercherLivres(){
    printf("******************Rechercher LIvre******************\n");

 char t[100];

int j,f=0;


printf("Entrer le nom du livre: ");
 fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';
   for (int i=0; i<cmp;i++){
        if (strcmp(t,l[i].titre)==0){

            j=i;
    }
    else f++;
    }
     if (f == 0){

     printf("Livre Trouver \n");
    printf("Titre du Livre: %s\n", l[j].titre);
    printf("Auteur du Livre: %s\n", l[j].auteur);
    printf("Prix du Livre: %.2f\n", l[j].prix);
    printf("Quantite du livre: %d\n", l[j].quantite);
}
else
    printf("NOT FOUND!! \n");
    printf("************************************\n");
}
void afficherTotalLivres(){
    int total=0;
    for (int i=0;i<cmp;i++){
        total+=l[i].quantite;
    }
    printf("le total des livres dans le stock est: %d",total);

}
void supprimerLivre() {
    char titre[100];
    int i, j;
    int livreTrouve = 0;

   while (getchar() != '\n');
    printf("Entrez le titre du livre à supprimer : ");
    fgets(titre, sizeof(titre), stdin);
    titre[strcspn(titre, "\n")] = '\0';


    for (i = 0; i < cmp; i++) {
        if (strcmp(l[i].titre, titre) == 0) {
            livreTrouve = 1;

            for (j = i; j < cmp - 1; j++) {
                l[j] = l[j + 1];
            }
            cmp--;
            printf("Livre \"%s\" supprimé avec succès !\n", titre);
            break;
        }
    }

    if (!livreTrouve) {
        printf("Livre non trouvé.\n");
    }
}
int main()
{

    char titre[100];
  int choix;
  do {
  printf("\nMenu: \n");
    printf("Pour AJouter un livre tappez 1: \nPour modifier un livre tappez 2: \nPour Supprimer un livre tappez 3: \nPour rechercher un livre tappez 4: \nPour afficher tous les livres tappez 5: \nPour afficher le total des livres tappez 6: \nQuitter 7:");
    printf("\nChoisissez une option: ");

    scanf("%d",&choix);
        switch (choix){
    case 1:
        {
            ajouterLivre();



            break;
        }
    case 2:
        {
            modifierLivre();
            break;
        }
    case 3:
        {
           supprimerLivre();
            break;
        }
    case 4:
        {
            rechercherLivres();
            break;
        }
    case 5:
        {
            afficherLivres();
            break;
        }
         case 6:
        {
            afficherTotalLivres();
            break;
        }
    default:
        printf("Choix invalid, ressayez!!");

        }




    }while(choix!=7);




        return 0;
}
