inherit "room/room";

void reset(int arg) {
    ::reset(arg);

    set_light(1);

    short_desc="Fields";

    long_desc="You are in the middle of the fields where the city " +
              "grows all its crops.\n";

    dest_dir=({ 
               "room/crop2","north",
               "room/crop4","south",
               "room/shore/s01","southeast",
             });

    property = ({ "no_clean_up" });

    items = ({
              "crops","Corn is grown here",
              "city", "The epicenter of Holy Mission",
              "fields","The city grows its crops here",
            });

    replace_program("room/room");
}
