inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A nice little grave.";
    long_desc=
        "You see a nice little grave, to the north there are some dark"+
        " shades\ndancing in the dark\n";
    items=({
        "grave","A nice little grave with flowers on it",
        "shades","Some undead...maybe",
        "dark shades","Some undead...maybe"
          });
    dest_dir=({
        "/players/jewel/quest/grave5","south",
        "/players/jewel/quest/grave9","east",
        "/players/jewel/quest/grave11","north",
        "/players/jewel/quest/grave7","west"
             });
}

dig() {
    write("You find nothing.\n");
    say(this_player()->query_name() +" digs and finds nothing.\n");
    return(1);
}
