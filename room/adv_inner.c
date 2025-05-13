inherit "/room/room";

void reset(int arg) {

    set_light(1);

    short_desc = "The wiz board.";

    long_desc = "\
This is the wizard board room.\n\
Feel free to discuss your wizardly opinions here.\n\
Please update any exits leading here (eg from your workroom) to \
/room/wiz/general.\n";

    dest_dir=({
               "/room/adv_guild", "north",
               "/room/wiz/lpc", "south",
               "/room/wiz/coding_room", "up",
               "/room/wiz/idea", "southwest",
               "/room/wiz/flame", "down",
             });

    ::reset(arg);
    replace_program("/room/room");
}
