inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/silas");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Silas' Room";
    no_castle_flag = 0;
    long_desc = 
        "This is the room of Silas, the wizard who created this hall and the area\n"
        + "surrounding it. The room itself is painted with various shades of green to \n"
        + "resemble the wizard's love of nature.\n";
    dest_dir = 
        ({
        "/players/silas/caves/hall3", "south",
        });
    smell = "This place reeks of sheep.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
