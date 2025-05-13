inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "It is too dark";
	long_desc= "The torches in this room seem to have gone out right when you\n"+
	"entered. A cold draft blows through you, you shiver. Strange sounds\n"+
	"echo through the halls. You start to wonder if it was a good idea to\n"+
	"even enter this fortess.\n";
	items =
	({
	  "torches","Dark torches",
	});
	dest_dir =
	({
	  FROOM+"plroom","east",
	  FROOM+"hall5","west",
	  FROOM+"hall3","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}
