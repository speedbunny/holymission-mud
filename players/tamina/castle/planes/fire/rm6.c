inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset(arg) {
  if (!arg) {

      timer  = 5;    	    /*  How often player is burned  */
      damage = 20;	    /*  How much damage player takes from burns  */
      survivor = "ruby";    /*  That object which saves the player from burns */
      envname  = "fire";    /*  Type of alien environment  */
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

      	set_light(1);
	short_desc = "Continuing path along the Chasm (nw,s)";
	long_desc = 
"    You venture forth north, following the clear path as it weaves\n"+
"    amongst the large boulders, seemingly strewn in random places.\n"+
"    Ahead of you, there can be see the lip of the plateau you are on\n"+
"    where it falls into a great, awning chasm, which runs far into the\n"+
"    wavering distance.  You can also see the mountain rise high in the\n"+
"    east.\n";

	dest_dir = ({
          FIRE + "rm11","northwest",
          FIRE + "rm4","south",
        });

	items = ({
  "mountain",
"  A large pinnacle of red rock",
  "chasm",
"  A great rift in the landscape the size of a canyon",
  "boulders",
"Enormous rocks that have fallen, or rolled from somewhere",
  "plateau",
"The flat piece of rock on which you stand",
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

