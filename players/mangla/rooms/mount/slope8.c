inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Gentle mountain slope";

    long_desc="You are at the bottom of a large mountain. The side\n" +
              "extend on up into the clouds. From this point you see\n" +
              "a gentle slope covered in grass leading into the rocky\n" +
              "terrain of the mountain proper.\n";

    set_light(1);

    items = ({"grass","The luscious green color that a mountain goat loves",
              "rocks","dominate the upper part of the mountian,\n" +
                      "but there are not many here",
              "clouds","Way up there in the air",
              "slope","Gently leading up to the rocky terrain",
            });

    property=({  });

    smell="\nA fresh spring breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/slope1","east",
               ROOM + "mount/rock8","up",
               ROOM + "mount/slope7","north",
             });

    ::reset();
    replace_program("room/room");
}
