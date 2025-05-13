inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Gentle mountain slope";

    long_desc="You are at the bottom of a large mountain. The side\n" +
              "extend on up into the clouds. From this point you see\n" +
              "a gentle slope covered in grass leading into the rocky\n" +
              "terrain of the mountain proper. As you moved into this\n" +
              "area you notice the grass is taller and there is a lack\n" +
              "of smaller land dwelling rodents. As you look up you can\n" +
              "why. There is a rather large snake prowling the grass.\n";

    set_light(1);

    items = ({"grass","Tall and uninhabited except for that large snake",
              "rocks","dominate the upper part of the mountian,\n" +
                      "but there are not many here",
              "clouds","they are way up there",
              "slope","Gently leading up to the rocky terrain",
            });

    property=({  });

    smell="\nA fresh spring breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/slope5","west",
               ROOM + "mount/rock4","up",
               ROOM + "mount/slope3","south",
               "/players/kryll/rooms/hills/foothills49","northeast",
             });

    clone_list = ({ 1, 1, "snake", MNST+"snake", 0,
                 });
    ::reset();
    replace_program("room/room");
}
