inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/palanthea");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Palanthea's Room";
    no_castle_flag = 0;
    long_desc = 
        "This room looks more like a jungle than a regular room; plants and tropical\n"
        + "trees grow everywhere and the air is filled with the sounds of a tropical\n"
        + "rain forest. The humidity is killing you and you wonder how anyone could\n"
        + "stand to live in such a climate.\n";
    dest_dir = 
        ({
        "/players/silas/caves/hall3", "east",
        });
    smell = "The smells of the jungle enter your nose.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
