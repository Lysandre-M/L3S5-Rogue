/* Auteurs : Nicolas Mazeyrac, Lysandre Macke
 * Creation : 26/12/2021
 * Modification : 13/01/2022*/

/*Bibliothèque générale*/

/*Bibliothèque interne*/
#include "gameControl.h"
#include "save.h"

#ifndef __TURN__
#define __TURN__

    /*Define*/

    #define SCREEN_WIDTH  13 /* The number of cells presented on the screen horizontaly */
    #define SCREEN_HEIGHT  9 /* The number of cells presented on the screen verticaly */

    /*Struct*/


    /*Functions*/

    /* Perform the turn of the monster, attack first then move */
    int enemyTurn(Enemy monster, Player* player, Point coordEnemy, Stage* level);

    /* Perform the turn of all the monsters */
    int allEnemyTurn(Stage *level, Player* player, ListCoord* coordsEnnemies);

    /* Perform the turn of all the monsters present on screen */
    int turnEnemyOnScreen(Stage *stage, Player* player);

    /* Perform one turn of a player */
    int playerTurn(Player *player, StageList *dungeon, int *play, int *quit);
#endif