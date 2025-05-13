// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A grave with an iron cross.";
    long_desc=
        "You are standing in front of a grave with an iron cross.\n";
    items=({
        "cross","A simple iron cross",
        "grave","A very small grave.  Perhaps a child's grave?"
          });
    dest_dir=({
        "/players/jewel/quest/grave1","west",
        "/players/jewel/quest/grave3","east",
        "/players/jewel/quest/grave5","north"
             });
}

dig() {
    write("You find nothing.\n");
    say(this_player()->query_name() +" digs and finds nothing.\n");
    return(1);
}

