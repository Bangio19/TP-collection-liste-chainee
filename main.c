#include "header.h"

int main()
{
    int choix=0;    ///Variable pour le choix du menu.
    int retour=0;   ///Varaibel "verrou" pour revenir au menu.
    int i=0;    ///Variable compteur.

    t_collec* collec=NULL;  ///D�claration d'un pointeur sur collection.

    collec = initCollec();  ///On initialise la collection et on donne son adresse � collec.


    while(choix != 6)   ///Tant que l'utilisateur ne veut pas quitter :
    {
        choix=menu();   ///On lance le menu et on r�cup�re le choix.

        switch(choix)
        {
        case 1 :    ///L'utilisateur veut afficher la collection :
        {
            affichageCollec(collec);    ///On affiche.

            while(retour != 1)  ///Tant que l'utilisateur ne tape pas 1 :
            {
                printf("\n Retour : Tapez 1.\n");   ///On lui demande de taper 1.
                scanf("%d", &retour);
            }
            for(i=0; i<100; i++) ///On tire un trait
            {
                printf("%c",196);
            }
            printf("\n");
            retour=0;

        }
        //case 2 : recherche();
        //case 3 : tri();
        //case 4 : ajout();
        //case 5 : supprimer();
        default :
            break;
        }
    }


    return 0;
}

///Fonction d'affichage du menu (retourne le choix) :
int menu()
{
    int choix=0;  ///Variable choix utilisateur pour le switch.
    int i=0;  ///Variable pour les boucles.

    ///Interface graphique (limit�e car le CDC interdit l'utilisation de la fonction gotoligcol) :

    ///Ligne du haut :
    printf("%c",201);
    for(i=0; i<27; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);

    ///Titre :
    printf("%c Collection de cartes FIFA %c\n", 186, 186);

    ///Ligne du bas :
    printf("%c",200);
    for(i=0; i<27; i++)
    {
        printf("%c",205);
    }
    printf("%c\n\n",188);

    ///Choix :
    printf(" 1 - Voir la collection\n");
    printf(" 2 - Rechercher une carte\n");
    printf(" 3 - Trier la collection\n\n");

    printf(" 4 - Ajouter une carte\n");
    printf(" 5 - Supprimer une carte\n\n");

    printf(" 6 - Quitter l'application\n\n");

    printf(" Que voulez-vous faire ?\n");
    scanf("%d",&choix);

    for(i=0; i<100; i++)
    {
        printf("%c",196);
    }
    printf("\n");

    return choix;
}

///Fonction d'initialisation de la collection (retourne un pointeur sur l'ancre) :
t_collec* initCollec()
{
    int i=0;

    t_stats* stats;
    stats = (t_stats*) malloc(sizeof(t_stats));  ///On alloue dynamiquement les stats de la premi�re carte.

    t_carte* carte;
    carte = (t_carte*) malloc(sizeof(t_carte));  ///On alloue dynamiquement la premi�re carte.

    t_collec* collec;
    collec = (t_collec*) malloc(sizeof(t_collec));   ///On alloue dynamiquement l'ancre.


    if(collec == NULL || carte == NULL || stats == NULL) ///Si une des trois allocs dynamiques s'est mal pass� :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }

    ///On initialise l'ancre :
    collec->first = carte;
    collec->last = carte;

    ///On initialise la premi�re carte :
    carte->nom = "Cristiano Ronaldo";
    carte->note = 99;
    carte->poste = "AG";
    carte->club = "Real Madrid CF";
    carte->pays = "Portugal";

    ///On initialise les stats de la premi�re carte.
    carte->stats.vit = 98;
    carte->stats.dri = 98;
    carte->stats.tir = 99;
    carte->stats.def = 50;
    carte->stats.pas = 94;
    carte->stats.phy = 95;

    carte->next = NULL;

    return collec;
}

///Fonction d'affichage de la collection :
void affichageCollec(t_collec* collec)
{
    t_carte* carteActuelle = collec->first;

    if(collec == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(carteActuelle != NULL)
    {
        printf("\t\t%s\n\n", carteActuelle->nom);

        printf(" Note g%cn%crale : %d\n", 130, 130, carteActuelle->note);
        printf(" Poste : %s\n", carteActuelle->poste);
        printf("  Club : %s\n", carteActuelle->club);
        printf("  Pays : %s\n", carteActuelle->pays);

        printf(" Stats : %d VIT, %d DRI, %d TIR, %d DEF, %d PAS, %d PHY.\n\n", carteActuelle->stats.vit, carteActuelle->stats.dri, carteActuelle->stats.tir, carteActuelle->stats.def, carteActuelle->stats.pas, carteActuelle->stats.phy);


        carteActuelle = carteActuelle->next;
    }
}
