#include "/players/tinman/defs.h"
inherit "room/room";

reset (arg)
{
  if (!arg)
  {
  set_light(1);
  short_desc=("A path\n");
  long_desc=("   You are traveling on a path opening into a large field.\n"+
" You can see action north of you. You can see black smoke traveling \n"+
"up toward the sky.\n");
  dest_dir=({
	"players/tinman/area/rooms/bf1", "north",
	  });
  items=({
	"smoke","Many tenticles reaching toward the sky.",
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
