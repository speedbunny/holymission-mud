inherit "/room/room";

#include "/players/tamina/defs.h"

object guard;

reset(arg) 
{
  if (!arg) 
  {
    timer  = 4;
    damage = 25;
    survivor = "necklace";
    envname  = "air";
    saymsg   = "seems to be unable to breathe.";
    wrtmsg   = "There is not enough oxygen to breathe!";
    property = ({"in_air", "no_teleport" });

    set_light(1);
    short_desc = "On the Plane of Air";
    long_desc = 
"   You seem to have come to a stable junction in this open area.\n"+
"   To the west you can see where you just entered the plane.\n"+
"   Farther to the east you can now see what appears to be a tall \n"+
"   structure made entirely from clouds.  To your north and south,\n"+
"   however, seem to be an extension of what you went through before...\n";

    dest_dir = ({
     AIR + "rm3", "north",
     AIR + "rm2", "south",
     AIR + "rm6", "east",
     AIR + "rm1", "west",
    });

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
    });

    if (!guard)
    {
      guard = CLO(AIR + "guard");
      MO(guard, TO);
    }
  }
}
