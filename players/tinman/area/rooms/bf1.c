#include "/players/tinman/defs.h"
inherit "room/room";

reset (arg)
{
  if (!arg)
  {
  set_light(1);
  short_desc=("Southern Battlefield\n");
  long_desc=("As you go north, you see chaos and destruction.  There is\n"+
             "many dead bodies all over the place.  You now know that you\n"+
	    "have stumble upon a war.  As you tried to recognize this\n"+
	    "place you see that it is the Plains of Tian-chui.\n");
  dest_dir=({
	"players/tinman/area/rooms/bf2", "east",
	"players/tinman/area/rooms/bf3", "west",
	"players/tinman/area/rooms/entry", "south",
	"players/tinman/area/rooms/bf4", "northeast",
	"players/tinman/area/rooms/bf6", "northwest",
	"players/tinman/area/rooms/bf5", "north",
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
