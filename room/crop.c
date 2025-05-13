inherit "room/room";

void reset(int arg) {
    ::reset();

    set_light(1);

    short_desc="Fields";

    long_desc="You are in northern edge of the fields where " +
              "the city grows all its crops. A road runs north " +
              "and south of here.\n";

    dest_dir=({ "room/vill_shore","north",
                "room/crop2","south" });

    items=({
            "crops","The city grows corn",
            "fields","The fields are to the south",
            "city","It is a city",
          });

    replace_program("room/room");
}
