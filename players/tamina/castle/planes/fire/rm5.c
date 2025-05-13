inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset (arg) {
  if (!arg) {

      timer  = 5;
      damage = 20;
      survivor = "ruby";
      envname  = "fire";
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

      	set_light(1);
	short_desc = "Trail leading up the Mountains (ne,w)";
	long_desc = 
"    You mount the steep climb up the moutain side, on a vague trail\n"+
"    that leads in amongst the scree and fallen rocks.  You take\n"+
"    care to nimbly dodge these potentially fatal hazards.  Ahead\n"+
"    you can see that the trail ascend further and higher into the\n"+
"    mountains.\n";

	dest_dir = ({
          FIRE + "rm8","northeast",
          FIRE + "rm4","west",
        });


	items = ({
  "scree",
"  These are loose rocks that have been eroded from the tops of the "+
"mountain, and have fallen down the trail",
  "trail",
"  The trail is nothing more than a slightly obscured pathway",
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

init() 
{
  ::init();
  if (!nodanger) light_all();
}
