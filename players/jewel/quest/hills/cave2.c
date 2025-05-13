inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(0);
    short_desc="Inside a big cave";
    long_desc=
         "You are standing in a big dark dry cave. To the south you hear \n"+
         "rattling sounds.\n";
    items=({
        "cave","A big dry and dark cave"
          });
    dest_dir=({
        "/players/jewel/quest/hills/cave3","south",
        "/players/jewel/quest/hills/cave10","up"
             });
}
