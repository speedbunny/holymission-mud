inherit "room/room";

reset(arg) {
    if (!present("balor")) {
        move_object(clone_object("/players/jewel/quest/hills/balor"),
                    this_object());
    }
    if (arg) return;
    set_light(0);
    short_desc="A dead end of the cave";
    long_desc=
        "This is a dead end of the cave, a huge demon is lurking here.\n";
    items=({ 
        "cave","A dry and dark cave"
          });
    dest_dir=({
        "/players/jewel/quest/hills/cave10","east"
             });
}


 

