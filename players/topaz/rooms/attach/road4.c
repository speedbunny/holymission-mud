inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are on a corner of Village Road South.\n" +
              "The trees to the west are solid, while a small path leads\n" +
              "into the trees to the north.\n" +
              "There is a big building southeast of here.  The entrance is on\n" +
              "the north side of the building.\n" +
              "Village Road South goes east and south from here.\n";

    dest_dir=({ATTACH + "road5","south",
               ATTACH + "road3","east",
    });
    hidden_dir=({ATTACH + "forest1","north",
    });
    items=({"road","The road is well worn from much use",
            "building","It looks inviting." +
                      "Maybe you should check it out",
            "big building","It looks inviting." +
                           "Maybe you should check it out",
            "corner","A signpost says this is Village Road South",
            "signpost","It seems Village road goes east and south",
            "tree","There are big oaks and some other kinds of trees",
            "trees","Some large willow trees sway in the breeze",
            "path","It leads into the forest",
    });
    set_light(1);
    smell="The trees smell refreshing and clean.";
return 1;
RR;
}
