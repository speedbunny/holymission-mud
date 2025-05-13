inherit "players/tamina/castle/planes/hostiles/fire"

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset(arg)
{
  if (!arg)
    {
      timer  = 5;    	    /*  How often player is burned  */
      damage = 20;	    /*  How much damage player takes from burns  */
      survivor = "ruby";    /*  That object which saves the player from burns */
      envname  = "fire";    /*  Type of alien environment  */
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

      set_light(1);
      short_desc = "Path on top of the Mountain";
      long_desc = 
"    You continue with the path that leads to the east, staying on top\n"+
"    of the Mountain.  You can see now that this clear path does wind\n"+ 
"    its way through the clusters of huge rock formations on top of the\n"+
"    Mountain, leading to the spindly Minaret in the distance.\n";

      dest_dir = ({
      FIRE + "rm16", "north",
      FIRE + "rm13", "west",
      });

      items = ({
  "minaret",
"It is very tall, reaching up into the clouds",
  "rocks",
"They are huge rocks which you cannot climb over",
  "formations",
"Clusters of rock that have formed over the years",
      });

    }
}

light_text (str)
{
  write("\nYou find an area of concetrated heat in the room,\n"+
	"and hold the "+str+" there to light it.\n");
  say(TPN+" lights a "+str+",\n"+
      "using the heat of the room.\n");
}

init() {
  ::init();
  if (!nodanger) light_all();
}
