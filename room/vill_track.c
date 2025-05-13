inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Village track";

    long_desc=
              "A track going into the village. The track opens up " +
              "to a road to the east and ends with a green lawn " +
              "to the west. While to the north you hear the sound " +
              "of money, and a crowd of people.\n";

    dest_dir=({ "room/vill_road1","east",
//                 "players/rasta/room/raspath","south", /* Warlord 070294 */
                "/players/haplo/casino/casino","north",
                "players/cashimor/extend/village1","west",
             });

    ::reset(arg);
    replace_program("room/room");
}

