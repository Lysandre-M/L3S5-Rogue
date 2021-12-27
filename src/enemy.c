#include "enemy.h"
#include <stdio.h>

Enemy generateEnemy(unsigned int stage, unsigned int manhattan) {
    
    Enemy monster;
    unsigned int stat;

    monster.name = "Monster";

    stat = 10*stage + manhattan;
    monster.attack = stat;
    monster.hp = stat;

    monster.crit.modificater = 3 ; /* 300% */
    monster.crit.rate = 5;           /* 5% */
    monster.crit.accuracy = 20 ;    /* +/-20% */

    return monster;
}

int enemyIsDead(Enemy monster) {
    if(monster.hp <= 0){
        return 1;
    }
    return 0;
}

void quickPrintEnemy(Enemy monster){
    printf("****Enemy STATS****\n");
    printf("name            : %s\n", monster.name);

    printf("strenght        : %d\n",  monster.attack);

    printf("hp              : %d\n", monster.hp);

    printf("CritModificater : %d%%\n", monster.crit.modificater*100);
    printf("CritRate        : %d%%\n", monster.crit.rate);
    printf("Accuracy        : %d%% - %d%%\n", 100-monster.crit.accuracy, 100+monster.crit.accuracy);
}