inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="The dark path";
    long_desc=
        "You are walking on a dark path with sharp stones, some bones lie\n"+
        "beside the path. In a distance you can see a dark tower to the\n"+
        "southwest.\n";
    items=({
        "path","A small path with sharp stones, on each side there are some\n"+
        "rotten bones",
        "stones","Sharp black stones",
        "bones","Bones of poor adventurers, who died here",
        "tower","A huge tower looking like a vampire tooth"
          });
    dest_dir=({
        "/players/jewel/quest/darkl5","north",
        "/players/jewel/quest/darkl7","west"
             });
}
