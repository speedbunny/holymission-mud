inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/kguard");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Village Road";
    no_castle_flag = 0;
    long_desc = 
        "This is the end of the village of Keidall. In the near future the road will\n"
        + "continue from this point on, but for now this is where it ends. Please check\n"
        + "back regularly.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/keidall5", "east",
        "/players/meecham/pot_shops/ps_silas","north",
        });
    smell = "Smoke and cow manure give off a pungent odor.\n";
}

query_light() {
    return 1;
}
