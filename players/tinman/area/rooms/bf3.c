#include "/players/tinman/defs.h"
inherit "room/room";

reset (arg)
{
  if (!arg)
  {
  set_light(1);
  short_desc=("Southern battlefield\n");
  long_desc=("   Heavy tolls had been taken by both side of the fighting.\n"+
"The fire of burning wagons with the blue flag light the area even in th\n"+
"darkness of the night. The fire disturt the faces of the fighters here.\n");
  dest_dir=({
	"players/tinman/area/rooms/bf1", "east",
	"players/tinman/area/rooms/bf6", "north",
	"players/tinman/area/rooms/bf5", "northeast",
	"players/tinman/area/rooms/bf7", "northwest",
	  });
  items=({
	"flag","The blue flag of Liu Bei's army burns here.",
	"bodies","More deaths resulting from the war.",
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
