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
    short_desc = "On the stairs of the Cloud Tower";
    long_desc = 
"   You start to climb the stairs...\n\n"+
"                                ... UP ...\n\n"+
"                                       ... UP ...\n\n"+
"                                              ... UP ...\n\n";

    no_obvious_msg = "";

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
    });

  }

}

void init() 
{
  ::init();
  call_out("mover", 4);
}

int mover()
{
  MPL("up the stairs#/players/tamina/castle/planes/air/tower3");
  return 1;
}

