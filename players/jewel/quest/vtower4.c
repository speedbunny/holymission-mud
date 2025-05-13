inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="The third level of the tower";
    long_desc=
        "You are standing on the third level of the vampire kings tower.\n"+
        "You hear a whispering sound from above\n";
    items=({
        "room","A dim light room"
          });
    dest_dir=({
        "/players/jewel/quest/vtower5","up",
        "/players/jewel/quest/vtower3","down"
             });
}
