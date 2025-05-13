inherit "room/room";
#include "../asgard.h"

reset (int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="Murbor's hut.",
  long_desc="Murbor's hut.\n"+
	"You are in Murbor's labratory. Straight before you\n"+
        "there is a little cupboard filled with potions and\n"+
        "other chemical liquids, while to the left you notice\n"+
        "a small blackboard with some lines drew on it.\n";

  items=({
        "cupboard","It is filled with potions",
        "blackboard","You see some strang writing",
         });

   smell="The air smells mystic in here";

   dest_dir=({
                ROOM + "ihut001","up",
            });

  CM("murbor");

}
