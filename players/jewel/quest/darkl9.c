inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="On the road to the masters castle";
    long_desc=
        "The crossroads lie now for behind you, in a small distance to the \n"+
        "east you can see a little house\n";
    items=({
        "house","The house looks like a bar"
    });
    dest_dir=({
        "/players/jewel/quest/hills/hill1","north",
        "/players/jewel/quest/darkl2","west",
        "/players/jewel/quest/vampirebar","east" 
             });
}
