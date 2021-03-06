#include "loot.h"

Equipment generateEquipment(EquipType type, unsigned int quality, unsigned int rarity){
    
    Equipment equipment;
    
    assert(type != NONE);

    /* Generate a new equipment object */
    equipment.quality = quality;
    equipment.rarity = rarity;
    equipment.type = type;

    return equipment;
}

Equipment generateRandomEquipment(unsigned int quality, unsigned int rarity){
    
    Equipment equipment;
    int randomnumber;

    randomnumber = rand() % NUM_EQUIP_TYPE;/* no equipment is rarer than the other */

    /* The quality and rarety are the same no matter the type of equipment */
    switch(randomnumber){
        case 0:equipment = generateEquipment(ARMOR, quality, rarity);break;
        case 1:equipment = generateEquipment(WEAPON, quality, rarity);break;
        case 2:equipment = generateEquipment(WAND, quality, rarity);break;
        default :fprintf(stderr, "ERROR: randomnumber = %d \n", randomnumber);
    }

    return equipment;
}

Consummables generateRandomConsummable(void){
    int randomnumber;

    randomnumber = rand() % NUM_DIFF_CONSUMMABLE;/* no object is rarer than the other */

    switch(randomnumber){
        case 0:return HEAL;
        case 1:return MAGIC;
        case 2:return REGEN;
        case 3:return LEARNING;
        case 4:return PRECISION;
        default :fprintf(stderr, "ERROR: not a consummable randomnumber = %d \n", randomnumber);
    }

    return EMPTY;
}

Loot generateLoot(unsigned int quality, unsigned int rarity, LootType type) {
    
    Loot loot;

    loot.type = type;

    switch(loot.type){
        case EQUIPMENT: loot.equipment = generateRandomEquipment(quality, rarity);break;
        case CONSUMMABLE: loot.consummable = generateRandomConsummable();break;/* the quality and rarity are not used for consummables */
        case NO_ITEM:break;
        default : fprintf(stderr, "This type of loot doesn't exist");
    }

    return loot;
}

/* Shell display */

int quickPrintEquipment(Equipment equip){

    switch(equip.type){
        case ARMOR: printf("ARMOR \n");break;
        case WEAPON: printf("WEAPON \n");break;
        case WAND: printf("WAND \n");break;
        case NONE: printf("NONE \n");break;
        default: fprintf(stderr, "ERROR \n");return 0;
    }
    /* in addition to the type print all other information */
    printf("- rarity : %d \n", equip.rarity);
    printf("- quality : %d \n", equip.quality);
    return 1;
}

int quickPrintConsummable(Consummables consummable){

    switch(consummable){
        case HEAL: printf("HEAL \n");break;
        case MAGIC: printf("MAGIC \n");break;
        case REGEN: printf("REGEN \n");break;
        case LEARNING: printf("LEARNING \n");break;
        case PRECISION: printf("PRECISION \n");break;
        case EMPTY: printf("EMPTY \n");break;
        default: fprintf(stderr, "ERROR \n");return 0;
    }

    return 1;
}

int quickPrintLoot(Loot loot){
    

    switch(loot.type){
        case EQUIPMENT: printf("EQUIPMENT : \n");return quickPrintEquipment(loot.equipment);break;
        case CONSUMMABLE: printf("CONSUMMABLE : \n");return quickPrintConsummable(loot.consummable);break;
        case NO_ITEM:printf("NO_ITEM : \n"); return 1;break;
        default : fprintf(stderr, "This type of loot doesn't exist");
    }
    return 0;
}