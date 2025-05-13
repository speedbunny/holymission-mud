inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="Still on the dark path";
    long_desc=
        "You are still walking on the dark path. To the southwest, now in a\n"+
        "very short distance you can see the vampire tower.\n";
    items=({
        "path","Still the dark path",
        "tower","The tower of the vampires-Be VERY careful !!!"
          });
    dest_dir=({
        "/players/jewel/quest/darkl6","east",
        "/players/jewel/quest/darkl8","south"
             });
}
