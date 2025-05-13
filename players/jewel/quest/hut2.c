inherit "room/room";

reset(arg) {
    object sp;
    if (!present("spectre")) {
        move_object(sp=clone_object("/players/jewel/quest/spectre"),this_object());
        move_object(clone_object("/players/jewel/quest/shovel"),sp); 
     }
    if (arg) return;
    set_light(1);
    short_desc="The bedroom.";
    long_desc=
        "You are in the bedroom of the undertaker, he rises angry and\n"+
        "attacks you\n";
    items=({
        "bed","An old rotten matrace"
          });
    dest_dir=({
        "/players/jewel/quest/hut1","south"
             });
}
