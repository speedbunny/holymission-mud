inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="The attic";

    long_desc=
              "This is the attic above the church. You notice a glowing " +
              "portal to the north and a deep shaft to the west.\n";
    dest_dir=({
            "room/statroom","north",
/*
            "room/boxroom","east",
*/
                 });
    clone_list = ({ 1, 1, "wheel", "players/cashimor/objects/wheel",
                                         ({ "set_level", 6, }),
                 });
    smell="There is a lot of dust in the air.";
    
    ::reset(arg);
    replace_program("room/room");
}
