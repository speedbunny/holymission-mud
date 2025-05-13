#include "/players/qclxxiv/myroom.h"  
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object rat1, rat2, spider, stinkhorn, cr1, cr2;
object key_obj, dwarfsoldier;

query_qnewbie() { return 1; }
extra_reset(arg) { 
    if (!dwarfsoldier) {
    	dwarfsoldier = clone_object("players/qclxxiv/leaf7/dwarfsoldier");
    	move_object(dwarfsoldier, this_object());
		MAKE_KEY( key_obj, "musty","inshelter" );
    	move_object(key_obj, dwarfsoldier);
    }
	FRESH_IN_ROOM(stinkhorn, LEAF+"stinkhorn");
	PLACE_IN_ROOM(rat1, LEAF+"bigrat");
	PLACE_IN_ROOM(rat2, LEAF+"bigrat");
	PLACE_IN_ROOM(cr1, LEAF+"cockroach");
	PLACE_IN_ROOM(cr2, LEAF+"cockroach");
	PLACE_IN_ROOM(spider, LEAF+"spider");
	if (arg) return;
	items = ({ 
				"path","The grubby remainders of what once has been a path",
				"track","The grubby remainders of what once has been a path",
				"filth","The filthiest of all filths has been gathered here",
			});
}

THREE_EXIT( LEAF+"q16","west",
			LEAF+"q14","east",
			LEAF+"q9","northeast",
       	 "A smudgy, dark, filth-covered track",
"A smudgy, dark, filth-covered track that seems to have been a path once.\n"+
"It's terribly cold down here and also terribly humid. The stench makes you\n"+
"vomit repeatedly.\n" , 0)

