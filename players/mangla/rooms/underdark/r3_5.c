inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Dark Passage";

    long_desc="You see all around you only black, your light source\n" +
              "only extents a short distance into the dark. The shadows\n" +
              "seem to creep in on you. The walls are all made from\n" +
              "solid rock. Hope dwindles rapidly in this dismal place\n" +
              "where even the air reeks of death and decay. The walls\n" +
              "are wet and it feels like you are walking through the mists\n" +
              "of a water fall as you proceed.\n\n";

    set_light(-1);

    items = ({"rock","Black, hard rock. You cannot chip it, much less dig it",
              "walls","The walls are made from hard rock",
              "wall","The walls are made from hard rock",
              "dark","Impenetrable blackness surrounds you",
              "shadows","Did you see something move? Fear mounts",
              "mist","Heavy and humid",
            });

    property=({ "no_teleport" });

    smell="\nThe odor of rotten and decayed flesh prevails.\n";

    dest_dir=({UNDER + "r3_4","south",
               UNDER + "r4_5","east"
             });

    replace_program("room/room");
}
