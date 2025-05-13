
inherit "room/room";
#include "../garden.h"

void reset(int arg) 
{
  if (filter_live(TO) < 1)
     CM("owl");

  if (arg) return;
  set_light(0);
  short_desc = "In a dark forest";
  long_desc = BS(
    "You are standing in the western part of the dark forest. " +
    "You see many large spruce trees surrounding you, and a "+
    "path leads to all directions. You think something flew past "+
    "you, but you are uncertain. There is a howling noise coming "+
    "from the east.");

  dest_dir = ({ ROOM+"/forest1", "southeast",
		ROOM+"/forest5", "northeast",
		ROOM+"/forest4", "east" });
  items = ({ "spruces",
             "Tall spruces with large cones hanging from the branches"});
}
