inherit "room/room";

reset(arg) {
 object ob;
  if (!(present("agent"))) {
  move_object(clone_object("players/silas/houses/estate_agent"),
  this_object());
  }
  if(!(present("notice"))) {
  move_object(clone_object("players/silas/obj/notice"),
  this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Real estate office";
    no_castle_flag = 0;
    long_desc = 
        "This is the real estate office which serves the citizens of Keidall. You can\n"
        + "buy your very own house here for a modest fee. A real estate agent sits in the\n"
        + "center of the room behind a cluttered desk.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/keidall3", "north",
        });
    smell = "It smells pleasant in here.\n";
}

query_light() {
    return 1;
}
