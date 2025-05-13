inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A warm campfire";
    long_desc =
         "You have come to the main campfire of the tinker camp.  There is a fire here "+
         "with a kettle sitting over it.  Many tinkers, that are around the fire, "+
         "are dancing and singing.  This is a joyful spot and everyone appears to "+
         "be happy.  The camp is filled with the feeling of love.\n";
    dest_dir=({
      TINK+"room/path8", "east",
    });
    items=({
      "fire", "A crackling canmpfire with a kettle sitting over it",
      "kettle", "A dark iron kettle used for cooking",
      "tinkers", "Brighty dressed humans who love to sing and dance",
    });

    clone_list=({
           1, 1, "shuvani", TINK+"npc/shuvani", 0,
           1, 1, "man", TINK+"npc/tman", 0,
           1, 1, "woman", TINK+"npc/twoman", 0,
           1, 1, "girl", TINK+"npc/tgirl", 0,
           1, 1, "boy", TINK+"npc/tboy", 0,
          -1, 1, "kettle", TINK+"obj/tkettle", 0,
     });
     ::reset();
     replace_program("room/room");
}
