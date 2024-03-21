#include <stdio.h>
#include <allegro.h>
#include <stdbool.h>


typedef struct creation_personnage {
    int position_x;
    int position_y;
    int tomate;
    int riz;
    int saumon;
    int avocat;
    int algue;
    int maki;
    int assiette;
} creation_personnage;
//jrglotg

int main() {
    allegro_init();
    install_mouse();
    install_keyboard();
    creation_personnage perso1;
    set_color_depth(32); // Définir la profondeur de couleur à 32 bits RGBA
    // Activer la prise en charge de la transparence
    set_alpha_blender();
    // Initialiser la profondeur de couleurs de votre écran
    set_color_depth(desktop_color_depth());

    // Ouvrir une fenêtre
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1520, 850, 0, 0) != 0) {
        allegro_message("Erreur d'ouverture de la fenetre");
        return 1;
    }


    if (access("../ressource/image/map1.tga", F_OK) == 0) {
        printf("hello");
    }


    if (access("../ressource/image/photomakitest.tga", F_OK) == 0) {
        printf("hello");
    }

    // Charger l'image depuis un fichier
    BITMAP *imagemaki = load_tga("../ressource/image/photomakitest.tga", NULL);
    if (!imagemaki) {
        allegro_message("haram 8 mort 6 bléssés ");
        return 1;
    }
    // Charger l'image depuis un fichier
    BITMAP *imagemap = load_tga("../ressource/image/map1.tga", NULL);
    if (!imagemap) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    // Charger l'image depuis un fichier
    BITMAP *imageDROITE = load_tga("../ressource/image/DROITE.tga", NULL);
    if (!imageDROITE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    // Charger l'image depuis un fichier
    BITMAP *imageBAS = load_tga("../ressource/image/BAS.tga", NULL);
    if (!imageBAS) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    // Charger l'image depuis un fichier
    BITMAP *imageGAUCHE = load_tga("../ressource/image/GAUCHE.tga", NULL);
    if (!imageGAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    // Charger l'image depuis un fichier
    BITMAP *imageHAUT = load_tga("../ressource/image/HAUT.tga", NULL);
    if (!imageHAUT) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
// Charger l'image depuis un fichier
    BITMAP *imagePOSE = load_tga("../ressource/image/POSE.tga", NULL);
    if (!imagePOSE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    // Charger l'image depuis un fichier
    BITMAP *imageHAUT_DROITE = load_tga("../ressource/image/imageHAUT_DROITE.tga", NULL);
    if (!imageHAUT_DROITE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
    // Charger l'image depuis un fichier
    BITMAP *imageBAS_DROITE = load_tga("../ressource/image/imageBAS_DROITE.tga", NULL);
    if (!imageBAS_DROITE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    // Charger l'image depuis un fichier
    BITMAP *imageBAS_GAUCHE = load_tga("../ressource/image/imageBAS_GAUCHE.tga", NULL);
    if (!imageBAS_GAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

    // Charger l'image depuis un fichier
    BITMAP *imageHAUT_GAUCHE = load_tga("../ressource/image/imageHAUT_GAUCHE.tga", NULL);
    if (!imageHAUT_GAUCHE) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }

// Charger l'image depuis un fichier
  /*  BITMAP *imageinvisble1 = load_tga("../ressource/image/imageinvisble1.tga", NULL);
    if (!imageinvisble1) {
        allegro_message("../ressource/image/map1.tga");
        return 1;
    }
*/
    // Créer un double buffer
    BITMAP *page = create_bitmap(SCREEN_W, SCREEN_H);
    clear(page);

    printf("La taille de mon écran est %d par %d", SCREEN_W, SCREEN_H);

    int x = 300, y = 300;
    int dx = 1, dy = 1;
    int taillex = 64, tailley = 71;
    int points = 0;
    int y1;
    int x1;
    int y2 = 55;
    int x2 = 55;
    int xobjet1 = 400;
    int yobjet1 = 400;
    int mapx= 0;
    int mapy = 0;
    int invisiblex1=20;
    int invisibley1=20;
    int invisiblex2=20;
    int invisibley2=20;
    int tailleinvisblex2 = 50;
    int tailleinvisbley2 = 50;

    bool rectangle_visible = true;
    bool POSE = true;
    while (!key[KEY_ESC]) {
        // Effacer l'écran
        clear(page);


        // Afficher la souris à l'écran
        show_mouse(page);

        // Boucle de jeu
        textprintf_ex(page, font, 0, 250, makecol(255, 255, 255), -1, "%d Points", points);
      //  draw_trans_sprite(page, imageinvisble1,invisiblex2,invisibley2);
        blit(imagemap, page, 0, 0, mapx, mapy, imagemap->w, imagemap->h);
        rectfill(page, x, y, x + taillex, y + tailley, makecol(255, 255, 255));
        rectfill(page, x2, y2, x2 + taillex, y2 + tailley, makecol(13, 255, 145));
        rectfill(page, invisiblex2, invisibley2, invisiblex2+ tailleinvisblex2, invisibley2 + tailleinvisbley2, makecol(0,0,0) );
        // Dessiner l'image à la place du premier rectangle
        if (rectangle_visible) {
            draw_trans_sprite(page,imagemaki,   xobjet1, yobjet1);
        }


       if( POSE != (key[KEY_W] || key[KEY_A] || key[KEY_S] || key[KEY_D] || key[KEY_S]&&key[KEY_D] || key[KEY_S]&&key[KEY_A] || key[KEY_W]&&key[KEY_D] || key[KEY_W]&&key[KEY_A])){
           draw_trans_sprite(page,imagePOSE,  x1, y1);

       }

        // Mouvement de l'objet contrôlé par les touches de clavier
        if (x1 < 0) {
            x1 = 0;  // Empêcher de sortir à gauche
        }
        if (x1 + taillex > SCREEN_W) {
            x1 = SCREEN_W - taillex;  // Empêcher de sortir à droite
        }
        if (y1 < 0) {
            y1 = 0;  // Empêcher de sortir en haut
        }
        if (y1 + tailley > SCREEN_H) {
            y1 = SCREEN_H - tailley;  // Empêcher de sortir en bas
        }

        if (x2 < 0) {
            x2 = 0;  // Empêcher de sortir à gauche
        }
        if (x2 + taillex > SCREEN_W) {
            x2 = SCREEN_W - taillex;  // Empêcher de sortir à droite
        }
        if (y2 < 0) {
            y2 = 0;  // Empêcher de sortir en haut
        }
        if (y2 + tailley > SCREEN_H) {
            y2 = SCREEN_H - tailley;  // Empêcher de sortir en bas
        }

        // touche de déplacement des personnages
        if (key[KEY_S]&&key[KEY_D]) {
            y1++;
            x1++;
            draw_trans_sprite( page,imageBAS_DROITE,x1, y1);

        }
        // touche de déplacement des personnages
        if (key[KEY_S]&&key[KEY_A]) {
            y1++;
            x1--;
            draw_trans_sprite( page,imageBAS_GAUCHE,x1, y1);

        }
        // touche de déplacement des personnages
        if (key[KEY_W]&&key[KEY_D]) {
            y1--;
            x1++;
            draw_trans_sprite( page,imageHAUT_DROITE,x1, y1);

        }

        // touche de déplacement des personnages
        if (key[KEY_W]&&key[KEY_A]) {
            y1--;
            x1--;
            draw_trans_sprite( page,imageHAUT_GAUCHE,x1, y1);


        }
        else if(key[KEY_S]) {
            y1++;
            draw_trans_sprite( page,imageBAS,x1, y1);
        }
        else if (key[KEY_W]) {
            y1--;
            draw_trans_sprite( page, imageHAUT,  x1, y1);
        }
        else if (key[KEY_A]) {
            x1--;
            draw_trans_sprite( page,imageGAUCHE,   x1, y1);
        }
        else if (key[KEY_D]) {
            x1++;
            draw_trans_sprite( page,imageDROITE, x1, y1);

        }

        else if (key[KEY_DOWN]) {
            y2++;
            invisiblex2 = x2 + 7;
            invisibley2 = y2 + 40;
            rectfill(page, invisiblex2, invisibley2, invisiblex2+ tailleinvisblex2, invisibley2 + tailleinvisbley2, makecol(0,0,0) );

        }
        if (key[KEY_UP]) {
            y2--;
            invisiblex2 = x2 + 7;
            invisibley2 = y2 - 20;
            rectfill(page, invisiblex2, invisibley2, invisiblex2+ tailleinvisblex2, invisibley2 + tailleinvisbley2, makecol(0,0,0) );


        }

        if (key[KEY_LEFT]) {
            x2--;
            invisiblex2 = x2 - 10;
            invisibley2 = y2 + 10;
            rectfill(page, invisiblex2, invisibley2, invisiblex2+ tailleinvisblex2, invisibley2 + tailleinvisbley2, makecol(0,0,0) );


        }
        if (key[KEY_RIGHT]) {
            x2++;
            invisibley2 = y2 + 10;
            invisiblex2 = x2 + 30;
            rectfill(page, invisiblex2, invisibley2, invisiblex2+ tailleinvisblex2, invisibley2 + tailleinvisbley2, makecol(0,0,0) );

        }

        // Si les deux rectangles ont au moins un pixel en commun et si la touche "C" est pressée, rendre le rectangle invisible
        if ((x1 <= xobjet1 + taillex && x1 + taillex >= xobjet1 && y1 <= yobjet1 + tailley && y1 + tailley >= yobjet1) && key[KEY_C]) {
            rectangle_visible = false;

            perso1.maki = 1;
        }

        //si plus maki essaye de le refaire apparaitre
        if(rectangle_visible == false && key[KEY_C] ) {
            perso1.maki = 0;
            draw_trans_sprite( page,imagemaki, x1 + taillex + 1, y1);
        }

        // Faire bouger le texte vers la droite
        if (x + taillex > SCREEN_W || x < 0) {
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

        // Afficher la page sur screen
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    // Libérer la mémoire de l'image
    destroy_bitmap(imagemaki);
    destroy_bitmap(imagemap);


    allegro_exit();
    return 0;
}
END_OF_MAIN()
