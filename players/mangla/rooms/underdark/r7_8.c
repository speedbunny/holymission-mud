inherit "room/room";

#include "/players/mangla/defs.h"

static int mon;
static object cil;


int make_mon() {

    mon = 1;
    cil = clone_object(MNST + "under/cil");
    transfer(cil,TO);
    call_out("remove_mon",30,0);
    return 1;
}


int remove_mon() {

    object *ob;
    int i,j;

    ob = all_inventory(ENV(TO));
    j = 0;

    for (i=0; i<sizeof(ob); i++) {
        if (living(ob[i]) && ob[i] != TO && !ob[i]->query_npc()) {
            i = sizeof(ob);
            j = 1;
        }
    }
    if (!j) call_out("remove_mon",20,0);
    else {
        mon = 0;
        if(objectp(cil))
            destruct(cil);
    }
    return 1;
}

reset(arg) {
    if(!arg) {

    ::reset();


    short_desc="Dark Passage";

    long_desc="You see all around you only black, your light source\n" +
              "only extends a short distance into the dark. The shadows\n" +
              "seem to creep in on you. The walls are all made from\n" +
              "solid rock. Hope dwindles rapidly in this dismal place\n" +
              "where even the air reeks of death and decay. You sense the\n" +
              "presence of the fearsome cildabrin, but you cannot see\n" +
              "him at all times since it has the ability to hide in the\n" +
              "shadows. You notice, to your dismay, that the shadows do\n" +
              "appear to be deeper here than elsewhere.\n\n";

    set_light(-1);

    items = ({"rock","Black, hard rock. You cannot chip it, much less dig it",
              "walls","The walls are made from hard rock",
              "wall","The walls are made from hard rock",
              "dark","Impenetrable blackness surrounds you",
              "shadows","Did you see something move? Fear mounts"
            });

    property=({ "no_teleport" });

    smell="\nThe odor of rotten and decayed flesh prevails.\n";

    dest_dir=({UNDER + "r8_8","east"
             });

    clone_list = ({ -1, 2, "coin", "/obj/money", 0,
                 });
    }
}

init() {

    ::init();

    if (!cil && !mon)
        call_out("make_mon",5,0);
}

