inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "A dark dungeon";
	long_desc= "You sense evil as you walk into the room. Glowing red and yellow\n"+
	"eyes surround you in the shadows. The walls have scratch marks on\n"+
	"them. Skeletons and bones are lying around the room. Blood decorates\n"+
	"the walls. You can hear a low grumbling, as if it is some warning  \n"+
	"to you.\n";
	items =
	({
	  "eyes","They are looking straight through you it seems",
	  "walls","Blood is just soaked on them",
	  "skeletons","Probably from some poor prisoners",
	  "bones","Bones that have come off the skeletons",
	  "marks","Scratch marks from some huge beast",
	  "shadows","Dark shadows surround you with eyes glowing at you",
	});
	dest_dir=
	({
	  FROOM+"dun1","east",
	  FROOM+"dun3","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
