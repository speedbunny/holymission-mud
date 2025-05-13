inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
if(!arg) {
set_light(1);
short_desc= "Runed chambers";
long_desc= "Runes cover the whole room from the floor to the ceiling. Different\n"+
	   "coloured globes float around you. Crystals hang from the ceiling.\n"+
	   "Big barred windows cover most of the west and east walls. The bars\n"+
	   "on the windows seem to be made out of magical fire.\n";
items=
({
"runes","Blue and red runes cover the whole room",
"globes","Globes of different colours float around the room",
"crystals","Rays of light shoot from the crystals",
"windows","They seem to have glowing red bars on them",
"bars","They seem to be made out of magical fire, i wouldnt touch them",
});
clone_list = ({
1, 2, "mage", "players/tuppence/fortress/monster/mmage", 0,
-1, 1, "headband", "players/tuppence/fortress/armour/headband", 0,
2, 2, "monk", "players/tuppence/fortress/monster/rmonk", 0,
-2, 1, "leggings", "players/tuppence/fortress/armour/leg", 0,
});
dest_dir=
({
FROOM+"top7","south",
});
}
::reset(arg);
replace_program("/room/room");
}
