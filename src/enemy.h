/* Autors : Nicolas Mazeyrac, Lysandre Macke
 * Creation : 27/11/2021
 * Modification : 03/01/2022*/

/* General libraries */
#include <stdlib.h>

/* Internal libraries */
#include "player.h"

#ifndef __ENEMY__
#define __ENEMY__

    /*Define*/

    #define LEVEL_WIDTH  63
    #define LEVEL_HEIGHT 43

    /*Struct*/

    typedef struct {
        char* name;/*Name of the monster*/
        unsigned int exp;/*Exp given after its death*/
        unsigned int attack;/* Used to calculate the power of a melee attack */
        unsigned int hp;/*hp*/
        Critical crit;/* Information about critical attack */
    } Enemy;

    typedef struct NextEnemy{
        Enemy enemy;
        Point coords;
        struct NextEnemy* nextEnemy;
    }ListEnemy;


    /*Functions*/

    /* Returns an enemy which attributes will be determined by the current stage and his distance from the stairs */
    Enemy generateEnemy(unsigned int stage, unsigned int distance);

    /* Debug */
    void quickPrintEnemy(Enemy enemy);
#endif