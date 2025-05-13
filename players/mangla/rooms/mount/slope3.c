inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Gentle mountain slope";

    long_desc="You are at the bottom of a large mountain. The side\n" +
              "extend on up into the clouds. From this point you see\n" +
              "a gentle slope covered in grass leading into the rocky\n" +
              "terrain of the mountain proper. Off to the northwest you\n" +
              "notice something moving low to the ground.\n";

    set_light(1);

    items = ({"grass","The luscious green color that a mountain goat loves",
              "rocks","Dominate the upper part of the mountain,\n" +
                      "but there are not many here",
              "goats","They are off in the distance to the south",
              "slope","Gently leading up to the rocky terrain",
            });

    property=({  });

    smell="\nA fresh spring breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/slope4","northwest",
               ROOM + "mount/rock3","up",
               ROOM + "mount/slope2","southwest",
             });

    ::reset();
    replace_program("room/room");
}
