inherit "room/room";
#include "../asgard.h"

reset (int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="Murbor's hut.",
  long_desc="Murbor's hut.\n"+
		"You are near Murbor's hut. It does not seem to be\n"+
		"very big, however, you have no chance knowing if end\n"+
		"is in the cave or not. The hut itself looks very old\n"+
		"and also a bit rotten. Perhaps you can go around to\n"+
                "its back. There. is a small entrance in here.\n";


  items=({
           "mountains","They are really high",
           "hut","It looks quite old",
	   "entrance","It looks quite nice",
         });

   smell="The air smells mystic in here";

   dest_dir=({
                ROOM + "hut003","east",
		ROOM + "ihut001","enter",
            });
}
