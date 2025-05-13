inherit "room/room";
#include "../asgard.h"

reset (int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="Murbor's hut.",
  long_desc="Murbor's hut.\n"+
            "You are near Murbor's hut. You are at\n"+
            "the beginning of the cave and the hut\n"+
            "ends here. As you hear the several noises\n"+
            "and screams that come from inside the cave\n"+
	    "and you feel wary about entering it.\n";

  items=({
           "mountains","They are really high",
           "hut","It looks quite old",
         });

   smell="The air smells mystic in here";

   dest_dir=({
                ROOM + "hut004","east",
            });
}
