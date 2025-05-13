// Code originally by jewel/quest of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "The entrance to the graveyard";
    long_desc="You are standing in the dim light of a small spooky graveyard.\n";
    items=({
        "graveyard","A small spooky graveyard",
        "tombstones","What do you want on YOUR tombstone? pepperoni?"
          });
    dest_dir=({
        "/players/jewel/quest/tunnel2","west",
        "/players/jewel/quest/grave4","north",
        "/players/jewel/quest/grave2","east"
             });
}

