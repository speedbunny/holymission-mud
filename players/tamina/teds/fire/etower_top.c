inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tower Top";
    long_desc =
    "You are on top of the east tower. Just to the west you see\n"+
    "the other tower. They both flank the gates, alowing archers\n"+
    "to fire their bows at anyone attacking the gate.\n";

    dest_dir = ({
      TFIRE + "etower_bot","down",
    });

    items = ({
      "tower","The tower to the west looks exactly like this tower",
      "gates","the gates appear to be open and unguarded"
    });

    clone_list = 
  ({ 1, 1, "archer", "/players/ted/monsters/fire_giant_archer", 
    ({"set_name", "fire giant archer",
      "set_alias", "archer",
      "set_short", "A Fire Giant Archer",
      "set_long", 
        "This is the King's Archer.\nHe is dressed in brilliant red attire.\n",
      "set_race", "giant",
      "set_gender", 1,
      "set_level", 15,
      "set_ac", 6,
      "set_wc", 25, 
      "set_whimpy", 25,
      "set_al", -550,
      "set_aggressive", 1,
      "set_spell_mess1", "The Archer fires a flurry of arrows.\n",
      "set_spell_mess2", "The Archer makes a pincushion of you with arrows.\n",
      "set_spell_dam", 40,
      "set_chance", 40 }),
    -1, 1, "arrow", "obj/treasure", 
      ({"set_name", "arrow",
        "set_short", "A Gold Plated Arrow",
	"set_long",
	  "This small representation of the golden arrow is given as "+
	  "a prize to\nall of the kings archers who excel at archery.\n",
	"set_weight", 1,
        "set_value", 700 }),
    });

    ::reset(arg);
    replace_program("room/room");
}
