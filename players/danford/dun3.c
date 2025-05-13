inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "A lighted chamber";
	long_desc= "You have entered a dimly lit chamber of the dungeon. The scratch\n"+
	"marks continue till the middle of the room. As you look at a moving\n"+
	"shadow, you start to see something come out of the shadows. More\n"+
	"bones and skeletons lay on the floor around you. The low grumbling\n"+
	"has now turned into screeching and flapping of huge wings.\n";
	items=
	({
	  "marks","They seem fresh",
	  "shadow","It seems to have something moving around in it",
	  "bones","Bones wthemh flesh hanging off of it",
	  "skeletons","Skeletons of poor prisoners lay here",
	});
clone_list = ({
1, 1, "gathan", "players/tuppence/fortress/monster/gathan", 0,
-1, 1, "axe", "players/tuppence/fortress/weapon/daxe", 0,
-1, 1, "boots", "players/tuppence/fortress/armour/dboot", 0,
-1, 1, "gloves", "players/tuppence/fortress/armour/dglove", 0,
-1, 1, "helmet", "players/tuppence/fortress/armour/dhelmet", 0,
});
	dest_dir=
	({
	  FROOM+ "dun4","north",
	  FROOM+"dun2","east",
	});
    }
::reset(arg);
replace_program("/room/room");
}
