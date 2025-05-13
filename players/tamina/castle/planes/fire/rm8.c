inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"

reset(arg)
{
  if (!arg)
    {
        timer  = 5;
        damage = 20;
        survivor = "ruby";
        envname  = "fire";
        saymsg   = "is singed by the heat.";
        wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
        property = ({ "has_fire", "no_teleport" });

      	set_light(1);
	short_desc = "Atop the Mountainous trail (sw,e)";
	long_desc = 
"    You continue up the slope, which has now begun to steepen.\n"+
"    Off the edge of the mountain trail, you can see a ledge run\n"+
"    along the side of the moutain itself.  And below that is an\n"+
"    enormous, gaping chasm, stretching for what seems like miles\n"+
"    downward.  Ahead of you, the trail turns to the east as it\n"+
"    reaches the summit of the mountain\n";

	dest_dir = ({
          FIRE + "rm5","southwest",
          FIRE + "rm9","east",
        });

	items = ({
  "ledge",
"  A small path running along the side of the mountain",
  "chasm",
"  A huge canyon that runs for miles into the northern distance",
  "summit",
"  Not far up ahead of you now, you can see the tip of the mountain",
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
