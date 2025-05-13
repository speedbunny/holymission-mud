inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Gentle mountain slope";

    long_desc="You are at the bottom of a large mountain. The side\n" +
              "extends up into the clouds. From this point you see\n" +
              "a gentle slope covered in grass leading into the rocky\n" +
              "terrain of the mountain proper. You can see mountian goats\n" +
              "grazing off to the northeast.\n";

    set_light(1);

    items = ({"grass","The luscious green color that a mountain goat loves",
              "rocks","dominate the upper part of the mountian,\n" +
                      "but there are not many here",
              "goats","They are off in the distance to the east",
              "clouds","they are way up there",
              "slope","Gently leading up to the rocky terrain",
            });

    property=({  });

    smell="\nA fresh spring breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/slope2","northeast",
               ROOM + "mount/rock1","up",
               ROOM + "mount/slope8","northwest",
             });

//  clone_list = ({ 1,15, "bat", MNST+"under/bat", 0,
//               });
    ::reset();
    replace_program("room/room");
}
