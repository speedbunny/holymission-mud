inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Road";

    long_desc=
              "You are on a road going out of the village. " +
              "Eastroad runs north from here, along the " +
              "eastern perimeter of the city, and to the south " +
              "are some fields planted with all the crops " +
              "that the city needs. The main road runs towards " +
              "the shore to the east, and into the city to the west.\n";

    dest_dir=({
               "room/vill_road2","west",
               "room/vill_road3","east",
               "room/eastroad1","north",
               "room/crop","south",
             });

    ::reset(arg);
    replace_program("room/room");
}

