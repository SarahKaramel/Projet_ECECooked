/*
 * Si le fichier a deja ete analyse par le compilateur,
 * On ne le lis pas une deuxieme fois pour eviter de redefinir la structure
 * et les fonctions.
 */
#ifndef PERSONAGE_H_ // if not def dans le main.c ou personnage.c
#define PERSONAGE_H_ // alors definie le header personnage.h pour pouvoir l'utiliser

#define LIGNE 12 // Taille map
#define COLONNE 20

#include <allegro.h>

typedef struct image_objet {

} image_objet;

typedef struct objet {
    bool assiette;
    bool algues;
    bool avocat_pas_decoupe;
    bool avocat_decoupe;
    bool maki;
    bool onigiri;
    bool riz_cru;
    bool riz_cuit;
    bool saumon_neutre;
    bool saumon_decoupe;
    bool saumon_cuit;
    bool sushi;
} objet;


typedef struct creation_personnage {
    int position_x;
    int position_y;
    int direction_x;// pour garder la derniere image vers où il est allé (en gros)
    int direction_y;
    int taille_x; //76 largeur
    int taille_y;// 68 longueur

    // Objet que le personnage tient dans les mains
    objet* obj;// si on veut lui enlever lobjet des mains on le met à null


    // tu definies les differentes direction que chacun des perso (1 et 2) aura
    BITMAP *imageDROITE;
    BITMAP *imageGAUCHE;
    BITMAP *imageHAUT;
    BITMAP *imageBAS;
    BITMAP *imagePOSE;
    BITMAP *imageHAUT_DROITE;
    BITMAP *imageBAS_DROITE;
    BITMAP *imageBAS_GAUCHE;
    BITMAP *imageHAUT_GAUCHE;
} creation_personnage;

// On declare les fonctions et leurs types pour qu'elles soient visible dans le main.
creation_personnage creer_personage1();
creation_personnage creer_personage2();

// pour que le main puisse les retrouver il faut les declarer dans personnage.h
bool touches_personage1(creation_personnage* personnage);
bool touches_personage2(creation_personnage* personnage);
void deplacer_personage(creation_personnage* personnage);
void attraper_objet(creation_personnage* personnage, BITMAP *page, int tab[LIGNE][COLONNE], objet* tabObjet[LIGNE][COLONNE]);
void afficher_personage(creation_personnage* personnage, BITMAP *page);
void transporterobjet(creation_personnage* personnage, BITMAP *page, BITMAP* image);
void detruire_personnage(creation_personnage* personnage);

#endif
