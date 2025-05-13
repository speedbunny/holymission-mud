inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="East road";

    long_desc="East road runs south from here. To the west lies the training\n"
             +"halls of the famous fighter guild.\n";

    dest_dir=({
               "players/bobo/krooms/vill/eastroad6","north",
               "/players/saffrin/area/tinker/room/joy8","east",
               "/players/sargon/guild/rooms/castle","west",
               "room/eastroad4","south",
             });

    ::reset(arg);
    replace_program("room/room");
}
