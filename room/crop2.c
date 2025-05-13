inherit "room/room";

void reset(int arg) {
    ::reset(arg);

    set_light(1);

    short_desc="Fields";

    long_desc="You are in the northern part of the fields where the " +
              "city grows all its crops. A path runs north and south " +
              "here.\n";

    dest_dir=({ 
               "room/crop","north",
               "room/crop3","south",
             });

    items=({
            "crops","The city grows corn here",
            "path","A narrow dirt road running through the crops",
            "fields","The city grows crops here",
            "city","The epicenter of Holy Mission",
          });

    replace_program("room/room");
}
