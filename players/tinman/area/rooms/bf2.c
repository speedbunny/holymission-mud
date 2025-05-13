#include "/players/tinman/defs.h"
inherit "room/room";

reset (arg)
{
  if (!arg)
  {
  set_light(1);
  short_desc=("Southern Battlefield\n");
  long_desc=("	There is still fighting in this area of the battlefield.\n"+
"Destruction and chao reign here. Bodies of horse and human spreaded all\n"+
" over this place. Get out of here before you get involve!!\n");
  dest_dir=({
	"players/tinman/area/rooms/bf19", "east",
	"players/tinman/area/rooms/bf1", "west",
	"players/tinman/area/rooms/bf18", "northeast",
	"players/tinman/area/rooms/bf5", "northwest",
	  });
  items=({
	"wagons","Many burning broken wagons bearing Liu Bei's blue flag.",
	"bodies","Many corpse burned and cut into pieces.",
	});
  property = ({
	    });
  smell = "You smell wood burning and the bitter sweet of burning bodies.\n";
  }
}
init()
{
  ::init();
}
