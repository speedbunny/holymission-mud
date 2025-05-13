inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="The northeast corner of the yard.";
    long_desc=
        "You are in the northeast corner of the graveyard, it is\n"+
        "very spooky here\n";
    items=({
        "corner","The corner of the graveyard"
          });
    dest_dir=({
        "/players/jewel/quest/grave9","south",
        "/players/jewel/quest/grave11","west"
             });
}
