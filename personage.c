#include <malloc.h>
#include <stdbool.h>
#include <stdbool.h>
#include "personage.h"

creation_personnage creer_personage1() {

    creation_personnage perso1;
    //sa postion
    perso1.position_x = 100;
    perso1.position_y = 20;
    // sa direction pour 2 raisons tout d'abord pour garder la derniere image en memoir pour lafficher au lieu de pose
    // et aussi pour le bloc directionnel
    perso1.direction_x = 0;
    perso1.direction_y = 0;


    // sa taille pour quand on va comparer les pixels
    //(finalement mais jsp pas pk)
    perso1.taille_x = 76;
    perso1.taille_y = 68;


    // on initialise le fait qu'il ait aucun objet dans les mains
    perso1.obj = NULL;

    // Charger l'image depuis un fichier
    perso1.imageBAS = load_tga("../ressource/image/BAS.tga", NULL);
    if (!perso1.imageBAS) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso1.imageDROITE = load_tga("../ressource/image/DROITE.tga", NULL);
    if (!perso1.imageDROITE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso1.imageGAUCHE = load_tga("../ressource/image/GAUCHE.tga", NULL);
    if (!perso1.imageGAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso1.imageHAUT = load_tga("../ressource/image/HAUT.tga", NULL);
    if (!perso1.imageHAUT) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
// Charger l'image depuis un fichier
    perso1.imagePOSE = load_tga("../ressource/image/POSE.tga", NULL);
    if (!perso1.imagePOSE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso1.imageHAUT_DROITE = load_tga("../ressource/image/imageHAUT_DROITE.tga", NULL);
    if (!perso1.imageHAUT_DROITE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso1.imageBAS_DROITE = load_tga("../ressource/image/imageBAS_DROITE.tga", NULL);
    if (!perso1.imageBAS_DROITE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }

    // Charger l'image depuis un fichier
    perso1.imageBAS_GAUCHE = load_tga("../ressource/image/imageBAS_GAUCHE.tga", NULL);
    if (!perso1.imageBAS_GAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }

    // Charger l'image depuis un fichier
    perso1.imageHAUT_GAUCHE = load_tga("../ressource/image/imageHAUT_GAUCHE.tga", NULL);
    if (!perso1.imageHAUT_GAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    return perso1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////                     Même chose pour le perso 2                            /////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////                                                                           /////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



creation_personnage creer_personage2() {
    creation_personnage perso2;

    perso2.position_x = 50;
    perso2.position_y = 50;
    perso2.direction_x = 0;
    perso2.direction_y = 0;
    perso2.taille_x = 76;
    perso2.taille_y = 68;
    perso2.obj = NULL;

    // Charger l'image depuis un fichier
    perso2.imageBAS = load_tga("../ressource/image/BAS.tga", NULL);
    if (!perso2.imageBAS) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso2.imageDROITE = load_tga("../ressource/image/DROITE.tga", NULL);
    if (!perso2.imageDROITE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso2.imageGAUCHE = load_tga("../ressource/image/GAUCHE.tga", NULL);
    if (!perso2.imageGAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso2.imageHAUT = load_tga("../ressource/image/HAUT.tga", NULL);
    if (!perso2.imageHAUT) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
// Charger l'image depuis un fichier
    perso2.imagePOSE = load_tga("../ressource/image/POSE.tga", NULL);
    if (!perso2.imagePOSE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso2.imageHAUT_DROITE = load_tga("../ressource/image/imageHAUT_DROITE.tga", NULL);
    if (!perso2.imageHAUT_DROITE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    // Charger l'image depuis un fichier
    perso2.imageBAS_DROITE = load_tga("../ressource/image/imageBAS_DROITE.tga", NULL);
    if (!perso2.imageBAS_DROITE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }

    // Charger l'image depuis un fichier
    perso2.imageBAS_GAUCHE = load_tga("../ressource/image/imageBAS_GAUCHE.tga", NULL);
    if (!perso2.imageBAS_GAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }

    // Charger l'image depuis un fichier
    perso2.imageHAUT_GAUCHE = load_tga("../ressource/image/imageHAUT_GAUCHE.tga", NULL);
    if (!perso2.imageHAUT_GAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        exit(1);
    }
    return perso2;
}

// de type boolen parce que regarder main quand on appelle la fonction
bool touches_personage1(creation_personnage* personnage) {
    // on bouge pas donc initialise à false le mouvement
    bool mouvementX = false;
    bool mouvementY = false;

    // on lui donne son sens vers où il va aller en fonction des touches appuyer

    if(key[KEY_S]) {
        personnage->direction_y = 1;
        mouvementY = true;
    }
    if (key[KEY_W]) {
        personnage->direction_y = -1;
        mouvementY = true;
    }
    if (key[KEY_A]) {
        personnage->direction_x = -1;
        mouvementX = true;
    }
    if (key[KEY_D]) {
        personnage->direction_x = 1;
        mouvementX = true;
    }
// si on detecte un mouvement jors true sur mouvement x ou y
    if (mouvementX || mouvementY) {

        //
        if (mouvementX== false)
            personnage->direction_x = 0;
        if (mouvementY== false)
            personnage->direction_y = 0;
        return true;
    }
//quand j'arrete d'appuyer sur la touche je return false pour remettre les booleens de deplacement de se mettre à false
    return false;
}
// même chose que pour perso 1 mais avec touche différente
bool touches_personage2(creation_personnage* personnage) {
    bool mouvementX = false;
    bool mouvementY = false;

    if(key[KEY_DOWN]) {
        personnage->direction_y = 1;
        mouvementY = true;
    }
    if (key[KEY_UP]) {
        personnage->direction_y = -1;
        mouvementY = true;
    }
    if (key[KEY_LEFT]) {
        personnage->direction_x = -1;
        mouvementX = true;
    }
    if (key[KEY_RIGHT]) {
        personnage->direction_x = 1;
        mouvementX = true;
    }
    if (mouvementX || mouvementY) {
        //
        if (!mouvementX)
            personnage->direction_x = 0;
        if (!mouvementY)
            personnage->direction_y = 0;
        return true;
    }

    return false;
}

// Toutes les actions a faire quand on appuie sur la touche attrapper (C ou Entrer)
//parametre 1 pour connaitre les pos du perso
//parametre 2 pour pouvoir dessiner sur lecran obligatoire (surtout pour le rectangle invisble)
//parametre 3 la map tt court mais pas les objets
//parametre 4 les objets qui sont sur la map jors poisson tt dans la struc objet
void attraper_objet(creation_personnage* personnage, BITMAP *page, int tab[LIGNE][COLONNE], objet* tabObjet[LIGNE][COLONNE]) {
    //on initialise la taille du rectangle invisble
    int tailleinvisblex2 = 50;
    int tailleinvisbley2 = 50;

    // on initialise les coordonnées invisble avant qu'il dépende du perso
    int invisiblex2 = 0;
    int invisibley2 = 0;



    //tu dois changer les pos x et y un peu partout !! oublie pas moi-même
    if (personnage->direction_y == -1) {
        invisiblex2 = personnage->position_x + 7;
        invisibley2 = personnage->position_y - 20;
        rectfill(page, invisiblex2, invisibley2, invisiblex2 + tailleinvisblex2, invisibley2 + tailleinvisbley2,
                 makecol(0, 0, 0));
    }

    if (personnage->direction_y == 1){
        invisiblex2 = personnage->position_x + 7;
        invisibley2 = personnage->position_y + 60;
        rectfill(page, invisiblex2, invisibley2, invisiblex2 + tailleinvisblex2, invisibley2 + tailleinvisbley2,
                 makecol(0, 0, 0));

    }
    if (personnage->direction_x==1){
        invisiblex2 = personnage->position_x + 30;
        invisibley2 = personnage->position_y + 30;
        rectfill(page, invisiblex2, invisibley2, invisiblex2 + tailleinvisblex2, invisibley2 + tailleinvisbley2,
                 makecol(0, 0, 0));
    }
    if (personnage->direction_x==-1){
        invisiblex2 = personnage->position_x - 30;
        invisibley2 = personnage->position_y + 20;
        rectfill(page, invisiblex2, invisibley2, invisiblex2 + tailleinvisblex2, invisibley2 + tailleinvisbley2,
                 makecol(0, 0, 0));
    }

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 20; ++j) {

            int x = j*76 + 76 / 2;
            int y = i*68 + 76 / 2;
// on verifie que le milieu d'un des rectangles de la map soit dans le rectangle invisble
            if (x > invisiblex2 && x < invisiblex2 + tailleinvisblex2
                && y > invisibley2 && y < invisibley2 + tailleinvisbley2)

                // Si oui on effectue les actions en fonction du case du carreau en question
                switch (tab[i][j]) {
                    case 7: // Poubelle  ex : on
                        free(personnage->obj); // optionnel (je vous vois louis mahl)
                        personnage->obj = NULL; // on le fait disparaitre pour comprendre voir case 8 et 9 et fonction afficher perso
                        break;
                    case 8:
                    case 9:
                        // si la table ou tu regardes est vide et que le personnage detient un objet alors:
                        if (tabObjet[i][j] == NULL && personnage->obj != NULL) {
                            // alors on met l'objet sur la table
                            tabObjet[i][j] = personnage->obj;
                            // et on initialise ce que le perso a sur lui à nul
                            personnage->obj = NULL;
                        }

                        // si la table ou tu regardes contien un objet et que le personnage n'en a pas:
                        else if (tabObjet[i][j] != NULL && personnage->obj == NULL) {
                            // on recupere l'objet sur la table
                            personnage->obj = tabObjet[i][j];
                            //et on initialise la position de l'objet sur la table à nul
                            tabObjet[i][j] = NULL;
                        }

                        break;

                    case 10: // Saumon pas decoupe spwan

                    // si la touche c est appuyer on alloue de la nouvelle pour un saumon
                        personnage->obj = calloc(1, sizeof(objet));
                        // on chope le saumon
                        personnage->obj->saumon_neutre = true;

                        break;


                        // meme chose pour ce qui suit



                    case 11: // algues spwan
                        personnage->obj = calloc(1, sizeof(objet));
                        personnage->obj->algues = true;

                        break;
                    case 12: // avocat normal spwan
                        personnage->obj = calloc(1, sizeof(objet));
                        personnage->obj->avocat_pas_decoupe = true;

                        break;
                    case 13: //  spwan riz
                        personnage->obj = calloc(1, sizeof(objet));
                        personnage->obj->riz_cru = true;

                        break;
                    case 14: //  spwan riz
                        personnage->obj = calloc(1, sizeof(objet));
                        personnage->obj->assiette = true;

                        break;
                }
        }
    }
}


// (regarder dans le main) pour l'instant vers la ligne 183
// mais si la fonction touches perso renvoie true on peut executer deplacer perso

/*
 deplacer perso reçoit les variables direction x et y de touches perso grace au fleche (pointeur) qui permet de passer les variables
 d'une focntion à une autre
*/

void deplacer_personage(creation_personnage* personnage) {
// selon l'information de la direction transmis par directionperso on change la position en x
    personnage->position_x += personnage->direction_x;  //ex si direction = -1 alors la position va aller à gauche

    // selon l'information de la direction transmis par directionperso on change la position en y
    personnage->position_y += personnage->direction_y;



    // Mouvement de l'objet contrôlé par les touches de clavier
    if (personnage->position_x < 0) {
        personnage->position_x = 0;  // Empêcher de sortir à gauche
    }
    if (personnage->position_x + personnage->taille_x > SCREEN_W) {
        personnage->position_x = SCREEN_W - personnage->taille_x;  // Empêcher de sortir à droite
    }
    if (personnage->position_y < 0) {
        personnage->position_y = 0;  // Empêcher de sortir en haut
    }

    if (personnage->position_y + personnage->taille_y > SCREEN_H) {
        personnage->position_y = SCREEN_H - personnage->taille_y;  // Empêcher de sortir à droite
    }
}

/*
 * Affiche la bonne image du personage en fonction de la direction
 */
void afficher_personage(creation_personnage* personnage, BITMAP *page) {

    // On affiche les differentes directions du personage en fonction de sa direction
    if (personnage->direction_x == 0 && personnage->direction_y == 0) {

        draw_trans_sprite( page,personnage->imagePOSE, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == 1 && personnage->direction_y == 0) {

        draw_trans_sprite( page,personnage->imageDROITE, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == -1 && personnage->direction_y == 0) {

        draw_trans_sprite( page,personnage->imageGAUCHE, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == 0 && personnage->direction_y == -1) {

        draw_trans_sprite( page,personnage->imageHAUT, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == 0 && personnage->direction_y == 1) {

        draw_trans_sprite( page,personnage->imageBAS, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == 1 && personnage->direction_y == 1) {

        draw_trans_sprite( page,personnage->imageBAS_DROITE, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == 1 && personnage->direction_y == -1) {

        draw_trans_sprite( page,personnage->imageHAUT_DROITE, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == -1 && personnage->direction_y == 1) {

        draw_trans_sprite( page,personnage->imageBAS_GAUCHE, personnage->position_x, personnage->position_y);
    } else if (personnage->direction_x == -1 && personnage->direction_y == -1) {

        draw_trans_sprite( page,personnage->imageHAUT_GAUCHE, personnage->position_x, personnage->position_y);
    }

    if (personnage->obj != NULL) {
        int invisiblex2 = 0;
        int invisibley2 = 0;

        if (personnage->direction_y == -1) {
            invisiblex2 = personnage->position_x + 7;
            invisibley2 = personnage->position_y - 20;
            draw_trans_sprite( page, personnage->imageHAUT_GAUCHE, invisiblex2, invisibley2);
        } else if (personnage->direction_y == 1){
            invisiblex2 = personnage->position_x + 7;
            invisibley2 = personnage->position_y + 40;
            draw_trans_sprite( page, personnage->imageHAUT_GAUCHE, invisiblex2, invisibley2);
        } else if (personnage->direction_x==1){
            invisiblex2 = personnage->position_x + 10;
            invisibley2 = personnage->position_y + 30;
            draw_trans_sprite( page, personnage->imageHAUT_GAUCHE, invisiblex2, invisibley2);
        } else if (personnage->direction_x==-1){
            invisiblex2 = personnage->position_x - 10;
            invisibley2 = personnage->position_y - 10;
            draw_trans_sprite( page, personnage->imageHAUT_GAUCHE, invisiblex2, invisibley2);
        }
    }
}

void transporterobjet(creation_personnage* personnage, BITMAP *page, BITMAP* image){



        int invisiblex2 = 0;
        int invisibley2 = 0;

        if (personnage->direction_y == -1) {
            invisiblex2 = personnage->position_x + 7;
            invisibley2 = personnage->position_y - 20;

        } else if (personnage->direction_y == 1){
            invisiblex2 = personnage->position_x + 7;
            invisibley2 = personnage->position_y + 40;

        } else if (personnage->direction_x==1){
            invisiblex2 = personnage->position_x + 10;
            invisibley2 = personnage->position_y + 30;

        } else if (personnage->direction_x==-1){
            invisiblex2 = personnage->position_x - 10;
            invisibley2 = personnage->position_y - 10;

        }

        draw_trans_sprite( page, image, invisiblex2, invisibley2);
    }





void detruire_personnage(creation_personnage* personnage) {


    free(personnage);
}