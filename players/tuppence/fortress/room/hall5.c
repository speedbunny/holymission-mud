inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Hall leading to the dungeons";
	long_desc= "This is the hallway leading to the stairs to the dungeons.\n"+
	"The hallway is lit up by torches and candles. The stairs leading\n"+
	"down to the dungeons look dark and dusty. You had better not go down\n"+
	"there, you might never come back up. Legends say that an evil demon\n"+
	"guards the prisoners, so no one gets out or in.\n";
	items =
	({
	  "torches","They light up the hallway",
	  "cwithles","They are black and blood dripping from them",
	  "stairs","They lead down to the dungeons, dont go down there",
	});
	dest_dir=
	({
	  FROOM+"hall4","east",
	  FROOM+"hall6","north",
	  FROOM+"dun1","down",
	});
    }
::reset(arg);
replace_program("/room/room");
}
