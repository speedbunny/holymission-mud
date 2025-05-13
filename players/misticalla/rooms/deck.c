inherit "room/room";

reset(arg) {

    if(arg) return;

    set_light(1);

   short_desc = "Private deck";
   long_desc = "This is a private deck. This is where Misticalla goes "+
               "when she is having problems or feeling down. You "+
               "really shouldn't be here unless you were invited. "+
               "The view of the mountains and lake surrounding her "+
               "house is spectacular. You feel at peace here.\n";

    property=({"no_teleport","no_sneak"});

}

init() {

    ::init();
}


