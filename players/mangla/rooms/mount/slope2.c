inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Gentle mountain slope";

    long_desc="You are at the bottom of a large mountain. The side\n" +
              "extends up into the clouds. From this point you see\n" +
              "a gentle slope covered in grass leading into the rocky\n" +
              "terrain of the mountain proper. There are mountian goats\n" +
              "grazing around you. They do not look like they wish to be\n" +
              "disturbed.\n";

    set_light(1);

    items = ({"grass","The luscious green color that a mountain goat loves",
              "rocks","Dominate the upper part of the mountain,\n" +
                      "but there are not many here",
              "clouds","They are way up there",
              "slope","Gently leading up to the rocky terrain",
            });

    property=({  });

    smell="\nA fresh spring breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/slope3","north",
               ROOM + "mount/rock2","up",
               ROOM + "mount/slope1","west",
             });

    clone_list = ({ 1,5, "goat", MNST+"goat", 0,
                 });

    ::reset();
    replace_program("room/room");
}
