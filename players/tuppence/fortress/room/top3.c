inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
if(!arg){
set_light(1);
short_desc= "Black monk chambers";
long_desc= "This is the chamber of the black monks. They dwell here in their magic.\n"+
	    "You can almost smell the death and disease here.\n"+
	    "The whole room is decorated in black and brown. There are\n"+
	    "two round tables in the middle of the room, with vials and herbs\n"+
	    "ready for some kind of deadly potion, spell or other harmful things.\n";
items=
({
"tables","They both have poison and deadly herbs on them",
"herbs","They look bad for you",
"vials","They are empty and waiting for deadly potions to fill them",
});
clone_list = ({
1, 2, "monk", "players/tuppence/fortress/monster/bmonk", 0,
-1, 1, "staff", "players/tuppence/fortress/weapon/bmstaff", 0,
});
dest_dir=
({
FROOM+"top2","east",
});
}
::reset(arg);
replace_program("/room/room");
}
