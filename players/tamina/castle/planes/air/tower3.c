inherit "/room/room";

#include "/players/tamina/defs.h"

object monster;

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
    short_desc = "On the tope floor of the Cloud Tower";
    long_desc = 
"   You stand at the top of an oddly constructed tower, made entirely\n"+
"   from cloud formations.  The room is totally bare, with no remarkable\n"+
"   features, apart from gaps in the walls, looking out on the base of \n"+
"   clouds surrounding the weird plane.\n";

    dest_dir = ({
     AIR + "tower2a", "down",
    });

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
    });

    monster = present("lord");
    if (!monster)
    {
      monster = clone_object(AIR + "monster");
      MO(monster, TO);
    }
  }

}
