inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Rocky terrain";

    long_desc="This rocky and barren terrain is a testament to the\n" +
              "powers of nature. Without magic, the air becomes thin\n" +
              "and plants struggle to grow. As you look around you feel\n" +
              "depressed by the grey surroundings. The only life you see\n" +
              "consists of the occasional mouse. The area does appear a bit\n" +
              "blackened in places like a fire has swept through to clear\n" +
              "away all excess life and leave a clear space. Up the mountian\n" +
              "you notice a dark opening. The mountain slopes gently away\n" +
              "below you.\n";

    set_light(1);

    items = ({"rocks","They dominate the upper part of the mountain.\n" +
                      "You had better watch your step",
              "clouds","Not too far above you but still a good ways up",
              "terrain","All coverd in rocks. Not many plants can grow here",
            });

    property=({  });

    smell="\nA fresh breeze assails your nose.\n";

    dest_dir=({ROOM + "mount/rock3","north",
               ROOM + "mount/rock12","up",
               ROOM + "mount/rock1","west",
               ROOM + "mount/slope2","down",
             });

//    clone_list = ({ 1, 5, "mouse", MNST + "mouse", 0,
//                 });

    ::reset();
    replace_program("room/room");
}
