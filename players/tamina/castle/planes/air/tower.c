inherit "/room/room";

#include "/players/tamina/defs.h"

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
    short_desc = "In the Cloud Tower";
    long_desc = 
"   You stand at the base of a tall, thin tower made from puffy white\n"+
"   clouds.  You see a set of stairs protruding from the walls leading\n"+
"   up into the heights of the tower.  Or there is the exit behind you.\n";

    dest_dir = ({
     AIR + "tower2", "up",
     AIR + "rm7", "out",
    });

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
  "stairs",
"They lead upwards to where you cannot see..",
    });

  }

}

