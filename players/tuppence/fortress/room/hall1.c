inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc="Lighted hallway";
	long_desc="Somehow you have managed to pass the guards and enter. The long\n"+
	"hallway stretches north, and seems like it will never end. The walls have\n"+
	"torches bracketed on them to light up the hallway. As you stare at the walls\n"+
	"with terror, you see heads hanging on them up and down the hallway. You\n"+
	"feel you will be sick.\n";
	items=
	({
	  "hallway","It is long and dangerous looking",
	  "walls","torches and heads are hung there, the heads seem to stare\n"+
	          "at you",
	  "torches","Big lit torches to light up the hallway",
	  "heads","They are rotten, bloody heads from dead soldiers",
	});
	dest_dir=
	({
	FROOM+"hall2","north",
	FROOM+"weproom","east",
	FROOM+"armroom","west",
	  FROOM+"gates","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}
