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
    short_desc = "At the gates to a Cloud Tower";
    long_desc = 
"   You stand at the entrance to what appears to be a tower made\n"+
"   of clouds.  The open entrance seems to beckon you forward...\n";

    dest_dir = ({
      AIR + "rm6", "east",
    });
  }
}

init()
{
  ::init();
  AA("_enter", "enter");
  AA("_enter", "forward");
}

int _enter(string str)
{
  if (!str || str == "tower" || str == "structure")
  {
    write("You enter the Cloud Tower.\n");
    say(TPN+" enters the Cloud Tower.\n");

    MPL("into the Cloud Tower#/players/tamina/castle/planes/air/tower");
    return 1;
  }
}

