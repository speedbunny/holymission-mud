// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A drave with a wooden cross.";
    long_desc=
        "You look at a grave with a rotten, wooden cross. There are also\n"+
        "some rotten flowers on it.\n";
    items=({
        "grave","This is a grave with a wooden cross",
        "cross","A small, rotten wooden cross",
        "wooden cross","The wood is moldy and decayed",
        "flowers","Long stem rotten roses"
          });
    dest_dir=({
        "/players/jewel/quest/grave2","south",
        "/players/jewel/quest/grave6","east",
        "/players/jewel/quest/grave8","north",
        "/players/jewel/quest/grave4","west"
             });
}

dig() {
    write("You find nothing.\n");
    say(this_player()->query_name() +" digs and finds nothing.\n");
    return(1);
}

