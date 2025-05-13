inherit "room/room";
reset(arg)
{
    if (!present("vampirelord")) {
        move_object(clone_object("/players/jewel/quest/vampire2"), this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc = "The dark crossroad";
    long_desc =
        "You are standing on the main crossroad to the dark lands.\n" +
        "To the north you can see a dark castle in the far distance.\n" +
        "To the southwest there is a dark tower.\n";
    items = ({
        "castle", "A dark, cold looking castle",
        "tower", "A tower looking like a sharp, thin, black blade"
            });
    dest_dir = ({
        "/players/jewel/quest/darkl3", "north",
        "/players/jewel/quest/darkl9", "east",
        "/players/jewel/quest/darkl1", "south",
        "/players/jewel/quest/darkl4", "west"
               });
}

init()
{
    ::init();
    add_action("west", "west", 1);
}

west() {
    if (present("vampirelord")) {
        write("The dark figure bars your way.\n");
    } else {
        this_player()->move_player("west#players/jewel/quest/darkl4");
    }
    return 1;
}
