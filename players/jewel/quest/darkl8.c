inherit "room/room";

reset(arg) {
    int i;
    if (!present("vampire guard")) {
        for (i=0;i<3;i++)
            move_object(clone_object("/players/jewel/quest/vampire5"),
                        this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc="In front of the vampire tower";
    long_desc=
        "You are standing in front of a huge black tower, the owner will not\n"+
        "be very nice to visitors. Some guards charge.\n";
    items=({
        "tower","The tower of the Vampire King"
          });
    dest_dir=({
        "/players/jewel/quest/darkl7","north"
             });
}

init() {
    ::init();
    add_action("enter","enter");
}

enter(str) {
    notify_fail("Enter what ?\n");
    if(str!="tower") return;
 
    if(!present("vampire guard")) {
        this_player()->move_player("enter#players/jewel/quest/vtower1");
    } else {
        write("The Guard blocks your way.\n");
    }
    return 1;
}

