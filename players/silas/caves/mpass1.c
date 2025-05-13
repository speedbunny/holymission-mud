

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Maze Passage";
    no_castle_flag = 0;
    long_desc = 
        "The giant archway stands to the west of here while this passage meets an \n"
        + "intersection to the east. Many footprints lead toward the archway, but only\n"
        + "very few returning footprints can be seen.\n";
    dest_dir = 
        ({
        "/players/silas/caves/pass5", "east",
        "/players/silas/caves/mpass2", "west",
        });
    smell = "The smell of mold wafts around this cave.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
