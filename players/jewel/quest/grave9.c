inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A grave with a little gravestone.";
    long_desc=
        "You are standing in front of a grave with a little stone with a\n"+
        "short message on it\n";
    items=({
        "stone","A small gravestone with a message",
        "message","......mpi.es ..e ver. dan..ro.s........."
          });
    dest_dir=({
        "/players/jewel/quest/grave6","south",
        "/players/jewel/quest/grave12","north",
        "/players/jewel/quest/grave8","west"
             });
}

dig() {
    write("You find nothing.\n");
    say(this_player()->query_name() +" digs and finds nothing.\n");
    return(1);
}
