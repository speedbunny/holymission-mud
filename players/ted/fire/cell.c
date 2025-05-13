#include "/players/ted/defs.h"

inherit "room/room";
object prisoner, weapon, key_ob;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_light(0);
	short_desc = "Dark Cell";
	long_desc =
	"The floor of this cell is covered with straw dark with mildew.\n"+
	"Rats scatter and scurry out of the range of your light. A\n"+
	"small cot sits in one corner of the room.\n";
	dest_dir = ({
	  FIRE + "dungeon","east"
	});
	items = ({
	  "cot","A hard plank of wood covered with a wet blanket"
	});
    }
    if(!present("prisoner")) {
	prisoner = clone_object("players/ted/monsters/frost_giant_prisoner");
	key_ob = clone_object("players/ted/items/frost_key");
	MOVE(prisoner, TO);
    }
}


id(str) {
    if(::id(str)) return 1;
    return(str == "cot" || str == "cots" );
}

init() {
    ::init();
    add_action("give_key","open");
}

give_key(str) {
    if(!str || str!="shackles")
	return NF("Open what?\n");
    write("Frost Giant says: Thank you!\n");
    write("Frost Giant gives you his key.\n");
    write("Frost Giant says: Take this key to the Frost Giant King....\n");
    say("Frost Giant gives away his key.\n");
    if(transfer(key_ob, TP)) {
	write("You are carrying too much.\n");
	move_object(key_ob,TO);
    }
    write("Frost Giant leaves.\n");
    say("Frost Giant leaves.\n");
    destruct(prisoner);
    return 1;
}
