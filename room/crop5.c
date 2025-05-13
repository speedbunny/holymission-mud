inherit "room/room";

void reset(int arg) {
    ::reset(arg);

    set_light(1);

    short_desc="Fields";

    long_desc="You are in the southern edge of the fields where " +
              "the city grows all its crops. The crops seem quite " +
              "rotten here. you notice off to the east a break " +
              "in the forest you can enter.\n";

    dest_dir=({
               "room/crop4","northeast",
               "room/forest12", "west",
//                "players/kasgaroth/keep/crop6","east",
             });

    items=({
            "crops","The city grows corn but it has rotted",
            "city","The epicenter of Holy Mission",
            "fields","This is where the city grows its crops",
          });

    replace_program("room/room");
}
