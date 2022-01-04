#include "gameControl.h"

enum PLAYER_ACTION getPlayerAction() {
    MLV_Keyboard_button sym   = MLV_KEYBOARD_NONE;
    MLV_Keyboard_modifier mod = MLV_KEYBOARD_KMOD_NONE;
    MLV_Input_box *input_box  = NULL;
    char* texte               = NULL;
    MLV_Button_state state;
    int x, y;

    /* getting the event */
    MLV_Event ev = MLV_get_event( 
            &sym, &mod, NULL,
            &texte, &input_box,
            &x, &y, NULL,
            &state
    );

    /* checking the event */
    switch( ev ) {
    	/* keyboard event */
    	case MLV_KEY :
    		if(state == MLV_PRESSED) {
    			switch( sym ) {
    				case MLV_KEYBOARD_ESCAPE :
    					return QUIT;
    				case MLV_KEYBOARD_z :
    					return UP;
    				case MLV_KEYBOARD_q :
    					return LEFT;
    				case MLV_KEYBOARD_s :
    					return DOWN;
    				case MLV_KEYBOARD_d :
    					return RIGHT;
    				case MLV_KEYBOARD_i :
    					return INVENTORY;
    				case MLV_KEYBOARD_o :
    					return OPTN;
    				default :
    					break;
    				/* ideas for PHYSICAL and MAGICAL ? */
    			}
    		}
    	/* mouse event */
    	case MLV_MOUSE_BUTTON :
    		if(state == MLV_PRESSED) {
    			/* check mouse coords */
    			return MLV_NONE; /* TODO */
    		}
    	/* no event */
    	case MLV_NONE :
    		return NO_ACTION;

    	default :
    		return NO_ACTION;
    }
    return NO_ACTION;
}

int doAction(enum PLAYER_ACTION act, Stage *stage, Player *player) {
	switch( act ) {
		case UP :
			playerMove(*stage, player, N);
			return 1;
		case DOWN :
			return playerMove(*stage, player, S);
		case LEFT :
			playerMove(*stage, player, W);
			return 1;
		case RIGHT :
			playerMove(*stage, player, E);
			return 1;
		case PHYSICAL :
			return 1;
		case MAGICAL :
			return 1;
		case INVENTORY :
			/* function for the inventory */
			return 1;
		case OPTN :
			/* function for the options */
			return 1;
		case QUIT :
			return -1;
		default :
			return 0;
	}
}