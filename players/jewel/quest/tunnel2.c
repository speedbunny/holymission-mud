// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "room/room";

reset(arg) {
    if (!present("ghoul")) {
        move_object(clone_object("/players/jewel/quest/monster/ghoul"),this_object());
    }
    if (arg) return;
    set_light(0);
    short_desc="A dark tunnel";
    long_desc=
        "A dark tunnel. In the distance you see dim daylight.\n";
    items=({
        "tunnel","A dark stone tunnel",
        "daylight","Dim light coming from the end of the tunnel",
        "light","Dim light coming from the end of the tunnel"
          });
    dest_dir=({
        "/players/jewel/quest/tunnel1","west",
        "/players/jewel/quest/grave1","east"
             });
}

init() {
    ::init();
    add_action("north","east",1);
}

north() {
    if(present("ghoul")) {
         write("The ghoul bars your way.\n");
    } else {
        this_player()->move_player("east#players/jewel/quest/grave1");
    }
    return 1;
}


