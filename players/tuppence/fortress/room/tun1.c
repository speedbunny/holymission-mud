inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "A dark damp tunnel";
	long_desc= "This is a dark dank tunnel. There is a glimmer of light ahead.\n"+
	"Very old wooden planks and boulders hold up the ceiling and walls.\n"+
	"As you touch the walls, slime runs down your fingers. The slime has\n"+
	"dripped into a big blob in the middle of the room. You can hear\n"+
	"squeeks coming from the next room, your guess is that water rats\n"+
	"live down here.\n";
	items =
	({
	  "light","Looks like it is coming from a opening",
	  "planks","Old wooden planks, they dont look sturdy",
	  "boulders","Big boulders standing next to the walls to keep them up",
	  "walls","They have blue slime running down them",
	});
	clone_list = ({
	  1, 1, "blob", "players/tuppence/fortress/monster/blob", 0,
	});
	dest_dir=
	({
	  FROOM+"dun7","south",
	  FROOM+"tun2","north",
	});
    }
    ::reset(arg);
    replace_program("/room/room");
}
