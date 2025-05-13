inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Crater Bottom";
    long_desc =
    "You are in the bottom of a huge volcanic crater. The\n"+
    "heat coming up from cracks and fissures is almost\n"+
    "unbearable. A huge forge stands here.\n";

    dest_dir = ({
      THOT + "rim","west"
    });

    clone_list = 
    ({ 1,1, "smith of the gods", "players/tamina/teds/monsters/smith", 0,
      2,1,"forge", "obj/treasure", 
      ({ "set_name","forge",
	"set_short","Vulcans forge",
	"set_long","This is a massive block of black steel.  It is where\n"+ 
	"Vulcan makes weapons.\n",
	"set_weight",15,
	"set_value",500, }), });

    ::reset(arg);

    replace_program("room/room");
}
