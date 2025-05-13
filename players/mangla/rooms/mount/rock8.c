inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Rocky terrain";

    long_desc="This rocky and barren terrain is a testament to the\n" +
              "powers of nature. Without magic, the air becomes thin\n" +
              "and plants struggle to grow. As you look around you feel\n" +
              "depressed by the grey surroundings. The only life you see\n" +
              "consists of the occasional mouse. The mountain slopes\n" +
              "gently away below you.\n";

    set_light(1);

    items = ({"rocks","They dominate the upper part of the mountain.\n" +
                      "You had better watch your step",
              "clouds","Not too far above you but still a good ways up",
              "terrain","All coverd in rocks. Not many plants can grow here",
            });

    property=({  });

    smell="\nA fresh breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/rock1","east",
               ROOM + "mount/rock18","up",
               ROOM + "mount/rock7","north",
               ROOM + "mount/slope8","down",
             });

    clone_list = ({ 1, 5, "mouse", MNST + "mouse", 0,
                 });

    ::reset();
    replace_program("room/room");
}
