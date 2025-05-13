inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Planing room";
	long_desc= "This seems to be where the soldiers plan their attacks. There is\n"+
	"a big table in the middle of the room with papers and a big map\n"+
	"in the center of the table. There are stools surrounding the table\n"+
	"and a big chair at the head of the table, probably where the lord\n"+
	"of the fortess sits when planing their battles. Lucky for you he\n"+
	"isnt there at the moment.\n";
	items =
	({
	  "table","A big table with maps and scrolls on it",
	  "chair","A big black chair made out of bones for the lord of Haden",
	  "stools","Where the other soldiers sit",
	  "scrolls","You cant read the writing on them",
	  "maps","Just maps of areas, some you have never seen before",
	});
clone_list = ({
1, 2, "rat", "players/tuppence/fortress/monster/rat", 0,
});
	dest_dir =
	({
	  FROOM+"maproom","east",
	  FROOM+"hall4","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
