inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/pworm");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Maze";
    no_castle_flag = 0;
    long_desc = 
        "This is the maze of Argannos; all passages look alike. You wonder if you will\n"
        + "ever find your way out of here.\n";
    dest_dir = 
        ({
        "/players/silas/maze/maze9", "north",
        "/players/silas/maze/maze6", "south",
        "/players/silas/maze/maze7", "east",
        "/players/silas/maze/maze8", "west",
        });
    smell = "The faint smell of human flesh drifts through this maze.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
