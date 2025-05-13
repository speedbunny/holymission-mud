inherit "room/room";

#include "/players/tamina/defs.h"

object salamander;

void reset(int arg) 
{
    ::reset(arg);
    if (arg) return 0;
    set_light(1);
    short_desc = "Burning Desert";
    long_desc =
	"There is nothing but sand dunes baking in the sun\n"+
	"for as far as the eye can see.\n";

    dest_dir = ({
	  THOT + "fire","north",
	});

    salamander = clone_object("obj/monster");

    salamander->set_name("fire salamander");
    salamander->set_race("salamander");
    salamander->set_long("A Firey red Salamander.\n");
    salamander->set_gender(1);
    salamander->set_level(13);
    salamander->set_wc(30);
    salamander->set_ac(3);
    salamander->set_aggressive(1);
    salamander->set_whimpy(25);

    "/players/tamina/teds/random_magic"->make_item(salamander, 13);
    move_object(salamander, this_object());
}

