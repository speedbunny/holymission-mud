inherit "room/room";

reset(arg) {

    if(arg) return;

    set_light(1);

   short_desc = "Misticalla's test room";
    long_desc = "Misticalla's room for testing monsters.\n";

    property=({"no_teleport","no_sneak"});

}

init() {

    ::init();
}


