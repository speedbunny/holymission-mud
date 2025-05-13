inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/goragatha");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(0);
    property = "no_teleport";
    short_desc = "Goragatha's Lair";
    no_castle_flag = 0;
    long_desc = 
        "Bones and rotting flesh are strewn about this room and you feel sick. \n"
        + "From the looks of this place it might not be a bad idea to make a hasty\n"
        + "retreat before you are noticed and dismembered into a jumble of body parts and organs.\n";
    dest_dir = 
        ({
        "/players/silas/maze/hole2", "up",
        "/players/silas/maze/treasury", "north",
        });
    smell = "The smell of rotting flesh almost knocks you out.\n";
}

query_light() {
    return 0;
}
