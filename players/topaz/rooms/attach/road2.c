inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="Village Road South";
    long_desc="You are at a corner on Village Road South.\n" +
              "There is a statue in the middle of the road that seems\n" +
              "to attract all of your attention.  Trees line the road\n" +
              "to the north and there is a big building southwest of here.\n" +
              "Village Road South goes east, west and south from here.\n";

    dest_dir=({ATTACH + "road1","east",
               ATTACH + "road3","west",
                ATTACH + "road9","south",
    });
    items=({"road","The road looks well used",
            "corner","A signpost says this is Village Road South",
            "signpost","It seems Village Road South goes south, east and west",
             "building","It is a big grey building." +
                         "There are probably lots of interesting things in there",
             "big building","It is a big grey building." +
                            "There are probably lots of interesting things in there",
             "tree","There are lots of oaks, ashes and maples",
             "trees","They rise up above you, giving you a feeling of security",
             "statue","It is a well crafted statue of Topaz the Wizard",
    });
    set_light(1);
    smell="The leaves on the trees smell fresh and invigorating.";
    move_object(clone_object(OBJS + "attach/statue"),TO);
return 1;
  }
}
