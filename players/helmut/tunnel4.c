inherit "room/room";

reset(arg) {
 object ob;
#if 0
  if (!(present("golem")) || !living(ob)) {	/* Done by Herp */
#endif
  if (!(ob=present("golem")) || !living(ob)) {
     move_object(clone_object("players/silas/monster/sgolem"),
     this_object());
     }

    if (arg) return;

    set_light(1);
    short_desc = "Tunnel Intersection";
    no_castle_flag = 0;
    long_desc = 
        "You have arrived at an intersection of three passages. The long north/south\n"
        + "passageway meets with a smaller westerly passage which is normally guarded\n"
        + "by a stone golem. \n";
    dest_dir = 
        ({
        "/players/silas/caves/tunnel5", "north",
        "/players/silas/caves/tunnel3", "south",
        "/players/silas/caves/gtunnel1", "west",
        });
    smell = "You smell a damp and musty odor.\n";
}


