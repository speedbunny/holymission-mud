inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/gpworm");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Maze";
    no_castle_flag = 0;
    long_desc = 
        "This is the maze of Argannos; all passages look alike. You wonder if you will\n"
        + "ever find your way out of here.\n"
        + "You can see a small room to the south of here.\n";
    dest_dir = 
        ({
        "/players/silas/maze/maze2", "north",
        "/players/silas/maze/earthroom", "south",
        "/players/silas/maze/maze10", "east",
        "/players/silas/maze/maze11", "west",
        });
    smell = "The faint smell of human flesh drifts through this maze.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
