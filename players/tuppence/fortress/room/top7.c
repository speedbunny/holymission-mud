inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Vined hallway";
	long_desc= "Wow, even more vines cover this room. The silver vines are so thick\n"+
	"you can hardly see the room. You feel like you are in a jungle. Something\n"+
	"has fallen out of the vines and onto the ground. The hallway is\n"+
	"decorated in unique metals and stone furniture.\n";
	items=
	({
	  "vines","Big silver vines with golden leafs cover the room",
	  "metals","They are very scarce in this area of the world",
	  "furniture","It is all made out of lime stone",
	});
clone_list = ({
1, 2, "leaf", "players/tuppence/fortress/monster/leaf", 0,
-1, 1, "thorn", "players/tuppence/fortress/weapon/thorn", 0,
});
	dest_dir=
	({
	  FROOM+"top6","west",
	  FROOM+"top9","south",
	  FROOM+"top8","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
