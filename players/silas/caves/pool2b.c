inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living (ob)) {
  ob = clone_object("players/silas/monster/omermaid");
  move_object(ob,this_object());
  }

    if (arg) return;

    set_light(1);
    short_desc = "Pool";
    no_castle_flag = 0;
    long_desc = 
        "You are swimming in the northwestern area of the cavern pool. Towering walls\n"
        + "of rock surround you save to the east and the south where you can continue\n"
        + "swimming. \n";
    dest_dir = 
        ({
        "/players/silas/caves/pool2", "east",
        "/players/silas/caves/pool2a", "south",
        });
    smell = "The air here has a stuffy quality to it.\n";
    ::reset();
    replace_program("room/room");
}


