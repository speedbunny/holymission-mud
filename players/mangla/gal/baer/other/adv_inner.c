inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc = "The LPC board";

    long_desc =
               "This is the LPC discussion room.\n" +
               "Only wizards can access this room.\n";

    dest_dir=({
               "room/adv_guild", "north",
             });

    clone_list = ({ 1, 1, "board", "/boards/adv_inner", 0,
                   });

//    transfer(clone_object("/boards/adv_inner2"),this_object());

    ::reset(arg);
    replace_program("room/room");
}
