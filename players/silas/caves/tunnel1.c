inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/augustine");
  move_object(ob,this_object());
     }

    if (arg) return;

    set_light(0);
    short_desc = "Dark room";
    no_castle_flag = 0;
    long_desc = 
        "You are wandering down a long tunnel with no end in sight.\n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel2", "north",
        "/room/mine/tunnel_room", "south",
        });
    smell = "You smell a damp and musty odor.\n";
    ::reset();
    replace_program("room/room");
}


