inherit "room/room";

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
	short_desc = "Plane of fire (s,e,w)";
	long_desc = 
"    On continuing northward, you soon notice that the trail\n"+
"    has recently improved quality, and now looks like a well-worn \n"+
"    pathway.  You also find that the disused trail you were on\n"+ 
"    starts to lead west, going off the mountain-side...\n";

	dest_dir = ({
          FIRE + "rm9","south",
          FIRE + "rm14","east",
          FIRE + "rm12","west",
        });

	smell = "The soot makes you cough when you try to smell!\n";

	items = ({
  "mountains",
" Huge erections thrust up from the boiling pits of "+
"lava and magma",
  "path",
" It is a small pathway made of a very fine sand, "+
"with steam vapour rising from your feet.  Without "+
"the protection from the ruby, you think you would "+
"not survive here for long",
  "trail",
" It is not as well-used as the path that you are on",
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
