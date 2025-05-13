inherit "/room/room";

void reset(int arg) {

    no_castle_flag = 1;
   
    set_light(1);      

    short_desc = "Jetty";

    long_desc = "You are at a jetty. The waves rolls in from east.\n" +
                "A small path leads back to west.\n";
               
    dest_dir = ({ "room/vill_shore4", "west",
                  "room/sea",         "east",
               });

    clone_list = ({ 1, 1, "bag", "obj/bag", 0,
                 });

    ::reset(arg);
    replace_program("room/room");
}

void long(string arg) {

   call_other( "room/sea", "???" );
   long_desc = "You are at a jetty. The waves rolls in from east.\n" +
               "A small path leads back to west.\n";

   ::long( arg );
}
