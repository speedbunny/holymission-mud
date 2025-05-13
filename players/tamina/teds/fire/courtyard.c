inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "A Large Open Courtyard";
    long_desc =
	"This open courtyard is surrounded by high walls. A large\n"+
	"double door leads north, while to the south is a guard room.\n"+
	"To the east and west are two smaller doors. The ground is\n"+
	"hard packed from much use. Giant footprints can be seen in\n"+
	"the dirt. They lead in all directions.\n";

    dest_dir = ({
	TFIRE + "ante_room","north",
	TFIRE + "guard","south",
	TFIRE + "whall4","west",
	TFIRE + "ehall3","east",
    });

	::reset(arg);
	replace_program("room/room");
    }
