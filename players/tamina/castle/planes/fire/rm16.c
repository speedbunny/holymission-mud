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
"    You walk along the path which is drawing you inexorably to the \n"+
"    eerie Minaret.  As the path starts to wind out of the rocks, you\n"+ 
"    can see that the Minaret is not actually on the top of the \n"+
"    Mountain.  But the path will lead you to it...\n";

      dest_dir = ({
      FIRE + "rm17", "northwest",
      FIRE + "rm14", "south",
      });

      items = ({
  "minaret",
"It is very tall, reaching up into the clouds.\n"+
"You can now see that the Minaret is suspended in mid-air, hanging in "+
"almost nothingness.  It has a slender bridge leading from the edge of "+ 
"the mountain over the heights of the chasm, to the base of the tower",
  "rocks",
"They are huge rocks which you cannot climb over, which is making the "+
"path wind, and twist and bend",
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
