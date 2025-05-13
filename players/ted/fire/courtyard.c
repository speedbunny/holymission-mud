#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
	set_light(1);
	short_desc = "A Large Open Courtyard";
	long_desc =
	"This open courtyard is surrounded by high walls. A large\n"+
	"double door leads north, while to the south is a guard room.\n"+
	"To the east and west are two smaller doors. The ground is\n"+
	"hard packed from much use. Giant footprints can be seen in\n"+
	"the dirt. They lead in all directions.\n";
	dest_dir = ({
	  FIRE + "ante_room","north",
	  FIRE + "guard","south",
	  FIRE + "whall4","west",
	  FIRE + "ehall3","east"
	});
	replace_program("room/room");
    }
