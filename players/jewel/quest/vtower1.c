inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="The base level of the vampire tower";
    long_desc=
        "You are standing on the base level of the vampire kings tower.\n"+
        "some stairs lead up and down\n";
    items=({
        "stairs","Some stairs made of black stone",
        "stair","A stair made of black stone"
          });
    dest_dir=({
        "/players/jewel/quest/darkl8","east",
        "/players/jewel/quest/vtower2","up",
        "/players/jewel/quest/vtower6","down"
             });
}
