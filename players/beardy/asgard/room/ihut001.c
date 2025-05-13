inherit "room/room";
#include "../asgard.h"

reset (int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="Murbor's hut.",
  long_desc="Murbor's hut.\n"+
 		"You are in the center of a very small looking place.\n"+
		"Several shelves are fixed to the wall and you notice\n"+
                "some strange pictures too. There is a trap door leading\n"+
		"down.\n";

  items=({
             "shelves","They are filled with books",
             "books","They look very old",
             "trapdoor","It is open",
             "pictures","Oh my god ! It looks like a formula"
         });

   smell="The air smells mystic in here";

   dest_dir=({
                ROOM + "ihut002","down",
		ROOM + "hut006","out",
            });
}
