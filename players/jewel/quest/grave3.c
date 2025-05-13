// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="An open grave.";
    long_desc=
        "Here you see an open grave, maybe thieves have done this.\n";
    items=({
        "grave","A dark empty hole",
        "hole","A dark empty hole"
          });
    dest_dir=({
        "/players/jewel/quest/grave2","west",
        "/players/jewel/quest/grave6","north"
             });
}

dig() {
    write("You can't dig an already open grave.\n");
    return 1;
}

