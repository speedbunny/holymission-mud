inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
if(!arg) {
set_light(0);
short_desc= "Dark moat";
long_desc = "Shadows dance gracefully upon the walls of the fortress. The shadows\n"+
	   "seem to almost grin at you as you walk by them. The water here\n"+
	   "starts to bubble up again and splash about. You wonder what could\n"+
	   "make it do that? Big bugs sit on the walls, staring at you with\n"+
	   "their red and yellow eyes. You feel as if someone or something might\n"+
	   "be watching you.\n";
items =
({
"shadows","They grin at you as they dance around",
"water","It starts to bubble and splash around",
"bugs","Huge bugs sit on the walls of the fortress peering at you",
});
clone_list = ({
1, 3, "pirhana", "players/tuppence/fortress/monster/pfish", 0,
2, 2, "goblin", "players/tuppence/fortress/monster/goblin", 0,
-2, 1, "sword", "players/tuppence/fortress/weapon/gsword", 0,
-2, 1, "helmet", "players/tuppence/fortress/armour/ghelmet", 0,
});
dest_dir=
({
FROOM+"moat18","north",
FROOM+"moat20","south",
});
}
::reset(arg);
replace_program("/room/room");
}
