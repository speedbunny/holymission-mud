inherit "room/room";

void reset(int arg) {
    ::reset(arg);

    set_light(1);

    short_desc="Fields";

    long_desc="You are in the southern part of the fields where " +
              "the city grows all its crops. A chill flows from " +
              "the west where a dense, black fog eminates.\n";

    dest_dir=({
               "room/crop3","north",
               "/players/tuppence/fortress/room/entrance","west",
//                "players/kasgaroth/keep/crop6","south",
               "room/crop5","southwest"
             });

    items = ({
              "fields","The place where the city grows its crops",
              "city","The epicenter of Holy Mission",
              "crops","The city grows corn",
              "fog","It is dense and black and sends a chill up your spine",
            });

    replace_program("room/room");
}
