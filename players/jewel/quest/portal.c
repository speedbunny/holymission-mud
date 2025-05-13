inherit "room/room";

reset(arg) {
    if (!present("skeleton guard")) {
        move_object(clone_object("/players/jewel/quest/skelleton"),this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc="The Portal to the dark Domain";
    long_desc=
        "You see a huge black Portal made of Obsidian\n";
    items=({
        "portal","The Portal is made of black Obsidian, on the top there"+
                 " is a \nhead of a Vampire",
        "head","The head of a Vampire",
        "vampire","The head of a Vampire"
          });
    dest_dir=({
        "/players/angmar/downstairs","up"
             });
}

init() {
    ::init();
    add_action("enter","enter");
}

enter(str) {
    notify_fail("Enter what ?\n");
    if(str!="portal") return;
 
    if(!present("skeleton guard")) {
        this_player()->move_player("through portal#players/jewel/quest/tunnel1");
    } else {
        write("The Guard blocks your way.\n");
    }
    return 1;
}

