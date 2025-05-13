inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/hamburger");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Forest Entrance";
    no_castle_flag = 0;
    long_desc = 
        "This is the entrance to Ragbutho Forest, which is alive with the noises you\n"
        + "would associate with the woods. At this point you can't see any paths into the\n"
        + "forest, but there should be one before too long.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/keidall1", "west",
        });
    smell = "A brisk forest breeze blows the odor of moldy leaves and wildflowers in your face.\n";
}

query_light() {
    return 1;
}
