inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="The cellar of the vampire tower";
    long_desc=
        "You are in the cellar of the vampire tower, some rotten bones\n"+
        "lie here. From the north you can hear the sound of a party.\n"+
        "A sign reads: Only vampires are allowed tonight !!\n";
    items=({
        "bones","Some rotten human bones",
        "bone","A rotten human bone"
          });
    dest_dir=({
        "/players/jewel/quest/vtower1","up",
        "/players/jewel/quest/vtower7","north"
             });
}
