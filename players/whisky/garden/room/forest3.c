
inherit "room/room";
#include "../garden.h"

void reset(int arg) 
{
  if (filter_live(TO) < 1)
     CM("owl");

  if (arg) return;
  set_light(0);
  short_desc = "In a dark forest";
  long_desc =
             "You are standing in the western part of the dark " +
             "forest. You see many large spruce trees surrounding " +
             "you, and a clear path leads northeast, southeast, " +
             "and east from here. The trees are dark and forboding " +
            "and animal paths can be seen heading west. " +
             "You think something flew past your head, but are not " +
             "certain. A howling noise can be heard from the east.\n";

  dest_dir = ({ ROOM+"/forest1", "southeast",
		ROOM+"/forest5", "northeast",
		ROOM+"/forest4", "east" });
  items = ({ "spruces",
             "Tall spruces with large cones hanging from the branches"});
}
