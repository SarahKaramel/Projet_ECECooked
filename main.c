#include <stdio.h>
#include <allegro.h>
#include <stdbool.h>
#include <time.h>
#include "personage.h"

// pour garder toute les images dans une structure pour pouvoir passser en paramètre toute les images d'un seul à une fonction
struct images_objets {
    BITMAP *imagealgues;
    BITMAP *image_assiette;
    BITMAP *imageriz_cru;
    BITMAP *imageavocapasdecoupe;
    BITMAP *imagemaki;
} images_objets;

// fonction qui telecharge toute les images



int main() {
    allegro_init();
    install_mouse();
    install_keyboard();


    set_color_depth(32); // Définir la profondeur de couleur à 32 bits RGBA
    //activer la prise en charge de la transparence
    set_alpha_blender();
    //initialiser la profondeur de couleurs de votre écran
    set_color_depth(desktop_color_depth());
    // Ouvrir une fenêtre
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1520, 850, 0, 0) != 0) {
        allegro_message("Erreur d'ouverture de la fenetre");
        return 1;
    }

    BITMAP *menu = load_tga("../ressource/image/menu.tga", NULL);
    if (!menu) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    BITMAP *imagealgues = load_tga("../ressource/image/algues.tga", NULL);
    if (!imagealgues) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    BITMAP *image_assiette = load_tga("../ressource/image/assiette.tga", NULL);
    if (!image_assiette) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    BITMAP *imageriz_cru = load_tga("../ressource/image/riz_cru.tga", NULL);
    if (!imageriz_cru) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }

    BITMAP *imageavocapasdecoupe = load_tga("../ressource/image/avocat_pas_decoupe_.tga", NULL);
    if (!imageavocapasdecoupe) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    BITMAP *imagemaki = load_tga("../ressource/image/photomakitest.tga", NULL);
    if (!imagemaki) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    BITMAP *table1Ca = load_tga("../ressource/image/table1C.tga", NULL);
    if (!table1Ca) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    BITMAP *imagemap = load_tga("../ressource/image/map1.tga", NULL);
    if (!imagemap) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }


    BITMAP *image1_carreau_table = load_tga("../ressource/image/table_1c.tga", NULL);
    if (!image1_carreau_table) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    BITMAP *sol_map = load_tga("../ressource/image/sol_map.tga", NULL);
    if (!sol_map) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    BITMAP *image_2_carreaux_table = load_tga("../ressource/image/table_2c.tga", NULL);
    if (!image_2_carreaux_table) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    // Charger l'image depuis un fichier
    BITMAP *bloc_transparent = load_tga("../ressource/image/bloctransparent.tga", NULL);
    if (!bloc_transparent) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    BITMAP *poubelle = load_tga("../ressource/image/poubelle.tga", NULL);
    if (!poubelle) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    BITMAP *tablepivoter = load_tga("../ressource/image/tablepivoter.tga", NULL);
    if (!tablepivoter) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    BITMAP *saumonneutre = load_tga("../ressource/image/saumon_pas_decoupe.tga", NULL);
    if (!saumonneutre) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    /* BITMAP *IMAGE2JOUEURSINVISIBLE = load_tga("../ressource/image/saumon_pas_decoupe.tga", NULL);
     if (!) {
         allegro_message("../ressource/image/map1.tga");
         return 1;
     }*/
    // borne gauche 190 borne droit 570
    //borne

    // Créer un double buffer
    BITMAP *page = create_bitmap(SCREEN_W, SCREEN_H);
    clear(page);

    printf("La taille de mon ecran est %d par %d", SCREEN_W, SCREEN_H);
///////////////////////////////// nul / 20
// sert à rien
    int x = 300, y = 300;
    int dx = 1, dy = 1;
/////////////////////////////////
    int taillex = 64, tailley = 71;
    int points = 0;



// le pointeur vaut nul si il y a pas d'objet voir la structure objet par exemple table n'est pas un objet mais saumon pas cuit si
    objet *tabObjet[LIGNE][COLONNE];

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 20; ++j) {
            tabObjet[i][j] = NULL;
        }
    }
    int tab[LIGNE][COLONNE] = {
            {9, 8,  8,  8,  8,  8,  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 7, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 0,  0,  0,  0,  0,  0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 12, 11, 10, 13, 14, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
            {9, 8,  8,  8,  8,  8,  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9},
    };



    bool twoplayer = false;
    bool startjeu = false;
    bool code = true;
    bool menujeu = true;
    while (code) {
        if (menujeu) {
            draw_trans_sprite(page, menu, 0, 0);
            show_mouse(page);
         /*
           rectfill(page, 350, 330, 520, 385, makecol(255, 255, 255));
            rectfill(page, 250, 265, 600, 320, makecol(100, 100, 100));
            rectfill(page, 250, 200, 600, 250, makecol(0, 0, 0));
            */
            blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        }

        if (mouse_b & 1
            && mouse_x > 350 && mouse_x < 520 // Curseur x à l'interieur du rectangle
            && mouse_y > 330 && mouse_y < 385) {
            exit(0);
        }
        //350 largeur       //55 hauteur
        if (mouse_b & 1 // Clic gauche
            && mouse_x > 250 && mouse_x < 600 // Curseur x à l'interieur du rectangle
            && mouse_y > 200 && mouse_y < 250) {
            twoplayer = false;
            startjeu = true;

        }// Curseur y à l'interieur du rectangle)
        //afficher la page sur screen
        if (mouse_b & 1 // Clic gauche
            && mouse_x > 250 && mouse_x < 600 // Curseur x à l'interieur du rectangle
            && mouse_y > 265 && mouse_y < 320) // Curseur y à l'interieur du rectangle)
        {
            twoplayer = true;
            startjeu = true;
        }
            if (startjeu) {
                long long total_seconds = 120;
                long long start_seconds = time(NULL);// je recupere l'heure actuelle en secondes
                creation_personnage perso1 = creer_personage1();

                creation_personnage perso2 = creer_personage2();


                while (!key[KEY_ESC]) {

                    // Effacer l'écran
                    clear(page);


                    // Afficher la souris à l'écran
                    show_mouse(page);


                    for (int i = 0; i < 12; ++i) {
                        for (int j = 0; j < 20; ++j) {


                            switch (tab[i][j]) {
                                case 0:
                                    draw_trans_sprite(page, sol_map, j * 76, i * 68);
                                    break;

                                case 2 :
                                    draw_trans_sprite(page, imagemaki, i * 74, y * 68);
                                    break;

                                case 3 :
                                    draw_trans_sprite(page, image1_carreau_table, j * 76, i * 68);
                                    break;
                                case 4 :
                                    draw_trans_sprite(page, image_2_carreaux_table, j * 76, i * 68);
                                    break;
                                case 5:
                                    draw_trans_sprite(page, bloc_transparent, j * 76, i * 68);
                                    break;
                                case 7:
                                    draw_trans_sprite(page, poubelle, j * 76, i * 68);
                                    break;
                                case 8:
                                    draw_trans_sprite(page, table1Ca, j * 76, i * 68);
                                    break;
                                case 9:
                                    draw_trans_sprite(page, tablepivoter, j * 76, i * 68);
                                    break;
                                case 10:
                                    draw_trans_sprite(page, sol_map, j * 76, i * 68);
                                    draw_trans_sprite(page, saumonneutre, j * 76, i * 68);
                                    break;
                                case 11:
                                    draw_trans_sprite(page, sol_map, j * 76, i * 68);
                                    draw_trans_sprite(page, imagealgues, j * 76, i * 68);
                                    break;
                                case 12:
                                    draw_trans_sprite(page, sol_map, j * 76, i * 68);
                                    draw_trans_sprite(page, imageavocapasdecoupe, j * 76, i * 68);
                                    break;
                                case 13:
                                    draw_trans_sprite(page, sol_map, j * 76, i * 68);
                                    draw_trans_sprite(page, imageriz_cru, j * 76, i * 68);
                                    break;
                                case 14:
                                    draw_trans_sprite(page, sol_map, j * 76, i * 68);
                                    draw_trans_sprite(page, image_assiette, j * 76, i * 68);
                                    break;
                            }




                            //on parcours aussi en même à l'aide des 2 boucles for le tableau d'objet alors si on trouve un objet on le fait apparaitre
                            if (tabObjet[i][j] != NULL) {
                                if (tabObjet[i][j]->assiette)
                                    draw_trans_sprite(page, image_assiette, j * 76, i * 68);
                                if (tabObjet[i][j]->saumon_neutre)
                                    draw_trans_sprite(page, saumonneutre, j * 76, i * 68);
                                if (tabObjet[i][j]->avocat_pas_decoupe)
                                    draw_trans_sprite(page, imageavocapasdecoupe, j * 76, i * 68);
                                if (tabObjet[i][j]->algues)
                                    draw_trans_sprite(page, imagealgues, j * 76, i * 68);
                                if (tabObjet[i][j]->riz_cru)
                                    draw_trans_sprite(page, imageriz_cru, j * 76, i * 68);
                            }
                        }
                    }
////////////////////////////////////////////////////////////////////////////////////////
                    if (touches_personage1(&perso1))
                        deplacer_personage(&perso1);
                    afficher_personage(&perso1, page);

                    if (twoplayer) {
                    if (touches_personage2(&perso2))
                        deplacer_personage(&perso2);
                }
                    //pour faire spawn le carré invisble que quand on veut faire laction avec
                        if (key[KEY_C])
                        attraper_objet(&perso1, page, tab, tabObjet);
                    if (twoplayer){  afficher_personage(&perso2, page);}
                    if (twoplayer){    if (key[KEY_L])
                        attraper_objet(&perso2, page, tab, tabObjet);}
/////////////////////////////////////////////////////////////////////////////////////////
                    long long now_seconds = time(NULL);// je recupere lheure actuelle nouvelle
                    // je calcule la différence (qui va etre négatif)
                    // et je ladditionne au total de secondes
                    long long remaining_seconds = start_seconds - now_seconds + total_seconds;
                    // affichage des secondes sur lecran
                    textprintf_ex(page, font, 200, 250, makecol(255, 255, 255), -1, "%lld Secondes", remaining_seconds);




                    //affichage des points pas encore utilisé
                    textprintf_ex(page, font, 0, 250, makecol(255, 255, 255), -1, "%d Points", points);


                    //afficher la page sur screen
                    blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                }


                allegro_exit();
                return 0;
            }
        }
    }

END_OF_MAIN()









// souvenir de ce code plus utile pour la nostalgie voila .....
// Si les deux rectangles ont au moins un pixel en commun et si la touche "C" est pressée, rendre le rectangle invisible
/* if ((x1 <= xobjet1 + taillex && x1 + taillex >= xobjet1 && y1 <= yobjet1 + tailley && y1 + tailley >= yobjet1) && key[KEY_C] && perso1.maki == 0) {
     rectangle_visible = false;
     estplein = false
     perso1.maki = 1;

     while (key[KEY_C]);
 }

 //si plus maki essaye de le refaire apparaitre
 if(rectangle_visible == false && key[KEY_C]&& perso1.maki>0 ) {
     perso1.maki = 0;

     xobjet1 = x1 ;
     yobjet1 = y1 ;
     rectangle_visible = true;
     while (key[KEY_C]);

 }
*/
// Faire bouger le texte vers la droite
/*    if (x + taillex > SCREEN_W || x < 0) {
        dx = dx * (-1);
    }
    if (y + tailley > SCREEN_H || y < 0) {
        dy = dy * (-1);
    }

    x += dx;
    y += dy;

    // Si le curseur est à l'intérieur du rectangle ET que le joueur clique, alors ajouter 1 point
    if (mouse_b & 1 // Clic gauche
        && mouse_x > x && mouse_x < x + taillex // Curseur x à l'interieur du rectangle
        && mouse_y > y && mouse_y < y + tailley) // Curseur y à l'interieur du rectangle
    {
        points++;
    }
*/