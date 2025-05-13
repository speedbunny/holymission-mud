inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Dark Passage";

    long_desc="You see in all around you only black, your light source\n" +
              "only extents a short distance into the dark. The shadows\n" +
              "seem to creep in on you. The walls are all made from\n" +
              "solid rock. Hope dwindles rapidly in this dismal place\n" +
              "where even the air reeks of death and decay. The air lulls\n" +
              "you into a feeling of peace and serinity.\n\n";

    set_light(-1);

    items = ({"rock","Black, hard rock. You cannot chip it, much less dig it",
              "dark","Impenetrable blackness surrounds you",
              "walls","The walls are made from hard rock",
              "wall","The walls are made from hard rock",
              "shadows","Did you see something move? Fear mounts"
            });

    property=({ "no_teleport" });

    smell="\nThe scents are mild, but carry a sense of foreboding.\n";

    dest_dir=({UNDER + "r5_6","east",
               UNDER + "r4_7","north",
               UNDER + "r4_5","south"
             });

    ::reset();
    replace_program("room/room");
}
