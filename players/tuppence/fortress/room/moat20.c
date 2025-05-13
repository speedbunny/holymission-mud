inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
if(!arg) {
set_light(0);
short_desc= "Dark moat";
long_desc= "Shadows gracefully dance upon the walls of the fortress. The shadows\n"+
	   "seems to almost grin at you as you walk by them. The water here\n"+
	   "starts to bubble up again and splash about. You wonder what could\n"+
	   "make it do that? Big bugs sit on the walls staring at you with\n"+
	   "their red and yellow eyes. You feel as if someone or something might\n"+
	   "be watching you.\n";
items =
({
"shadows","They grin at you as they dance around",
"water","It starts to bubble and splash around",
"bugs","Huge bugs sit on the walls of the fortress peering at you",
});
clone_list = ({
1, 1, "ivy", "players/tuppence/fortress/monster/ivy", 0,
2, 1, "slug", "players/tuppence/fortress/monster/slug", 0,
-2, 1, "slime", "players/tuppence/fortress/armour/slime", 0,
});
dest_dir=
({
FROOM+"moat19","north",
FROOM+"entrance","up",
});
}
::reset(arg);
replace_program("/room/room");
}
