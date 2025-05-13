inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A crossing in the Yard.";
    long_desc=
        "You are standing on a crossing in the Yard, to the east you see\n"+
        "the ruin of a small hut.\n";
    items=({
        "crossing","A crossing in the graveyard",
        "hut","The hut of the undertaker"
          });
    dest_dir=({
        "/players/jewel/quest/grave3","south",
        "/players/jewel/quest/hut1","east",
        "/players/jewel/quest/grave9","north",
        "/players/jewel/quest/grave5","west"
             });
}
