inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Fields";
    long_desc=
    "This is the southern edge of the fields where the village grows its crops.\n"
    +"From here a road runs north into the village.  Off to the south, swarthed\n"
    +"in shadow, stands a black keep.  Deep shadows extend from its dark walls\n"
    +"and a chill seeps into your soul.  You think you smell death about.\n";
    items = ({
      "keep","Directly to the south stands this looming shape, covered in shadow",
    });
    dest_dir=({ "room/crop4","north",
      "room/crop5","west",
      "players/kasgaroth/keep/entrance","south" });
    /* Airborne - 930512 */
    replace_program("room/room");
}
