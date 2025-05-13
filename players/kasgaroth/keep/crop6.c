inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Fields";
    long_desc=
    "You stand in the southern part of the fields where the city grows its crops.\n";
    dest_dir=({ "room/crop4","north",
      "room/crop5","west",
    });

    /* Airborne - 05-12-93 */
    replace_program("room/room");

}
