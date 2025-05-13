inherit "room/room";

#include "/players/mangla/defs.h"

int _search(string str) {

    object ob;

    if(str == "moss" || str == "the moss") {
        write("You rustle the moss and a small stone comes rolling out.\n");
        ob = clone_object("/players/mangla/objects/q1.c");
        MOVE(ob,ENV(TO));
        say("A stone comes rolling out.\n");
    }
    else
        return 0;
    return 1;
}


reset(arg) {
    if(arg) return;

    short_desc="Dark Passage";

    long_desc="You see all around you only black, your light source\n" +
              "extents only a short distance into the dark. The shadows\n" +
              "seem to creep in on you. The walls are all made from\n" +
              "solid rock. Hope dwindles rapidly in this dismal place\n" +
              "where even the air reeks of death and decay. The gurgling\n" +
              "of a stream can be heard from the north. The hard stone\n" +
              "floor gives way to some moss here.\n\n";

    set_light(-1);

    items = ({"rock","Black, hard rock. You cannot chip it, much less dig it",
              "walls","The walls are made from hard rock",
              "wall","The walls are made from hard rock",
              "dark","Impenetrable blackness surrounds you",
              "shadows","Did you see something move? Fear mounts"
              "moss","The moss is soft and spongy. There is a little\n" +
                     "lump in the moss over to the side of the passage",
              "lump","It just does not appear to be natural",
            });

    property=({ "no_teleport" });

    smell="\nThe odor of rotten and decayed flesh prevails.\n";

    dest_dir=({UNDER + "r1_4","south",
               UNDER + "r1_6","north"
             });

    ::reset();
}

void init() {

    ::init();
    add_action("_search","search");
    add_action("_search","dig");
}

