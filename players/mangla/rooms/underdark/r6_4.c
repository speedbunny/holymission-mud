inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Dark Passage";

    long_desc="You see all around you only black, your light source\n" +
              "only extents a short distance into the dark. The shadows\n" +
              "seem to creep in on you. The walls are all made from\n" +
              "solid rock. Hope dwindles rapidly in this dismal place\n" +
              "where even the air reeks of death and decay. Too the north\n" +
              "you can hear the screeching of bats. The floor is covered\n" +
              "with a sticky substance you just know is guano.\n\n";

    set_light(-1);

    items = ({"rock","Black, hard rock. You cannot chip it, much less dig it",
              "dark","Impenetrable blackness surrounds you",
              "walls","The walls are made from hard rock",
              "wall","The walls are made from hard rock",
              "shadows","Did you see something move? Fear mounts",
              "guano","Spread over the floor, it makes a squish as you walk",
              "shit","Bat guano all over the floor",
            });

    property=({ "no_teleport" });

    smell="\nThe odor of rotten and decayed flesh prevails.\n";

    dest_dir=({UNDER + "r6_3","south",
               UNDER + "r6_5","north",
             });

    ::reset();
    replace_program("room/room");
}

