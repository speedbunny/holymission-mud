inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc="The dark path";
    long_desc="You are walking on a dark trodden path with many sharp stones\n";
    items=({
        "path","A small path with sharp stones, on each side there are some\n"+
               "dead bushes",
        "stones","Sharp black stones",
        "bushes","Some rotten bushes",
        "bush","A rotten bush"
          });
    dest_dir=({
        "/players/jewel/quest/darkl2","east",
        "/players/jewel/quest/darkl5","west"
             });
}
