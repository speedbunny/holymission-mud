inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/tnoggoth");
  move_object(ob,this_object());
     }
    if (arg) return;

    set_light(1);
    short_desc = "Tnoggoth's Lair";
    no_castle_flag = 0;
    long_desc = 
        "A phosphorescent greenish light illuminates this small cave. This is where\n"
        + "Tnoggoth feasts on his prey as you can see from the countless bones and other\n"
        + "mortal remains which are lying around. Hopefully you will do better than your\n"
        + "predecessors...\n";
    dest_dir = 
        ({
        "/players/silas/caves/unpool", "south",
        });
    smell = "You decide not to inhale the water.\n";
    ::reset();
    replace_program("room/room");
}


