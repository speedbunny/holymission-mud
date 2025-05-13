inherit "room/room";

reset(arg) {
    int i;

    if (!present("skeleton guard")) {
        for (i=0;i<5;i++)
            move_object(clone_object("/players/jewel/quest/skelleton"),
                        this_object());
    }
    if (!present("zombie")) {
        for (i=0;i<5;i++)
            move_object(clone_object("/players/jewel/quest/zombie"),this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc="Many undead in front of a little church";
    long_desc=
        "You see many skeletons and zombies in front of a little church\n";
    items=({
        "church","The church of the graveyard, many people got their last \n"+
        "blessing inside"
        });
    dest_dir=({
        "/players/jewel/quest/grave8","south",
        "/players/jewel/quest/grave12","east",
        "/players/jewel/quest/church1","north",
        "/players/jewel/quest/grave10","west"
             });
}
