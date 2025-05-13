#include "/players/ted/defs.h"

inherit "room/room";
reset(arg) {
    set_light(1);
    short_desc = "Tower Top";
    long_desc =
    "You are on top of the east tower. Just to the west you see\n"+
    "the other tower. They both flank the gates, alowing archers\n"+
    "to fire their bows at anyone attacking the gate.\n";
    dest_dir = ({
      FIRE + "etower_bot","down",
    });
    items = ({
      "tower","The tower to the west looks exactly like this tower",
      "gates","the gates appear to be open and unguarded"
    });
    clone_list = ({
      1,1,"archer","/players/ted/monsters/fire_giant_archer", ({
	"set_wc",25 }),
      -1,1,"arrow","obj/treasure", ({
	"set_name","arrow","set_short","A Gold Plated Arrow",
	"set_long",
	"This small representation of the golden arrow is given as "+
	"a prize to\nall of the kings "+
	"archers who excel at archery.\n",
	"set_weight",1,"set_value",700 }),
    });
    ::reset();
    replace_program("room/room");
}
