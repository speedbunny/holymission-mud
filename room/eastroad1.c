inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="East road";

    long_desc="East road runs north-south.\n";

    dest_dir=({
               "room/eastroad2","north",
               "room/vill_shore","south",
             });

    ::reset(arg);
    replace_program("room/room");
}
