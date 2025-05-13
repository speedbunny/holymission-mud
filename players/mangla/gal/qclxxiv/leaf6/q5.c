#include "/players/qclxxiv/myroom.h"  
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object key_obj, dwarfsoldier;
object rat1, rat2, wig, stinkhorn, cr1, cr2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
    if (!dwarfsoldier) {
    	dwarfsoldier = clone_object("players/qclxxiv/leaf7/dwarfsoldier");
    	move_object(dwarfsoldier, this_object());
		MAKE_KEY( key_obj, "dirty","inshackle" );
    	move_object(key_obj, dwarfsoldier);
    }
	FRESH_IN_ROOM(stinkhorn, LEAF+"stinkhorn");
	PLACE_IN_ROOM(rat1, LEAF+"bigrat");
	PLACE_IN_ROOM(rat2, LEAF+"bigrat");
	PLACE_IN_ROOM(cr1, LEAF+"cockroach");
	PLACE_IN_ROOM(cr2, LEAF+"cockroach");
	PLACE_IN_ROOM(wig, LEAF+"earwig");
	if (arg) return;
	items = ({ 
				"path","The dirty remainders of what once has been a path",
				"track","The dirty remainders of what once has been a path",
				"filth","The filthiest of all filths has been gathered here",
			});
}

THREE_EXIT( LEAF+"q6","west",
			LEAF+"q4","east",
			LEAF+"q9","southeast",
       	 "A dingy, dark, filth-covered track",
"A dingy, dark, filth-covered track that seems to have been a path once.\n"+
"It's terribly humid down here and also terribly cold. The stench makes you\n"+
"vomit repeatedly.\n" , 0)

