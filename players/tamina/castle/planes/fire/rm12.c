inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset(arg)
{
  if (!arg)
    {
      timer  = 4;    	    /*  How often player is burned  */
      damage = 25;	    /*  How much damage player takes from burns  */
      survivor = "ruby";    /*  That object which saves the player from burns */
      envname  = "fire";    /*  Type of alien environment  */
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

     	set_light(1);
	short_desc = "Top of a Ledge leading down the Mountain (e,down)";
	long_desc = 
"    You continue along with the Old Trail.\n"+
"    You can see that at the edge of the Mountain, there is a \n"+
"    small, thin ledge leading down the face of the near-vertical\n"+
"    cliff.  The view from this point is breathtaking to say the\n"+
"    least.  You can see for miles...so much so that your head \n"+
"    starts to spin...\n";

	dest_dir = ({
          FIRE + "rm13","east",
          FIRE + "rm7","down",
        });
	
	smell = "The soot makes you cough when you try to smell!\n";

	items = ({
  "mountain",
" You have just climbed up the rough Mountain",
  "path",
" It is a small pathway made of a very fine sand, "+
"with steam vapour rising from your feet.  Without "+
"the protection from the ruby, you think you would "+
"not survive here for long",
  "trail",
" It is not as well-used as the path that you are on",
  "ledge",
" You think that a very large person might have troubles "+
"going down that..",
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
