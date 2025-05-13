#include "/players/ambrose/defs.h"

inherit "room/room";


void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
      short_desc="Shrine Gate";
      long_desc="You stand before a large gate with is inscribed with a \n"+
                "with a large unicorn.  The gate is in a long, tall, marble\n"+
                "which stretches both to the east and the west.  There is a\n"+
                "set in the wall next to the gate.\n";
      property=({"no_teleport"});
      dest_dir=({
                "/players/ambrose/avalon/forest/forest35","north",
                "/players/ambrose/avalon/forest/shrine2","west",
                "/players/ambrose/avalon/forest/shrine3","east",
      });
      items=({
      "wall","This high wall towers over you, it is unscalable.",
      "gate","Only the most strong could batter down this gate.",
      "sign","There is a sign here, maybe you should read it.",
           });
       smell="You can smell the musky smell of a animal near here.";
     }
