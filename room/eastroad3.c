inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="East road";

    long_desc=
              "East road runs north-south.  Sun alley is to the west.\n" +
              "Noxious smells float to you from the east.\n";

    dest_dir=({
               "room/eastroad4","north",
               "room/eastroad2","south",
               "players/brainsprain/guild/rooms/alch_shop","east",
               "room/sunalley1","west",
             });

    ::reset(arg);
    replace_program("room/room");
}
